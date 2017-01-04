//
//  HJMacrosVersion.h
//  HJMacrosDemo
//
//  Created by 顾海军 on 2017/1/4.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef HJMacrosVersion_h
#define HJMacrosVersion_h

#import <UIKit/UIKit.h>

#define HJM_iOSVersion              [[UIDevice currentDevice] systemVersion]
#define HJM_iOSVersionCmp(vString)  [HJM_iOSVersion compare:vString options:NSNumericSearch]

#endif /* HJMacrosVersion_h */
