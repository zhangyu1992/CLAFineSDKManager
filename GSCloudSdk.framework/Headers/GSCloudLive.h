//
//  GSCloudLive.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/7.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
@interface GSCloudLive : NSObject
/**
 *各模块回调注册
 */
-(void)setAudioEvent:(id<GSAudioEvent>)audioEvent;
-(void)setLiveEvent:(id<GSLiveEvent>)liveEvent;
-(void)setChatEvent:(id<GSChatEvent>)chatEvent;
-(void)setDocEvent:(id<GSDocEvent>)docEvent;
-(void)setVoteEvent:(id<GSVoteEvent>)voteEvent;
-(void)setPraiseEvent:(id<GSPraiseEvent>)praiseEvent;
-(void)setGoodEvent:(id<GSGoodEvent>)goodEvent;
-(void)setRewardEvent:(id<GSRewardEvent>)rewardEvent;
-(void)setCardEvent:(id<GSCardEvent>)cardEvent;


/// 登录先校验在加入直播
/// @param pwd 加入密码
/// @param liveId 直播间id
/// @param guestId 指定嘉宾id
/// @param config 直播配置
/// @param success 成功回调
/// @param failure 失败回调
-(void)loginPwdCheck:(NSString *)pwd roomNum:(NSString *)liveId GuestId:(NSString *)guestId config:(GSCloudLiveConfig *)config success:(void(^)(YBPermissionRole joinRole))success failure:(void(^)(YBError *))failure;

/// 加入直播
/// @param param 加入参数
/// @param config 加入配置
-(void)joinLive:(GSJoinParam*)param config:(GSCloudLiveConfig*)config;
/**
 *离开直播
 */
-(void)leave;
/**
 *直播间信息
 */
-(LiveRoomInfo *)getLiveRoomInfo;

/**
 *消息ID的生成，如发聊天的消息ID一定得使用
 */
- (NSString *) createMsgId;

/**
 *主控权用户id
 */
- (NSString *)mainAuthUid;

/**
 *演示权用户id
 */
- (NSString *)shareAuthUid;



/// 获取直播间信息
/// @param liveId 直播id
/// @param config 直播配置
/// @param success 成功回调
/// @param failure 失败回调
- (void)getLiveSetContent:(NSString *)liveId
                   config:(GSCloudLiveConfig *)config
                  success:(void(^)(LiveRoomInfo *roomInfo))success
                  failure:(void(^)(YBError *))failure;


/// 获取直播后台设置信息
/// @param success 成功回调
/// @param failure 失败回调
- (void)getClouldSetting:(void(^)(LiveCloudSettingModel *settingInfo))success
                 failure:(void(^)(YBError *error))failure;

/**
 *获取指定嘉宾昵称
 */
-(void)getSpecialGuestName:(NSString *)guestID success:(void(^)(NSString *guestName))success failure:(void(^)(YBError *error))failure;

/**
 *获取历史聊天记录
 */
-(void)getChatHistory:(NSInteger)maxSize success:(void(^)(NSArray<GSChatMessage*>* messages))success failure:(void(^)(YBError *error))failure;
/**
 *获取主播设置
 */
- (void)getHostSettingWithLiveId:(NSString *)liveId OnSuccess:(void(^)(GSHostSettingInfo * hostSettingInfo))success onFailure:(void(^)(YBError *error))failure;
/**
 *设置观众窗口跟随切换
 */
- (void)resetAudienceWindow:(NSString *)type OnSuccess:(void(^)(void))success onFailure:(void(^)(YBError *error))failure;

/**
 *发送点赞
 */
-(void)praise:(void(^)(BOOL isSuccess))block;

/**
 *获取点赞总数
 */
- (void)getPraiseCount:(void(^)(NSInteger praiseCount))success failure:(void(^)(YBError *error))failure;


/**
 *获取礼物列表
 */
