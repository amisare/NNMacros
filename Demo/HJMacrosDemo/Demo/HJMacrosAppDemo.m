//
//  HJMacrosAppDemo.m
//  HJMacrosDemo
//
//  Created by 顾海军 on 2017/1/6.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#import "HJMacrosAppDemo.h"

@implementation HJMacrosAppDemo

- (void)macroTest
{
    DLog(@"%@", HJM_AppName);
    DLog(@"%@", HJM_AppVersion);
    DLog(@"%@", HJM_AppVersionBuild);
}

@end
