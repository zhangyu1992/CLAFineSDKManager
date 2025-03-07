//
//  RTMGroupUserInfoModel.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/6/28.
//

#import <Foundation/Foundation.h>
#import <FineSdk/RTMEnum.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTMGroupUserInfoModel : NSObject


@property (strong) NSString * uid; //用户ID
@property (strong) NSString * cid; //用户CID
@property (strong) NSString * name; //用户名字
@property (strong) NSString * mobile; //手机
@property (strong) NSString * mail; //邮箱
@property (strong) NSString * position; //职位
@property (strong) NSString * signname; //签名
@property (assign) RTM_GroupUserStatus  status; // 用户状态
@property (assign) long long createtime; //创建时间，单位是毫秒
@property (assign) long long updatetime; //更新时间，单位是毫秒
@property (assign) RTM_GroupUserType usertype; //成员类型

@property (assign) NSInteger sort; //排序值
@property (assign) NSInteger audio; //音频权限
@property (assign) NSInteger video; //视频权限
@property (assign) NSInteger share; //共享权限
@property (assign) NSInteger note; //批注权限
@property (assign) NSInteger speak; //发言权限
@property (assign) NSInteger avctl; //音视频控制权限


@end

NS_ASSUME_NONNULL_END
