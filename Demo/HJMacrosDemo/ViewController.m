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

@property (weak, nonatomic) IBOutlet UITextView *logTextView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.logTextView.text = @"";
    self.logTextView.editable = NO;
    
    [self redirectSTD:STDOUT_FILENO];
    [self redirectSTD:STDERR_FILENO];
    
#pragma mark - HJMacrosLazyGetter宏demo
    HJMacrosLazyGetterDemo *lazyGetterDemo = [HJMacrosLazyGetterDemo new];
    [lazyGetterDemo macroTest];
    
    if(HJM_ScreenIs3Dot5inch)
    {
        HJM_DLog()
    }
//    HJM_DlogCG(CGRectZero);
}


- (void)log:(CGSize)CG
{
    if(sizeof(CG) == sizeof(CGSize)) {
        NSLog(@"{x = %f y = %f}", ((CGSize *)(&CG))->width, ((CGSize *)(&CG))->height);
    }
    else if (sizeof(CG) == sizeof(CGRect)) {
        NSLog(@"{x = %f y = %f\nw = %f h = %f}", ((CGRect *)(&CG))->origin.x, ((CGRect *)(&CG))->origin.x, ((CGRect *)(&CG))->size.width, ((CGRect *)(&CG))->size.height);
    }
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
