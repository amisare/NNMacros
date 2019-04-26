//
//  NNMacrosRGBColor.h
//  NNMacros
//
//  Created by 顾海军 on 2017/1/4.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef NNMacrosRGBColor_h
#define NNMacrosRGBColor_h

#define NN_RGBColor(r, g, b)               [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0]
#define NN_RGBColorAlpha(r, g, b, a)       [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a/1.0]
#define NN_RGBColorHex(c)                  [UIColor colorWithRed:((c>>16)&0xff)/255.0 green:((c>>8)&0xff)/255.0 blue:(c&0xff)/255.0 alpha:1.0]
// rand color
#define NN_randColor                       [UIColor colorWithRed:arc4random_uniform(256) / 255.0 green:arc4random_uniform(256) / 255.0 blue:arc4random_uniform(256) / 255.0 alpha:1]

#endif /* NNMacrosRGBColor_h */
