//
//  NNMacrosApp.h
//  NNMacros
//
//  Created by 顾海军 on 2017/1/6.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef NNMacrosApp_h
#define NNMacrosApp_h

#define NN_appName             ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"])
#define NN_appVersion          ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"])
#define NN_appVersionBuild     ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"])

#endif /* NNMacrosApp_h */
