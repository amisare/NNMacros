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
#include "metamacros.h"

/***************************************************
 associated synthesize
 ***************************************************/
/*
 atomic_type:   atomic, nonatomic
 arc_type:      assign, strong, copy
 data_type:     属性类型
 getter:        getter方法名
 */

#ifndef nn_associated_synthesize

#define nn_associated_synthesize(atomic_type, arc_type, data_type, property_name) \
        nn_associated_getter(atomic_type, arc_type, data_type, property_name); \
        nn_associated_setter(atomic_type, arc_type, data_type, property_name); \

#endif /* nn_associated_synthesize */

#endif /* NNMacrosAssociatedSynthesize_h */
