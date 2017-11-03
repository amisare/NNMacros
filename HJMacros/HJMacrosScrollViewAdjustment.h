//
//  HJMacrosScrollViewAdjustment.h
//  HJMacros
//
//  Created by GuHaijun on 2017/11/3.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef HJMacrosScrollViewAdjustment_h
#define HJMacrosScrollViewAdjustment_h

/*
 HJMacroScrollViewAdjustment(ViewController, ...)

 参数解释：

 4个参数：
 ViewController:    ScrollView所在viewController
 args[0]:           ScrollView
 args[1]:           ViewController.args[0].contentInsetAdjustmentBehavior = args[1];
 args[2]:           ViewController.automaticallyAdjustsScrollViewInsets = args[2];

 3个参数：
 ViewController:    ScrollView所在viewController
 args[0]:           ScrollView
 args[1]:           ViewController.args[0].contentInsetAdjustmentBehavior = args[1];
 args[2]:(不传参)    ViewController.automaticallyAdjustsScrollViewInsets = !(UIScrollViewContentInsetAdjustmentNever == args[1]);

 2个参数：
 ViewController:    ScrollView所在viewController
 args[0]:           ScrollView
 args[1]:(不传参)    ViewController.args[0].contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
 args[2]:(不传参)    ViewController.automaticallyAdjustsScrollViewInsets = false;

 其他参数：报错


 使用示例：

 4个参数eg:          HJMacroScrollViewAdjustment(self, tableView, HJMacroScrollViewAdjustmentBehaviorAlways, true);
 3个参数eg:          HJMacroScrollViewAdjustment(self, tableView, HJMacroScrollViewAdjustmentBehaviorAlways);
 2个参数eg:          HJMacroScrollViewAdjustment(self, tableView);

 */

// 适配ScrollView AdjustmentBehavior
typedef NS_ENUM(NSInteger, HJMacroScrollViewAdjustmentBehavior) {
    HJMacroScrollViewAdjustmentBehaviorAutomatic,           // UIScrollViewContentInsetAdjustmentAutomatic
    HJMacroScrollViewAdjustmentBehaviorScrollableAxes,      // UIScrollViewContentInsetAdjustmentScrollableAxes
    HJMacroScrollViewAdjustmentBehaviorNever,               // UIScrollViewContentInsetAdjustmentNever
    HJMacroScrollViewAdjustmentBehaviorAlways,              // UIScrollViewContentInsetAdjustmentAlways
};


#define HJMacroScrollViewAdjustment(ViewController, ...) \
\
metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))\
    (HJMacroScrollViewAdjustmentAllArgs(ViewController,\
                                        __VA_ARGS__,\
                                        HJMacroScrollViewAdjustmentBehaviorNever,\
                                        false))\
(metamacro_if_eq(2, metamacro_argcount(__VA_ARGS__))\
    (HJMacroScrollViewAdjustmentAllArgs(ViewController,\
                                        metamacro_at(0, __VA_ARGS__),\
                                        metamacro_at(1, __VA_ARGS__),\
                                        (!(HJMacroScrollViewAdjustmentBehaviorNever == (metamacro_at(1, __VA_ARGS__))))))\
(metamacro_if_eq(3, metamacro_argcount(__VA_ARGS__))\
    (HJMacroScrollViewAdjustmentAllArgs(ViewController,\
                                        __VA_ARGS__))\
\
(HJMacroScrollViewAdjustmentArgsError(ViewController, __VA_ARGS__))))\


#define HJMacroScrollViewAdjustmentArgsError(__VA_ARGS__) \
({\
    _Error "Wrong number of arguments"\
})\


#define HJMacroScrollViewAdjustmentAllArgs(ViewController, ScrollViewProperty, HJMacroScrollViewAdjustmentBehavior, AutomaticallyAdjustsScrollViewInsets) \
({ \
__weak id vc_ = (ViewController); \
if ([vc_ isKindOfClass:[UIViewController class]]) {\
    id sv_ = [vc_ valueForKeyPath:@keypath(ViewController, ScrollViewProperty)];\
    if ([sv_ isKindOfClass:[UIScrollView class]]) {\
        if (@available(iOS 11.0, *)) {\
            ((UIScrollView *)sv_).contentInsetAdjustmentBehavior = (UIScrollViewContentInsetAdjustmentBehavior)HJMacroScrollViewAdjustmentBehavior;\
        } else {\
            ((UIViewController *)vc_).automaticallyAdjustsScrollViewInsets = AutomaticallyAdjustsScrollViewInsets;\
        }\
    }\
}\
})

#endif /* HJMacrosScrollViewAdjustment_h */
