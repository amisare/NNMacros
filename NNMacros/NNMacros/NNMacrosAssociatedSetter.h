//
//  NNMacrosAssociatedSetter.h
//  NNMacros
//
//  Created by 顾海军 on 2019/10/16.
//  Copyright © 2019 GuHaijun. All rights reserved.
//

#ifndef NNMacrosAssociatedSetter_h
#define NNMacrosAssociatedSetter_h

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#include "metamacros.h"
#include "NNMacrosAssociatedCommon.h"

/***************************************************
 associated setter
 ***************************************************/
/*
 atomic_type:   atomic, nonatomic
 arc_type:      assign, strong, copy
 data_type:     属性类型
 param0:        setter方法名
 param1:        hook_begin_set
 param2:        hook_befor_store
 */

#ifndef nn_associated_setter

#pragma mark - setter tools


/**
 获取 setter 方法中 objc_setAssociatedObject 参数 policy

 @param arcType arc 类型
 @param atomicType atomic 类型
 @return setter 方法中 objc_setAssociatedObject 参数 policy
 */
static inline objc_AssociationPolicy nn_associated_setter_store_policy(NSString *arcType, NSString *atomicType) {
    if ([arcType isEqualToString:@"strong"] && [atomicType isEqualToString:@"nonatomic"]) {
        return OBJC_ASSOCIATION_RETAIN_NONATOMIC;
    }
    else if ([arcType isEqualToString:@"strong"] && [atomicType isEqualToString:@"atomic"]) {
        return OBJC_ASSOCIATION_RETAIN;
    }
    else if ([arcType isEqualToString:@"weak"] && [atomicType isEqualToString:@"nonatomic"]) {
        return OBJC_ASSOCIATION_RETAIN_NONATOMIC;
    }
    else if ([arcType isEqualToString:@"weak"] && [atomicType isEqualToString:@"atomic"]) {
        return OBJC_ASSOCIATION_RETAIN;
    }
    else if ([arcType isEqualToString:@"assign"] && [atomicType isEqualToString:@"nonatomic"]) {
        return OBJC_ASSOCIATION_RETAIN_NONATOMIC;
    }
    else if ([arcType isEqualToString:@"assign"] && [atomicType isEqualToString:@"atomic"]) {
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
 获取 getter 方法的 sel

 @discussion 函数通过截取 setter 方法的 sel ，获取 getter 方法的 sel
 @param cls 类名
 @param sel setter 方法的 sel
 @return getter 方法的 sel
 */
static inline SEL nn_associated_getter_sel(Class cls, SEL sel) {
    SEL ret = nil;
    const char *selName = sel_getName(sel);
    const char *prefix = "set";
    // 1. 判断 sel 是否是以 "set" 开头
    if (0 != memcmp(selName, prefix, strlen(prefix))) { return ret; }
    // 2. 判断 sel 是否是以 ":" 结尾
    if (':' != selName[strlen(selName) - 1]) { return ret; }
    // 3. 拷贝 "set" 之后的字符串，包括 "\0"。
    size_t keySize = (strlen(selName) + 1) - strlen(prefix);
    unsigned char *key = (unsigned char *)calloc(keySize, sizeof(unsigned char));
    memcpy(key, (selName + strlen(prefix)), keySize);
    // 4. 如果 "set" 是字母，那么转换为小写。如："setUserName:"，将 "UserName:" 转为 "userName:" 。
    if (key[0] >= 'A' && key[0] <= 'Z') { key[0] += ('a' - 'A'); }
    // 5. 去掉 sel 结尾的 ":" ，使用 "\0" 替换。
    key[strlen((const char *)key) - 1] = '\0';
    // 6. 获取 getter 方法的 sel
    if (strlen((const char *)key)) {
        ret = sel_getUid((const char *)key);
    }
end:
    free(key);
    return ret;
}


#pragma mark - setter

#define nn_associated_setter(atomic_type, arc_type, data_type, ...) \
        metamacro_concat(nn_associated_setter, \
        metamacro_concat(_, arc_type))\
        (atomic_type, arc_type, data_type, nn_associated_setter_args_fill(3, __VA_ARGS__)) \

#define nn_associated_setter_key(clazz, setter) \
        nn_associated_getter_sel(clazz, setter)\

#define nn_associated_setter_policy(arc_type, atomic_type) \
        nn_associated_setter_store_policy(NN_arg2String(arc_type), NN_arg2String(atomic_type)) \

#define nn_associated_setter_args_fill(expect_number, ...) \
        metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))(__VA_ARGS__, , ,) \
        (metamacro_if_eq(2, metamacro_argcount(__VA_ARGS__))(__VA_ARGS__, ,) \
        (__VA_ARGS__)) \


