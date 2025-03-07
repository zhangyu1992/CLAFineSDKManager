//
//  RTCParticipantInfo.h
//  FineSdk
//
//  Created by 张俞 on 2021/7/1.
//

#import <Foundation/Foundation.h>
#import <FineSdk/RTCFormat.h>

NS_ASSUME_NONNULL_BEGIN

/// 参会人信息类
@interface RTCParticipantInfo : NSObject
/// 参会人id
@property (nonatomic, copy) NSString * participantId;
/// 参会人姓名
@property (nonatomic, copy) NSString * participantName;
/// 参会人姓名 拼音
@property (nonatomic, copy) NSString * participantNamePinYin;

/// 设备类型
@property (nonatomic, assign) RTCDevicesType deviceType;
/// 角色
@property (nonatomic, assign) RTCRoleType roleType;
/// 音频状态
@property (nonatomic, assign) RTCAudioStatus audioStatus;
/// 视频状态
@property (nonatomic, assign) RTCVideoStatus videoStatus;
/// 申请类型
@property (nonatomic, assign) RTCParticipantApplyType applyType;
/// 呼叫状态
@property (nonatomic, assign) RTCParticipantsCallingStatus callingStatus;
/// 音频权限
@property (nonatomic, assign) BOOL audioAuth;
/// 视频权限
@property (nonatomic, assign) BOOL videoAuth;
/// 主控权限
@property (nonatomic, assign) BOOL avctlAuth;
/// 置顶状态
@property (nonatomic, assign) BOOL isTop;
/// 置顶排序值
@property (nonatomic, assign) NSInteger sort;
/// 入会顺序
@property (nonatomic, assign) NSInteger joinOrder;
/// 共享权限
@property (nonatomic, assign) BOOL shareAuth;
/// 批注权限
@property (nonatomic, assign) BOOL noteAuth;
/// 是否是自己
@property (nonatomic, assign) BOOL isMySelf;
///更新时间，单位是毫秒
@property (nonatomic,assign) long long updatetime; 


@end

NS_ASSUME_NONNULL_END
