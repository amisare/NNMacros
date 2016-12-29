//
//  HAMLogOutputWindow+Category.h
//  HJMacrosDemo
//
//  Created by 顾海军 on 2016/12/29.
//  Copyright © 2016年 HaijunGu. All rights reserved.
//

#import "HAMLogOutputWindow.h"

@interface HAMLogOutputWindow (Category)

+ (void)printLogWithFormat:(NSString *)format, ...;

@end
