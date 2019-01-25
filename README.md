
<h1 align = "center">HJMacros</h1>

## 项目简介
- HJMacros通过宏的方式来简化iOS开发中OC的语法和Api的操作


## 功能介绍

### categorysynthesize
categorysynthesize用于简化在categroy中为类动态添加属性时的getter和setter实现。

- categorysynthesize: 属性getter/setter方法实现，类似于@implementation中的@synthesize
- categorygetter: 属性getter方法实现
- categorysetter: 属性setter方法实现

### lazygetter
lazygetter简写懒加载getter实现

- lazygetter: 属性懒加载getter方法实现

## 语法说明（详细使用见[使用示例](#使用示例)）

### categorysynthesize

1. `categorysynthesize(atomic_type, arc_type, type, getter, setter)`
	- atomic_type: `nonatomic、atomic`
	- arc_type: `strong、weak、assign、copy`
	- data_type: 属性类型 `类：NSObject *、NSString * ... 基本数据类：NSInteger、BOOL ...`
	- getter: getter方法名（*需要严格按照苹果命名规则书写*）
	- setter: setter方法名（*需要严格按照苹果命名规则书写*）

2. `categorygetter(atomic_type, arc_type, data_type, ...)`
	- atomic_type: `nonatomic、atomic`
	- arc_type: `strong、weak、assign、copy`
	- data_type: 属性类型 `类：NSObject *、NSString * ... 基本数据类：NSInteger、BOOL ...`
	- param0:（必传）getter方法名（*需要严格按照苹果命名规则书写*）
	- param1:（选传）hook_after_load，传参为代码块`{}`，代码块插入到objc_getAssociatedObject之后
	- param2:（选传）hook_befor_ret，传参为代码块`{}`，代码块插入到return之前
	
   > param1、param2中间代码段可获取的参数有：
   > - __key: objc_getAssociatedObject中用到的参数key
   > - __obj: objc_getAssociatedObject加载获取的对象
   > - __ivar: getter方法最终返回值

3. `categorysetter(atomic_type, arc_type, data_type, ...)`
	- atomic_type: `nonatomic、atomic`
	- arc_type: `strong、weak、assign、copy`
	- data_type: 属性类型 `类：NSObject *、NSString * ... 基本数据类：NSInteger、BOOL ...`
	- param0:（必传）setter方法名（*需要严格按照苹果命名规则书写*）
	- param1:（选传）hook_begin_set，传参为代码块`{}`，代码块插入到setter方法最开始执行位置
	- param2:（选传）hook_befor_store，传参为代码块`{}`，代码块插入到objc_setAssociatedObject之前
	
   > param1、param2中间代码段可获取的参数有：
   > - __key: objc_setAssociatedObject中用到的参数key
   > - __ivar: setter方法传入参数值
   > - __obj: objc_getAssociatedObject关联保存的对象

### lazygetter

1. `lazygetter(type, ...)`
	- type: 属性类型 `类：NSObject *、NSString * ...`（因为懒加载是对象属性，所以此处省略*号）
	- param0:（必传）属性名称
	- param1:（选传）插入的初始话代码块，传参为代码块`{}`
	- param2:（选传）非property属性，或getter和setter均需重写时，传入操作变量 如：变量var，则传入self->var


## 使用示例

