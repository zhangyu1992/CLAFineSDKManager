//
//  RTMChatRoom.h
//  FineSdk
//
//  Created by 张俞 on 2022/3/2.
//

#import <Foundation/Foundation.h>
#import <FineSdk/RTMErrHeaders.h>
#import <FineSdk/RTMChatRoomMessageModel.h>

NS_ASSUME_NONNULL_BEGIN
/// chatroom绑定和解除消息代理回调方法
@protocol RTMChatRoomBindResultDelegate <NSObject>
@optional

/// 接收到绑定APPID结果回调（103）
/// @param resultMessage 结果信息
- (void)RTMChatRoomDidReceiveBindResultMessage:(RTMChatRoomBindAppIdModel *)resultMessage;

/// 接收到解绑APPID结果回调（105）
/// @param resultMessage 结果信息
- (void)RTMChatRoomDidReceiveUnBindResultMessage:(RTMChatRoomBindAppIdModel *)resultMessage;

@end
/// chatroom消息代理回调方法
@protocol RTMChatRoomMessageDelegate <NSObject>

@optional
/// 接收到申请加入room结果（6105）
/// @param headMessage 消息头内容
/// @param receiveMessage 消息内容
- (void)RTMChatRoomDidReceiveHeadMessage:(RTMChatRoomHeadMessageModel *)headMessage  JoinRoomResultMessage:(RTMChatRoomControlJoinResultMessageModel *)receiveMessage;

/// 接收到申请退出room结果（6107）
/// @param headMessage 消息头内容
/// @param receiveMessage 消息内容
- (void)RTMChatRoomDidReceiveHeadMessage:(RTMChatRoomHeadMessageModel *)headMessage OutRoomResultMessage:(RTMChatRoomControlOutResultMessageModel *)receiveMessage;

/// 接收用户在room内角色变更（6121）
/// @param headMessage 消息头内容
/// @param receiveMessage 消息内容
- (void)RTMChatRoomDidReceiveHeadMessage:(RTMChatRoomHeadMessageModel *)headMessage RoleChangedMessage:(RTMChatRoomControlRoleChangedMessageModel *)receiveMessage;

/// 接收到用户在room内被禁言或解除禁言（6125）
/// @param headMessage 消息头内容
/// @param receiveMessage 消息内容
- (void)RTMChatRoomDidReceiveHeadMessage:(RTMChatRoomHeadMessageModel *)headMessage SilenceChangedMessage:(RTMChatRoomControlSilenceChangedMessageModel *)receiveMessage;

/// 接收到room属性变更（6157）
/// @param headMessage 消息头内容
/// @param receiveMessage 消息内容
- (void)RTMChatRoomDidReceiveHeadMessage:(RTMChatRoomHeadMessageModel *)headMessage RoomAttrChangedMessage:(RTMChatRoomControlRoomAttrChangedMessageModel *)receiveMessage;

/// 接收到room extra变更（6167）
/// @param headMessage 消息头内容
/// @param receiveMessage 消息内容
- (void)RTMChatRoomDidReceiveHeadMessage:(RTMChatRoomHeadMessageModel *)headMessage RoomExtraChangedMessage:(RTMChatRoomControlRoomExtraChangedMessageModel *)receiveMessage;

/// 接收到room内禁言个人（6165）
/// @param headMessage 消息头内容
/// @param receiveMessage 消息内容
- (void)RTMChatRoomDidReceiveHeadMessage:(RTMChatRoomHeadMessageModel *)headMessage UsersSilenceChangedMessage:(RTMChatRoomControlUsersSilenceChangedMessageModel *)receiveMessage;

/// 接收到用户成功加入room（6145）
/// @param headMessage 消息头内容
/// @param receiveMessage 消息内容
- (void)RTMChatRoomDidReceiveHeadMessage:(RTMChatRoomHeadMessageModel *)headMessage UsersJoinedRoomMessage:(RTMChatRoomControlUsersJoinedRoomMessageModel *)receiveMessage;

/// 接收到room 71xx消息 包括（7101，7107，7125，7119，7123，7121,7111，7113,7127）
/// @param headMessage 消息头内容
/// @param receiveMessage 消息内容
- (void)RTMChatRoomDidReceiveHeadMessage:(RTMChatRoomHeadMessageModel *)headMessage RoomPublicChatMessage:(RTMChatRoomPublicMessageModel *)receiveMessage;

