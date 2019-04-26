//
//  NNMacrosSandboxPathDemo.m
//  NNMacrosDemo
//
//  Created by 顾海军 on 2017/1/6.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#import "NNMacrosSandboxPathDemo.h"

@implementation NNMacrosSandboxPathDemo

- (void)macroTest
{
    DLog(@"%@:%@", NN_Arg2String(NN_PathHome), NN_PathHome);
    DLog(@"%@:%@", NN_Arg2String(NN_PathHome), NN_PathTmp);
    DLog(@"%@:%@", NN_Arg2String(NN_PathHome), NN_PathCaches);
    DLog(@"%@:%@", NN_Arg2String(NN_PathHome), NN_PathLibrary);
    DLog(@"%@:%@", NN_Arg2String(NN_PathHome), NN_PathDocuments);
    DLog(@"%@:%@", NN_Arg2String(NN_PathHome), NN_PathPreference);
}

@end
