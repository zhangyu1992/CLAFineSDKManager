//
//  GSPhoneConnect.h
//  GSCloudSdk
//
//  Created by leo on 2022/5/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class GSConnectData;
@class GSPartyListItem;
@interface GSPhoneConnect : NSObject

@property (nonatomic , copy) NSString       * timestamp;
@property (nonatomic , assign) NSInteger      status;
@property (nonatomic , copy) NSString       * message;
@property (nonatomic , copy) NSString       * token;
///会议具体信息
@property (nonatomic , strong) GSConnectData  * data;
@property (nonatomic , assign) BOOL           success;

@end

@interface GSConnectData : NSObject
///会议状态 0：未召开；1：正在召开；2：已召开；3：已过期 
@property (nonatomic , assign) NSInteger             meetingStatus;
///云视主持人免密入会地址
@property (nonatomic , copy) NSString              * cloudUrl;
///短连接
@property (nonatomic , copy) NSString              * shortUrl;
///主持人参会密码
@property (nonatomic , copy) NSString              * hostPassCode;
///会议id
@property (nonatomic , assign) NSInteger             meetingId;
///额外发放PIN码字符串数组
@property (nonatomic , strong) NSArray             * pinList;
///直播助手密码
@property (nonatomic , copy) NSString              * helperPassword;
///小程序二维码
@property (nonatomic , copy) NSString              * qrCodeBaseUrl;
///直播开始时间
@property (nonatomic , copy) NSString              * liveStartTime;
///云视id
@property (nonatomic , copy) NSString              * roomId;
///主控url
@property (nonatomic , copy) NSString              * secHostUrl;
///推流地址（自定义直播间返回）
@property (nonatomic , copy) NSString              * pushUrl;
///Meet主持人密码
@property (nonatomic , copy) NSString              * meetingHostPasscode;
///会控只读url
@property (nonatomic , copy) NSString              * secGuestUrl;
///会议编码
@property (nonatomic , copy) NSString              * meetingCode;
///验证方式 0不启用；   1启用白名单，验证失败直接挂断（暂不支持）；
/// 2 启用白名单，验证失败转人工接引；  3启用PIN码认证；   4启用第三方白名单
@property (nonatomic , assign) NSInteger             secirtyStatus;
///直播间信息，具体参见直播间信息实体（自动生成直播间返回） 
@property (nonatomic , copy) NSString              * liveRoom;
///会议时长，单位分钟
@property (nonatomic , assign) NSInteger             durationMinute;
///预约会议开始时间戳
@property (nonatomic , assign) NSInteger             startTime;
///直播参会人密码
@property (nonatomic , copy) NSString              * livePassword;
///嘉宾
@property (nonatomic , copy) NSString              * vip;
///三合一会控页面
@property (nonatomic , copy) NSString              * adminUrl;
///直播观看地址
@property (nonatomic , copy) NSString              * liveAddress;
/// 主播助手密码
@property (nonatomic , copy) NSString              * helperAddress;
///// Meet参会人密码
@property (nonatomic , copy) NSString              * meetingGuestPasscode;
/// 白名单验证处理方式 0转人工,1直接挂断
@property (nonatomic , assign) NSInteger             notesType;
///CRM白名单外处理方式 0验证后后挂断;1转人工验证;挂断 
@property (nonatomic , assign) NSInteger             crmNotesType;
///会议主题
@property (nonatomic , copy) NSString              * meetingTitle;
/// 直播助手免密地址
@property (nonatomic , copy) NSString              * helperAddressToken;
///参会人列表
@property (nonatomic , strong) NSArray <GSPartyListItem *>              * partyList;
///H5链接地址
@property (nonatomic , copy) NSString              * plusWebBaseUrl;
///接入号
@property (nonatomic , copy) NSString              * accessNumber;
///主讲人
@property (nonatomic , copy) NSString              * speaker;
///参会人密码
@property (nonatomic , copy) NSString              * guestPassCode;
///临时补充白名单信息
@property (nonatomic , strong) NSArray             * whiteList;


@end

@interface GSPartyListItem :NSObject
@property (nonatomic , copy) NSString              * partyShortUrl;
@property (nonatomic , copy) NSString              * uid;
@property (nonatomic , copy) NSString              * phoneNumber;
@property (nonatomic , copy) NSString              * partyEmail;
@property (nonatomic , copy) NSString              * pinCode;
@property (nonatomic , copy) NSString              * partyName;
@property (nonatomic , assign) NSInteger              partyId;
@property (nonatomic , copy) NSString              * partyType;
@property (nonatomic , copy) NSString              * accept;

@end

NS_ASSUME_NONNULL_END
