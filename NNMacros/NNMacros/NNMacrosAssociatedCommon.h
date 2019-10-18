//
//  NNMacrosAssociatedCommon.h
//  NNMacros
//
//  Created by 顾海军 on 2019/10/18.
//  Copyright © 2019 GuHaijun. All rights reserved.
//

#ifndef NNMacrosAssociatedCommon_h
#define NNMacrosAssociatedCommon_h


#define nn_associated_copy_obj_2_type_value(obj, type) \
({ \
    void *ivar = calloc(1, sizeof(type)); \
    NSString *typeName = [NN_arg2String(type) stringByReplacingOccurrencesOfString:@" " withString:@""]; \
    if ([typeName isEqualToString:@"char"])                     { *(char *)ivar = [obj charValue]; } \
    if ([typeName isEqualToString:@"unsignedchar"])             { *(unsigned char *)ivar = [obj unsignedCharValue]; } \
    if ([typeName isEqualToString:@"short"])                    { *(short *)ivar = [obj shortValue]; } \
    if ([typeName isEqualToString:@"unsignedshort"])            { *(unsigned short *)ivar = [obj unsignedShortValue]; } \
    if ([typeName isEqualToString:@"int"])                      { *(int *)ivar = [obj intValue]; } \
    if ([typeName isEqualToString:@"unsignedint"])              { *(unsigned int *)ivar = [obj unsignedIntValue]; } \
    if ([typeName isEqualToString:@"long"])                     { *(long *)ivar = [obj longValue]; } \
    if ([typeName isEqualToString:@"unsignedlong"])             { *(unsigned long *)ivar = [obj unsignedLongValue]; } \
    if ([typeName isEqualToString:@"longlong"])                 { *(long long *)ivar = [obj longLongValue]; } \
    if ([typeName isEqualToString:@"unsignedlonglong"])         { *(unsigned long long *)ivar = [obj unsignedLongLongValue]; } \
    if ([typeName isEqualToString:@"float"])                    { *(float *)ivar = [obj floatValue]; } \
    if ([typeName isEqualToString:@"double"])                   { *(double *)ivar = [obj doubleValue]; } \
    if ([typeName isEqualToString:@"BOOL"])                     { *(BOOL *)ivar = [obj boolValue]; } \
    if ([typeName isEqualToString:@"NSInteger"])                { *(NSInteger *)ivar = [obj integerValue]; } \
    if ([typeName isEqualToString:@"NSUInteger"])               { *(NSUInteger *)ivar = [obj unsignedIntegerValue]; } \
    if ([typeName isEqualToString:@"CGPoint"])                  { *(CGPoint *)ivar = [obj CGPointValue]; } \
    if ([typeName isEqualToString:@"CGVector"])                 { *(CGVector *)ivar = [obj CGVectorValue]; } \
    if ([typeName isEqualToString:@"CGSize"])                   { *(CGSize *)ivar = [obj CGSizeValue]; } \
    if ([typeName isEqualToString:@"CGRect"])                   { *(CGRect *)ivar = [obj CGRectValue]; } \
    if ([typeName isEqualToString:@"CGAffineTransform"])        { *(CGAffineTransform *)ivar = [obj CGAffineTransformValue]; } \
    if ([typeName isEqualToString:@"UIEdgeInsets"])             { *(UIEdgeInsets *)ivar = [obj UIEdgeInsetsValue]; } \
    if ([typeName isEqualToString:@"UIOffset"])                 { *(UIOffset *)ivar = [obj UIOffsetValue]; } \
    if ([typeName isEqualToString:@"NSDirectionalEdgeInsets"])  { \
        if (@available(iOS 11.0, *)) { \
            *(NSDirectionalEdgeInsets *)ivar = [obj directionalEdgeInsetsValue]; \
        } \
    } \
    ivar;\
}) \


#endif /* NNMacrosAssociatedCommon_h */
