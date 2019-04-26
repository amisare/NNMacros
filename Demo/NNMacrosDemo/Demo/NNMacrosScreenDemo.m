//
//  NNMacrosScreenDemo.m
//  NNMacrosDemo
//
//  Created by 顾海军 on 2017/1/6.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#import "NNMacrosScreenDemo.h"

@implementation NNMacrosScreenDemo

- (void)macroTest
{
    DLog(@"%f", NN_ScreenWidth);
    DLog(@"%f", NN_ScreenHeight);
    DLog(@"%@", NSStringFromCGRect(NN_ScreenBounds));
    DLog(@"%@", NSStringFromCGSize(NN_ScreenSize));
    
    DLog(@"%@ = %@", NN_Arg2String(NN_ScreenIs3Dot5inch), NN_ScreenIs3Dot5inch ? @"YES" : @"NO");
    DLog(@"%@ = %@", NN_Arg2String(NN_ScreenIs4inch),     NN_ScreenIs4inch ? @"YES" : @"NO");
    DLog(@"%@ = %@", NN_Arg2String(NN_ScreenIs4Dot7inch), NN_ScreenIs4Dot7inch ? @"YES" : @"NO");
    DLog(@"%@ = %@", NN_Arg2String(NN_ScreenIs5Dot5inch), NN_ScreenIs5Dot5inch ? @"YES" : @"NO");
}




@end
