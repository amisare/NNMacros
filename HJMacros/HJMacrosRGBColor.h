//
//  HJMacrosRGBColor.h
//  HJMacros
//
//  Created by 顾海军 on 2017/1/4.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef HJMacrosRGBColor_h
#define HJMacrosRGBColor_h

#define HJM_RGBColor(r,g,b)                 [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0]
#define HJM_RGBColorAlpha(r,g,b,a)          [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a/1.0]
#define HJM_RGBColorHex(c)                  [UIColor colorWithRed:((c>>16)&0xff)/255.0 green:((c>>8)&0xff)/255.0 blue:(c&0xff)/255.0 alpha:1.0]
// rand color
#define HJM_RandColor                       [UIColor colorWithRed:arc4random_uniform(256) / 255.0 green:arc4random_uniform(256) / 255.0 blue:arc4random_uniform(256) / 255.0 alpha:1]

#endif /* HJMacrosRGBColor_h */
