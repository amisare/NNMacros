//
//  HJMacrosScreen.h
//  HJMacros
//
//  Created by 顾海军 on 2017/1/4.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef HJMacrosScreen_h
#define HJMacrosScreen_h

#import <UIKit/UIKit.h>


#define HJM_KeyWindow                ([[[UIApplication sharedApplication] delegate] window])

#define HJM_ScreenWidth              ([UIScreen mainScreen].bounds.size.width)
#define HJM_ScreenHeight             ([UIScreen mainScreen].bounds.size.height)
#define HJM_ScreenSize               ([UIScreen mainScreen].bounds.size)
#define HJM_ScreenBounds             ([UIScreen mainScreen].bounds)

#define HJM_ScreenIsZoomed \
\
{\
    BOOL isZoomed = NO;\
    if (HJM_ScreenInchIs4Dot7inch && [UIScreen mainScreen].nativeScale > [UIScreen mainScreen].scale) {\
        isZoomed = YES;\
    }else if (HJM_ScreenInchIs5Dot5inch && [UIScreen mainScreen].nativeScale < [UIScreen mainScreen].scale){\
        isZoomed = YES;\
    }\
    isZoomed;\
}\

#define HJM_ScreenIs3Dot5inch   CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size)
#define HJM_ScreenIs4inch       CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size)
#define HJM_ScreenIs4Dot7inch   CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size)
#define HJM_ScreenIs5Dot5inch   CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size)
#define HJM_ScreenIs5Dot8inch   CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size)
#define HJM_ScreenIs6Dot1inch   CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size)
#define HJM_ScreenIs6Dot5inch   CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size)

#endif /* HJMacrosScreen_h */
