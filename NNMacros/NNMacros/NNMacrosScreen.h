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

// iPhone
// iPhone 2G
// iPhone 3
// iPhone 3GS
#define NN_screenSize3Dot5inch1x    CGSizeMake(320, 480)
// iPhone 4
// iPhone 4s
#define NN_screenSize3Dot5inch      CGSizeMake(640, 960)
// iPhone 5
// iPhone 5s
// iPhone 5c
// iPhone SE
#define NN_screenSize4inch          CGSizeMake(640, 1136)
// iPhone 6
// iPhone 6s
// iPhone 7
// iPhone 8
#define NN_screenSize4Dot7inch      CGSizeMake(750, 1334)
// iPhone 6
// iPhone 6s
// iPhone 7
// iPhone 8
#define NN_screenSize5Dot5inch      CGSizeMake(1242, 2208)
// iPhone X
// iPhone XS
// iPhone 11 Pro
#define NN_screenSize5Dot8inch      CGSizeMake(1125, 2436)
// iPhone XR
// iPhone 11
#define NN_screenSize6Dot1inch      CGSizeMake(828, 1792)
// iPhone XR
// iPhone 11
#define NN_screenSize6Dot5inch      CGSizeMake(1242, 2688)

#define NN_screenIs3Dot5inch1x      CGSizeEqualToSize(NN_screenSize3Dot5inch1x, [[UIScreen mainScreen] currentMode].size)
#define NN_screenIs3Dot5inch        CGSizeEqualToSize(NN_screenSize3Dot5inch, [[UIScreen mainScreen] currentMode].size)
#define NN_screenIs4inch            CGSizeEqualToSize(NN_screenSize4inch, [[UIScreen mainScreen] currentMode].size)
#define NN_screenIs4Dot7inch        CGSizeEqualToSize(NN_screenSize4Dot7inch, [[UIScreen mainScreen] currentMode].size)
#define NN_screenIs5Dot5inch        CGSizeEqualToSize(NN_screenSize5Dot5inch, [[UIScreen mainScreen] currentMode].size)
#define NN_screenIs5Dot8inch        CGSizeEqualToSize(NN_screenSize5Dot8inch, [[UIScreen mainScreen] currentMode].size)
#define NN_screenIs6Dot1inch        CGSizeEqualToSize(NN_screenSize6Dot1inch, [[UIScreen mainScreen] currentMode].size)
#define NN_screenIs6Dot5inch        CGSizeEqualToSize(NN_screenSize6Dot5inch, [[UIScreen mainScreen] currentMode].size)

#endif /* NNMacrosScreen_h */
