## HJMacros

### 目的
- 分享自己在iOS开发中编写和收集有利于开发的OC宏

### 感谢
- 宏的可变参数分析由`metamacros.h`实现，源于[ReactiveCocoa](https://github.com/ReactiveCocoa/ReactiveCocoa)，感谢他们开源了这么优秀的响应式编程框架

## 宏lazygetter
lazygetter宏替换了懒加载getter方法中的if判断部分，精简了懒加载书写，对于属性较多的类尤为明显。

### 示例：

- 定义一个UITableView的成员属性

- 通常懒加载getter写法，如果是十几个属性或更多😂

```
- (UITableView *)tableView
{
    if (!_tableView) {
        _tableView = [[UITableView alloc] init];
    }
    return _tableView;
}
``` 
- 使用lazygetter宏写法

```
lazygetter(UITableView, tableView)
```

### 安装：

- 添加HJMacros目录到项目中
- `#import "HJMacros.h"`

### 使用：

1. 方式一：实例化对象，默认调用的new方法
    
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

2. 方式二：在{}中实例化对象，并初始化


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

3. 方式三：通过第四个参数指定，指定属性
    - 用于处理getter方法和setter方法都需要重写的情况


```
lazygetter(UIImageView, imageView, {
    self->imageView = [UIImageView new];
}, self->imageView)
```

等价

```
- (UIImageView *)imageView
{
    if (!self->imageView) {
        self->imageView = [UIImageView new];
    }
    return self->imageView;
}
```
### 使用中会遇到的问题及处理：

在使用数组和字典中会遇编译错误的情况（其实是同一类问题）

1. 使用数组时遇到的问题及处理

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


2. 使用字典时遇到的问题及处理
    
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

