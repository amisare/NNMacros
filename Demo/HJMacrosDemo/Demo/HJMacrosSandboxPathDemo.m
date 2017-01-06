//
//  HJMacrosSandboxPathDemo.m
//  HJMacrosDemo
//
//  Created by 顾海军 on 2017/1/6.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#import "HJMacrosSandboxPathDemo.h"

@implementation HJMacrosSandboxPathDemo

- (void)macroTest
{
    DLog(@"%@", HJM_PathHome);
    DLog(@"%@", HJM_PathTmp);
    DLog(@"%@", HJM_PathCaches);
    DLog(@"%@", HJM_PathLibrary);
    DLog(@"%@", HJM_PathDocuments);
    DLog(@"%@", HJM_PathPreference);
}

@end
