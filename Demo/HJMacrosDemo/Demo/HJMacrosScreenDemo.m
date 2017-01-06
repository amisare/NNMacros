//
//  HJMacrosScreenDemo.m
//  HJMacrosDemo
//
//  Created by 顾海军 on 2017/1/6.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#import "HJMacrosScreenDemo.h"

@implementation HJMacrosScreenDemo

- (void)macroTest
{
    DLog(@"%f", HJM_ScreenWidth);
    DLog(@"%f", HJM_ScreenHeight);
    DLog(@"%@", NSStringFromCGRect(HJM_ScreenBounds));
    DLog(@"%@", NSStringFromCGSize(HJM_ScreenSize));
    
    DLog(@"%@ = %@", HJM_Macro2String(HJM_ScreenIs3Dot5inch), HJM_ScreenIs3Dot5inch ? @"YES" : @"NO");
    DLog(@"%@ = %@", HJM_Macro2String(HJM_ScreenIs4inch),     HJM_ScreenIs4inch ? @"YES" : @"NO");
    DLog(@"%@ = %@", HJM_Macro2String(HJM_ScreenIs4Dot7inch), HJM_ScreenIs4Dot7inch ? @"YES" : @"NO");
    DLog(@"%@ = %@", HJM_Macro2String(HJM_ScreenIs5Dot5inch), HJM_ScreenIs5Dot5inch ? @"YES" : @"NO");
    
}




@end
