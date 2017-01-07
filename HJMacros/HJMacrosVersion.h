//
//  HJMacrosVersion.h
//  HJMacros
//
//  Created by 顾海军 on 2017/1/5.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef HJMacrosVersion_h
#define HJMacrosVersion_h

#define HJM_iOSVersion                                  ([[UIDevice currentDevice] systemVersion])

#define HJM_iOSVersionEqualTo(vString)                  ([HJM_iOSVersion compare:vString options:NSNumericSearch] == NSOrderedSame)
#define HJM_iOSVersionGreaterThan(vString)              ([HJM_iOSVersion compare:vString options:NSNumericSearch] == NSOrderedDescending)
#define HJM_iOSVersionGreaterThanOrEqualTo(vString)     ([HJM_iOSVersion compare:vString options:NSNumericSearch] != NSOrderedAscending)
#define HJM_iOSVersionLessThan(vString)                 ([HJM_iOSVersion compare:vString options:NSNumericSearch] == NSOrderedAscending)
#define HJM_iOSVersionLessThanOrEqualTo(vString)        ([HJM_iOSVersion compare:vString options:NSNumericSearch] != NSOrderedDescending)

#endif /* HJMacrosVersion_h */
