//
//  HJM_NSLog.h
//  HJMacros
//
//  Created by 顾海军 on 2017/1/6.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef HJM_NSLog_h
#define HJM_NSLog_h

#include <stdio.h>
#include <UIKit/UIKit.h>


void __HJM_NSLog (NSString* format, ...);

#define HJM_NSLog(format, ...)      {__HJM_NSLog((@"[%s] %s [Line %d] " format), __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);}

typedef struct HJM_NSLogFormate HJM_NSLogFormateDef;

struct HJM_NSLogFormate {
    BOOL hasDate;
    BOOL hasProcessName;
    BOOL hasThreadID;
    BOOL hasPID;
    BOOL hasPrettyFunction;
    BOOL hasFileName;
    BOOL hasLine;
    BOOL hasReturn;
};


extern HJM_NSLogFormateDef HJM_NSLogFormate;

#endif /* HJM_NSLog_h */
