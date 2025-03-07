//
//  GSCloudLive+Audience.h
//  GSCloudSdk
//
//  Created by 张俞 on 2022/4/26.
//

NS_ASSUME_NONNULL_BEGIN

@interface GSCloudLive (Audience)
/// 设置观众列表代理对象
-(void)setLiveAudienceEvent:(id<GSLiveAudienceEvent>)liveAudienceEvent;

/// 获取观众列表
/// @param userCount 获取数量
/// @param sortId 最后一条数据的id
/// @param searchName 搜索名字
/// @param success 成功回调
/// @param failure 失败回调
- (void)getAudienceUserListWithUserCount:(NSInteger)userCount fromLsatSortId:(NSString *)sortId withSearchName:(NSString *)searchName onSuccess:(void(^)(NSArray<GSAudienceInfo*> * audienceInfoList))success onFailure:(void(^)(YBError *error))failure;


/// 踢出观众
/// @param userId 用户id
/// @param success 成功回调
/// @param failure 失败回调
- (void)kickoutAudienceWithUserId:(NSString *)userId OnSuccess:(void(^)(void))success onFailure:(void(^)(YBError *error))failure;

/// 禁言观众
/// @param userInfo 用户信息
/// @param isSilence YES: 禁言 NO:取消禁言
/// @param success 成功回调
/// @param failure 失败回调
- (void)silenceAudienceWithUserInfo:(GSAudienceInfo *)userInfo isSilence:(BOOL)isSilence  OnSuccess:(void(^)(void))success onFailure:(void(^)(YBError *error))failure;

///删除观众的所有聊天消息
/// @param userInfo 用户信息
/// @param success 成功回调
/// @param failure 失败回调
- (void)deleteAudienceAllChatMessageWithUserInfo:(GSAudienceInfo *)userInfo OnSuccess:(void(^)(void))success onFailure:(void(^)(YBError *error))failure;
@end

NS_ASSUME_NONNULL_END
