//
//  HJMacrosVersionDemo.m
//  HJMacrosDemo
//
//  Created by 顾海军 on 2017/1/4.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#import "HJMacrosVersionDemo.h"
#import "HJMacros.h"

@implementation HJMacrosVersionDemo

- (void)macroTest
{
    HJM_DLog(@"%@", HJM_iOSVersion);
    
    HJM_DLog(@"%zd", HJM_iOSVersionCmp(@"9.1"));
    HJM_DLog(@"%zd", HJM_iOSVersionCmp(@"10.1"));
    HJM_DLog(@"%zd", HJM_iOSVersionCmp(@"10.2"));
    
}


@end
