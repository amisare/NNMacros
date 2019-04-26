//
//  NNMacrosString.h
//  NNMacros
//
//  Created by 顾海军 on 2017/1/4.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef NNMacrosString_h
#define NNMacrosString_h

#define NN_arg2String(macro)             @(#macro)

#define NN_stringConst(name, value)        NSString *const name  = value;
#define NN_stringStatic(name, value)       static NSString *name = value;


#define NN_stringConnect(str, ...) \
metamacro_concat(NN_stringConnect, metamacro_argcount(__VA_ARGS__))(str, __VA_ARGS__)

//#define NN_stringConnect1(str0, str1)      (str0 str1)
#define NN_stringConnect1(str0, str1)      @"" str0 "" str1 ""
#define NN_stringConnect2(str0, str1, str2)      @"" str0 "" str1 "" str2 ""
#define NN_stringConnect3(str0, str1, str2, str3)      @"" str0 "" str1 "" str2 "" str3 ""
#define NN_stringConnect4(str0, str1, str2, str3, str4)      @"" str0 "" str1 "" str2 "" str3 "" str4 ""
#define NN_stringConnect5(str0, str1, str2, str3, str4, str5)      @"" str0 "" str1 "" str2 "" str3 "" str4 "" str5 ""
#define NN_stringConnect6(str0, str1, str2, str3, str4, str5, str6)      @"" str0 "" str1 "" str2 "" str3 "" str4 "" str5 "" str6 ""
#define NN_stringConnect7(str0, str1, str2, str3, str4, str5, str6, str7)      @"" str0 "" str1 "" str2 "" str3 "" str4 "" str5 "" str6 "" str7 ""
#define NN_stringConnect8(str0, str1, str2, str3, str4, str5, str6, str7, str8)      @"" str0 "" str1 "" str2 "" str3 "" str4 "" str5 "" str6 "" str7 "" str8 ""
#define NN_stringConnect9(str0, str1, str2, str3, str4, str5, str6, str7, str8, str9)      @"" str0 "" str1 "" str2 "" str3 "" str4 "" str5 "" str6 "" str7 "" str8 "" str9 ""

#endif /* NNMacrosString_h */
