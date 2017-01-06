//
//  HJMacrosString.h
//  HJMacros
//
//  Created by 顾海军 on 2017/1/4.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef HJMacrosString_h
#define HJMacrosString_h

#define HJM_Macro2String(macro)             @(#macro)

#define HJM_StringConst(name, value)        NSString *const name  = value;
#define HJM_StringStatic(name, value)       static NSString *name = value;


#define HJM_StringConnect(str, ...) \
metamacro_concat(HJM_StringConnect, metamacro_argcount(__VA_ARGS__))(str, __VA_ARGS__)

//#define HJM_StringConnect1(str0, str1)      @""str0""str1""
#define HJM_StringConnect1(str0, str1)      (str0 str1)
#define HJM_StringConnect2(str0, str1, str2)      @""str0""str1""str2""
#define HJM_StringConnect3(str0, str1, str2, str3)      @""str0""str1""str2""str3""
#define HJM_StringConnect4(str0, str1, str2, str3, str4)      @""str0""str1""str2""str3""str4""
#define HJM_StringConnect5(str0, str1, str2, str3, str4, str5)      @""str0""str1""str2""str3""str4""str5""
#define HJM_StringConnect6(str0, str1, str2, str3, str4, str5, str6)      @""str0""str1""str2""str3""str4""str5""str6""
#define HJM_StringConnect7(str0, str1, str2, str3, str4, str5, str6, str7)      @""str0""str1""str2""str3""str4""str5""str6""str7""
#define HJM_StringConnect8(str0, str1, str2, str3, str4, str5, str6, str7, str8)      @""str0""str1""str2""str3""str4""str5""str6""str7""str8""
#define HJM_StringConnect9(str0, str1, str2, str3, str4, str5, str6, str7, str8, str9)      @""str0""str1""str2""str3""str4""str5""str6""str7""str8""str9""

#endif /* HJMacrosString_h */
