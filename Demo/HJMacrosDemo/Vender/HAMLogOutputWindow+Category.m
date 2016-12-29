//
//  HAMLogOutputWindow+Category.m
//  HJMacrosDemo
//
//  Created by 顾海军 on 2016/12/29.
//  Copyright © 2016年 HaijunGu. All rights reserved.
//

#import "HAMLogOutputWindow+Category.h"

@implementation HAMLogOutputWindow (Category)


+ (void)printLogWithFormat:(NSString *)format, ...
{
    va_list args;
    va_start(args, format);
    [self printLog:[[NSString alloc] initWithFormat:format arguments:args]];
    va_end(args);
}

@end
