//
//  GSJoinParam.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/10.
//

#import <Foundation/Foundation.h>
#import <GSCloudSdk/Login.h>

typedef NS_ENUM(NSInteger, YBPermissionRole)
{
    YBPermissionRole_AUDIENCE = 0,  //观众
    YBPermissionRole_ANCHOR = 12,//主播
    YBPermissionRole_GUEST = 11,//嘉宾
    YBPermissionRole_ASSISTANT = 10,//助手
    YBPermissionRole_SpecialGUEST = 13,//指定嘉宾

};


NS_ASSUME_NONNULL_BEGIN
@interface GSJoinParam : NSObject
@property(nonatomic, copy)NSString *nickName;//昵称
@property(nonatomic, copy)NSString *webcastId;//直播id
@property(nonatomic, copy)NSString *accountNumber;//账号
@property(nonatomic, copy)NSString *checkCode;//白名单
@property(nonatomic, copy)NSString *clientId;//客户端ID
@property(nonatomic, copy)NSString *headImgUrl;//头像
@property(nonatomic, assign)NSInteger jointype;
@property(nonatomic, assign)YBPermissionRole type; //登录角色
@property(nonatomic, assign)NSInteger liveType;//当前登录类型 1-直播, 2回放 (默认为直播登录)
@property(nonatomic, copy)NSString *posterId;//海报id
@property(nonatomic, assign)NSInteger recordFileId;//回放登录时需要指定录制件id
@property(nonatomic, copy)NSString *recordFileName;//录制件名称
@property(nonatomic, copy)NSString *sessionKey;//sessionKey
@property(nonatomic, copy)NSString *thirdPartyUserId;//一次性登录用户(客户方定义的userId)
@property(nonatomic, copy)NSString *thirdPartyRemark;//一次性登录用户的备注

@property(nonatomic, copy)NSString *specialGuestId;//指定嘉宾ID
@property(nonatomic, copy)NSString *specialGuestUserId;//指定嘉宾userID


@end

NS_ASSUME_NONNULL_END
