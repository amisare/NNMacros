//
//  NNMacrosColor.h
//  NNMacros
//
//  Created by 顾海军 on 2017/1/4.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef NNMacrosColor_h
#define NNMacrosColor_h

#define NN_colorWithRGBAlpha(r, g, b, a)       [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a/1.0]
#define NN_colorWithRGB(r, g, b)               NN_colorWithRGBAlpha(r, g, b, 1.0)
#define NN_colorWithHexAlpha(h, a)             [UIColor colorWithRed:((h>>16)&0xff)/255.0 green:((h>>8)&0xff)/255.0 blue:(h&0xff)/255.0 alpha:a/1.0]
#define NN_colorWithHex(h)                     NN_colorWithHexAlpha(h, 1.0)
// Rand Color
#define NN_colorRand                           [UIColor colorWithRed:arc4random_uniform(256) / 255.0 green:arc4random_uniform(256) / 255.0 blue:arc4random_uniform(256) / 255.0 alpha:1.0]

#endif /* NNMacrosColor_h */
