//
//  NNMacrosVersion.h
//  NNMacros
//
//  Created by 顾海军 on 2017/1/5.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef NNMacrosVersion_h
#define NNMacrosVersion_h

#define NN_iOSVersion                                  ([[UIDevice currentDevice] systemVersion])

#define NN_iOSVersionEqualTo(vString)                  ([NN_iOSVersion compare:vString options:NSNumericSearch] == NSOrderedSame)
#define NN_iOSVersionGreaterThan(vString)              ([NN_iOSVersion compare:vString options:NSNumericSearch] == NSOrderedDescending)
#define NN_iOSVersionGreaterThanOrEqualTo(vString)     ([NN_iOSVersion compare:vString options:NSNumericSearch] != NSOrderedAscending)
#define NN_iOSVersionLessThan(vString)                 ([NN_iOSVersion compare:vString options:NSNumericSearch] == NSOrderedAscending)
#define NN_iOSVersionLessThanOrEqualTo(vString)        ([NN_iOSVersion compare:vString options:NSNumericSearch] != NSOrderedDescending)

#endif /* NNMacrosVersion_h */
