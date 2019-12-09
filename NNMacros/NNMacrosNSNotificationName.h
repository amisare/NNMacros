//
//  NNMacrosNSNotificationName.h
//  NNMacros
//
//  Created by 顾海军 on 2019/12/9.
//  Copyright © 2019 GuHaijun. All rights reserved.
//

#ifndef NNMacrosNSNotificationName_h
#define NNMacrosNSNotificationName_h

#import "metamacros.h"

#define NN_NSNotificationName(...) \
		metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__)) \
		(NN_NSNotificationName_Find(__VA_ARGS__))\
		(NN_NSNotificationName_Define(__VA_ARGS__))

#define NN_NSNotificationName_Define(GROUP, DOMAIN, ...) \
		typedef struct { \
			metamacro_foreach_cxt(NN_NSNotificationName_Define_Type, , , __VA_ARGS__) \
		} NN_NSNotificationName_Define_Group(GROUP); \
		\
		NS_INLINE __unused NN_NSNotificationName_Define_Group(GROUP) NN_NSNotificationName_Define_Function(GROUP)() {\
			NN_NSNotificationName_Define_Group(GROUP) group = { \
				metamacro_foreach_cxt(NN_NSNotificationName_Define_Value, , DOMAIN, __VA_ARGS__) \
			}; \
			return group; \
		};

#define NN_NSNotificationName_Find(GROUP) \
		NN_NSNotificationName_Define_Function(GROUP)()

#define NN_NSNotificationName_Define_Function(GROUP) \
		metamacro_concat(Find, \
		metamacro_concat(_, NN_NSNotificationName_Define_Group(GROUP)))

#define NN_NSNotificationName_Define_Group(GROUP) \
		metamacro_concat(NN_NSNotificationName, \
		metamacro_concat(_, GROUP))

#define NN_NSNotificationName_Define_Type(INDEX, CONTEXT, VAR) \
		NSNotificationName VAR;

#define NN_NSNotificationName_Define_Value(INDEX, CONTEXT, VAR) \
		.VAR = @"" CONTEXT "." metamacro_stringify(VAR) "",

#endif /* NNMacrosNSNotificationName_h */
