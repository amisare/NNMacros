//
//  NNMacrosAppExample.m
//  NNMacrosExample
//
//  Created by 顾海军 on 2017/1/6.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#import "NNMacrosAppExample.h"

@implementation NNMacrosAppExample

- (void)macroTest {
    DLog(@"%@", NN_appName);
    DLog(@"%@", NN_appShortVersion);
    DLog(@"%@", NN_appBuildVersion);
}

@end
