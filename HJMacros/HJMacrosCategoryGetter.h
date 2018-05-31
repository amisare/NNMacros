//
//  HJMacrosCategoryGetter.h
//  HJMacros
//
//  Created by GuHaijun on 2018/5/31.
//  Copyright © 2018年 顾海军. All rights reserved.
//

#ifndef HJMacrosCategoryGetter_h
#define HJMacrosCategoryGetter_h

#if !__has_include(<metamacros.h>)
# include "metamacros.h"
#endif

/*
 atomic_type:   atomic, nonatomic
 arc_type:      assign, strong, copy
 data_type:     属性类型
 param0:        getter方法名
 param1:        hook0
 param2:        hook1
 */

static inline char categorygetter_ret_encoding(Class cls, SEL sel) {
    Method method = class_getInstanceMethod(cls, sel);
    if (method == nil) { return 'v'; }
    const char *encoding = method_getTypeEncoding(method);
    if (encoding == nil || strlen(encoding) == 0) { return 'v'; }
    char ret = encoding[0];
    return ret;
}

#define obj_2_type(obj, type, encoding) \
({ \
    type ivar = 0; \
    if (encoding == _C_CHR)         { ivar = (type)[obj charValue]; } \
    if (encoding == _C_UCHR)        { ivar = (type)[obj unsignedCharValue]; } \
    if (encoding == _C_SHT)         { ivar = (type)[obj shortValue]; } \
    if (encoding == _C_USHT)        { ivar = (type)[obj unsignedShortValue]; } \
    if (encoding == _C_INT)         { ivar = (type)[obj intValue]; } \
    if (encoding == _C_UINT)        { ivar = (type)[obj unsignedIntValue]; } \
    if (encoding == _C_LNG)         { ivar = (type)[obj longValue]; } \
    if (encoding == _C_ULNG)        { ivar = (type)[obj unsignedLongValue]; } \
    if (encoding == _C_LNG_LNG)     { ivar = (type)[obj longLongValue]; } \
    if (encoding == _C_ULNG_LNG)    { ivar = (type)[obj unsignedLongLongValue]; } \
    if (encoding == _C_FLT)         { ivar = (type)[obj floatValue]; } \
    if (encoding == _C_DBL)         { ivar = (type)[obj doubleValue]; } \
    if (encoding == _C_BOOL)        { ivar = (type)[obj boolValue]; } \
    ivar; \
}) \

#define categorygetter_args_fill(expect_number, ...) \
        metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))(__VA_ARGS__, , ,) \
        (metamacro_if_eq(2, metamacro_argcount(__VA_ARGS__))(__VA_ARGS__, ,) \
        (__VA_ARGS__)) \

#pragma mark - getter

#define categorygetter(atomic_type, arc_type, data_type, ...) \
        metamacro_concat(categorygetter, \
        metamacro_concat(_, arc_type))\
        (atomic_type, arc_type, data_type, categorygetter_args_fill(3, __VA_ARGS__)) \

#pragma mark - getter strong

#define categorygetter_strong(atomic_type, arc_type, data_type, ...) \
\
- (data_type)metamacro_at(0, __VA_ARGS__) \
{\
    SEL __key = _cmd; \
    id __obj = objc_getAssociatedObject(self, __key); \
    metamacro_at(1, __VA_ARGS__) \
    data_type __ivar = __obj; \
    metamacro_at(2, __VA_ARGS__) \
    return __ivar; \
}\

#pragma mark - getter weak

#define categorygetter_weak(atomic_type, arc_type, data_type, ...) \
\
- (data_type)metamacro_at(0, __VA_ARGS__) \
{\
    SEL __key = _cmd; \
    NSMapTable *__table = objc_getAssociatedObject(self, __key); \
    metamacro_at(1, __VA_ARGS__) \
    id __obj = [__table objectForKey:NSStringFromSelector(__key)]; \
    data_type __ivar = __obj; \
    metamacro_at(2, __VA_ARGS__) \
    return __ivar; \
}\

#pragma mark - getter assign

#define categorygetter_assign(atomic_type, arc_type, data_type, ...) \
\
- (data_type)metamacro_at(0, __VA_ARGS__) \
{\
    SEL __key = _cmd; \
    id __obj = objc_getAssociatedObject(self, __key); \
    metamacro_at(1, __VA_ARGS__) \
    char __encoding = categorygetter_ret_encoding([self class], _cmd); \
    data_type __ivar = obj_2_type(__obj, data_type, __encoding); \
    metamacro_at(2, __VA_ARGS__) \
    return __ivar; \
}\

#endif /* HJMacrosCategoryGetter_h */
