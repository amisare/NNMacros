//
//  NNMacrosCheck.h
//  NNMacros
//
//  Created by GuHaiJun on 2022/4/16.
//  Copyright © 2022 GuHaijun. All rights reserved.
//

#ifndef NNMacrosCheck_h
#define NNMacrosCheck_h

#define NN_safeType(type, ...) \
metamacro_concat(NN_safeType, metamacro_argcount(__VA_ARGS__))(type, __VA_ARGS__)

#define NN_safeType1(type, obj)                NN_safeType2(type, obj, nil)
#define NN_safeType2(type, obj, default)       ([obj isKindOfClass:[type class]] ? (type *)obj : default)

#define NN_isEmptyString(string) ([NN_safeType(NSString, string) length] == 0)


#endif /* NNMacrosCheck_h */
