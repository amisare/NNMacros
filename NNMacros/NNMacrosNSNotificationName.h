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


#define NN_NSNotificationName(GROUP, DOMAIN, ...) \
		NN_NSNotificationName_Value(GROUP, DOMAIN, __VA_ARGS__) \
		NN_NSNotificationName_Object(GROUP, DOMAIN, __VA_ARGS__) \
		

#define NN_NSNotificationName_Object(GROUP, DOMAIN, ...) \
		__unused static const struct { \
			NN_NSNotificationName_Object_Var(__VA_ARGS__) \
		} GROUP = { \
			NN_NSNotificationName_Object_Value(GROUP, DOMAIN, __VA_ARGS__) \
		};

#define NN_NSNotificationName_Object_Var(...) \
		metamacro_foreach_cxt(NN_NSNotificationName_Object_Var_iter, , , __VA_ARGS__) \

#define NN_NSNotificationName_Object_Var_iter(INDEX, CONTEXT, VAR) \
		NSNotificationName VAR;

#define NN_NSNotificationName_Object_Value(GROUP, DOMAIN, ...) \
		metamacro_foreach_cxt(NN_NSNotificationName_Object_Value_iter, , GROUP, __VA_ARGS__) \
		
#define NN_NSNotificationName_Object_Value_iter(INDEX, CONTEXT, VAR) \
		.VAR = metamacro_concat(CONTEXT, VAR),


#define NN_NSNotificationName_Value(GROUP, DOMAIN, ...) \
		metamacro_foreach_cxt(NN_NSNotificationName_Value_iter, , DOMAIN, metamacro_tail(NN_NSNotificationName_Var(GROUP, __VA_ARGS__))) \

#define NN_NSNotificationName_Value_iter(INDEX, CONTEXT, VAR) \
		__unused static const NSNotificationName VAR = @"" CONTEXT "." metamacro_stringify(VAR) "";

#define NN_NSNotificationName_Var(CONTEXT, ...) \
        metamacro_foreach_cxt(NN_NSNotificationName_Var_iter, , CONTEXT, __VA_ARGS__) \

#define NN_NSNotificationName_Var_iter(INDEX, CONTEXT, VAR) \
        ,metamacro_concat(CONTEXT, VAR) \

#endif /* NNMacrosNSNotificationName_h */
