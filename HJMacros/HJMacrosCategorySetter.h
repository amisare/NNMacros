//
//  HJMacrosCategorySetter.h
//  HJMacros
//
//  Created by GuHaijun on 2018/5/31.
//  Copyright © 2018年 顾海军. All rights reserved.
//

#ifndef HJMacrosCategorySetter_h
#define HJMacrosCategorySetter_h

#if !__has_include(<metamacros.h>)
# include "metamacros.h"
#endif

/*
 atomic_type:   atomic, nonatomic
 arc_type:      assign, strong, copy
 data_type:     属性类型
 param0:        setter方法名
 param1:        hook0
 param2:        hook1
 */

static inline objc_AssociationPolicy categorysetter_store_policy(NSString *arcType, NSString *atomicType) {
    objc_AssociationPolicy policy = OBJC_ASSOCIATION_ASSIGN;
    if ([arcType isEqualToString:@"strong"] || [arcType isEqualToString:@"weak"]) {
         if ([atomicType isEqualToString:@"atomic"]) {
             policy = OBJC_ASSOCIATION_RETAIN;
         }
         else {
             policy = OBJC_ASSOCIATION_RETAIN_NONATOMIC;
         }
    }
    else if ([arcType isEqualToString:@"copy"]) {
        if ([atomicType isEqualToString:@"atomic"]) {
            policy = OBJC_ASSOCIATION_COPY;
        }
        else {
            policy = OBJC_ASSOCIATION_COPY_NONATOMIC;
        }
    }
    else {
        policy = OBJC_ASSOCIATION_ASSIGN;
    }
    return policy;
}

static inline SEL ategorysetter_store_key(Class cls, SEL sel) {
    SEL ret = nil;
    const char *selName = sel_getName(sel);
    const char *prefix = "set";
    size_t keyNameSize = (strlen(selName) + 1) - strlen(prefix);
    char *keyName = calloc(keyNameSize, sizeof(char));
    if (0 != memcmp(selName, prefix, strlen(prefix))) { goto end; }
    memcpy(keyName, (selName + strlen(prefix)), keyNameSize);
    if (keyName[0]>'A' && keyName[0]<'Z') { keyName[0] += ('a' - 'A'); }
    if (keyName[strlen(keyName) - 1] == ':') { keyName[strlen(keyName) - 1] = '\0'; }
    SEL keySel = NSSelectorFromString(@(keyName));
    Method method = class_getInstanceMethod(cls, keySel);
    if (method == nil) {  goto end; }
    ret = method_getName(method) ;
end:
    free(keyName);
    return ret;
}

#define categorysetter_policy(arc_type, atomic_type) \
        categorysetter_store_policy(HJM_Arg2String(arc_type), HJM_Arg2String(atomic_type)) \

#define categorysetter_key(clazz, setter) \
        ategorysetter_store_key(clazz, setter)\

#define categorysetter_args_fill(expect_number, ...) \
        metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))(__VA_ARGS__, , ,) \
        (metamacro_if_eq(2, metamacro_argcount(__VA_ARGS__))(__VA_ARGS__, ,) \
        (__VA_ARGS__)) \

#pragma mark - setter

#define categorysetter(atomic_type, arc_type, data_type, ...) \
        metamacro_concat(categorysetter, \
        metamacro_concat(_, arc_type))\
        (atomic_type, arc_type, data_type, categorysetter_args_fill(3, __VA_ARGS__)) \

#pragma mark - setter strong

#define categorysetter_strong(atomic_type, arc_type, data_type, ...) \
\
- (void)metamacro_at(0, __VA_ARGS__):(data_type)newValue\
{ \
    SEL __key = categorysetter_key([self class], _cmd); \
    metamacro_at(1, __VA_ARGS__) \
    data_type __ivar = newValue; \
    metamacro_at(2, __VA_ARGS__) \
    objc_setAssociatedObject(self, __key, __ivar, categorysetter_policy(arc_type, atomic_type)); \
} \

#pragma mark - setter weak

#define categorysetter_weak(atomic_type, arc_type, data_type, ...) \
\
- (void)metamacro_at(0, __VA_ARGS__):(data_type)newValue\
{ \
    SEL __key = categorysetter_key([self class], _cmd); \
    metamacro_at(1, __VA_ARGS__) \
    data_type __ivar = newValue; \
    NSMapTable *__table = [NSMapTable strongToWeakObjectsMapTable]; \
    [__table setObject:__ivar forKey:NSStringFromSelector(__key)]; \
    metamacro_at(2, __VA_ARGS__) \
    objc_setAssociatedObject(self, __key, __table, categorysetter_policy(arc_type, atomic_type)); \
} \

#pragma mark - setter assign

#define categorysetter_assign(atomic_type, arc_type, data_type, ...) \
\
- (void)metamacro_at(0, __VA_ARGS__):(data_type)newValue\
{ \
    SEL __key = categorysetter_key([self class], _cmd); \
    metamacro_at(1, __VA_ARGS__) \
    id __ivar = @(newValue); \
    metamacro_at(2, __VA_ARGS__) \
    objc_setAssociatedObject(self, __key, __ivar, categorysetter_policy(arc_type, atomic_type)); \
} \

#endif /* HJMacrosCategorySetter_h */
