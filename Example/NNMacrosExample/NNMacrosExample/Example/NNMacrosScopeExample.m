//
//  NNMacrosScopeExample.m
//  NNMacrosExample
//
//  Created by 顾海军 on 2019/10/21.
//  Copyright © 2019 顾海军. All rights reserved.
//

#import "NNMacrosScopeExample.h"

@interface NNMacrosScopeExample ()

@property (nonatomic, strong) void(^scopeTest)(void);
@property (nonatomic, strong) NSString *name;

@end

@implementation NNMacrosScopeExample

- (void)macroTest {
    
    self.name = @"Alice";
    @weakify(self)
    self.scopeTest = ^{
        @strongify(self);
        DLog(@"%@", self.name);
        self.name = @"Bob";
        DLog(@"%@", self.name);
    };
}

- (void)dealloc {
    DLog(@"%s", __func__);
}

@end
