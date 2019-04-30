#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "NNMacros.h"
#import "NNMacrosApp.h"
#import "NNMacrosCategoryGetter.h"
#import "NNMacrosCategorySetter.h"
#import "NNMacrosCategorySynthesize.h"
#import "NNMacrosColor.h"
#import "NNMacrosDevice.h"
#import "NNMacrosLazyGetter.h"
#import "NNMacrosSandboxPath.h"
#import "NNMacrosScreen.h"
#import "NNMacrosString.h"
#import "NNMacrosVersion.h"
#import "NNMacrosCocoapodsFix.h"
#import "metamacros.h"

FOUNDATION_EXPORT double NNMacrosVersionNumber;
FOUNDATION_EXPORT const unsigned char NNMacrosVersionString[];

