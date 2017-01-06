//
//  HJMacrosSandboxPath.h
//  HJMacrosDemo
//
//  Created by 顾海军 on 2017/1/4.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef HJMacrosSandboxPath_h
#define HJMacrosSandboxPath_h


#define HJM_PathHome            (NSHomeDirectory())
#define HJM_PathDocuments       ([NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject])
#define HJM_PathLibrary         ([NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) firstObject])
#define HJM_PathCaches          ([NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject])
#define HJM_PathPreference      ([[NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) firstObject] stringByAppendingString:@"/Preferences"])
#define HJM_PathTmp             (NSTemporaryDirectory())


#endif /* HJMacrosSandboxPath_h */
