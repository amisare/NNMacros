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
#import "HJMacrosString.h"

#ifdef DEBUG

#define HJM_DLOG_USE_HJM_NSLOG \
{\
    setenv("HaiJunGu_HJMacros_EVN_HJM_NSLOG_ON", "HaiJunGu_HJMacros_EVN_HJM_NSLOG_ON", 1);\
    char *evn = getenv("HaiJunGu_HJMacros_EVN_HJM_NSLOG_ON");\
    printf("evn = %s\n", evn);\
}\

#define HJM_DLOG_USE_NSLOG \
{\
    setenv("HaiJunGu_HJMacros_EVN_HJM_NSLOG_ON", "HaiJunGu_HJMacros_EVN_HJM_NSLOG_OFF", 1);\
    char *evn = getenv("HaiJunGu_HJMacros_EVN_HJM_NSLOG_ON");\
    printf("evn = %s\n", evn);\
}\

#define HJM_DLog(format, ...) \
{\
    char *evn = getenv("HaiJunGu_HJMacros_EVN_HJM_NSLOG_ON");\
    if (evn != NULL && (0 == strcmp(evn, "HaiJunGu_HJMacros_EVN_HJM_NSLOG_ON"))) {\
        HJM_NSLog(format, ##__VA_ARGS__);\
    }\
    else {\
        NSLog((@"%s [Line %d] " format), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);\
    }\
}\

#define HJM_ELog(err)           {if(err) HJM_DLog(@"%@", err)}


#else
#   define HJM_DLog(...)
#   define HJM_ELog(err)
#endif


#endif /* HJMacrosDLog_h */
