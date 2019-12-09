//
//  NNMacrosScreenExample.m
//  NNMacrosExample
//
//  Created by 顾海军 on 2017/1/6.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#import "NNMacrosScreenExample.h"

@implementation NNMacrosScreenExample

- (void)macroTest {
    DLog(@"%f", NN_screenWidth);
    DLog(@"%f", NN_screenHeight);
    DLog(@"%@", NSStringFromCGRect(NN_screenBounds));
    DLog(@"%@", NSStringFromCGSize(NN_screenSize));
    
    DLog(@"%@ = %@", NN_arg2String(NN_screenIs3Dot5inch1x), NN_screenIs3Dot5inch1x ? @"YES" : @"NO");
    DLog(@"%@ = %@", NN_arg2String(NN_screenIs3Dot5inch), NN_screenIs3Dot5inch ? @"YES" : @"NO");
    DLog(@"%@ = %@", NN_arg2String(NN_screenIs4inch),     NN_screenIs4inch ? @"YES" : @"NO");
    DLog(@"%@ = %@", NN_arg2String(NN_screenIs4Dot7inch), NN_screenIs4Dot7inch ? @"YES" : @"NO");
    DLog(@"%@ = %@", NN_arg2String(NN_screenIs5Dot5inch), NN_screenIs5Dot5inch ? @"YES" : @"NO");
    DLog(@"%@ = %@", NN_arg2String(NN_screenIs5Dot8inch), NN_screenIs5Dot8inch ? @"YES" : @"NO");
    DLog(@"%@ = %@", NN_arg2String(NN_screenIs6Dot1inch), NN_screenIs6Dot1inch ? @"YES" : @"NO");
    DLog(@"%@ = %@", NN_arg2String(NN_screenIs6Dot5inch), NN_screenIs6Dot5inch ? @"YES" : @"NO");
}

@end
