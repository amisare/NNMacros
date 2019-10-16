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
#include "NNMacrosAssociatedKey.h"

/***************************************************
 associated setter
 ***************************************************/
/*
 atomic_type:   atomic, nonatomic
 arc_type:      assign, strong, copy
 data_type:     属性类型
 param0:        属性名称
 param1:        hook_begin_set
 param2:        hook_befor_store
 */

#ifndef nn_associated_setter


#pragma mark - setter

#define nn_associated_setter(atomic_type, arc_type, data_type, ...) \
        metamacro_concat(nn_associated_setter, \
        metamacro_concat(_, arc_type))\
        (atomic_type, arc_type, data_type, nn_associated_setter_args_fill(3, __VA_ARGS__)) \

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

#define nn_associated_setter_policy(arc_type, atomic_type) \
        nn_associated_setter_store_policy(NN_arg2String(arc_type), NN_arg2String(atomic_type)) \

#define nn_associated_setter_args_fill(expect_number, ...) \
        metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))(__VA_ARGS__, , ,) \
        (metamacro_if_eq(2, metamacro_argcount(__VA_ARGS__))(__VA_ARGS__, ,) \
        (__VA_ARGS__)) \

#pragma mark - setter strong

#define nn_associated_setter_strong(atomic_type, arc_type, data_type, ...) \
@dynamic metamacro_at(0, __VA_ARGS__);\
- (void)metamacro_concat(nn_associated_setter_prefix, metamacro_at(0, __VA_ARGS__)):(data_type)newValue\
{ \
    const char *__key = metamacro_stringify(metamacro_concat(nn_associated_store_key, metamacro_at(0, __VA_ARGS__))); \
    data_type __ivar = newValue; \
    metamacro_at(1, __VA_ARGS__) \
    id __obj = __ivar; \
    metamacro_at(2, __VA_ARGS__) \
    objc_setAssociatedObject(self, __key, __obj, nn_associated_setter_policy(arc_type, atomic_type)); \
} \

#pragma mark - setter weak

#define nn_associated_setter_weak(atomic_type, arc_type, data_type, ...) \
@dynamic metamacro_at(0, __VA_ARGS__);\
- (void)metamacro_concat(nn_associated_setter_prefix, metamacro_at(0, __VA_ARGS__)):(data_type)newValue\
{ \
    const char *__key = metamacro_stringify(metamacro_concat(nn_associated_store_key, metamacro_at(0, __VA_ARGS__))); \
    data_type __ivar = newValue; \
    metamacro_at(1, __VA_ARGS__) \
    NSMapTable *__obj = [NSMapTable strongToWeakObjectsMapTable]; \
    [__obj setObject:__ivar forKey:@(__key)]; \
    metamacro_at(2, __VA_ARGS__) \
    objc_setAssociatedObject(self, __key, __obj, nn_associated_setter_policy(arc_type, atomic_type)); \
} \

#pragma mark - setter assign

#define nn_associated_setter_assign(atomic_type, arc_type, data_type, ...) \
@dynamic metamacro_at(0, __VA_ARGS__);\
- (void)metamacro_concat(nn_associated_setter_prefix, metamacro_at(0, __VA_ARGS__)):(data_type)newValue\
{ \
    const char *__key = metamacro_stringify(metamacro_concat(nn_associated_store_key, metamacro_at(0, __VA_ARGS__))); \
    data_type __ivar = newValue; \
    metamacro_at(1, __VA_ARGS__) \
    id __obj = @(__ivar); \
    metamacro_at(2, __VA_ARGS__) \
    objc_setAssociatedObject(self, __key, __obj, nn_associated_setter_policy(arc_type, atomic_type)); \
} \

#endif /* nn_associated_setter */

#endif /* NNMacrosAssociatedSetter_h */
