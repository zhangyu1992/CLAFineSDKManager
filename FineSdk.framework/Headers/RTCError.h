//
//  RTCError.h
//  FineSdk
//
//  Created by 张俞 on 2021/6/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef enum : NSUInteger {
    RTCErrorTypeUnknown,//未知原因
    RTCErrorTypeRTCRoomNotFound,//RTCRoom对象找不到
    RTCErrorTypeNetworkError,// 网络错误
    RTCErrorTypeLoginInvalid,// 登录失效
    RTCErrorTypeRoomNameEmpty,// 会议名称为空
    RTCErrorTypeJoinNameEmpty,// 入会姓名为空
    RTCErrorTypeRoomIdEmpty,// 会议id为空
    RTCErrorTypeRoomNotfound,// 会议不存在
    RTCErrorTypeRoomIdInvalid,// 会议id失效
    RTCErrorTypeAlreadyInRoom,// 已经在会中
    RTCErrorTypeRoomFull,// 会议满员
    RTCErrorTypeRoomIsLock,// 会议加锁 需要申请才能进入
    RTCErrorTypePermissionDennied,//没有操作权限
    RTCErrorTypeRoomIsRecording,// 会议正在录像
    RTCErrorTypeRoomNORecordAuth,// 没有录制权限
    RTCErrorTypeRoomNORecordSpace,// 没有录制空间
    RTCErrorTypeInviteParticipantIDError,// 邀请参会人id错误
    RTCErrorTypeNoPublishStream,// 没有推流
    RTCErrorTypeNoSubscribeStream,// 没有订阅流
    RTCErrorTypeLeaveConferenceBeforeJoin,// 加入会议前先点击了离开会议
    RTCErrorTypeTokenEmpty,// 加入会议 token为空
    RTCErrorTypeCidFrozen,// 账号被禁用

} RTCErrorType;

@interface RTCError : NSObject
@property (nonatomic, assign) NSInteger errorCode;
@property (nonatomic, copy) NSString * errorDescription;
- (instancetype)initWithCode:(NSInteger)errorCode;
- (instancetype)initWithCode:(NSInteger)errorCode Description:(NSString *)errorDescription;
@end

NS_ASSUME_NONNULL_END

