//
//  RTMDepartmentBaseModel.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/7/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTMDepartmentBaseModel : NSObject

@property (copy) NSString * cid; //客户id
@property (copy) NSString * pdid; //部门的上级id
@property (copy) NSString * name; //部门名字，必填
@property (copy) NSString * pinyin; //拼音
@property (copy) NSString * pyhead; //拼音头
@property (assign) NSInteger  sort; //同级部门排序值


@end

NS_ASSUME_NONNULL_END
