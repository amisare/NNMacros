//
//  NNMacrosNSNotificationNameExample.m
//  NNMacrosExample
//
//  Created by 顾海军 on 2019/12/9.
//  Copyright © 2019 顾海军. All rights reserved.
//

#import "NNMacrosNSNotificationNameExample.h"

NN_NSNotificationName(Example, @"com.nn.macros", name0, name1);

@implementation NNMacrosNSNotificationNameExample {
	id _observer;
}

- (instancetype)init {
	self = [super init];
	_observer =
	[[NSNotificationCenter defaultCenter] addObserverForName:NN_NSNotificationName(Example).name0
													  object:nil
													   queue:[NSOperationQueue mainQueue]
												  usingBlock:^(NSNotification * _Nonnull note) {
		DLog(@"%@", note.object);
	}];
	[[NSNotificationCenter defaultCenter] addObserver:self
											 selector:@selector(observerHandler:)
												 name:NN_NSNotificationName(Example).name1
											   object:nil];
	return self;
}

- (void)macroTest {
	[[NSNotificationCenter defaultCenter] postNotificationName:NN_NSNotificationName(Example).name0 object:@"post_name0"];
	[[NSNotificationCenter defaultCenter] postNotificationName:NN_NSNotificationName(Example).name1 object:@"post_name1"];
}

- (void)observerHandler:(NSNotification *)note {
	DLog(@"%@", note.object);
}

- (void)dealloc {
	[[NSNotificationCenter defaultCenter] removeObserver:_observer];
    DLog(@"%s", __func__);
}

@end
