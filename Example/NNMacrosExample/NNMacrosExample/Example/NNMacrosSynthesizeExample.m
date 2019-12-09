//
//  NNMacrosSynthesizeExample.m
//  NNMacrosExample
//
//  Created by 顾海军 on 2019/10/16.
//  Copyright © 2019 顾海军. All rights reserved.
//

#import "NNMacrosSynthesizeExample.h"

@implementation NNMacrosSynthesizeExample

- (void)macroTest {
    
    DLog(@"nn_associated_synthesize宏的使用");
	
    DLog(@"");
    self.astring = @"fristString astring";
    DLog(@"%@", self.astring);
    self.astring = @"secondString astring";
    DLog(@"%@", self.astring);
	
    DLog(@"");
    self.zstring = @"fristString zstring";
    DLog(@"%@", self.zstring);
    self.zstring = @"secondString zstring";
    DLog(@"%@", self.zstring);
    
    DLog(@"");
    self.string = @"fristString";
    {__unused NSString *temp = self.string;};
    self.string = @"secondString";
    {__unused NSString *temp = self.string;};
    DLog(@"");
    self.weakId = self;
    {__unused id temp = self.weakId;};
    DLog(@"");
    self.iValue = 1;
    {__unused NSInteger temp = self.iValue;};
    DLog(@"");
    self.rValue = CGRectMake(100, 101, 102, 103);
    {__unused CGRect temp = self.rValue;};
    
    DLog(@"");
    self.string2 = @"string2 fristString";
    DLog(@"%@", self.string2);
    self.string2 = @"string2 secondString";
    DLog(@"%@", self.string2);
    self.weakId2 = self;
    DLog(@"%@", self.weakId2);
    self.iValue2 = 1;
    DLog(@"%ld", self.iValue2);
    self.rValue2 = CGRectMake(100, 101, 102, 103);
    DLog(@"%@", NSStringFromCGRect(self.rValue2));
    
    
    DLog(@"");
    self.string3 = @"string3 fristString";
    DLog(@"%@", self.string3);
    self.string3 = @"string3 secondString";
    DLog(@"%@", self.string3);
    
    
    DLog(@"");
    self.string4 = @"string4 fristString";
    DLog(@"%@", self.string4);
    self.string4 = @"string4 secondString";
    DLog(@"%@", self.string4);
    
}

- (void)dealloc {
    DLog(@"%s", __func__);
}

@end

@implementation NNMacrosSynthesizeExample (Synthesize)

@nn_associated_synthesize(nonatomic, strong, id, astring, setAstring);
@nn_associated_synthesize(nonatomic, strong, id, zstring, setZstring);

@nn_synthesize(NNMacrosSynthesizeExample, string4);

@nn_associated_synthesize(NNMacrosSynthesizeExample, string3);

@nn_associated_synthesize(nonatomic, strong, id, string2, setString2)
@nn_associated_synthesize(nonatomic, weak, id, weakId2, setWeakId2)
@nn_associated_synthesize(nonatomic, assign, NSInteger, iValue2, setIValue2);
@nn_associated_synthesize(nonatomic, assign, CGRect, rValue2, setRValue2);

nn_associated_setter(nonatomic, strong, NSString *, setString, ({
    DLog(@"setter oldValue:%@", oldValue);
    DLog(@"setter setValue:%@", setValue);
}), ({
    DLog(@"setter newValue:%@", newValue);
}));
nn_associated_getter(nonatomic, strong, NSString *, string, ({
    DLog(@"getter getValue:%@", getValue);
}));

nn_associated_setter(nonatomic, weak, id, setWeakId, ({
    DLog(@"setter oldValue:%@", oldValue);
    DLog(@"setter setValue:%@", setValue);
}), ({
    DLog(@"setter newValue:%@", newValue);
}));
nn_associated_getter(nonatomic, weak, id, weakId, ({
    DLog(@"getter getValue:%@", getValue);
}));

nn_associated_setter(nonatomic, assign, NSInteger, setIValue, ({
    DLog(@"setter oldValue:%ld", oldValue);
    DLog(@"setter setValue:%ld", setValue);
}), ({
    DLog(@"setter newValue:%ld", newValue);
}));
nn_associated_getter(nonatomic, assign, NSInteger, iValue, ({
    DLog(@"getter getValue:%ld", getValue);
}));

nn_associated_setter(nonatomic, assign, CGRect, setRValue, ({
    DLog(@"setter oldValue:%@", NSStringFromCGRect(oldValue));
    DLog(@"setter setValue:%@", NSStringFromCGRect(setValue));
}), ({
    DLog(@"setter newValue:%@", NSStringFromCGRect(newValue));
}));
nn_associated_getter(nonatomic, assign, CGRect, rValue, ({
    DLog(@"getter getValue:%@", NSStringFromCGRect(getValue));
}));


@end
