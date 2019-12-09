//
//  NNMacrosShortHead.h
//  NNMacrosExample
//
//  Created by 顾海军 on 2017/1/6.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef NNMacrosShortHead_h
#define NNMacrosShortHead_h

#define DLog(format, ...) printf("%s\n", [[NSString stringWithFormat:format, ##__VA_ARGS__] UTF8String]);

#endif /* NNMacrosShortHead_h */
