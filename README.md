
<h1 align = "center">NNMacros</h1>

[![GitHub release](https://img.shields.io/github/release/amisare/NNMacros.svg)](https://github.com/amisare/NNMacros/releases)
[![CocoaPods](https://img.shields.io/cocoapods/v/NNMacros.svg)](https://cocoapods.org/pods/NNMacros)
[![CocoaPods](https://img.shields.io/cocoapods/p/NNMacros.svg)](https://cocoapods.org/pods/NNMacros)
[![GitHub license](https://img.shields.io/github/license/amisare/NNMacros.svg)](https://github.com/amisare/NNMacros/blob/master/LICENSE)

## 项目简介
- NNMacros 通过宏的方式来简化 iOS 开发中 OC 的语法和 API 的操作


## 功能介绍

### nn_associated_synthesize
nn_associated_synthesize用于简化通过associated为类动态添加属性时的getter和setter实现。

- nn_associated_synthesize: 属性getter/setter方法实现，类似于@implementation中的@synthesize
- nn_associated_getter: 属性getter方法实现
- nn_associated_setter: 属性setter方法实现

### nn_lazygetter
nn_lazygetter简写懒加载getter实现

- nn_lazygetter: 属性懒加载getter方法实现

## 语法说明（详细使用见[使用示例](#使用示例)）

### nn_associated_synthesize

1. `nn_associated_synthesize(atomic_type, arc_type, type, getter, setter)`
	- atomic_type: `nonatomic、atomic`
	- arc_type: `strong、weak、assign、copy`
	- data_type: 属性类型 `类：NSObject *、NSString * ... 基本数据类：NSInteger、BOOL ...`
	- getter: getter方法名（*需要严格按照苹果命名规则书写*）
	- setter: setter方法名（*需要严格按照苹果命名规则书写*）

2. `nn_associated_getter(atomic_type, arc_type, data_type, ...)`
	- atomic_type: `nonatomic、atomic`
	- arc_type: `strong、weak、assign、copy`
	- data_type: 属性类型 `类：NSObject *、NSString * ... 基本数据类：NSInteger、BOOL ...`
	- param0:（必传）属性名称（*需要严格按照苹果命名规则书写*）
	- param1:（选传）hook_after_load，传参为代码块`{}`，代码块插入到objc_getAssociatedObject之后
	- param2:（选传）hook_befor_ret，传参为代码块`{}`，代码块插入到return之前
	
   > param1、param2中间代码段可获取的参数有：
   > - __key: objc_getAssociatedObject中用到的参数key
   > - __obj: objc_getAssociatedObject加载获取的对象
   > - __ivar: getter方法最终返回值

3. `nn_associated_setter(atomic_type, arc_type, data_type, ...)`
	- atomic_type: `nonatomic、atomic`
	- arc_type: `strong、weak、assign、copy`
	- data_type: 属性类型 `类：NSObject *、NSString * ... 基本数据类：NSInteger、BOOL ...`
	- param0:（必传）属性名称（*需要严格按照苹果命名规则书写*）
	- param1:（选传）hook_begin_set，传参为代码块`{}`，代码块插入到setter方法最开始执行位置
	- param2:（选传）hook_befor_store，传参为代码块`{}`，代码块插入到objc_setAssociatedObject之前
	
   > param1、param2中间代码段可获取的参数有：
   > - __key: objc_setAssociatedObject中用到的参数key
   > - __ivar: setter方法传入参数值
   > - __obj: objc_getAssociatedObject关联保存的对象

### nn_lazygetter

1. `nn_lazygetter(type, ...)`
	- 3 个入参：
        - type: 属性类型 `类：NSObject *、NSString * ...`（因为懒加载是对象属性，所以此处省略*号）
        - param0:（必传）属性名称
        - param1:（选传）插入的初始话代码块，传参为代码块`{}`
    - 4 个入参：
        - type: 属性类型 `类：NSObject *、NSString * ...`（因为懒加载是对象属性，所以此处省略*号）
        - param0:（必传）属性名称
        - param1:（选传）非property属性，或getter和setter均需重写时，传入操作变量 如：变量var，则传入var
        - param2:（选传）插入的初始话代码块，传参为代码块`{}`


## 使用示例

### nn_associated_synthesize
nn_associated_synthesize用于简化通过associated为类动态添加属性时的getter和setter实现。

在开发中常常会通过runtime在categroy中为已有的类动态添加属性，来丰富类的实现。此过程中，开发者需要为categroy的property手动实现getter和setter方法，并在getter和setter方法中通过runtime的objc_getAssociatedObject和objc_setAssociatedObject实现属性的加载和存储。这些代码通常是枯燥的并且雷同！

#### 1. 在category中定义一个成员属性

```
@interface NSObject (Awful)
@property (nonatomic, assign) NSInteger param;
@end

```

#### 2.实现getter/setter

```
@implementation NSObject (Awful)
nn_associated_synthesize(nonatomic, assign, NSInteger, param, setParam)
@end
```

等价

```
@implementation NSObject (Awful)
- (NSInteger)param {
    return [objc_getAssociatedObject(self, _cmd) integerValue];
}
- (void)setParam:(NSInteger)param {
    
