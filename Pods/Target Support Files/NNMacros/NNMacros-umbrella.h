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

#import "EXTSynthesize.h"
#import "NNMacros.h"
#import "NNMacrosApp.h"
#import "NNMacrosAssociatedCommon.h"
#import "NNMacrosAssociatedGetter.h"
#import "NNMacrosAssociatedSetter.h"
#import "NNMacrosAssociatedSynthesize.h"
#import "NNMacrosColor.h"
#import "NNMacrosDevice.h"
#import "NNMacrosLazyGetter.h"
#import "NNMacrosSandbox.h"
#import "NNMacrosScope.h"
#import "NNMacrosScreen.h"
#import "NNMacrosString.h"
#import "NNMacrosVersion.h"
#import "NNMacrosCocoapodsFix.h"
#import "metamacros.h"

FOUNDATION_EXPORT double NNMacrosVersionNumber;
FOUNDATION_EXPORT const unsigned char NNMacrosVersionString[];

