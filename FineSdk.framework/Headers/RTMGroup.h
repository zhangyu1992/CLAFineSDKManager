//
//  RTMGroup.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/6/18.
//

#import <Foundation/Foundation.h>
#import <FineSdk/RTMGroupInfoModel.h>
#import <FineSdk/RTMGroupUserInfoModel.h>
#import <FineSdk/RTMErrHeaders.h>

NS_ASSUME_NONNULL_BEGIN

//收到邀请入群
typedef void (^receiveGroupOWnerReply)(RTMGroupInfoModel *groupModel,RTMGroupUserInfoModel *user,bool status);
//收到群主信息改变
typedef void (^receiveChangeGroupOwner)(RTMGroupInfoModel *groupModel,RTMGroupUserInfoModel *olderGroupOwner,RTMGroupUserInfoModel *newGroupOwner);
//接收到群组内个人权限变更
typedef void (^receiveChangeGroupUserAuthType)(RTMGroupInfoModel *groupInfo,RTMGroupUserInfoModel *user,RTM_GroupUserAuthType authType,int result);
//接收到群权限变更发送成功的消息
typedef void (^changeGroupAuthType)(void);
//接收到被踢掉线
typedef void (^receiveKickOutGroupBySever)(RTMGroupInfoModel *groupModel,RTMGroupUserInfoModel *kickoutUser);
//接收到群解散的方法回调
typedef void (^receiveDissolveGroup)(RTMGroupInfoModel *groupModel);
/**收到群成员申请入群*/
typedef void (^receiveApplyJoinGroup)(RTMGroupInfoModel *groupModel,RTMGroupUserInfoModel *groupUser);
//收到群成员申请权限
typedef void (^receiveGroupUserApplyAuth)(RTMGroupInfoModel *groupModel,RTMGroupUserInfoModel *applyUser,RTM_GroupUserAuthType applyAuthType);
typedef void(^receiveInviteJoinGroupFeedBack)(RTMGroupInfoModel *groupModel,RTMGroupUserInfoModel *responderUser,bool agree);
typedef void(^receiveChangeGroupAuth)(RTMGroupInfoModel *groupInfo,RTM_GroupAuthType authType,int result);



@interface RTMGroup : NSObject

@property (nonatomic, copy) receiveGroupOWnerReply receiveGroupInviteBlock;
@property (nonatomic, copy) receiveApplyJoinGroup receiveApplyJoinGroupBlock;
@property (nonatomic, copy) receiveChangeGroupOwner receiveChangeGroupOwnerBlock;
@property (nonatomic, copy) receiveGroupUserApplyAuth receiveGroupUserApplyAuthBlock;
@property (nonatomic, copy) receiveChangeGroupUserAuthType receiveChangeGroupUserAuthTypeBlock;
@property (nonatomic, copy) changeGroupAuthType changeGroupAuthTypeBlock;
@property (nonatomic, copy) receiveKickOutGroupBySever receiveKickOutGroupBySeverBlock;
@property (nonatomic, copy) receiveDissolveGroup receiveDissolveGroupBlock;
@property (nonatomic,copy) receiveGroupOWnerReply receiveGroupOwnerReplyJoinBlock;//接收到群主是否同意申请入群
@property (nonatomic,copy) receiveInviteJoinGroupFeedBack receiveInviteJoinGroupFeedBackBlock;
@property (nonatomic,copy) receiveChangeGroupAuth receiveChangeGroupAuthBlock;//接收到群权限变更通知
@property (nonatomic,copy) receiveApplyJoinGroup receiveGroupUserExitGroupBlock;//接收到群成员退出群的方法回调

/// 创建群组
/// @param groupName 群名称
/// @param success 成功回调
/// @param failed 失败回调
- (void)createGroupWithGroupName:(NSString*)groupName
                         success:(void (^)(RTMGroupInfoModel *groupModel))success
                          failed:(void(^)(RTMError *error))failed;


/// 设置群属性 -入群时是否需要申请
/// @param isApply 入群时是否需要申请
/// @param groupID 群id
/// @param groupCID 群cid
/// @param success 成功回调
- (void)changeJoinGroupAuthApply:(BOOL)isApply
            WithGroupID:(NSString*)groupID
               groupCID:(NSString*)groupCID
                success:(void (^)(void))success;