@end

@interface RTMChatRoom : NSObject

/// 绑定和解除结果代理
@property (nonatomic, weak) id<RTMChatRoomBindResultDelegate> bindResultDelegate;

/// chatroom消息代理
@property (nonatomic, weak) id<RTMChatRoomMessageDelegate> messageDelegate;
/// 申请加入chatroom -- 1605
/// @param roomId 房间id
/// @param appId appid
/// @param msg 请求说明
/// @param msgId 消息id 非必传，必须使用[RTGuid newMessageGuid]生成
/// @param tag 请求tag，服务器原样返回
/// @param block 消息发送结果
- (void)applyJoinChatRoomWithRoomId:(NSString *)roomId AppId:(NSString *)appId Msg:(NSString * _Nullable)msg MsgId:(NSString * _Nullable)msgId Tag:(NSString * _Nullable )tag result:(void (^)(RTMError * error))block;

/// 申请退出chatroom -- 1607
/// @param roomId 房间id
/// @param appId appid
/// @param msgId 消息id 非必传，必须使用[RTGuid newMessageGuid]生成
/// @param tag 请求tag，服务器原样返回
/// @param block 消息发送结果
- (void)applyOutChatRoomWithRoomId:(NSString *)roomId AppId:(NSString *)appId MsgId:(NSString * _Nullable)msgId Tag:(NSString * _Nullable )tag result:(void (^)(RTMError * error))block;

/// room公聊消息，全room广播 -- 1701
/// @param roomId 房间id
/// @param msgId 消息id 非必传，必须使用[RTGuid newMessageGuid]生成
/// @param chatJson 消息内容
/// @param block 消息发送结果
- (void)sendPublicMsgToChatRoomWithRoomId:(NSString *)roomId MsgId:(NSString * _Nullable)msgId ChatJson:(NSString *)chatJson result:(void (^)(RTMError * error))block;

/// room内透传信令消息，对角色 -- 1727
/// @param roomId 房间id
/// @param roles 角色编号列表 1：主持人 2：聊天助手  3：嘉宾
/// @param msgId 消息id 非必传，必须使用[RTGuid newMessageGuid]生成
/// @param chatJson 消息内容
/// @param block 消息发送结果
- (void)sendDirectMessageToRoleWithRoomId:(NSString *)roomId ToRoles:(NSString *)roles  MsgId:(NSString * _Nullable)msgId  ChatJson:(NSString *)chatJson result:(void (^)(RTMError * error))block;

/// 个人room消息撤回 -- 1721
/// @param roomId 房间id
/// @param msgId 消息id 非必传，必须使用[RTGuid newMessageGuid]生成
/// @param chatJson 消息内容
/// @param block 消息发送结果
- (void)sendWithdrawnChatMessageWithRoomId:(NSString *)roomId MsgId:(NSString * _Nullable)msgId  ChatJson:(NSString *)chatJson result:(void (^)(RTMError * error))block;


/// 绑定其他app_id -- 103
/// @param appId appid 必传
/// @param msgId 消息id 非必传，必须使用[RTGuid newMessageGuid]生成
/// @param block 消息发送结果
- (void)bindAppIdWithAppId:(NSString *)appId MsgId:(NSString * _Nullable)msgId result:(void (^)(RTMError * error))block;

/// 解绑其他app_id -- 105
/// @param appId appid 必传
/// @param msgId 消息id 非必传，必须使用[RTGuid newMessageGuid]生成
/// @param block 消息发送结果
- (void)unBindAppIdWithAppId:(NSString * )appId MsgId:(NSString * _Nullable)msgId result:(void (^)(RTMError * error))block;


/// 发送消息给chatroom 基础方法
/// @param cmd 命令字
/// @param roomId 房间id
/// @param msgId 消息id 非必传，必须使用[RTGuid newMessageGuid]生成
/// @param headDict 请求头字典
/// @param chatJson 消息内容
/// @param block 消息发送结果
- (void)sendBaseMessageToChatRoomWithCMD:(int)cmd RoomId:(NSString *)roomId MsgId:(NSString * _Nullable )msgId HeadAttrDict:(NSDictionary *)headDict ChatJson:(NSString *)chatJson result:(void (^)(RTMError * error))block;

@end

NS_ASSUME_NONNULL_END
