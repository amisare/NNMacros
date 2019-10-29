//
//  NNMacrosLazyGetter.h
//  NNMacros
//
//  Created by 顾海军 on 2016/12/28.
//  Copyright © 2016年 顾海军. All rights reserved.
//

#ifndef NNMacrosLazyGetter_h
#define NNMacrosLazyGetter_h

#include "metamacros.h"

/***************************************************
 懒加载
 ***************************************************/

/**
 * 3 个参数:
 * type:        属性类型
 * param0:      属性名
 * param1:      插入的初始化代码，由于是if判断的一部分，所以代码必须为{}代码块
 *
 * 4 个参数:
 * type:        属性类型
 * param0:      属性名
 * param1:      非property属性，或getter和setter均需重写时，传入操作变量
 *              例如：变量var，则传入self->var
 * param2:      插入的初始化代码，由于是if判断的一部分，所以代码必须为{}代码块
 *
 * @code
     case0:
     nn_lazygetter(NSString, name)

     case1:
     nn_lazygetter(NSString, name, {
        _name = @"name";
     })

     case2:
     nn_lazygetter(NSString, name, _name, {
        _name = @"name";
     })
 * @endcode
 */
 

#ifndef nn_lazygetter

#define nn_lazygetter(type, ...)\
\
metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))(nn_lazygetterparams2(type, __VA_ARGS__))\
(metamacro_if_eq(2, metamacro_argcount(__VA_ARGS__))(nn_lazygetterparams3(type, __VA_ARGS__))\
(metamacro_if_eq(3, metamacro_argcount(__VA_ARGS__))(nn_lazygetterparams4(type, __VA_ARGS__))\
(nn_lazygetterparamsother(type, __VA_ARGS__))))\
\


#define nn_lazygetterparamsother(type, __VA_ARGS__)

#define nn_lazygetterparams2(type, ...)\
\
- (type *)metamacro_at(0, __VA_ARGS__)\
{\
    if (!metamacro_concat(_, metamacro_at(0, __VA_ARGS__))) {\
        (metamacro_concat(_, metamacro_at(0, __VA_ARGS__)) = [type new]);\
    }\
    return metamacro_concat(_, metamacro_at(0, __VA_ARGS__));\
}\

#define nn_lazygetterparams3(type, ...)\
\
- (type *)metamacro_at(0, __VA_ARGS__)\
{\
    if (!metamacro_concat(_, metamacro_at(0, __VA_ARGS__))) {\
        (metamacro_at(1, __VA_ARGS__));\
    }\
    return metamacro_concat(_, metamacro_at(0, __VA_ARGS__));\
}\

#define nn_lazygetterparams4(type, ...)\
\
- (type *)metamacro_at(0, __VA_ARGS__)\
{\
    if (!metamacro_at(1, __VA_ARGS__)) {\
        (metamacro_at(2, __VA_ARGS__));\
    }\
    return metamacro_at(1, __VA_ARGS__);\
}\

#endif /* nn_lazygetter */

#endif /* NNMacrosLazyGetter_h */