/// 退出群
/// @param groupID  群id
/// @param groupCID  群ciid
/// @param success 成功回调
- (void)exitGroupWithGroupID:(NSString*)groupID
                    groupCID:(NSString*)groupCID
                     success:(void (^)(void))success;


/// 解散群组
/// @param groupID 群id
/// @param groupCID 群cid
/// @param success 成功回调
- (void)destoryGroupWithGroupID:(NSString*)groupID
                       groupCID:(NSString*)groupCID
                        success:(void (^)(void))success;



///  从服务器获取群信息,保存在本地数据库
/// @param groupID 群id
/// @param groupCID 群cid
/// @param success 成功回调
/// @param failed 失败回调
- (void)updateGroupListFromServerWithGroupID:(NSString*)groupID
                                    groupCID:(NSString*)groupCID
                                     success:(void (^)(void))success
                                      failed:(void (^)(RTMError *error))failed;

/// 查询本地数据库群组信息
/// @param gid 群id
/// @param cid 群cid
/// @param success 成功回调
/// @param failed 失败回调
- (void)queryGroupInfoFromLocalDBWithGroupID:(NSString*)gid
                                    groupCID:(NSString*)cid
                                     success:(void (^)(RTMGroupInfoModel *groupModel))success
                                      failed:(void(^)(RTMError *error))failed;




/// 邀请入群
/// @param memberInfos 要邀请的人员信息，只需设置RTMGroupUserInfoModel中的uid和cid
/// @param groupID 邀请入群的群id
/// @param groupCID 邀请入群的群cid
/// @param success 邀请消息发送成功的回调
- (void)inviteMemberArray:(NSArray<RTMGroupUserInfoModel*> *)memberInfos
                ToGroupID:(NSString*)groupID
                 groupCID:(NSString*)groupCID
                  success:(void (^)(void))success;




/// 取消邀请入群操作
/// @param memberInfos 要取消邀请的人员信息，只需设置RTMGroupUserInfoModel中的uid和cid
/// @param groupID 群id
/// @param groupCID 群cid
/// @param success 邀请消息发送成功的回调
- (void)cancelInviteMember:(NSArray<RTMGroupUserInfoModel*> *)memberInfos
                 ToGroupID:(NSString*)groupID
                  groupCID:(NSString*)groupCID
                   success:(void (^)(void))success;

/// 回复邀请入群消息
/// @param inviteReplyType 回复类型，同意或拒绝或者占线
/// @param InvitorUID 邀请者uid
/// @param InvitorCID 邀请者cid
/// @param gid 群id
/// @param gcid 群cid
/// @param success 成功回调
- (void)replyInviteJoinGroupMessageWithAnswerType:(RTM_ReplyInviteType)inviteReplyType
                                    withInvitorID:(NSString*)InvitorUID
                                       invitorCID:(NSString*)InvitorCID
                                          groupID:(NSString*)gid
                                         groupCID:(NSString*)gcid
                                          success:(void (^)(void))success;

/// 设置群消息接收方式
/// @param type 群消息接收方式
/// @param groupID 群id
/// @param groupCID 群cid
/// @param success 成功回调
- (void)changeRecevieGroupMessageType:(RTM_MessageReceiveSetType)type
                              GroupID:(NSString*)groupID
                             groupCID:(NSString*)groupCID
                              success:(void (^)(void))success;


/// 申请加入群组
/// @param groupID 群id
/// @param groupCID 群cid
/// @param hostCode 主持人密码
/// @param success 成功回调
- (void)applyJoinGrounpWithGroupID:(NSString*)groupID
                          groupCID:(NSString*)groupCID
                          hostCode:(NSString*)hostCode
                           success:(void (^)(void))success;

///申请加入群组 - 带昵称
/// @param groupID 群id
/// @param groupCID 群cid
/// @param hostCode 主持人密码
/// @param nickName 昵称
/// @param success 成功回调
- (void)applyJoinGrounpWithGroupID:(NSString*)groupID
                          groupCID:(NSString*)groupCID
                          hostCode:(NSString*)hostCode
                          nickName:(NSString *)nickName
                           success:(void (^)(void))success;

/// 群踢人
/// @param userArray 要踢出的人员数组，只需设置人员的uid和cid即可
/// @param groupID 被踢出的群组id
/// @param groupCID 被踢出的群组cid
/// @param success  成功回调
- (void)kickOutUsers:(NSArray<RTMGroupUserInfoModel*>*)userArray
         FromGroupID:(NSString*)groupID
            groupCID:(NSString*)groupCID
             success:(void (^)(void))success;


