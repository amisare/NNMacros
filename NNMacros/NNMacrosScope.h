//
//  NNMacrosScope.h
//  NNMacros
//
//  Created by 顾海军 on 2019/10/21.
//  Copyright © 2019 GuHaijun. All rights reserved.
//

#ifndef NNMacrosScope_h
#define NNMacrosScope_h

/**
 * The following code is copied from https://raw.githubusercontent.com/ReactiveCocoa/ReactiveObjC/master/ReactiveObjC/extobjc/EXTScope.h
 * and deleted and modified as needed.
 */

#import "metamacros.h"

#if !defined(weakify)
/**
 * Creates \c __weak shadow variables for each of the variables provided as
 * arguments, which can later be made strong again with #strongify.
 *
 * This is typically used to weakly reference variables in a block, but then
 * ensure that the variables stay alive during the actual execution of the block
 * (if they were live upon entry).
 *
 * See #strongify for an example of usage.
 */
#define weakify(...) \
    nn_keywordify \
    metamacro_foreach_cxt(nn_weakify_,, __weak, __VA_ARGS__)
#endif /* weakify */


#if !defined(unsafeify)
/**
 * Like #weakify, but uses \c __unsafe_unretained instead, for targets or
 * classes that do not support weak references.
 */
#define unsafeify(...) \
    nn_keywordify \
    metamacro_foreach_cxt(nn_weakify_,, __unsafe_unretained, __VA_ARGS__)
#endif /* unsafeify */


#if !defined(strongify)
/**
 * Strongly references each of the variables provided as arguments, which must
 * have previously been passed to #weakify.
 *
 * The strong references created will shadow the original variable names, such
 * that the original names can be used without issue (and a significantly
 * reduced risk of retain cycles) in the current scope.
 *
 * @code

    id foo = [[NSObject alloc] init];
    id bar = [[NSObject alloc] init];

    @weakify(foo, bar);

    // this block will not keep 'foo' or 'bar' alive
    BOOL (^matchesFooOrBar)(id) = ^ BOOL (id obj){
        // but now, upon entry, 'foo' and 'bar' will stay alive until the block has
        // finished executing
        @strongify(foo, bar);

        return [foo isEqual:obj] || [bar isEqual:obj];
    };

 * @endcode
 */
#define strongify(...) \
    nn_keywordify \
    _Pragma("clang diagnostic push") \
    _Pragma("clang diagnostic ignored \"-Wshadow\"") \
    metamacro_foreach(nn_strongify_,, __VA_ARGS__) \
    _Pragma("clang diagnostic pop")
#endif /* strongify */


#if !defined(nn_weakify_)
#define nn_weakify_(INDEX, CONTEXT, VAR) \
    CONTEXT __typeof__(VAR) metamacro_concat(VAR, _weak_) = (VAR);
#endif /* nn_weakify_ */

#if !defined(nn_strongify_)
#define nn_strongify_(INDEX, VAR) \
    __strong __typeof__(VAR) VAR = metamacro_concat(VAR, _weak_);
#endif /* nn_strongify_ */


#if !defined(nn_keywordify)
// Details about the choice of backing keyword:
//
// The use of @try/@catch/@finally can cause the compiler to suppress
// return-type warnings.
// The use of @autoreleasepool {} is not optimized away by the compiler,
// resulting in superfluous creation of autorelease pools.
//
// Since neither option is perfect, and with no other alternatives, the
// compromise is to use @autorelease in DEBUG builds to maintain compiler
// analysis, and to use @try/@catch otherwise to avoid insertion of unnecessary
// autorelease pools.
#if DEBUG
#define nn_keywordify autoreleasepool {}
#else
#define nn_keywordify try {} @catch (...) {}
#endif
#endif /* nn_keywordify */

#endif /* NNMacrosScope_h */
