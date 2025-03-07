//
//  RTMDepartmentInfoModel.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/7/8.
//

#import <Foundation/Foundation.h>
#import <FineSdk/RTMDepartmentBaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTMDepartmentInfoModel : RTMDepartmentBaseModel

@property (copy) NSString * did; //部门ID
@property (assign) NSInteger usernum; //用户数量
@property (copy) NSString * path; //部门路径，如：/1/2/3/
@property (assign) NSInteger  level; //层级，依次类推
@property (assign) long long createtime; //创建时间，单位是毫秒
@property (assign) long long updatetime; //更新时间，单位是毫秒

@end

NS_ASSUME_NONNULL_END