/// 转移群主
/// @param userID 要转移为群主的人的id
/// @param userCID 要转移为群主的人的cid
/// @param userName 要转移为群主的人的名称
/// @param groupID 要转移群主的群id
/// @param groupCID 要转移群主的群cid
/// @param success 成功回调
- (void)changeGroupOwnerToUserID:(NSString*)userID
                         userCID:(NSString*)userCID
                        username:(NSString*)userName
                     withGroupID:(NSString*)groupID
                        groupCID:(NSString*)groupCID
                         success:(void (^)(void))success;


/// 设置群权限
/// @param groupID 设置的群的id
/// @param groupCID 设置的群的cid
/// @param actMode 0：成员状态同步变更（默认，兼容云视），并通知appserver，1：仅改变群组属性
/// @param authType 设置的群的权限
/// @param state 权限是否开启
/// @param success 成功的回调
- (void)changeGroupAuthTypeWithGroupID:(NSString*)groupID
                              groupCID:(NSString*)groupCID
                               ActMode:(int)actMode
                         groupAuthType:(RTM_GroupAuthType)authType
                                 state:(BOOL)state
                               success:(void (^)(void))success;
/// 设置群成员权限
/// @param userID 成员id
/// @param userCID 成员cid
/// @param groupID 群id
/// @param groupCID 群cid
/// @param authType 设置的群权限
/// @param state 是否开启,1开启，0代表关闭，当设置authType 为 RTM_GroupAuthType_Sort 时，如果想要该成员置顶，state应大于群组内的所有成员的sort值（当前群内成员最大的sort值+1）
/// @param success 成功的回调
- (void)changeGroupUserAuthWithUserID:(NSString*)userID
                              userCID:(NSString*)userCID
                            toGroupID:(NSString*)groupID
                             groupCID:(NSString*)groupCID
                             AuthType:(RTM_GroupUserAuthType)authType
                                state:(NSInteger)state
                              success:(void (^)(RTMGroupInfoModel *groupInfo,RTM_GroupUserAuthType authType))success;

/// 申请权限
/// @param groupID   群id
/// @param groupCID 群cid
/// @param authType 群权限
/// @param success 成功的回调
- (void)applyGroupAuthWithGroupID:(NSString*)groupID
                         groupCID:(NSString*)groupCID
                    applyAuthType:(RTM_GroupUserAuthType)authType
                          success:(void (^)(RTM_GroupUserAuthType authType))success;



/// 群创建者收回群主权限
/// @param groupID   群id
/// @param groupCID 群cid
/// @param success 成功的回调
- (void)takeBackGroupOwnerWithGroupID:(NSString*)groupID
                             groupCID:(NSString*)groupCID
                              success:(void (^)(void))success
                               failed:(void(^)(RTMError *error))failed;


/// 从本地数据库中获取群主信息
/// @param groupID  群id
/// @param groupCid 群cid
/// @param success 成功的回调
- (void)queryHostFromDBWithGroupID:(NSString *)groupID
                          groupCID:(NSString *)groupCid
                           success:(void (^)(RTMGroupUserInfoModel* host))success;


/// 从服务器更新群列表到本地数据库
/// @param success 成功回调
/// @param failed 失败回调
- (void)updateAllGroupListFromServerSuccess:(void (^)(void))success
                                     failed:(void (^)(RTMError * error))failed;


/// 从数据库查询群列表
/// @param success 成功回调
/// @param failed 失败回调
- (void)queryAllGroupListFromDBSuccess:(void (^)(NSMutableArray<RTMGroupInfoModel*>* groupList))success
                                     failed:(void (^)(RTMError *error))failed;



/// 主持人回复 是否同意入群申请
/// @param groupID  群id
/// @param groupCID 群cid
/// @param userID  申请者的id
/// @param userCID 申请者的id
/// @param isAgree 是否同意入群
/// @param success 成功回调
- (void)replyApplyJoinGroupWithGroupID:(NSString*)groupID
                              groupCID:(NSString*)groupCID
                              ToUserID:(NSString*)userID
                               UserCID:(NSString*)userCID
                                statue:(bool)isAgree
                               success:(void (^)(void))success;

@end






NS_ASSUME_NONNULL_END
