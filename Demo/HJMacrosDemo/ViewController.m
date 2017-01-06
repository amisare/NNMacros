//
//  ViewController.m
//  HJMacrosDemo
//
//  Created by 顾海军 on 2016/12/28.
//  Copyright © 2016年 HaijunGu. All rights reserved.
//

#import "ViewController.h"
#import "HJMacrosDemo.h"

@interface ViewController ()

@property (weak, nonatomic) IBOutlet UITextView *logTextView;

@end

@implementation ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.logTextView.text = @"";
    self.logTextView.editable = NO;
    
//    [self redirectSTD:STDOUT_FILENO];
//    [self redirectSTD:STDERR_FILENO];
    
#define HJMacrosTest(classDemo) \
{\
    printf("%s\n", [HJM_Macro2String(classDemo) UTF8String]);\
    classDemo *demo = [classDemo new];\
    [demo macroTest];\
    printf("\n");\
}\

    
#pragma mark - HJMacrosLazyGetter宏demo
    HJMacrosTest(HJMacrosLazyGetterDemo)
    
    
#pragma mark - HJMacrosSandboxPathDemo宏demo
    HJMacrosTest(HJMacrosSandboxPathDemo)
    
#pragma mark - HJMacrosStringDemo宏demo
    HJMacrosTest(HJMacrosStringDemo)
    
#pragma mark - HJMacrosAppDemo宏demo
    HJMacrosTest(HJMacrosAppDemo)
    
#pragma mark - HJMacrosDeviceDemo宏demo
    HJMacrosTest(HJMacrosDeviceDemo)
    
#pragma mark - HJMacrosScreenDemo宏demo
    HJMacrosTest(HJMacrosScreenDemo)
    
}

- (void)redirectNotificationHandle:(NSNotification *)notification{
    NSData *data = [[notification userInfo] objectForKey:NSFileHandleNotificationDataItem];
    NSString *str = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    
    self.logTextView.text = [NSString stringWithFormat:@"%@\n%@",self.logTextView.text, str];
    NSRange range;
    range.location = [self.logTextView.text length] - 1;
    range.length = 0;
    [self.logTextView scrollRangeToVisible:range];
    
    [[notification object] readInBackgroundAndNotify];
}

- (void)redirectSTD:(int )fd{
    NSPipe * pipe = [NSPipe pipe] ;
    NSFileHandle *pipeReadHandle = [pipe fileHandleForReading] ;
    dup2([[pipe fileHandleForWriting] fileDescriptor], fd) ;
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(redirectNotificationHandle:)
                                                 name:NSFileHandleReadCompletionNotification
                                               object:pipeReadHandle] ;
    [pipeReadHandle readInBackgroundAndNotify];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
