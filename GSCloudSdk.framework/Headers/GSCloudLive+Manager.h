//
//  GSCloudLive+Manager.h
//  GSCloudSdk
//
//  Created by 张俞 on 2022/4/27.
//

NS_ASSUME_NONNULL_BEGIN

@interface GSCloudLive (Manager)
/// 设置管理员列表代理对象
-(void)setLiveManagerEvent:(id<GSLiveManagerEvent>)liveManagerEvent;
/**
 * 获取用户设备信息
 * @param userId 用户id
 */
- (void)getUserDeviceInfoWithUserId:(NSString *)userId OnSuccess:(void(^)(GSUserDevInfo * userInfo))success onFailure:(void(^)(YBError *error))failure;

/**
 * 打开/关闭 嘉宾视频
 * @param guestId 嘉宾Id
 * @param status 开关状态 YES：打开 NO：关闭
 */
- (void)switchGuestId:(NSString *)guestId VideoStatus:(BOOL)status OnSuccess:(void(^)(void))success onFailure:(void(^)(YBError *error))failure;
/**
 * 打开/关闭 嘉宾音频
 * @param guestId 嘉宾Id
 * @param status 开关状态 YES：打开 NO：关闭
 */
- (void)switchGuestId:(NSString *)guestId AudioStatus:(BOOL)status OnSuccess:(void(^)(void))success onFailure:(void(^)(YBError *error))failure;

/**
 * 嘉宾是否可以看观众列表
 * @param isSee 开关状态 YES：打开 NO：关闭
 */
- (void)setGuestSeeAudienceAuth:(BOOL)isSee OnSuccess:(void(^)(void))success onFailure:(void(^)(YBError *error))failure;


/**
 * 全体静音/取消全体静音
 */
- (void)switchAllGuestAudioStatus:(BOOL)status OnSuccess:(void(^)(void))success onFailure:(void(^)(YBError *error))failure;

/**
 * 主控权用户将演示权交给嘉宾
 * @param guestId 嘉宾Id
 */
-(void)giveShow:(NSString *)guestId
        success:(void(^)(void))success
        failure:(void (^)(YBError * _Nonnull error))failure;

/**
 * 主控权用户将演示权交给主播
 */
-(void)tackBackShow:(void(^)(void))success
            failure:(void (^)(YBError * _Nonnull error))failure;


/**
 * 主播将主控权转让给指定助手
 *  @param assistantId 助手Id
 */
-(void)giveUpMainControl:(NSString *)assistantId
                 success:(void(^)(void))success
                 failure:(void (^)(YBError * _Nonnull error))failure;


/**
 * 助手使用主播口令抢夺主控权
 */
-(void)snatchMainControl:(NSString *)hostPwd
                 success:(void(^)(void))success
                 failure:(void (^)(YBError * _Nonnull error))failure;


/**
 * 助手归还主动权
 */
-(void)giveMainControlBack:(void(^)(void))success
                   failure:(void (^)(YBError * _Nonnull error))failure;


/**
 * 主播收回主控权
 */
-(void)takeBackMainControl:(void(^)(void))success
                   failure:(void (^)(YBError * _Nonnull error))failure;


/// 修改昵称
/// 修改自己的昵称 嘉宾id为空
/// 助手主播可以修改嘉宾昵称 传入嘉宾id
/// @param newName 昵称
/// @param guestUid 修改嘉宾的uid
/// @param success 成功回调
/// @param failure 失败回调
- (void)updateName:(NSString *)newName
          guestUid:(NSString *)guestUid
         OnSuccess:(void(^)(void))success
         onFailure:(void(^)(YBError *error))failure;


/// 嘉宾升级为主播
/// @param hostPassword 主播密码
/// @param success 成功回调
/// @param failure 失败回调
- (void)guestToBeHost:(NSString *)hostPassword
         OnSuccess:(void(^)(void))success
         onFailure:(void(^)(YBError *error))failure;


/// 授予嘉宾主播角色
/// @param guestUid 嘉宾uid
/// @param success 成功回调
/// @param failure 失败回调
- (void)giveGuestTheAnchor:(NSString *)guestUid
         OnSuccess:(void(^)(void))success
         onFailure:(void(^)(YBError *error))failure;



/// 用户在线时长
-(void)getUserOnLineTime:(NSArray *)userIdArray success:(void(^)(NSArray * onlineUsers))success failure:(void(^)(YBError *error))failure;

@end

NS_ASSUME_NONNULL_END
