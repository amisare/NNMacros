//
//  ViewController.m
//  NNMacrosDemo
//
//  Created by 顾海军 on 2016/12/28.
//  Copyright © 2016年 HaijunGu. All rights reserved.
//

#import "ViewController.h"
#import "NNMacrosDemo.h"

@interface ViewController (CategroySynthesize)

@property (nonatomic, strong) NSString *string;
@property (nonatomic, weak) id weakId;
@property (nonatomic, assign) NSInteger iValue;

@property (nonatomic, strong) NSString *string1;
@property (nonatomic, weak) id weakId1;
@property (nonatomic, assign) NSInteger iValue1;

@end


@implementation ViewController (CategroySynthesize)

categorygetter(nonatomic, strong, NSString *, string)
categorysetter(nonatomic, strong, NSString *, setString)
categorygetter(nonatomic, weak, id, weakId)
categorysetter(nonatomic, weak, id, setWeakId)
categorygetter(nonatomic, assign, NSInteger, iValue);
categorysetter(nonatomic, assign, NSInteger, setIValue);

categorysynthesize(nonatomic, strong, NSString *, string1, setString1)
categorysynthesize(nonatomic, weak, id, weakId1, setWeakId1)
categorysynthesize(nonatomic, assign, NSInteger, iValue1, setIValue1)

@end

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
    
#define NNMacrosTest(classDemo) \
{\
    printf("%s\n", [NN_Arg2String(classDemo) UTF8String]);\
    classDemo *demo = [classDemo new];\
    [demo macroTest];\
    printf("\n");\
}\

#pragma mark - NNMacrosLazyGetter宏demo
    NNMacrosTest(NNMacrosLazyGetterDemo)
    
#pragma mark - NNMacrosSandboxPathDemo宏demo
    NNMacrosTest(NNMacrosSandboxPathDemo)
    
#pragma mark - NNMacrosStringDemo宏demo
    NNMacrosTest(NNMacrosStringDemo)
    
#pragma mark - NNMacrosAppDemo宏demo
    NNMacrosTest(NNMacrosAppDemo)
    
#pragma mark - NNMacrosDeviceDemo宏demo
    NNMacrosTest(NNMacrosDeviceDemo)
    
#pragma mark - NNMacrosScreenDemo宏demo
    NNMacrosTest(NNMacrosScreenDemo)
    
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