-(void)getGiftList:(void(^)(NSArray<GSRewardInfo*>* gifts))success failure:(void(^)(YBError *error))failure;

/**
 *获取在线用户列表
 */
-(void)getUserList:(NSInteger)pageNo pageSize:(NSInteger)pageSize success:(void(^)(NSArray<GSUserInfo*> *userList, GSMoreInfo *moreInfo))success failure:(void(^)(YBError *error))failure;


/// 查询本场次观看人数
/// @param success 成功回调
/// @param failure 失败回调
-(void)queryConfPersonTime:(void(^)(GSLiveConfInfo *))success failure:(void (^)(YBError * _Nonnull error))failure;


/**
 *发送聊天
 */
-(void)chat:(NSString*)text body:(NSString *)body failure:(void (^)(YBError * _Nonnull error))failure;

/**
 *回复消息
*/
- (void)reply:(NSString *)text body:(NSString *)body chatMag:(GSChatMessage *)chatMag failure:(void (^)(YBError * _Nonnull))failure;

/**
 *撤回消息
 */
- (void)revoke:(GSMessage*)message success:(void(^)(void))success failure:(void (^)(YBError * _Nonnull error))failure;

/**
 *消息置顶、删除、审核、个人禁言、全体禁言
 */
- (void)operationMsg:(id)chatMsg type:(GSOPERATIONMSG)type success:(void(^)(void))success failure:(void (^)(YBError * _Nonnull error))failure;


/**
 *提交问卷
 */
-(void)submitVote:(GSVote*)vote success:(void(^)(BOOL isSuccess))success failure:(void (^)(YBError * _Nonnull error))failure;
/**
 *打赏
 *gift 打赏信息
 */
-(void)reward:(GSRewardInfo *)gift success:(void(^)(GSRewardGift *reward))success failure:(void (^)(YBError * _Nonnull error))failure;


/**
 *申请取消连麦
 */
-(void)applyAudioTalk;
-(void)unApplyAudioTalk;


///开始直播
///结束直播
///@param liveStatus 状态
-(void)webcast:(YBadvocateLiveStatus)liveStatus
       success:(void(^)(void))success
     onFailure:(void(^)(YBError *error))failure;

///开始录制
///结束录制
///@param recordStatus 状态
-(void)record:(YBRecordStatus)recordStatus
      success:(void(^)(void))success
    onFailure:(void(^)(YBError *error))failure;

///设置音频 视频权限
/// @param authType 权限类型
/// @param isAuth 权限值：YES：有权限 NO：没有权限
- (void)setRoomAuthority:(YBRoomAuthType)authType
             toAuthValue:(BOOL)isAuth
                 success:(void(^)(void))success
               onFailure:(void(^)(YBError *error))failure;

/**
 * 获取推流列表
 */
-(void)getPushStreamList:(void(^)(NSArray<GSPushStream *> * pushStreamArr))success
                   failure:(void (^)(YBError * _Nonnull error))failure;


/**
 * 删除自定义推流配置
 */
-(void)pushStreamItemDelete:(NSString *)streamId
            success:(void(^)(void))success
                   failure:(void (^)(YBError * _Nonnull error))failure;

/**
 * 更新自定义推流配置
 */
-(void)pushStreamItemEdit:(GSPushStream *)streamParam
            success:(void(^)(void))success
                   failure:(void (^)(YBError * _Nonnull error))failure;

/**
 * 自定义推流开始推流
 */
-(void)pushStreamItemStart:(NSString *)streamId
            success:(void(^)(void))success
                   failure:(void (^)(YBError * _Nonnull error))failure;

/**
 * 自定义推流结束推流
 */
-(void)pushStreamItemStop:(NSString *)streamId
            success:(void(^)(void))success
                   failure:(void (^)(YBError * _Nonnull error))failure;

/**
 * 创建自定义推流配置
 */
-(void)pushStreamItemCreate:(GSPushStream *)streamParam
            success:(void(^)(void))success
                   failure:(void (^)(YBError * _Nonnull error))failure;

