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

#define HJM_StringConnect(str1, str2)       @""str1""str2""
#define HJM_StringConst(name, value)        NSString *const name  = value;
#define HJM_StringStatic(name, value)       static NSString *name = value;

#endif /* HJMacrosString_h */
