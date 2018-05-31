//
//  HJMacrosCategorySynthesize.h
//  HJMacros
//
//  Created by GuHaijun on 2018/5/30.
//  Copyright © 2018年 顾海军. All rights reserved.
//

#ifndef HJMacrosCategorySynthesize_h
#define HJMacrosCategorySynthesize_h

#if !__has_include(<metamacros.h>)
# include "metamacros.h"
#endif

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "HJMacrosCategoryGetter.h"
#import "HJMacrosCategorySetter.h"

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

#define categorysynthesize(atomic_type, arc_type, type, getter, setter) \
        categorygetter(atomic_type, arc_type, type, getter); \
        categorysetter(atomic_type, arc_type, type, setter); \

#endif /* HJMacrosCategorySynthesize_h */