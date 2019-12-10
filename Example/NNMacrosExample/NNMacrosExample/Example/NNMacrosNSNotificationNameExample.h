//
//  NNMacrosNSNotificationNameExample.h
//  NNMacrosExample
//
//  Created by 顾海军 on 2019/12/9.
//  Copyright © 2019 顾海军. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NNMacrosExampleProtocol.h"
#import <NNMacros/NNMacros.h>

NN_NSNotificationName(Example, @"com.nn.macros", Name0, Name1);

NS_ASSUME_NONNULL_BEGIN

@interface NNMacrosNSNotificationNameExample : NSObject <NNMacrosExampleProtocol>

@end

NS_ASSUME_NONNULL_END
