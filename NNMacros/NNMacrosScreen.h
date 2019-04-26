//
//  NNMacrosScreen.h
//  NNMacros
//
//  Created by 顾海军 on 2017/1/4.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef NNMacrosScreen_h
#define NNMacrosScreen_h

#import <UIKit/UIKit.h>


#define NN_KeyWindow                ([[[UIApplication sharedApplication] delegate] window])

#define NN_ScreenWidth              ([UIScreen mainScreen].bounds.size.width)
#define NN_ScreenHeight             ([UIScreen mainScreen].bounds.size.height)
#define NN_ScreenSize               ([UIScreen mainScreen].bounds.size)
#define NN_ScreenBounds             ([UIScreen mainScreen].bounds)

#define NN_ScreenIsZoomed \
\
{\
    BOOL isZoomed = NO;\
    if (NN_ScreenInchIs4Dot7inch && [UIScreen mainScreen].nativeScale > [UIScreen mainScreen].scale) {\
        isZoomed = YES;\
    }else if (NN_ScreenInchIs5Dot5inch && [UIScreen mainScreen].nativeScale < [UIScreen mainScreen].scale){\
        isZoomed = YES;\
    }\
    isZoomed;\
}\

#define NN_ScreenIs3Dot5inch   CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size)
#define NN_ScreenIs4inch       CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size)
#define NN_ScreenIs4Dot7inch   CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size)
#define NN_ScreenIs5Dot5inch   CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size)
#define NN_ScreenIs5Dot8inch   CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size)
#define NN_ScreenIs6Dot1inch   CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size)
#define NN_ScreenIs6Dot5inch   CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size)

#endif /* NNMacrosScreen_h */
