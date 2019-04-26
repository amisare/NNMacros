//
//  NNMacrosSandboxPath.h
//  NNMacros
//
//  Created by 顾海军 on 2017/1/4.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef NNMacrosSandboxPath_h
#define NNMacrosSandboxPath_h


#define NN_PathHome            (NSHomeDirectory())
#define NN_PathDocuments       ([NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject])
#define NN_PathLibrary         ([NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) firstObject])
#define NN_PathCaches          ([NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject])
#define NN_PathPreference      ([[NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) firstObject] stringByAppendingString:@"/Preferences"])
#define NN_PathTmp             (NSTemporaryDirectory())


#endif /* NNMacrosSandboxPath_h */
