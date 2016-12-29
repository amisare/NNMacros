//
//  ViewController.m
//  HJMacrosDemo
//
//  Created by 顾海军 on 2016/12/28.
//  Copyright © 2016年 HaijunGu. All rights reserved.
//

#import "ViewController.h"
#import "HJMacrosLazyGetterDemo.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [[HAMLogOutputWindow sharedInstance] setHidden:NO];
    
#pragma mark - lazygetter宏demo
    HJMacrosLazyGetterDemo *lazyGetterDemo = [HJMacrosLazyGetterDemo new];
    [lazyGetterDemo macroTest];
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
