//
//  RTMMessage.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/6/18.
//

#import <Foundation/Foundation.h>
#import <FineSdk/RTMGroupMessageSendModel.h>
#import <FineSdk/RTMModelHeaders.h>
#import <FineSdk/RTMErrHeaders.h>

NS_ASSUME_NONNULL_BEGIN


@interface RTMMessage : NSObject


/// 从服务器同步群历史消息到本地数据库
/// @param groupID 要同步消息的群的id
/// @param groupCID 要同步消息的群的id
/// @param messageID 此条消息的id，需要使用RTGuid类进行生成
/// @param updateTime  开始时间
/// @param count 需要更新的消息数量
/// @param success 成功的回调
/// @param failed 失败的回调
- (void)updateHistoryGroupMessageFromServerWithGroupID:(NSString*)groupID
                                              groupCID:(NSString*)groupCID
                                             messageID:(NSString*)messageID
                                            updateTime:(long long)updateTime
                                           updateCount:(NSInteger)count
                                               succecc:(void (^)(NSString* messageID))success
                                                failed:(void(^)(RTMError *error))failed;


/// 从本地数据库获取历史群组聊天消息
/// @param groupID 群id
/// @param groupCID 群cid
/// @param startTime 开始的时间
/// @param endTime 结束的时间
/// @param count 每页获取的数量
/// @param page 第几页 (从第 1  页开始)
/// @param block 成功回调
- (void)queryHistoryGroupListFromDBWithgroupID:(NSString*)groupID
                                      groupCID:(NSString*)groupCID
                                     startTime:(long long)startTime
                                       endTime:(long long)endTime
                                   selectCount:(NSInteger)count
                                          page:(NSInteger)page
                                       success:(void (^)(NSMutableArray<RTMGroupMessageSendModel*> *fetchedResults))block;


/// 删除聊天室消息
/// @param itemInfoModel 要删除的消息模型
/// @param block 执行结束的回调，根据result值判断是否成功删除
- (void)deletMessageWithItemModel:(RTMItemInfoModel*)itemInfoModel
                           result:(void (^)(bool result))block;


/// 从服务器同步系统消息到本地数据库
/// @param messageID 此条消息的id，需要使用RTGuid类进行生成
/// @param timeStamp 截止的时间
/// @param count 要同步的数量
/// @param success 成功的回调（messageID，此条消息的id）
/// @param failed 失败的回调
- (void)updateSystemMessageFromServerWithMessageID:(NSString*)messageID
                                         timeStamp:(NSString*)timeStamp
                                             count:(NSInteger)count
                                           success:(void (^)(NSString* messageID))success
                                            failed:(void(^)(RTMError *error))failed;


/// 根据状态查询系统消息
/// @param timeStamp 截止的时间
/// @param messageStatus 要查询的消息状态
/// @param pageIndex 第几页
/// @param pageSize 每页的数量
/// @param success 成功回调
/// @param failed 失败回调
- (void)selectSystemMessageFromDBWithUpdatetime:(NSString*)timeStamp
                                  messageStatus:(RTM_MessageStatus)messageStatus
                                      pageIndex:(int)pageIndex
                                       pageSize:(int)pageSize
                                        success:(void (^)(NSMutableArray<RTMSystemMessageModel*> *fetchedResults))success
                                         failed:(void (^)(RTMError *error))failed;


/// 查询所有的系统信息
/// @param page 第几页
/// @param pageSize 每页的数量
/// @param success 成功回调
/// @param failed 失败回调
- (void)selectAllSystemMessageFromDBWithPage:(NSInteger)page
                                    pageSize:(int)pageSize
                                     success:(void (^)(NSMutableArray<RTMSystemMessageModel*> *fetchedResults))success
                                      failed:(void (^)(RTMError *error))failed;


/// 设置系统消息状态
/// @param msgID 要设置状态的消息的messageId
/// @param messageStatus 要设置的状态
/// @param success 成功回调
/// @param failed 失败回调
- (void)updateSystemMessageWithMessageID:(NSString*)msgID
                                  Status:(RTM_MessageStatus)messageStatus
                                 success:(void (^)(void))success
                                    failed:(void (^)(RTMError *error))failed;

/// 设置群组消息状态
/// @param msgID 此条消息的id，需要使用RTGuid类进行生成
/// @param groupID 要设置的群的id
/// @param GroupCID 要设置的群的cid
/// @param messageStatus 要设置的消息状态
/// @param success 成功回调(messageID,此条消息的id)
/// @param failed 失败回调
- (void)resetGroupMessageWithMessageID:(NSString*)msgID
                               groupID:(NSString*)groupID
                              groupCID:(NSString*)GroupCID
                                Status:(RTM_MessageStatus)messageStatus
                               success:(void (^)(NSString* messageID))success
                                  failed:(void (^)(RTMError *error))failed;

@end

NS_ASSUME_NONNULL_END
