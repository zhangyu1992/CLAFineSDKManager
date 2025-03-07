//
//  GSRewardItemInfo.h
//  GSCloudSdk
//
//  Created by leo on 2022/5/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSRewardItemInfo : NSObject
@property(nonatomic, assign)NSInteger Id;
@property(nonatomic, copy)NSString *recordId;
@property(nonatomic, copy)NSString *cid;
@property(nonatomic, copy)NSString *liveId;
@property(nonatomic, copy)NSString *confId;
@property(nonatomic, copy)NSString *giftId;
@property(nonatomic, copy)NSString *giftType;
@property(nonatomic, copy)NSString *giftName;
@property(nonatomic, assign)double giftPrice;
@property(nonatomic, assign)double payPrice;
@property(nonatomic, copy)NSString *openid;
@property(nonatomic, copy)NSString *userId;
@property(nonatomic, copy)NSString *userName;

@property(nonatomic, copy)NSString *createTime;
@property(nonatomic, copy)NSString *updateTime;
@property(nonatomic, copy)NSString *orderId;
@property(nonatomic, copy)NSString *mchId;

@property(nonatomic, assign)NSInteger mchType;
@property(nonatomic, assign)NSInteger status;
@property(nonatomic, assign)NSInteger payType;
@property(nonatomic, assign)NSInteger payResultCode;
@property(nonatomic, copy)NSString *payClientInvokeType;
@property(nonatomic, copy)NSString *appName;

@end

@interface GSRewardData : NSObject
///打赏数量
@property (nonatomic,assign) NSInteger total;
///打赏金额
@property (nonatomic,assign) NSInteger amount;
///打赏单个明细
@property (nonatomic,strong) NSArray<GSRewardItemInfo *> *data;


@end

NS_ASSUME_NONNULL_END
