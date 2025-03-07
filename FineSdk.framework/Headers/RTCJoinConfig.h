//
//  RTCJoinConfig.h
//  FineSdk
//
//  Created by 张俞 on 2021/6/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// 入会配置类

@interface RTCJoinConfig : NSObject

/// 会议id 必传
@property (nonatomic, copy) NSString * roomId;

/// 入会sdk类型 非必传
@property (nonatomic,copy) NSString * joinSDKType;

/// 1.使用账号入会 需要传的参数
/// 主持人Code入会，可以获取主持人身份
@property (nonatomic, copy) NSString * hostCode;
/// 入会时，传入的昵称
@property (nonatomic, copy) NSString * nickName;

/// 强制入会 YES:强制入会 踢掉其他端相同账号
@property (nonatomic, assign) BOOL isForce;
/// 入会姓名 不为空时表示临时用户
@property (nonatomic, copy) NSString * joinName;



/// 2.无账号入会 需要传的参数
/// 会议 roomtoken
@property (nonatomic, copy) NSString * roomToken;
/// 会议 sessiontoken
@property (nonatomic, copy) NSString * sessionToken;


@end

NS_ASSUME_NONNULL_END
