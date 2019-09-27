//
//  NNMacrosSandbox.h
//  NNMacros
//
//  Created by 顾海军 on 2019/9/27.
//  Copyright © 2019 GuHaijun. All rights reserved.
//

#ifndef NNMacrosSandbox_h
#define NNMacrosSandbox_h

#define NN_pathHome            (NSHomeDirectory())
#define NN_pathDocuments       ([NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject])
#define NN_pathLibrary         ([NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) firstObject])
#define NN_pathCaches          ([NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject])
#define NN_pathPreference      ([[NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) firstObject] stringByAppendingString:@"/Preferences"])
#define NN_pathTmp             (NSTemporaryDirectory())

#endif /* NNMacrosSandbox_h */
