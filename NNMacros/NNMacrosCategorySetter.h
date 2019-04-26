//
//  NNMacrosCategorySetter.h
//  NNMacros
//
//  Created by GuHaijun on 2018/5/31.
//  Copyright © 2018年 顾海军. All rights reserved.
//

#ifndef NNMacrosCategorySetter_h
#define NNMacrosCategorySetter_h

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#include "metamacros.h"

/***************************************************
 category setter
 ***************************************************/
/*
 atomic_type:   atomic, nonatomic
 arc_type:      assign, strong, copy
 data_type:     属性类型
 param0:        setter方法名
 param1:        hook_begin_set
 param2:        hook_befor_store
 */

#ifndef categorysetter

#pragma mark - setter

#define categorysetter(atomic_type, arc_type, data_type, ...) \
        metamacro_concat(categorysetter, \
        metamacro_concat(_, arc_type))\
        (atomic_type, arc_type, data_type, categorysetter_args_fill(3, __VA_ARGS__)) \

#pragma mark - setter tools


/**
 获取 setter 方法中 objc_setAssociatedObject 参数 policy

 @param arcType arc 类型
 @param atomicType atomic 类型
 @return setter 方法中 objc_setAssociatedObject 参数 policy
 */
static inline objc_AssociationPolicy nn_categorysetter_store_policy(NSString *arcType, NSString *atomicType) {
    if ([arcType isEqualToString:@"strong"] && [atomicType isEqualToString:@"nonatomic"]) {
        return OBJC_ASSOCIATION_RETAIN_NONATOMIC;
    }
    else if ([arcType isEqualToString:@"strong"] && [atomicType isEqualToString:@"atomic"]) {
        return OBJC_ASSOCIATION_RETAIN;
    }
    else if  ([arcType isEqualToString:@"copy"] && [atomicType isEqualToString:@"nonatomic"]) {
        return OBJC_ASSOCIATION_COPY_NONATOMIC;
    }
    else if  ([arcType isEqualToString:@"copy"] && [atomicType isEqualToString:@"atomic"]) {
        return OBJC_ASSOCIATION_COPY;
    }
    else {
        return OBJC_ASSOCIATION_ASSIGN;
    }
}


/**
 获取 setter 方法中 objc_setAssociatedObject 参数 key

 @discussion 动态添加获取属性的 key 值为 getter 方法的 sel ，该函数通过截取 setter 方法的 sel ，获取 key 值
 @param cls 类名
 @param sel setter 方法的 sel
 @return setter 方法中 objc_setAssociatedObject 参数 key
 */
static inline SEL nn_categorysetter_store_key(Class cls, SEL sel) {
    SEL ret = nil;
    const char *selName = sel_getName(sel);
    const char *prefix = "set";
    // 1. 判断 sel 是否是以 "set" 开头
    if (0 != memcmp(selName, prefix, strlen(prefix))) { goto end; }
    // 2. 判断 sel 是否是以 ":" 结尾
    if (':' != selName[strlen(selName) - 1]) { goto end; }
    // 3. 拷贝 "set" 之后的字符串，包括 "\0"。
    size_t keyNameSize = (strlen(selName) + 1) - strlen(prefix);
    unsigned char *keyName = calloc(keyNameSize, sizeof(unsigned char));
    memcpy(keyName, (selName + strlen(prefix)), keyNameSize);
    // 4. 如果 "set" 是字母，那么转换为小写。如："setUserName:"，将 "UserName:" 转为 "userName:" 。
    if (keyName[0] > 'A' && keyName[0] < 'Z') { keyName[0] += ('a' - 'A'); }
    // 5. 去掉 sel 结尾的 ":" ，使用 "\0" 替换。
    keyName[strlen((const char *)keyName) - 1] = '\0';
    // 6. 实际应用中不会遇到仅有 setter 方法的情况，通过 method 获取 setter 方法 sel 。
    SEL keySel = NSSelectorFromString([NSString stringWithUTF8String:(const char *)keyName]);
    Method method = class_getInstanceMethod(cls, keySel);
    if (method == nil) {  goto end_free; }
    ret = method_getName(method) ;
end_free:
    free(keyName);
end:
    return ret;
}

#define categorysetter_key(clazz, setter) \
        nn_categorysetter_store_key(clazz, setter)\

#define categorysetter_policy(arc_type, atomic_type) \
        nn_categorysetter_store_policy(NN_Arg2String(arc_type), NN_Arg2String(atomic_type)) \

#define categorysetter_args_fill(expect_number, ...) \
        metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))(__VA_ARGS__, , ,) \
        (metamacro_if_eq(2, metamacro_argcount(__VA_ARGS__))(__VA_ARGS__, ,) \
        (__VA_ARGS__)) \

#pragma mark - setter strong

#define categorysetter_strong(atomic_type, arc_type, data_type, ...) \
\
- (void)metamacro_at(0, __VA_ARGS__):(data_type)newValue\
{ \
    SEL __key = categorysetter_key([self class], _cmd); \
    data_type __ivar = newValue; \
    metamacro_at(1, __VA_ARGS__) \
    id __obj = __ivar; \
    metamacro_at(2, __VA_ARGS__) \
    objc_setAssociatedObject(self, __key, __obj, categorysetter_policy(arc_type, atomic_type)); \
} \

#pragma mark - setter weak

#define categorysetter_weak(atomic_type, arc_type, data_type, ...) \
\
- (void)metamacro_at(0, __VA_ARGS__):(data_type)newValue\
{ \
    SEL __key = categorysetter_key([self class], _cmd); \
    data_type __ivar = newValue; \
    metamacro_at(1, __VA_ARGS__) \
    NSMapTable *__obj = [NSMapTable strongToWeakObjectsMapTable]; \
    [__obj setObject:__ivar forKey:NSStringFromSelector(__key)]; \
    metamacro_at(2, __VA_ARGS__) \
    objc_setAssociatedObject(self, __key, __obj, categorysetter_policy(arc_type, atomic_type)); \
} \

#pragma mark - setter assign

#define categorysetter_assign(atomic_type, arc_type, data_type, ...) \
\
- (void)metamacro_at(0, __VA_ARGS__):(data_type)newValue\
{ \
    SEL __key = categorysetter_key([self class], _cmd); \
    data_type __ivar = newValue; \
    metamacro_at(1, __VA_ARGS__) \
    id __obj = @(__ivar); \
    metamacro_at(2, __VA_ARGS__) \
    objc_setAssociatedObject(self, __key, __obj, categorysetter_policy(arc_type, atomic_type)); \
} \

#endif /* categorysetter */

#endif /* NNMacrosCategorySetter_h */