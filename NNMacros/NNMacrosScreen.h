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


#define NN_keyWindow                ([[[UIApplication sharedApplication] delegate] window])

#define NN_screenWidth              ([UIScreen mainScreen].bounds.size.width)
#define NN_screenHeight             ([UIScreen mainScreen].bounds.size.height)
#define NN_screenSize               ([UIScreen mainScreen].bounds.size)
#define NN_screenBounds             ([UIScreen mainScreen].bounds)

#define NN_screenIsZoomed \
\
{\
    BOOL isZoomed = NO;\
    if (NN_screenInchIs4Dot7inch && [UIScreen mainScreen].nativeScale > [UIScreen mainScreen].scale) {\
        isZoomed = YES;\
    }else if (NN_screenInchIs5Dot5inch && [UIScreen mainScreen].nativeScale < [UIScreen mainScreen].scale){\
        isZoomed = YES;\
    }\
    isZoomed;\
}\

#define NN_screenIs3Dot5inch   CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size)
#define NN_screenIs4inch       CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size)
#define NN_screenIs4Dot7inch   CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size)
#define NN_screenIs5Dot5inch   CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size)
#define NN_screenIs5Dot8inch   CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size)
#define NN_screenIs6Dot1inch   CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size)
#define NN_screenIs6Dot5inch   CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size)

#endif /* NNMacrosScreen_h */
