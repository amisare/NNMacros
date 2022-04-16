//
//  ViewController.m
//  NNMacrosExample
//
//  Created by 顾海军 on 2016/12/28.
//  Copyright © 2016年 HaijunGu. All rights reserved.
//

#import "ViewController.h"
#import "NNMacrosExample.h"
#import "NNMacrosExample-Swift.h"


@interface ViewController ()

@property (weak, nonatomic) IBOutlet UITextView *logTextView;

@end

@implementation ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.logTextView.text = @"";
    self.logTextView.editable = NO;
    
    [self redirectSTD:STDOUT_FILENO];
    [self redirectSTD:STDERR_FILENO];
    
    DLog(@"%@", @([[UIScreen mainScreen] currentMode].size));
    
#define NNMacrosTest(ExampleClass) \
{\
    printf("%s\n", [NN_arg2String(ExampleClass) UTF8String]);\
    ExampleClass *Example = [ExampleClass new];\
    [Example macroTest];\
    printf("\n");\
}\

    NNMacrosTest(NNMacrosLazyGetterExample)
    NNMacrosTest(NNMacrosSynthesizeExample)
    NNMacrosTest(NNMacrosSandboxPathExample)
    NNMacrosTest(NNMacrosStringExample)
    NNMacrosTest(NNMacrosAppExample)
    NNMacrosTest(NNMacrosDeviceExample)
    NNMacrosTest(NNMacrosScreenExample)
    NNMacrosTest(NNMacrosScopeExample)
    NNMacrosTest(NNMacrosNSNotificationNameExample)
	NNMacrosTest(NNMacrosNSNotificationNameExampleSwift)
    NNMacrosTest(NNMacrosCheckExample)
}

- (void)redirectNotificationHandle:(NSNotification *)notification{
    NSData *data = [[notification userInfo] objectForKey:NSFileHandleNotificationDataItem];
    NSString *str = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    
    self.logTextView.text = [NSString stringWithFormat:@"%@%@",self.logTextView.text, str];
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
