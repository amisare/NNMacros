//
//  HJMacrosApp.h
//  HJMacrosDemo
//
//  Created by 顾海军 on 2017/1/6.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef HJMacrosApp_h
#define HJMacrosApp_h

#define HJM_AppName             ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"])
#define HJM_AppVersion          ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"])
#define HJM_AppVersionBuild     ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"])

#endif /* HJMacrosApp_h */