/**
 * 一键推流
 */
-(void)pushStreamStart:(void(^)(void))success
                   failure:(void (^)(YBError * _Nonnull error))failure;

//***********************************视频布局**************************************************

/// 视频布局-获取非共享布局列表
-(void)getNotSharetLayoutList:(void(^)(NSArray<GSLayoutInfo *> * layoutArr))success
                   failure:(void (^)(YBError * _Nonnull error))failure;

/// 视频布局-获取共享布局列表
-(void)getSharetLayoutList:(void(^)(NSArray<GSLayoutInfo *> * layoutArr))success
                   failure:(void (^)(YBError * _Nonnull error))failure;

/// 获取选择视频源的用户列表
/// @param type 视频布局 0 共享布局 1
-(void)getParticipantsListLayout:(NSInteger)type
                         success:(void(^)(NSArray<GSLayoutUserInfo *> * userInfoArr))success
                   failure:(void (^)(YBError * _Nonnull error))failure;

/// 获取指定嘉宾
-(void)getSpecialGuestList:(void(^)(NSArray<GSLayoutUserInfo *> * userInfoArr))success
                   failure:(void (^)(YBError * _Nonnull error))failure;

/// 设置视频布局
-(void)layoutCheck:(GSLayoutCheckInfo *)layoutInfo
         success:(void(^)(void))success
                   failure:(void (^)(YBError * _Nonnull error))failure;

//***********************************连麦**************************************************

/// 主播或助教开关连麦功能 
/// @param voipStatus 连麦状态
- (void)voipStatusChange:(YBRoomVoipStatus)voipStatus
                 success:(void(^)(void))success
                 failure:(void (^)(YBError * _Nonnull error))failure;


/// 主播或助手获取连麦列表
- (void)getVoipUsers:(void(^)(NSArray<VoipItemInfo *> * voipInfoArr))success
             failure:(void (^)(YBError * _Nonnull error))failure;

/// 主播或助手拒绝所有用户申请
- (void)refuseAllUsersApply:(void(^)(void))success
                    failure:(void (^)(YBError * _Nonnull error))failure;


/// 主播或助教同意连麦
/// @param userToken 用户token
- (void)agreeAudioTalk:(NSString *)userToken
               success:(void(^)(void))success
               failure:(void (^)(YBError * _Nonnull error))failure;


/// 主播或助教拒绝连麦
/// @param userToken 用户token
- (void)rejectAudioTalk:(NSString *)userToken
                success:(void(^)(void))success
                failure:(void (^)(YBError * _Nonnull error))failure;


/// 主播或助教挂断连麦
/// @param userToken 用户token
- (void)hangUpAudioTalk:(NSString *)userToken
                success:(void(^)(void))success
                failure:(void (^)(YBError * _Nonnull error))failure;



///查询打赏明细
///@param page 页码
///@param limit 多少条数据
- (void)queryRewardRecord:(NSInteger)page
                    limit:(NSInteger)limit
                  success:(void(^)(GSRewardData *rewardData))success
                  failure:(void(^)(YBError *error))failure;

///电话连线
-(void)phoneConnect:(void(^)(GSPhoneConnect *connect))success
            failure:(void (^)(YBError * _Nonnull error))failure;

/**
 *签到
 */
- (void)rollcallAck:(void(^)(BOOL isSuccess))block;

/**
 *参与抽奖的人数
 *candidatesRange: 参与抽奖人员  0：全部  1：未中奖者
 */
- (void)getLotteryAudienceCount:(NSInteger)candidatesRange success:(void(^)(NSInteger count))success failure:(void(^)(YBError *error))failure;

/**
 *预中奖者信息
 *name:预中奖者昵称
 *sortId
 *count:人数
 */
- (void)matchAudienceName:(NSString *)name count:(NSInteger)count success:(void(^)(NSArray<GSUserInfo*> *userList))success failure:(void(^)(YBError *error))failure;

