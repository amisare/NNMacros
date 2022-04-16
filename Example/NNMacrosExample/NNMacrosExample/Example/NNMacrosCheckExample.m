//
//  NNMacrosCheckExample.m
//  NNMacrosExample
//
//  Created by GuHaiJun on 2022/4/16.
//  Copyright © 2022 顾海军. All rights reserved.
//

#import "NNMacrosCheckExample.h"

@implementation NNMacrosCheckExample

- (void)macroTest {
    DLog(@"%@", NN_safeType(NSString, [NSArray new]));
    DLog(@"%@", NN_safeType(NSString, [NSArray new], @"safe type"));
    DLog(@"%@", NN_safeType(NSString, @"", @"safe type"));
    DLog(@"%@", NN_safeType(NSString, @"字符串", @"safe type"));
    DLog(@"%@ is empty %d", [NSArray new], NN_isEmptyString([NSArray new]));
    DLog(@"%@ is empty %d", @"", NN_isEmptyString(@""));
    
}

@end
