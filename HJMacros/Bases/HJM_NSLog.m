//
//  HJM_NSLog.m
//  HJMacros
//
//  Created by 顾海军 on 2017/1/6.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#include "HJM_NSLog.h"

HJM_NSLogFormateDef HJM_NSLogFormate = {
    .hasDate = YES,
    .hasProcessName = YES,
    .hasPID = YES,
    .hasThreadID = NO,
    .hasFileName = NO,
    .hasPrettyFunction = YES,
    .hasLine = YES,
    .hasReturn = YES,
};


void HJM_NSLogv (NSString* format, va_list args)
{
    NSMutableString     *prefix = [NSMutableString string];
    NSString            *message;
    
    if (HJM_NSLogFormate.hasDate) {
        NSDateFormatter* formatter = [[NSDateFormatter alloc] init];
        formatter.locale = [NSLocale localeWithLocaleIdentifier:@"en"];
        formatter.dateFormat = @"Y-MM-dd HH:mm:ss.SSS";
        [prefix appendString:[formatter stringFromDate:[NSDate date]]];
        [prefix appendString:@" "];
    }
    
    if (HJM_NSLogFormate.hasProcessName) {
        [prefix appendString:[[NSProcessInfo processInfo] processName]];
    }
    
    if (HJM_NSLogFormate.hasPID || HJM_NSLogFormate.hasThreadID) {
        
        [prefix appendString:@"["];
            
        if (HJM_NSLogFormate.hasPID) {
            [prefix appendFormat:@"%d", (int)getpid()];
        }
    
        if (HJM_NSLogFormate.hasPID && HJM_NSLogFormate.hasThreadID) {
            [prefix appendString:@":"];
        }
        
        if (HJM_NSLogFormate.hasThreadID) {
            [prefix appendString:@"NO_THREAD_ID"];
        }
        
        [prefix appendString:@"]"];
        [prefix appendString:@" "];
    }
    
    
    if ([format hasPrefix:@"[%s] %s [Line %d] "]) {
        format = [format substringFromIndex:@"[%s] %s [Line %d] ".length];
        
        
        char *fileName = va_arg(args, char *);
        char *prettyFunction = va_arg(args, char *);
        
        //sizeof(__LINE__) == 4; 为int类型
        int line = va_arg(args, int);
        
        
        if (HJM_NSLogFormate.hasFileName) {
            [prefix appendFormat:@"[%s]", fileName];
            [prefix appendString:@" "];
        }
        
        if (HJM_NSLogFormate.hasPrettyFunction) {
            [prefix appendFormat:@"%s", prettyFunction];
            [prefix appendString:@" "];
        }
        
        if (HJM_NSLogFormate.hasLine) {
            [prefix appendFormat:@"[Line %d]", line];
            [prefix appendString:@" "];
        }
    }
    
    
    /* Check if there is already a newline at the end of the format */
    if ([format hasSuffix: @"\n"] == NO)
    {
        if (HJM_NSLogFormate.hasReturn) {
            format = [format stringByAppendingString: @"\n"];
        }
    }
    
    message = [[NSString alloc] initWithFormat:format arguments:args];
    
    [prefix appendString: message];
    
    printf("%s", [prefix UTF8String]);
}

void __HJM_NSLog (NSString* format, ...)
{
    va_list ap;
    
    va_start (ap, format);
    HJM_NSLogv (format, ap);
    va_end (ap);
}