#pragma mark - setter strong

#define nn_close_hint       __nn_close_hint_

#define nn_associated_setter_strong(atomic_type, arc_type, data_type, ...) \
\
- (void)metamacro_concat(nn_close_hint, metamacro_at(0, __VA_ARGS__)):(data_type)newValue{}\
\
- (void)metamacro_at(0, __VA_ARGS__):(data_type)value\
{ \
    SEL __key = nn_associated_setter_key([self class], _cmd); \
    /** will set */ \
    __unused id oldValue = objc_getAssociatedObject(self, __key); \
    id setValue = value; \
    metamacro_at(1, __VA_ARGS__); \
    /** set  */ \
    objc_setAssociatedObject(self, __key, setValue, nn_associated_setter_policy(arc_type, atomic_type)); \
    /** did set  */ \
    __unused id newValue = objc_getAssociatedObject(self, __key); \
    metamacro_at(2, __VA_ARGS__); \
} \


#pragma mark - setter weak

#define nn_associated_setter_weak(atomic_type, arc_type, data_type, ...) \
\
- (void)metamacro_concat(nn_close_hint, metamacro_at(0, __VA_ARGS__)):(data_type)newValue{}\
\
- (void)metamacro_at(0, __VA_ARGS__):(data_type)value\
{ \
    SEL __key = nn_associated_setter_key([self class], _cmd); \
    /** will set */ \
    NSMapTable *__get_old_table = objc_getAssociatedObject(self, __key); \
    __unused id oldValue = [__get_old_table objectForKey:NSStringFromSelector(__key)]; \
    id setValue = value; \
    metamacro_at(1, __VA_ARGS__); \
    /** set  */ \
    NSMapTable *__set_table = [NSMapTable strongToWeakObjectsMapTable]; \
    [__set_table setObject:setValue forKey:NSStringFromSelector(__key)]; \
    objc_setAssociatedObject(self, __key, __set_table, nn_associated_setter_policy(arc_type, atomic_type)); \
    /** did set  */ \
    NSMapTable *__get_new_table = objc_getAssociatedObject(self, __key); \
    __unused id newValue = [__get_new_table objectForKey:NSStringFromSelector(__key)]; \
    metamacro_at(2, __VA_ARGS__); \
} \


#pragma mark - setter assign

#define nn_associated_setter_assign(atomic_type, arc_type, data_type, ...) \
\
- (void)metamacro_concat(nn_close_hint, metamacro_at(0, __VA_ARGS__)):(data_type)newValue{}\
\
- (void)metamacro_at(0, __VA_ARGS__):(data_type)value\
{ \
    SEL __key = nn_associated_setter_key([self class], _cmd); \
    /** will set */ \
    id __get_old_obj = objc_getAssociatedObject(self, __key); \
    data_type *__old_value_p = nn_associated_copy_obj_2_type_value(__get_old_obj, data_type); \
    __unused data_type oldValue = *__old_value_p; \
    free(__old_value_p); \
    data_type setValue = value; \
    metamacro_at(1, __VA_ARGS__); \
    /** set  */ \
    id __set_obj = @(setValue); \
    objc_setAssociatedObject(self, __key, __set_obj, nn_associated_setter_policy(arc_type, atomic_type)); \
    /** did set  */ \
    id __get_new_obj = objc_getAssociatedObject(self, __key); \
    data_type *__new_value_p = nn_associated_copy_obj_2_type_value(__get_new_obj, data_type); \
    __unused data_type newValue = *__new_value_p; \
    free(__new_value_p); \
    metamacro_at(2, __VA_ARGS__); \
} \

#endif /* nn_associated_setter */

#endif /* NNMacrosAssociatedSetter_h */