/**
 *抽奖
 *lotteryDraw:抽奖信息
 */
- (void)lotteryDraw:(GSLotteryDraw *)lotteryDraw success:(void(^)(NSString *raffleId))success failure:(void(^)(YBError *error))failure;
/**
 *抽奖结果发布
 *raffleId:抽奖Id
 */
- (void)lotteryResult:(NSString *)raffleId success:(void(^)(NSArray<GSWinner*> *winnerList))success failure:(void(^)(YBError *error))failure;

/**
 *抽奖结果发布
 */
- (void)lotteryResultChange:(NSString *)raffleId success:(void(^)(BOOL isSuccess))success failure:(void(^)(YBError *error))failure;

/**
 *兑奖
 *winnner:抽奖信息
 *valueArray:兑奖信息
 */
- (void)raffle:(GSLottery *)winnner valueArray:(NSArray *)valueArray failure:(void(^)(YBError *error))failure;


/**
 *抽奖记录
 */
-(void)getRaffleRecord:(void(^)(NSArray<GSLottery*> *raffleList))success failure:(void(^)(YBError *error))failure;

/**
 *答题发布
 */
-(void)onCardPublish:(GSCard *)card;//GSCard

/**
 *提交发布
 */
- (void)commitCard:(NSArray *)answers block:(void(^)(BOOL isSuccess))block;

/**
答题结束
*/
- (void)onCardEnd;

/**
答题结果
 */
- (void)onCardResult:(GSCard *)card;


/**
 *待审核的消息
 */
-(void)getAuditMessage:(NSInteger)topSize success:(void(^)(NSArray<GSChatMessage*>* messages))success failure:(void(^)(YBError *error))failure;;


//***********************************商品***********************************************************
/// 上下架商品
/// @param goodsIdArray 要上架的商品ID数组
-(void)Goods_changeGoodsShelfStatus:(bool)isOn
                           goodsIds:(NSArray*)goodsIdArray
                            success:(void(^)(void))success
                            failure:(void(^)(YBError *error))failure;

/// 查询商品列表
/// @param limit 查询数量
/// @param page 页码
-(void)Goods_liveSearchGoodsLimit:(NSInteger)limit
                             page:(NSInteger)page
                          success: (void(^)(NSArray<GSGood*> *goodsList))success
                          failure:(void(^)(YBError *error))failure;


/// 推送-取消推送商品
/// @param isPush 推送或取消推送
/// @param goodsId 商品Id
-(void)Goods_pushGoods:(bool)isPush
               goodsId:(NSString*)goodsId
               success:(void(^)(void))success
               failure:(void(^)(YBError *error))failure;

//*************************************************************************************************
//***********************************插播***********************************************************
/// 获取插播文件列表
- (void)Intercut_getDocFileListSuccess:(void(^)(NSArray<GSIntercutFileInfo*>*fileArray))success
                            failure:(void(^)(YBError *error))failure;

/// 获取正在播放的插播文件
- (void)Intercut_queryPlayingFileWithRoomId:(NSString*)roomId
                            success:(void(^)(GSIntercutPlayingFileInfo *fileInfo))success
                                      failure:(void(^)(YBError *error))failure;
/// 开始播放插播文件
- (void)Intercut_startPlayMediaFileWithFileInfo:(GSIntercutFileInfo *)fileInfo
                                       playType:(YBIntercutFilePlayType)playType
                                        success:(void(^)(void))success
                                        failure:(void(^)(YBError *error))failure;
/// 修改插播文件播放状态
- (void)Intercut_changeMediaFilePlayStatus:(YBIntercutFileStatus)status
                                  fileId:(NSString *)fileId
                                      success:(void(^)(void))success
                                   failure:(void(^)(YBError *error))failure;

