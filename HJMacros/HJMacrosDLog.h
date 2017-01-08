//
//  HJMacrosDLog.h
//  HJMacros
//
//  Created by 顾海军 on 2017/1/4.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef HJMacrosDLog_h
#define HJMacrosDLog_h

#import "HJM_NSLog.h"

#ifdef DEBUG

#ifdef HJM_USE_HJM_NSLOG
#   define HJM_DLog(format, ...)   {HJM_NSLog(format, ##__VA_ARGS__);}
#   define HJM_ELog(err)           {if(err) HJM_DLog(@"%@", err)}
#else
#   define HJM_DLog(format, ...)   {NSLog((@"%s [Line %d] " format), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);}
#   define HJM_ELog(err)           {if(err) HJM_DLog(@"%@", err)}
#endif

#else
#   define HJM_DLog(...)
#   define HJM_ELog(err)
#endif



#endif /* HJMacrosDLog_h */
