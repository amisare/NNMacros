//
//  NNMacrosStringDemo.m
//  NNMacrosDemo
//
//  Created by 顾海军 on 2017/1/6.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#import "NNMacrosStringDemo.h"

@implementation NNMacrosStringDemo

- (void)macroTest
{
    DLog(@"%@", NN_StringConnect(@"_str0", @"_str1"));
    DLog(@"%@", NN_StringConnect(@"_str0", @"_str1", @"_str2"));
    DLog(@"%@", NN_StringConnect(@"_str0", @"_str1", @"_str2", @"_str3"));
    DLog(@"%@", NN_StringConnect(@"_str0", @"_str1", @"_str2", @"_str3", @"_str4"));
    DLog(@"%@", NN_StringConnect(@"_str0", @"_str1", @"_str2", @"_str3", @"_str4", @"_str5"));
    DLog(@"%@", NN_StringConnect(@"_str0", @"_str1", @"_str2", @"_str3", @"_str4", @"_str5", @"_str6"));
    DLog(@"%@", NN_StringConnect(@"_str0", @"_str1", @"_str2", @"_str3", @"_str4", @"_str5", @"_str6", @"_str7"));
    DLog(@"%@", NN_StringConnect(@"_str0", @"_str1", @"_str2", @"_str3", @"_str4", @"_str5", @"_str6", @"_str7", @"_str8"));
    DLog(@"%@", NN_StringConnect(@"_str0", @"_str1", @"_str2", @"_str3", @"_str4", @"_str5", @"_str6", @"_str7", @"_str8", @"_str9"));
}

@end
