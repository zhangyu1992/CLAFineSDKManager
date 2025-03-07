//
//  GSRewardInfo.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, GSRewardInfoType) {
    GSGiftTypeProps = 1,//道具
    GSGiftTypeFixedAmount = 2,//固定金额红包
    GSGiftTypeCustomAmount = 3,//自定义金额红包
};

@interface GSRewardInfo : NSObject
@property(nonatomic, assign)NSInteger Id;
///礼品创建时间
@property(nonatomic, copy)NSString *createTime;
@property(nonatomic, copy)NSString *effectId;
@property(nonatomic, copy)NSString *ext1;
@property(nonatomic, copy)NSString *ext2;
@property(nonatomic, copy)NSString *ext3;
///礼品id
@property(nonatomic, copy)NSString *giftId;
///礼物名称
@property(nonatomic, copy)NSString *giftName;
///道具图片url
@property(nonatomic, copy)NSString *giftPicUrl;
///礼品类型.1:道具;2:固定金额红包;3:自定义金额红包
@property(nonatomic, assign)GSRewardInfoType giftType;
///直播间id
@property(nonatomic, copy)NSString *liveId;
///礼物的价格
@property(nonatomic, assign)double price;
///自定义金额下限
@property(nonatomic, copy)NSString *priceLowerLimit;
///自定义金额上限
@property(nonatomic, copy)NSString *priceUpperLimit;
@property(nonatomic, assign)NSInteger source;
///礼物的状态.0:未启用;1:启用
@property(nonatomic, assign)NSInteger status;
///用户id
@property(nonatomic, copy)NSString *uid;
@property(nonatomic, copy)NSString *updateTime;
///用户昵称
@property(nonatomic, copy)NSString *nickName;
///0 使用自家appid， 1 使用263的appid（基本不存在）
@property(nonatomic, assign)NSInteger agent;
///用户微信开放平台APPid
@property(nonatomic, copy)NSString *appPayId;
@end

///付款详细信息
@interface GSRewardGift : NSObject

@property(nonatomic, assign)BOOL success;

@property(nonatomic, copy)NSString *data;
///商户id
@property(nonatomic, copy)NSString *mch_id;
///随机串，防重发
@property(nonatomic, copy)NSString *nonce_str;
///财付通文档填写的数据和签名
@property(nonatomic, copy)NSString *packages;
///微信开放平台文档对数据做的签名
@property(nonatomic, copy)NSString *pay_sign;
///预支付订单
@property(nonatomic, copy)NSString *prepay_id;
@property(nonatomic, copy)NSString *sign_type;
///时间戳
@property(nonatomic, assign)NSInteger time_stamp;

@end

NS_ASSUME_NONNULL_END
