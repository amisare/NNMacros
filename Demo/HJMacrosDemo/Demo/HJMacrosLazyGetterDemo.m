//
//  HJMacrosLazyGetterDemo.m
//  HJMacrosDemo
//
//  Created by 顾海军 on 2016/12/28.
//  Copyright © 2016年 HaijunGu. All rights reserved.
//

#import "HJMacrosLazyGetterDemo.h"


@interface HJMacrosLazyGetterDemo()
{
    NSMutableString *str_n;
}

@property (nonatomic, strong) NSMutableString *str_x;

@property (nonatomic, strong) NSMutableString *str_0;
@property (nonatomic, strong) NSMutableString *str_1;
@property (nonatomic, strong) NSMutableString *str_2;
@property (nonatomic, strong) NSMutableString *str_3;
@property (nonatomic, strong) NSMutableString *str_4;
@property (nonatomic, strong) NSMutableString *str_5;
@property (nonatomic, strong) NSMutableString *str_6;
@property (nonatomic, strong) NSMutableString *str_n;

@property (nonatomic, strong) NSMutableArray *arr_issue_0;
@property (nonatomic, strong) NSMutableDictionary *dic_issue_0;

@end


@implementation HJMacrosLazyGetterDemo

- (void)macroTest
{
    
    DLog(@"lazygetter宏的使用");
    
    DLog(@"懒加载实例化可变字符串对象");
    [self.str_0 appendString:@"str_0"];
    [self.str_1 appendString:@"str_1"];
    [self.str_2 appendString:@"str_2"];
    [self.str_3 appendString:@"str_3"];
    [self.str_4 appendString:@"str_4"];
    DLog(@"%@", self.str_0);
    DLog(@"%@", self.str_1);
    DLog(@"%@", self.str_2);
    DLog(@"%@", self.str_3);
    DLog(@"%@", self.str_4);
    
    DLog(@"懒加载实例化可变数组对象");
    for (NSString *value in self.arr_issue_0) {
        DLog(@"value:%@", value);
    }
    
    DLog(@"懒加载实例化可变字典对象");
    for (NSString *key in [self.dic_issue_0 allKeys]) {
        DLog(@"key:%@,value:%@", key, self.dic_issue_0[key]);
    }
}


#pragma mark - 方式一
//方式一：实例化对象，默认调用的new方法
lazygetter(NSMutableString, str_0)
lazygetter(NSMutableString, str_1)
lazygetter(NSMutableString, str_2)
lazygetter(NSMutableString, str_3)
lazygetter(NSMutableString, str_4)

#pragma mark - 方式二
//方式二：在{}中实例化对象，并初始化
lazygetter(NSMutableString, str_5, {
    self.str_5 = [NSMutableString new];
    [self.str_5 appendString:@"str_5"];
})

#pragma mark - 方式三
//方式三：通过第四个参数指定，指定属性
- (void)setStr_n:(NSMutableString *)str
{
    self->str_n = str;
}
lazygetter(NSMutableString, str_n, {
    self->str_n = [NSMutableString new];
    [self->str_n appendString:@"str_5"];
}, self->str_n)


#pragma mark - 问题一：array会遇到的问题
//问题一：
lazygetter(NSMutableArray, arr_issue_0, {
    self.arr_issue_0 = [NSMutableArray new];
    //编译错误代码：
    /*
    [self.arr_issue_0 addObjectsFromArray:@[@"str_x_0", @"str_x_1"]];
     */
    //解决方法，在数组外面加上小括号
    [self.arr_issue_0 addObjectsFromArray:(@[@"arr_objc_0", @"arr_objc_1"])];
})


#pragma mark - 问题二：dic会遇到的问题
//问题二：
lazygetter(NSMutableDictionary, dic_issue_0, {
    self.dic_issue_0 = [NSMutableDictionary new];
    //编译错误代码：
    /*
     [self.dic_issue_0 setValuesForKeysWithDictionary:@{@"key0":@"value0",
                                                        @"key1":@"value1"}];
     */
    //解决方法，在数组外面加上小括号
    [self.dic_issue_0 setValuesForKeysWithDictionary:(@{@"key0":@"value0",
                                                        @"key1":@"value1"})];
})


@end
