//
//  RTMGroupMessageSendModel.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/6/24.
//

#import <Foundation/Foundation.h>
#import <FineSdk/RTMEnum.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTMGroupMessageSendModel : NSObject

@property (nonatomic, copy) NSString *groupID;//群组ID
@property (nonatomic, copy) NSString *groupCID;// 群CID
@property (nonatomic, copy) NSString *content;//要发送的内容
@property (nonatomic, copy) NSString *msgId;//消息ID
@property (nonatomic, copy) NSString *senderUid;//消息发送者ID
@property (nonatomic, copy) NSString *senderCid;//消息发送者CID
@property (nonatomic, copy) NSString *senderName;//消息发送者名称
@property (nonatomic, assign) RTM_MessageDirectionType directionType;//标识消息为发送或者接收,主动发消息时可以不设置
@property (nonatomic, assign) RTM_GroupMessageSendStatus messageStatus;//标识消息发送状态,主动发消息时可以不设置
@property (nonatomic, assign) RTM_MessageSendType messageType; //消息类型，默认为文本消息


- (instancetype)initWithGroupID:(NSString *)groupID
                       groupCID:(NSString *)groupCID
                        content:(NSString*)content
                      messageID:(NSString*)msgID
                    messageType:(RTM_MessageSendType)messageType;

- (instancetype)initWithGroupID:(NSString *)groupID
                       groupCID:(NSString *)groupCID
                        content:(NSString*)content
                      messageID:(NSString*)msgID
                  directionType:(RTM_MessageDirectionType)direction
                  messageStatus:(RTM_GroupMessageSendStatus)status
                    messageType:(RTM_MessageSendType)messageType;

- (instancetype)initWithGroupID:(NSString *)groupID
                       groupCID:(NSString *)groupCID
                        content:(NSString*)content
                      messageID:(NSString*)msgID
                      senderUid:(NSString*)senderUid
                      senderCid:(NSString*)senderCid
                     senderName:(NSString*)senderName
                  directionType:(RTM_MessageDirectionType)direction
                  messageStatus:(RTM_GroupMessageSendStatus)status
                    messageType:(RTM_MessageSendType)messageType;

+ (instancetype)groupMessageSendModelWithGroupID:(NSString *)groupID
                                        groupCID:(NSString *)groupCID
                                         content:(NSString*)content
                                       messageID:(NSString*)msgID
                                   directionType:(RTM_MessageDirectionType)direction
                                     messageType:(RTM_MessageSendType)messageType;

+ (instancetype)groupMessageSendModelWithGroupID:(NSString *)groupID
                                        groupCID:(NSString *)groupCID
                                         content:(NSString*)content
                                       messageID:(NSString*)msgID
                                   directionType:(RTM_MessageDirectionType)direction
                                   messageStatus:(RTM_GroupMessageSendStatus)status
                                     messageType:(RTM_MessageSendType)messageType;

+ (instancetype)groupMessageSendModelWithGroupID:(NSString *)groupID
                                        groupCID:(NSString *)groupCID
                                         content:(NSString*)content
                                       messageID:(NSString*)msgID
                                       senderUid:(NSString*)senderUid
                                       senderCid:(NSString*)senderCid
                                      senderName:(NSString*)senderName
                                   directionType:(RTM_MessageDirectionType)direction
                                   messageStatus:(RTM_GroupMessageSendStatus)status
                                     messageType:(RTM_MessageSendType)messageType;

@end

NS_ASSUME_NONNULL_END
