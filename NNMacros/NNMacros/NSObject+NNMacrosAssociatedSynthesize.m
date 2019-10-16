//
//  NSObject+NNMacrosAssociatedSynthesize.m
//  NNMacros
//
//  Created by 顾海军 on 2019/10/16.
//  Copyright © 2019 GuHaijun. All rights reserved.
//

#import "NSObject+NNMacrosAssociatedSynthesize.h"
#import <objc/runtime.h>
#include "metamacros.h"
#include "NNMacrosAssociatedKey.h"

NS_INLINE SEL
nn_macro_realSetterSelector(Class cls, SEL sel) {
    SEL ret = nil;
    const char *selName = sel_getName(sel);
    const char *prefix = "set";
    // 1. 判断 sel 是否是以 "set" 开头
    if (0 != memcmp(selName, prefix, strlen(prefix))) { return ret; }
    // 2. 判断 sel 是否是以 ":" 结尾
    if (':' != selName[strlen(selName) - 1]) { return ret; }
    // 3. 拷贝 "set" 之后的字符串，包括 "\0"。
    size_t keyNameSize = (strlen(selName) + 1) - strlen(prefix);
    unsigned char *keyName = (unsigned char *)calloc(keyNameSize, sizeof(unsigned char));
    memcpy(keyName, (selName + strlen(prefix)), keyNameSize);
    // 4. 如果 "set" 是字母，那么转换为小写。如："setUserName:"，将 "UserName:" 转为 "userName:" 。
    if (keyName[0] > 'A' && keyName[0] < 'Z') { keyName[0] += ('a' - 'A'); }
    // 5. 获取 setter 方法 selector
    NSString *selectorName = [@(metamacro_stringify(nn_associated_setter_prefix)) stringByAppendingString:[NSString stringWithUTF8String:(const char *)keyName]];
    SEL selector = NSSelectorFromString(selectorName);
    // 6. 通过获取 Method ，判断 selector 是否存在。
    Method method = class_getInstanceMethod(cls, selector);
    if (method == nil) {  goto end; }
    ret = method_getName(method) ;
end:
    free(keyName);
    return ret;
}

NS_INLINE void
nn_macro_swizzledMark(id self, SEL _cmd) {
    NSLog(@"%@ %s methods have been swizzed", self, sel_getName(_cmd));
}

NS_INLINE void
nn_macro_swizzleSelector(Class clazz, SEL originalSelector, SEL swizzledSelector) {
    
    // 防止 swizzle 多次执行
    NSString *swizzedMarkName = [NSString stringWithFormat:@"%@_%@", @"nn_swizzedMark", @(sel_getName(swizzledSelector))];
    SEL swizzedMarkSelector = NSSelectorFromString(swizzedMarkName);
    if ([clazz respondsToSelector:swizzedMarkSelector]) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
        [clazz performSelector:swizzedMarkSelector];
#pragma clang diagnostic pop
        return;
    }
    class_addMethod(clazz, swizzedMarkSelector, (IMP)nn_macro_swizzledMark, "v@:");
    
    // swizzle 方法
    Method originalMethod = class_getClassMethod(clazz, originalSelector);
    Method swizzedMethod = class_getClassMethod(clazz, swizzledSelector);
    
    IMP originalImplementation = class_replaceMethod(clazz, method_getName(originalMethod), method_getImplementation(swizzedMethod), method_getTypeEncoding(originalMethod));
    
    class_replaceMethod(clazz, method_getName(swizzedMethod), originalImplementation, method_getTypeEncoding(originalMethod));
}

NS_INLINE BOOL
nn_macro_forwardInvocation(NSInvocation *anInvocation) {
    
    SEL selector = nn_macro_realSetterSelector([anInvocation.target class],
                                               anInvocation.selector);
    Method swizzedMethod = class_getInstanceMethod([anInvocation.target class],
                                                   selector);
    class_addMethod([anInvocation.target class],
                    anInvocation.selector,
                    method_getImplementation(swizzedMethod),
                    method_getTypeEncoding(swizzedMethod));
    
    // 检查响应
    if (![anInvocation.target respondsToSelector:anInvocation.selector]) {
        return false;
    }
    
    // 执行方法
    [anInvocation invoke];
    
    return true;
}

@implementation NSObject (NNMacrosAssociatedSynthesize)

+(void)load {
    
    // Hood 原生方法
    nn_macro_swizzleSelector(self,
                       @selector(forwardInvocation:),
                       @selector(nn_macro_instance_forwardInvocation:));
    nn_macro_swizzleSelector(self,
                       @selector(methodSignatureForSelector:),
                       @selector(nn_macro_methodSignatureForSelector:));
}

- (void)nn_macro_instance_forwardInvocation:(NSInvocation *)anInvocation {
    
    if (nn_macro_forwardInvocation(anInvocation)) {
        return;
    }
    [self nn_macro_instance_forwardInvocation:anInvocation];
}

- (NSMethodSignature *)nn_macro_methodSignatureForSelector:(SEL)aSelector {
    
    NSMethodSignature *sign = nil;
    sign = [self nn_macro_methodSignatureForSelector:aSelector];
    if (sign != nil) {
        return sign;
    }
    
    SEL selector = nn_macro_realSetterSelector([self class], aSelector);
    sign = [self nn_macro_methodSignatureForSelector:selector];
    
    return sign;
}

@end
