//
//  NNMacrosSandboxPath.h
//  NNMacros
//
//  Created by 顾海军 on 2017/1/4.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef NNMacrosSandboxPath_h
#define NNMacrosSandboxPath_h


#define NN_pathHome            (NSHomeDirectory())
#define NN_pathDocuments       ([NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject])
#define NN_pathLibrary         ([NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) firstObject])
#define NN_pathCaches          ([NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject])
#define NN_pathPreference      ([[NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) firstObject] stringByAppendingString:@"/Preferences"])
#define NN_pathTmp             (NSTemporaryDirectory())


#endif /* NNMacrosSandboxPath_h */
