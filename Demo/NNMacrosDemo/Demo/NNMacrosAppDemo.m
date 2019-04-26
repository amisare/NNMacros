//
//  NNMacrosAppDemo.m
//  NNMacrosDemo
//
//  Created by 顾海军 on 2017/1/6.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#import "NNMacrosAppDemo.h"

@implementation NNMacrosAppDemo

- (void)macroTest
{
    DLog(@"%@", NN_appName);
    DLog(@"%@", NN_appVersion);
    DLog(@"%@", NN_appVersionBuild);
}

@end
