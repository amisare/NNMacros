//
//  NNMacrosString.h
//  NNMacros
//
//  Created by 顾海军 on 2017/1/4.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef NNMacrosString_h
#define NNMacrosString_h

#define NN_Arg2String(macro)             @(#macro)

#define NN_StringConst(name, value)        NSString *const name  = value;
#define NN_StringStatic(name, value)       static NSString *name = value;


#define NN_StringConnect(str, ...) \
metamacro_concat(NN_StringConnect, metamacro_argcount(__VA_ARGS__))(str, __VA_ARGS__)

//#define NN_StringConnect1(str0, str1)      (str0 str1)
#define NN_StringConnect1(str0, str1)      @""str0""str1""
#define NN_StringConnect2(str0, str1, str2)      @""str0""str1""str2""
#define NN_StringConnect3(str0, str1, str2, str3)      @""str0""str1""str2""str3""
#define NN_StringConnect4(str0, str1, str2, str3, str4)      @""str0""str1""str2""str3""str4""
#define NN_StringConnect5(str0, str1, str2, str3, str4, str5)      @""str0""str1""str2""str3""str4""str5""
#define NN_StringConnect6(str0, str1, str2, str3, str4, str5, str6)      @""str0""str1""str2""str3""str4""str5""str6""
#define NN_StringConnect7(str0, str1, str2, str3, str4, str5, str6, str7)      @""str0""str1""str2""str3""str4""str5""str6""str7""
#define NN_StringConnect8(str0, str1, str2, str3, str4, str5, str6, str7, str8)      @""str0""str1""str2""str3""str4""str5""str6""str7""str8""
#define NN_StringConnect9(str0, str1, str2, str3, str4, str5, str6, str7, str8, str9)      @""str0""str1""str2""str3""str4""str5""str6""str7""str8""str9""

#endif /* NNMacrosString_h */
