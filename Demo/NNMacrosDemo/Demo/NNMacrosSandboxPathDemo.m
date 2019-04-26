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
    DLog(@"%@:%@", NN_arg2String(NN_pathHome), NN_pathHome);
    DLog(@"%@:%@", NN_arg2String(NN_pathHome), NN_pathTmp);
    DLog(@"%@:%@", NN_arg2String(NN_pathHome), NN_pathCaches);
    DLog(@"%@:%@", NN_arg2String(NN_pathHome), NN_pathLibrary);
    DLog(@"%@:%@", NN_arg2String(NN_pathHome), NN_pathDocuments);
    DLog(@"%@:%@", NN_arg2String(NN_pathHome), NN_pathPreference);
}

@end