/// 拖动播放进度
- (void)Intercut_seekPlayFileWithFileID:(NSString *)fileId
                               seektime:(long)seektime
                                success:(void(^)(void))success
                                failure:(void(^)(YBError *error))failure;

/// 停止插播间
- (void)Intercut_stopPlayMeidaFileSuccess:(void(^)(void))success
                                  failure:(void(^)(YBError *error))failure;

/// 删除插播文件
- (void)Intercut_deletFileWithFileId:(NSString*)fileId
                             success:(void (^)(void))success
                             failure:(void (^)(YBError * _Nonnull error))failure;

/// 修改插播文件播放方式
- (void)Intercut_changeMediaPlayType:(YBIntercutFilePlayType)PlayType
                         resource_id:(NSString *)resource_id
                            fileName:(NSString*)fileName
                             success:(void(^)(void))success
                             failure:(void(^)(YBError *error))failure;

/// 设置插播文件声音大小
- (void)Intercut_changeIntercutVoice:(int)voice success:(void (^)(void))success failure:(void(^)(YBError *error))failure;
//**********************************************************************************************

#pragma mark DocOperation
/**
 *设置文档Mode
 *type: 0：图片 ， 1：动画 , 2:动画优先（默认）
*/
- (void)setShareDocMode:(GSDocMode)docMode;
/**
 *获取共享文档
 *type: 0：文档 ， 1：白板
*/
- (void)getDocShareInfo:(GSDocShareType)type failure:(void(^)(YBError *error))failure;

//共享状态信息
-(void)getDocStatusInfo;

/**
 *文档列表
 *type:资源类型：0=文档 1=插播 2=暖场 3=伪直播
 *skip: 跳转页数
 *take:条数
*/
- (void)getResourceList:(NSInteger)skip take:(NSInteger)take failure:(void (^)(YBError * _Nonnull error))failure;
/**
 *文档发布
 *resource_id：文档资源Id
*/
- (void)publishDocWithResource_id:(NSString *)resource_id
                          success:(void(^)(NSString * shareId))success failure:(void (^)(YBError * _Nonnull error))failure;
/**
 *取消发布
 *resource_id：文档资源Id
*/
- (void)canclePublishDocWithResource_id:(NSString *)resource_id failure:(void (^)(YBError * _Nonnull error))failure;

/**
 *关联文档
 *bindType: 绑定类型: 1-仅绑定到场次, 2-同时绑定到场次和直播间
 *resourceId：文档资源Id
 *resourceType:资源类型：0=文档 1=插播 2=暖场 3=伪直播
*/
- (void)bindDoc:(NSInteger)bindType resourceId:(NSString *)resourceId resourceType:(NSInteger)resourceType failure:(void (^)(YBError * _Nonnull error))failure;

/**
 *取消关联
 *resource_id：文档资源Id
*/
- (void)cancleBindDoc:(NSString *)resource_id failure:(void (^)(YBError * _Nonnull error))failure;

/**
 *共享文档
 *transFileId：文档transFileId
 *page:当前文档页数
*/
- (void)shareDocument:(NSString *)transFileId page:(NSInteger)page success:(void(^)(NSString * shareId))success failure:(void (^)(YBError * _Nonnull error))failure;

/**
 *演示权变更同步文档
 *page:当前文档页数
 *step:动画步数
*/
- (void)sycShareDocumentWithPage:(NSInteger)page Step:(NSInteger)step success:(void(^)(NSString * shareId))success failure:(void (^)(YBError * _Nonnull error))failur;


/**
 *文档删除
 *resource_id：资源id
*/
- (void)deleteDoc:(NSString *)resource_id failure:(void (^)(YBError * _Nonnull error))failure;

/**
 *文档添加
 *filePath：文档路径
 *type:资源类型：0=文档 1=插播 2=暖场 3=伪直播
*/
- (void)addDocumentWithFilePath:(NSString *)filePath type:(YBRESOURCETYPE)type failure:(void (^)(YBError * _Nonnull error))failure;


