//
//  RTCDepartmentInfo.h
//  FineSdk
//
//  Created by 张俞 on 2021/7/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// 部门信息
@interface RTCDepartmentInfo : NSObject

@property (nonatomic, copy) NSString * customerId;
@property (nonatomic, copy) NSString * parentsDepartmentId;


@property (nonatomic, copy) NSString * departmentId;
@property (nonatomic, copy) NSString * departmentName;

@property (nonatomic,assign) NSInteger level;
@property (nonatomic, copy) NSString * path;

@property (nonatomic,assign) long long createtime;
@property (nonatomic,assign) long long updatetime;

@property (nonatomic, copy) NSString * pinyin;
@property (nonatomic, copy) NSString * pyhead;

@end

/// 部门用户信息
@interface RTCDepartmentUserInfo : NSObject
@property (nonatomic, copy) NSString * parentsDepartmentId;

@property (nonatomic, copy) NSString * departmentUserId;
@property (nonatomic, copy) NSString * departmentUserName;

@property (nonatomic,assign) long long createtime;
@property (nonatomic,assign) long long updatetime;

@property (nonatomic, copy) NSString * pinyin;
@property (nonatomic, copy) NSString * pyhead;

@property (nonatomic,copy) NSString * mobile; //手机
@property (nonatomic,copy) NSString * mail; //邮箱
@property (nonatomic,copy) NSString * tel; //固话
@property (nonatomic,copy) NSString * fax; //传真
@property (nonatomic,copy) NSString * position; //职位
@property (nonatomic,copy) NSString * signname; //签名
@property (nonatomic,copy) NSString * portraiturl; //头像URL
@property (nonatomic,assign) NSInteger type; //客户端类型
@property (nonatomic,assign) NSInteger siteid; //站点编号，默认是0
@property (nonatomic,copy) NSString * status; // 用户状态

@end


NS_ASSUME_NONNULL_END
