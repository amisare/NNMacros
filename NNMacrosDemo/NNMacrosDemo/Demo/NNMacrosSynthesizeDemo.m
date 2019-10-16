//
//  NNMacrosSynthesizeDemo.m
//  NNMacrosDemo
//
//  Created by 顾海军 on 2019/10/16.
//  Copyright © 2019 顾海军. All rights reserved.
//

#import "NNMacrosSynthesizeDemo.h"

@implementation NNMacrosSynthesizeDemo

- (void)macroTest {
    
    DLog(@"nn_associated_synthesize宏的使用");
    
    self.string = @"string";
    DLog(@"%@", self.string);
    self.weakId = self;
    DLog(@"%@", self.weakId);
    self.iValue = 1;
    DLog(@"%ld", self.iValue);
}

- (void)dealloc {
    DLog(@"%s", __func__);
}

@end

@implementation NNMacrosSynthesizeDemo (Synthesize)

//nn_associated_synthesize(nonatomic, strong, NSString *, string, setString)

nn_associated_getter(nonatomic, strong, NSString *, string)
nn_associated_setter(nonatomic, strong, NSString *, setString)
nn_associated_synthesize(nonatomic, weak, id, weakId, setWeakId)
nn_associated_synthesize(nonatomic, assign, NSInteger, iValue, setIValue);

@end
