//
//  Login.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/8.
//

#import <Foundation/Foundation.h>
#import <GSCloudSdk/GSWXParam.h>
NS_ASSUME_NONNULL_BEGIN



@interface Login : NSObject
@property(nonatomic, copy)NSString *accountNumber;//账号
@property(nonatomic, copy)NSString *checkCode;//白名单
@property(nonatomic, copy)NSString *clientId;//客户端ID
@property(nonatomic, copy)NSString *email;//邮箱地址
@property(nonatomic, copy)NSString *headImgUrl;//头像
@property(nonatomic, assign)NSInteger jointype;
@property(nonatomic, assign)NSInteger liveType;//当前登录类型 1-直播, 2回放 (默认为直播登录)
@property(nonatomic, copy)NSString *nickName;//昵称
@property(nonatomic, copy)NSString *passCode;//直播口令
@property(nonatomic, copy)NSString *phoneNumber;//手机号
@property(nonatomic, copy)NSString *posterId;//海报id
@property(nonatomic, assign)NSInteger recordFileId;//回放登录时需要指定录制件id
@property(nonatomic, copy)NSString *recordFileName;//录制件名称
@property(nonatomic, copy)NSString *sessionKey;//sessionKey
@property(nonatomic, copy)NSString *sid;//CC返回的认证id
@property(nonatomic, copy)NSString *smsCode;//短信验证码
//@property(nonatomic, assign)NSInteger type;//登录类型 type=0：无限制 type=1：密码入会 type=2：报名入会 type=3：白名单入会 type=9：直播助手sessionkey type=10：直播助手口令登录
@property(nonatomic, assign)NSInteger type;//登录角色 10:助手  11：嘉宾 12：主播 0：观看
@property(nonatomic, copy)NSString *webcastId;//直播id
@property(nonatomic, strong)WxUserInfo *workWxUserInfo;
@property(nonatomic, assign)BOOL wx;//是否是微信登录
@property(nonatomic, copy)NSString *wxId;//微信Id
@property(nonatomic, copy)NSString *thirdPartyUserId;//一次性登录用户(客户方定义的userId)
@property(nonatomic, copy)NSString *thirdPartyRemark;//一次性登录用户的备注

@property(nonatomic, copy)NSString *specialGuestId;//指定嘉宾ID

@end



NS_ASSUME_NONNULL_END
