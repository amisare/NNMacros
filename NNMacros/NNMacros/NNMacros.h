//
//  NNMacros.h
//  NNMacros
//
//  Created by GuHaijun on 2018/6/1.
//  Copyright © 2018年 GuHaijun. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for NNMacros.
FOUNDATION_EXPORT double NNMacrosVersionNumber;

//! Project version string for NNMacros.
FOUNDATION_EXPORT const unsigned char NNMacrosVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <NNMacros/NNMacrosPublicHeader.h>

#if __has_include(<NNMacros/NNMacros.h>)
#import <NNMacros/NNMacrosLazyGetter.h>
#import <NNMacros/NNMacrosCategoryGetter.h>
#import <NNMacros/NNMacrosCategorySetter.h>
#import <NNMacros/NNMacrosCategorySynthesize.h>
#import <NNMacros/NNMacrosColor.h>
#import <NNMacros/NNMacrosString.h>
#import <NNMacros/NNMacrosSandboxPath.h>
#import <NNMacros/NNMacrosApp.h>
#import <NNMacros/NNMacrosDevice.h>
#import <NNMacros/NNMacrosScreen.h>
#import <NNMacros/NNMacrosVersion.h>
#else
#import "NNMacrosLazyGetter.h"
#import "NNMacrosCategoryGetter.h"
#import "NNMacrosCategorySetter.h"
#import "NNMacrosCategorySynthesize.h"
#import "NNMacrosColor.h"
#import "NNMacrosString.h"
#import "NNMacrosSandboxPath.h"
#import "NNMacrosApp.h"
#import "NNMacrosDevice.h"
#import "NNMacrosScreen.h"
#import "NNMacrosVersion.h"
#endif
