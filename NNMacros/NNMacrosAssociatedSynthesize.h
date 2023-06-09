//
//  NNMacrosAssociatedSynthesize.h
//  NNMacros
//
//  Created by 顾海军 on 2019/10/16.
//  Copyright © 2019 GuHaijun. All rights reserved.
//

#ifndef NNMacrosAssociatedSynthesize_h
#define NNMacrosAssociatedSynthesize_h

#import "NNMacrosAssociatedGetter.h"
#import "NNMacrosAssociatedSetter.h"
#include "EXTSynthesize.h"
#include "metamacros.h"

/***************************************************
 associated synthesize
 ***************************************************/

/**
 * 2 个参数:
 * frist_type:      被关联参数类名
 * property:        属性名称
 *
 * 5 个参数:
 * frist_type:      atomic, nonatomic
 * arc_type:        assign, strong, copy
 * data_type:       属性类型
 * getter:          getter方法名
 * setter:          setter方法名
 */


#ifndef nn_associated_synthesize

#define nn_associated_synthesize(frist_type, ...) \
\
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wcompound-token-split-by-macro\"") \
metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))(nn_associated_synthesize2(frist_type, __VA_ARGS__))\
(metamacro_if_eq(4, metamacro_argcount(__VA_ARGS__))(nn_associated_synthesize5(frist_type, __VA_ARGS__))\
(nn_lazygetterparamsother(type, __VA_ARGS__)))\
_Pragma("clang diagnostic pop")\

#define nn_associated_synthesize2(frist_type, ...) \
\
synthesizeAssociation(frist_type, metamacro_at(0, __VA_ARGS__)) \

#define nn_associated_synthesize5(frist_type, ...) \
\
dynamic metamacro_at(2, __VA_ARGS__); \
nn_associated_getter(frist_type, metamacro_at(0, __VA_ARGS__), metamacro_at(1, __VA_ARGS__), metamacro_at(2, __VA_ARGS__)); \
nn_associated_setter(frist_type, metamacro_at(0, __VA_ARGS__), metamacro_at(1, __VA_ARGS__), metamacro_at(3, __VA_ARGS__)); \

#ifndef nn_synthesize

#define nn_synthesize   nn_associated_synthesize

#endif /* nn_synthesize */

#endif /* nn_associated_synthesize */

#endif /* NNMacrosAssociatedSynthesize_h */
