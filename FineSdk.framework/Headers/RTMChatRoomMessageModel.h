//
//  RTMChatRoomMessageModel.h
//  FineSdk
//
//  Created by 张俞 on 2022/3/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef enum : NSUInteger {
    /// （6105）系统响应用户请求退出room的结果
    RTMChatRoomCMD_JoinResult = 6105,
    /// （6107）系统响应用户请求退出room的结果
    RTMChatRoomCMD_OutResult = 6107,
    /// （6121）系统通知用户在room内角色变更
    RTMChatRoomCMD_RoleChanged = 6121,
    /// （6125）系统通知用户在room内被禁言或解除禁言
    RTMChatRoomCMD_SilenceChanged = 6125,
    /// （6157）room属性变更后广播到全room
    RTMChatRoomCMD_RoomAttrChanged = 6157,
    /// （6167）room extra变更后广播到全room
    RTMChatRoomCMD_RoomExtraChanged = 6167,
    /// （6165）广播room内禁言个人
    RTMChatRoomCMD_UsersSilenceChanged = 6165,
    /// （6145）用户成功加入room后可选择把进入消息广播到全room
    RTMChatRoomCMD_UsersJoinedRoom = 6145,
    /// (7101)room公聊消息
    RTMChatRoomCMD_PublicChatMessage = 7101,
    /// (7107)room内透传信令消息，对全room
    RTMChatRoomCMD_DirectMessageToRoom = 7107,
    /// (7125)room内透传信令消息，对个人
    RTMChatRoomCMD_DirectMessageToPerson = 7125,
    /// (7119)通知消息接收方删除room聊天消息
    RTMChatRoomCMD_DeleteChatMessageToRecipient = 7119,
    /// (7123)通知接收方room聊天消息撤回
    RTMChatRoomCMD_WithdrawnChatMessageToRecipient = 7123,
    /// (7121)通知请求方room聊天消息撤回结果
    RTMChatRoomCMD_WithdrawnChatMessageResultToRequester = 7121,
    /// (7111)需审核room公聊消息
    RTMChatRoomCMD_NeedAuditPublicChatMessage = 7111,
    /// (7113)room公聊消息审核结果通知
    RTMChatRoomCMD_AuditPublicChatResultMessage = 7113,
    /// (7127)room内透传信令消息，对角色
    RTMChatRoomCMD_DirectMessageToRole = 7127,
    
} RTMChatRoomCMD;
/// 用户基本信息类
@interface RTMChatRoomUserBaseInfoModel : NSObject
/// 用户的客户id
@property (nonatomic, copy) NSString * cid;

/// 用户的用户id
@property (nonatomic, copy) NSString * uid;

/// 用户的设备id
@property (nonatomic, copy) NSString * dev;

@end

/// ChatRoom 绑定和解绑结果模型
@interface RTMChatRoomBindAppIdModel : NSObject
/// 用户信息
@property (nonatomic, strong) RTMChatRoomUserBaseInfoModel * to_user;
/// appid
@property (nonatomic, copy) NSString * app_id;
/// 结果状态 200 表示成功
@property (nonatomic, assign) NSInteger status;
/// 结果信息
@property (nonatomic, copy) NSString * info;

@end


/// chatRoom head消息类
@interface RTMChatRoomHeadMessageModel : NSObject

/// 消息命令字
@property (nonatomic, assign) RTMChatRoomCMD CMD;

/// 消息ID
@property (nonatomic, copy) NSString * msg_id;

///// 消息时间
//@property (nonatomic, assign) NSInteger ts;

/// 房间号
@property (nonatomic, copy) NSString * room_id;

/// app_id
@property (nonatomic, copy) NSString * app_id;

/// 发送用户信息
@property (nonatomic, strong) RTMChatRoomUserBaseInfoModel * to_user;

/// 来自用户信息
@property (nonatomic, strong) RTMChatRoomUserBaseInfoModel * from_user;


@end

/// （6105）系统响应用户请求退出room的结果
@interface RTMChatRoomControlJoinResultMessageModel : NSObject

/// 结果状态
@property (nonatomic, assign) NSInteger status;

/// 结果信息
@property (nonatomic, copy) NSString * info;

/// room_id
@property (nonatomic, copy) NSString * room_id;


@end

/// （6107）系统响应用户请求退出room的结果
@interface RTMChatRoomControlOutResultMessageModel : NSObject
/// 退出原因
@property (nonatomic, copy) NSString * reason;
/// 被踢原因
@property (nonatomic, copy) NSString * kick_reason;

@end

/// （6121）系统通知用户在room内角色变更
@interface RTMChatRoomControlRoleChangedMessageModel : NSObject
/// 角色
@property (nonatomic, assign) NSInteger role;

@end

/// （6125）系统通知用户在room内被禁言或解除禁言
@interface RTMChatRoomControlSilenceChangedMessageModel : NSObject
/// 禁言或解除禁言
@property (nonatomic, copy) NSString * silence;

@end


/// （6157）room属性变更后广播到全room
@interface RTMChatRoomControlRoomAttrChangedMessageModel : NSObject
/// room属性
@property (nonatomic, copy) NSString * version;
@property (nonatomic, copy) NSString * huge;
@property (nonatomic, copy) NSString * audit;
@property (nonatomic, copy) NSString * auto_audit_time;
@property (nonatomic, copy) NSString * silence;
@property (nonatomic, copy) NSString * sensitive_dict_id;
@property (nonatomic, copy) NSString * msg_clean_time;

@end

/// （6167）room extra变更后广播到全room
@interface RTMChatRoomControlRoomExtraChangedMessageModel : NSObject
/// extra变更结果 json字符串
@property (nonatomic, copy) NSString * extraJson;

@end

/// 用户禁言信息类
@interface RTMChatRoomUserSilenceInfoModel : NSObject
/// 用户基本信息
@property (nonatomic, strong) RTMChatRoomUserBaseInfoModel * user;

/// 禁言或解除禁言
@property (nonatomic, copy) NSString * silence;

@end

/// （6165）广播room内禁言个人
@interface RTMChatRoomControlUsersSilenceChangedMessageModel : NSObject
/// 用户信息
@property (nonatomic, copy) NSArray<RTMChatRoomUserSilenceInfoModel *> * users;

@end

/// （6145）用户成功加入room后可选择把进入消息广播到全room
@interface RTMChatRoomControlUsersJoinedRoomMessageModel : NSObject
/// 用户基本信息
@property (nonatomic, strong) RTMChatRoomUserBaseInfoModel * user;
/// 角色
@property (nonatomic, assign) NSInteger role;
/// 禁言或解除禁言
@property (nonatomic, copy) NSString * silence;

@end


/// （7101）公聊消息 (7107)room内透传信令消息，对全room (7125)room内透传信令消息，对个人
@interface RTMChatRoomPublicMessageModel : NSObject

/// json信息
@property (nonatomic, copy) NSString * jsonBody;

@end


NS_ASSUME_NONNULL_END
