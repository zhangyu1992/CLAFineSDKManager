//
//  RTMDepartmentUserInfoModel.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/7/8.
//

#import <FineSdk/RTMDepartmentBaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTMDepartmentUserInfoModel : RTMDepartmentBaseModel

@property (copy) NSString * uid; //用户ID
@property (copy) NSString * mobile; //手机
@property (copy) NSString * mail; //邮箱
@property (copy) NSString * tel; //固话
@property (copy) NSString * fax; //传真
@property (copy) NSString * position; //职位
@property (copy) NSString * signname; //签名
@property (copy) NSString * portraiturl; //头像URL
@property (assign) NSInteger type; //客户端类型
@property (assign) NSInteger siteid; //站点编号，默认是0
@property (copy) NSString * status; // 用户状态
@property (assign) long long createtime; //创建时间，单位是毫秒
@property (assign) long long updatetime; //更新时间，单位是毫秒

@end

NS_ASSUME_NONNULL_END
