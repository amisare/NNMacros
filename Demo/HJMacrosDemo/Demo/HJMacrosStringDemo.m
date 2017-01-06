//
//  HJMacrosStringDemo.m
//  HJMacrosDemo
//
//  Created by 顾海军 on 2017/1/6.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#import "HJMacrosStringDemo.h"

@implementation HJMacrosStringDemo

- (void)macroTest
{
    DLog(@"%@", HJM_StringConnect(@"_str0", @"_str1"));
    DLog(@"%@", HJM_StringConnect(@"_str0", @"_str1", @"_str2"));
    DLog(@"%@", HJM_StringConnect(@"_str0", @"_str1", @"_str2", @"_str3"));
    DLog(@"%@", HJM_StringConnect(@"_str0", @"_str1", @"_str2", @"_str3", @"_str4"));
    DLog(@"%@", HJM_StringConnect(@"_str0", @"_str1", @"_str2", @"_str3", @"_str4", @"_str5"));
    DLog(@"%@", HJM_StringConnect(@"_str0", @"_str1", @"_str2", @"_str3", @"_str4", @"_str5", @"_str6"));
    DLog(@"%@", HJM_StringConnect(@"_str0", @"_str1", @"_str2", @"_str3", @"_str4", @"_str5", @"_str6", @"_str7"));
    DLog(@"%@", HJM_StringConnect(@"_str0", @"_str1", @"_str2", @"_str3", @"_str4", @"_str5", @"_str6", @"_str7", @"_str8"));
    DLog(@"%@", HJM_StringConnect(@"_str0", @"_str1", @"_str2", @"_str3", @"_str4", @"_str5", @"_str6", @"_str7", @"_str8", @"_str9"));
}

@end