/// 添加文件
/// @param data 文件的data
/// @param fileName 文件名
/// @param type 添加的资源类型
- (void)addDocumentWithData:(NSData*)data fileName:(NSString*)fileName type:(YBRESOURCETYPE)type failure:(void (^)(YBError * _Nonnull error))failure;
/**
 *添加白板
*/
- (void)addNewWhiteBoard:(void (^)(YBError * _Nonnull error))failure;

/**
 *切换共享类型
 *type: 0：文档 ， 1：白板
*/
- (void)switchShareDate:(NSInteger)type failure:(void (^)(YBError * _Nonnull error))failure;

/**
 *预览文档
 *transFileId: 文档transFileId
*/
- (void)docShareFileViewDomain:(NSString *)transFileId failure:(void (^)(YBError * _Nonnull error))failure;

/**
 *翻页跟随
 *isFollow: YES 与演示权用户同步; NO 标注、翻页、添加、删除）不跟随
*/
- (void)pageFollow:(BOOL)isFollow failure:(void (^)(YBError * _Nonnull error))failure;

#pragma mark NoticeOperation
/**
 *公告列表
*/
-(void)getBroadMessageList:(void(^)(NSArray<GSBrocadMsg*>* brocadMessages))success failure:(void (^)(YBError * _Nonnull error))failure;

/**
 *添加公告
 *title:公告内容
 *publish: YES:仅添加  NO：发布
*/
- (void)addNotice:(NSString *)title publish:(BOOL)publish failure:(void (^)(YBError * _Nonnull error))failure;
/**
 *公告模式切换
 *mode:0:单条 1:多条
 */
- (void)noticeModeChange:(GSBrocadMsgMode)mode failure:(void (^)(YBError * _Nonnull error))failure;

/**
 *发布/取消 公告
 *noticeId:公告Id
 *isPublish: YES:发布 NO:取消
*/
- (void)noticePublishstateChange:(NSString *)noticeId isPublish:(BOOL)isPublish failure:(void (^)(YBError * _Nonnull error))failure;


//*******************************问卷***************************************************************
// 查询问卷列表
- (void)Paper_queryQuestionnaureListSuccess:(void(^)(NSArray<GSVoteCard*>*voteCardArray))success
                                            failure:(void(^)(YBError *error))failure;

// 查询单个问卷详情
- (void)Paper_queryQuestionnaureDetailsWithId:(long)PaperId
                                              Success:(void(^)(GSVoteCard *voteCardInfo))success
                                              failure:(void(^)(YBError *error))failure;
// 创建或修改问卷
//创建问卷时，PaperId为-1
//修改问卷时，PaperId为对应的问卷id
- (void)Paper_createOrUpdateWithTitle:(NSString*)title
                              PaperId:(long)PaperId
                            questions:(NSMutableArray<GSVoteQuestions *>*)questions
                              success:(void (^)(void))success
                              failure:(void(^)(YBError *error))failure;

//删除问卷
- (void)Paper_deletWithuestionnaireId:(long)PaperId
                                      success:(void (^)(void))success
                                      failure:(void (^)(YBError * _Nonnull error))failure;

// 发布问卷
- (void)Paper_pubWithPaperId:(long)PaperId
                                     success:(void (^)(id _Nullable responseObject))success
                                     failure:(void (^)(YBError * _Nonnull error))failure;

// 结束问卷
- (void)Paper_stopWithPaperId:(long)PaperId
                                  confPaperId:(long)confpaperId
                                      success:(void (^)(void))success
                                      failure:(void (^)(YBError * _Nonnull error))failure;

// 根据问卷id获取发布的问卷信息
- (void)Paper_queryReplyByConfPaperId:(long)confPaperId
                                      success:(void (^)(GSPaperDetails* quetionnaireDetails))success
                                      failure:(void (^)(YBError * _Nonnull error))failure;
//**************************************************************************************************
@end

NS_ASSUME_NONNULL_END
