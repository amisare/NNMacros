//
//  HJMacrosLazyGetter.h
//  HJMacros
//
//  Created by 顾海军 on 2016/12/28.
//  Copyright © 2016年 顾海军. All rights reserved.
//

#ifndef HJMacrosLazyGetter_h
#define HJMacrosLazyGetter_h

#if !__has_include(<metamacros.h>)
# include "metamacros.h"
#endif


/***************************************************
 懒加载
 ***************************************************/
/*
 type:      属性类型
 param0:    属性名
 param1:    插入的初始化代码，由于是if判断的一部分，所以代码必须为{}代码块
 param2:    非property属性，或getter和setter均需重写时，传入操作变量
            例如：变量var，则传入self->var

 case0:
 lazygetter(NSString, name)

 case1:
 lazygetter(NSString, name, {
    _name = @"name";
 })

 case2:
 lazygetter(NSString, name, {
    self->name = @"name";
 }, self->name)

 */

#ifndef lazygetter

#define lazygetter(type, ...)\
\
metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))(lazygetterparams2(type, __VA_ARGS__))\
(metamacro_if_eq(2, metamacro_argcount(__VA_ARGS__))(lazygetterparams3(type, __VA_ARGS__))\
(metamacro_if_eq(3, metamacro_argcount(__VA_ARGS__))(lazygetterparams4(type, __VA_ARGS__))\
(lazygetterparamsother(type, __VA_ARGS__))))\
\


#define lazygetterparamsother(type, __VA_ARGS__)

#define lazygetterparams2(type, ...)\
\
- (type *)metamacro_at(0, __VA_ARGS__)\
{\
    if (!metamacro_concat(_, metamacro_at(0, __VA_ARGS__))) {\
        metamacro_concat(_, metamacro_at(0, __VA_ARGS__)) = [type new];\
    }\
    return metamacro_concat(_, metamacro_at(0, __VA_ARGS__));\
}\

#define lazygetterparams3(type, ...)\
\
- (type *)metamacro_at(0, __VA_ARGS__)\
{\
    if (!metamacro_concat(_, metamacro_at(0, __VA_ARGS__)))\
        metamacro_at(1, __VA_ARGS__)\
    \
    return metamacro_concat(_, metamacro_at(0, __VA_ARGS__));\
}\

#define lazygetterparams4(type, ...)\
\
- (type *)metamacro_at(0, __VA_ARGS__)\
{\
    if (!metamacro_at(2, __VA_ARGS__)) \
        metamacro_at(1, __VA_ARGS__)\
    \
    return metamacro_at(2, __VA_ARGS__);\
}\

#endif /* lazygetter */

#endif /* HJMacrosLazyGetter_h */
