//
//  NNMacrosVersion.h
//  NNMacros
//
//  Created by 顾海军 on 2017/1/5.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef NNMacrosVersion_h
#define NNMacrosVersion_h

#define NN_systemVersion                                    ([[UIDevice currentDevice] systemVersion])

#define NN_systemVersionIsEqualTo(vString)                  ([NN_systemVersion compare:vString options:NSNumericSearch] == NSOrderedSame)
#define NN_systemVersionIsGreaterThan(vString)              ([NN_systemVersion compare:vString options:NSNumericSearch] == NSOrderedDescending)
#define NN_systemVersionIsGreaterThanOrEqualTo(vString)     ([NN_systemVersion compare:vString options:NSNumericSearch] != NSOrderedAscending)
#define NN_systemVersionIsLessThan(vString)                 ([NN_systemVersion compare:vString options:NSNumericSearch] == NSOrderedAscending)
#define NN_systemVersionIsLessThanOrEqualTo(vString)        ([NN_systemVersion compare:vString options:NSNumericSearch] != NSOrderedDescending)

#endif /* NNMacrosVersion_h */
