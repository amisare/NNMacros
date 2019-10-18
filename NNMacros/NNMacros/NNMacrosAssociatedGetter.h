//
//  NNMacrosAssociatedGetter.h
//  NNMacros
//
//  Created by 顾海军 on 2019/10/16.
//  Copyright © 2019 GuHaijun. All rights reserved.
//

#ifndef NNMacrosAssociatedGetter_h
#define NNMacrosAssociatedGetter_h

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#include "metamacros.h"
#include "NNMacrosAssociatedCommon.h"

/***************************************************
 associated getter
 ***************************************************/
/*
 atomic_type:   atomic, nonatomic
 arc_type:      assign, strong, copy
 data_type:     属性类型
 param0:        getter方法名
 param1:        hook_after_load
 param2:        hook_befor_ret
 */

#ifndef nn_associated_getter


#pragma mark - getter

#define nn_associated_getter(atomic_type, arc_type, data_type, ...) \
        metamacro_concat(nn_associated_getter, \
        metamacro_concat(_, arc_type))\
        (atomic_type, arc_type, data_type, nn_associated_getter_args_fill(3, __VA_ARGS__)) \


#pragma mark - getter tools

#define nn_associated_getter_args_fill(expect_number, ...) \
        metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))(__VA_ARGS__, ,) \
        (__VA_ARGS__) \


#pragma mark - getter strong

#define nn_associated_getter_strong(atomic_type, arc_type, data_type, ...) \
\
- (data_type)metamacro_at(0, __VA_ARGS__) \
{\
    SEL __key = _cmd; \
    id getValue = objc_getAssociatedObject(self, __key); \
    metamacro_at(1, __VA_ARGS__); \
    return getValue; \
}\


#pragma mark - getter weak

#define nn_associated_getter_weak(atomic_type, arc_type, data_type, ...) \
\
- (data_type)metamacro_at(0, __VA_ARGS__) \
{\
    SEL __key = _cmd; \
    NSMapTable *__get_table = objc_getAssociatedObject(self, __key); \
    data_type getValue = [__get_table objectForKey:NSStringFromSelector(__key)]; \
    metamacro_at(1, __VA_ARGS__); \
    return getValue; \
}\


#pragma mark - getter assign

#define nn_associated_getter_assign(atomic_type, arc_type, data_type, ...) \
\
- (data_type)metamacro_at(0, __VA_ARGS__) \
{\
    SEL __key = _cmd; \
    id __get_obj = objc_getAssociatedObject(self, __key); \
    data_type *__value_p = nn_associated_copy_obj_2_type_value(__get_obj, data_type); \
    data_type getValue = *__value_p; \
    free(__value_p); \
    metamacro_at(1, __VA_ARGS__); \
    return getValue; \
}\

#endif /* nn_associated_getter */

#endif /* NNMacrosAssociatedGetter_h */
