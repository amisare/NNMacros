//
//  HJMacrosDLog.h
//  HJMacrosDemo
//
//  Created by 顾海军 on 2017/1/4.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef HJMacrosDLog_h
#define HJMacrosDLog_h

#import <CoreGraphics/CoreGraphics.h>

#ifdef DEBUG
#   define HJM_DLog(fmt, ...)   {NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);}
#   define HJM_ELog(err)        {if(err) DLog(@"%@", err)}
#else
#   define HJM_DLog(...)
#   define HJM_ELog(err)
#endif

#define HJM_DlogCG(CG) \
\
({\
    if(sizeof(CG) == sizeof(CGSize)) {\
    NSLog(@"\n{x = %f y = %f}", ((CGSize *)(&CG))->width, ((CGSize *)(&CG))->height);\
    }\
    else if (sizeof(CG) == sizeof(CGRect)) {\
        NSLog(@"\n{x = %f y = %f\n w = %f h = %f}", ((CGRect *)(&CG))->origin.x, ((CGRect *)(&CG))->origin.x, ((CGRect *)(&CG))->size.width, ((CGRect *)(&CG))->size.height);\
    }\
})

#endif /* HJMacrosDLog_h */
