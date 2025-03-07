//
//  GSRollCallInfo.h
//  GSCloudSdk
//
//  Created by 张俞 on 2022/5/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSRollCallInfo : NSObject

/// 签到率
@property (nonatomic, copy) NSString  * answeredPercent;

/// 会议id
@property (nonatomic, copy) NSString  * confId;

/// 签到id
@property (nonatomic, copy) NSString  * rollcallId;

/// 房间id
@property (nonatomic, copy) NSString  * roomId;

/// 签到人数
@property (nonatomic, copy) NSString  * signInCount;

/// 站点
@property (nonatomic, copy) NSString  * siteId;

/// 用户总数
@property (nonatomic, copy) NSString  * userCount;

/// 用户角色
@property (nonatomic, assign) YBUserRole userRole;

/// 直播id
@property (nonatomic, copy) NSString  * webcastId;
@end

@interface GSAnswerUser : NSObject

/// 签到时间
@property (nonatomic, copy) NSString  * answerTime;

/// 是否签到
@property (nonatomic, assign) BOOL answered;

/// 昵称
@property (nonatomic, copy) NSString  * nickname;

/// 用户id
@property (nonatomic, copy) NSString  * userId;

/// 用户名
@property (nonatomic, copy) NSString  * username;
@end

@interface GSRollCallResultInfo : NSObject

/// 签到id
@property (nonatomic, copy) NSString  * rollcallId;

/// 签到率
@property (nonatomic, copy) NSString  * answeredPercent;

/// 签到人数
@property (nonatomic, copy) NSString  * answeredUserCount;

/// 场次id
@property (nonatomic, copy) NSString  * confId;

/// 签到时长
@property (nonatomic, copy) NSString  * duration;

/// 在线人数
@property (nonatomic, copy) NSString  * onlineUserCount;

/// 签到时间
@property (nonatomic, copy) NSString  * rollcallTime;

/// 房间id
@property (nonatomic, copy) NSString  * roomId;

/// 轮次
@property (nonatomic, copy) NSString  * rounds;

/// 站点
@property (nonatomic, copy) NSString  * siteId;

/// 标题
@property (nonatomic, copy) NSString  * title;

/// 角色
@property (nonatomic, assign) YBUserRole userRole;
/// 用户列表
@property (nonatomic, copy) NSArray<GSAnswerUser *> * users;

/// 直播间id
@property (nonatomic, copy) NSString  * webcastId;

/// 直播间标题
@property (nonatomic, copy) NSString  * webcastTitle;

@end

NS_ASSUME_NONNULL_END
