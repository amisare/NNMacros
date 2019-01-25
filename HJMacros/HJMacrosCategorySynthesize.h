//
//  HJMacrosCategorySynthesize.h
//  HJMacros
//
//  Created by GuHaijun on 2018/5/30.
//  Copyright © 2018年 顾海军. All rights reserved.
//

#ifndef HJMacrosCategorySynthesize_h
#define HJMacrosCategorySynthesize_h

#import "HJMacrosCategoryGetter.h"
#import "HJMacrosCategorySetter.h"
#include "metamacros.h"

/***************************************************
 category synthesize
 ***************************************************/
/*
 atomic_type:   atomic, nonatomic
 arc_type:      assign, strong, copy
 data_type:     属性类型
 getter:        getter方法名
 setter:        setter方法名
 */

#ifndef categorysynthesize

#define categorysynthesize(atomic_type, arc_type, data_type, getter, setter) \
        categorygetter(atomic_type, arc_type, data_type, getter); \
        categorysetter(atomic_type, arc_type, data_type, setter); \

#endif /* categorysynthesize */

#endif /* HJMacrosCategorySynthesize_h */