### categorysynthesize
categorysynthesize用于简化在categroy中为类动态添加属性时的getter和setter实现。

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
categorysynthesize(nonatomic, assign, NSInteger, param, setParam)
@end
```

等价

```
@implementation NSObject (Awful)
- (NSInteger)param {
    return [objc_getAssociatedObject(self, _cmd) integerValue];
}
- (void)setParam:(NSInteger)param {
    objc_setAssociatedObject(self, @selector(param), @(param), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}
@end
```


### categorygetter

#### 1. 在category中定义一个成员属性

```
@interface NSObject (Awful)
@property (nonatomic, assign) NSInteger param;
@end

```

#### 2.实现getter

- 方式一：无hook代码块参数于categorysynthesize中相同
    
```
@implementation NSObject (Awful)
categorygetter(nonatomic, assign, NSInteger, param)
@end
```

等价

```
@implementation NSObject (Awful)
- (NSInteger)param {
    return [objc_getAssociatedObject(self, _cmd) integerValue];
}
@end
```

- 方式二：有hook代码块参数
    
```
@implementation NSObject (Awful)
categorygetter(nonatomic, assign, NSInteger, param, {
	NSLog(@"%@", __obj);
}, {
	__ivar += 100;
})
@end
```

等价

```
@implementation NSObject (Awful)
- (NSInteger)param {
    id obj = objc_getAssociatedObject(self, _cmd);
    NSLog(@"%@", obj);
    NSInteger value = [obj integerValue];
    value += 100;
    return value;
}
@end
```

### categorysetter

#### 1. 在category中定义一个成员属性

```
@interface NSObject (Awful)
@property (nonatomic, assign) NSInteger param;
@end

```

#### 2.实现setter

- 方式一：无hook代码块参数于categorysynthesize中相同
    
```
@implementation NSObject (Awful)
categorysetter(nonatomic, assign, NSInteger, setParam)
@end
```

等价

```
@implementation NSObject (Awful)
- (void)setParam:(NSInteger)param {
    objc_setAssociatedObject(self, @selector(param), @(param), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}
@end
```

- 方式二：有hook代码块参数
    
```
@implementation NSObject (Awful)
categorysetter(nonatomic, assign, NSInteger, setParam, {
    __ivar += 100;
}, {
    NSLog(@"%@", __obj);
})
@end
```

等价

```
@implementation NSObject (Awful)
- (void)setParam:(NSInteger)param {
	value = param;
    value += 100;
    id obj = @(value);
    NSLog(@"%@", obj);
    objc_setAssociatedObject(self, @selector(param), obj, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}
@end
```

### lazygetter
lazygetter宏替换了懒加载getter方法中的if判断部分，精简了懒加载书写，对于属性较多的类尤为明显。

#### 1. 定义一个成员属性

```
@interface AwfulNSObject
{
	UITableView *table;
}
@property (nonatomic, strong) UITableView *tableView;
@end

```


#### 2.实现懒加载getter

- 方式一：实例化对象，默认调用的new方法
    
```
lazygetter(UITableView, tableView)
```

等价

```
- (UITableView *)tableView
{
    if (!_tableView) {
        _tableView = [UITableView new];
    }
    return _tableView;
}
```

- 方式二：在代码块`{}`中实例化对象，并初始化


```
lazygetter(UITableView, tableView, {
    self.tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStyleGrouped];
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
})
```

等价

```
- (UITableView *)tableView
{
    if (!_tableView) {
        self.tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStyleGrouped];
        self.tableView.delegate = self;
        self.tableView.dataSource = self;
    }
    return _tableView;
}
```

- 方式三：通过第四个参数指定，指定属性(*用于处理getter方法和setter方法都需要重写的情况*)

```
lazygetter(UITableView, tableView, {
    self->table = [UITableView new];
}, self->table)
```

等价

```
- (UITableView *)tableView
{
    if (!self->table) {
        self->table = [UIImageView new];
    }
    return self->table;
}
```

## 安装

### 手动安装

- 添加HJMacros目录到项目中
- `#import "HJMacros.h"`

### CocoaPods

- `pod 'HJMacros'`
- `#import <HJMacros.h>`


## 使用中会遇到的问题及处理：

在使用数组和字典中会遇编译错误的情况（其实是同一类问题）

##### 使用数组时遇到的问题及处理

- 在使用@[]数组时，会报编译错误

编译错误情景：
```
lazygetter(NSMutableArray, arr_issue_0, {
    self.arr_issue_0 = [NSMutableArray new];
    //编译器会报错，无法编译通过：
    [self.arr_issue_0 addObjectsFromArray:@[@"str_x_0", @"str_x_1"]];
})
```
处理方法：在@[]外面加上小括号(@[])

```
lazygetter(NSMutableArray, arr_issue_0, {
    self.arr_issue_0 = [NSMutableArray new];
    //解决方法，在数组外面加上小括号
    [self.arr_issue_0 addObjectsFromArray:(@[@"arr_objc_0", @"arr_objc_1"])];
})
```

##### 使用字典时遇到的问题及处理
    
- 在使用@{}字典时，会报编译错误

编译错误情景：

```
lazygetter(NSMutableDictionary, dic_issue_0, {
    self.dic_issue_0 = [NSMutableDictionary new];
    //编译器会报错，无法编译通过
    [self.dic_issue_0 setValuesForKeysWithDictionary:@{@"key0":@"value0",
                                                        @"key1":@"value1"}];
})

```

处理方法：在@{}外面加上小括号(@{})

```
lazygetter(NSMutableDictionary, dic_issue_0, {
    self.dic_issue_0 = [NSMutableDictionary new];
    //解决方法，在数组外面加上小括号
    [self.dic_issue_0 setValuesForKeysWithDictionary:(@{@"key0":@"value0",
                                                        @"key1":@"value1"})];
})
```

## 鸣谢
- [ReactiveCocoa](https://github.com/ReactiveCocoa/ReactiveCocoa)
宏的可变参数分析使用`metamacros.h`实现，源于[ReactiveCocoa](https://github.com/ReactiveCocoa/ReactiveCocoa)。
- [P99](http://p99.gforge.inria.fr/)
`metamacros.h`中提到，其部分实现的灵感来自于[P99](http://p99.gforge.inria.fr/)。
