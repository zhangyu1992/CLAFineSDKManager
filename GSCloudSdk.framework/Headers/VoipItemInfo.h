//
//  VoipItemInfo.h
//  GSCloudSdk
//
//  Created by leo on 2022/5/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VoipItemInfo : NSObject
///用户cid
@property(nonatomic,copy)NSString *cid;
///用户id
@property(nonatomic,copy)NSString *uid;
///连麦状态
@property(nonatomic,assign)NSInteger status;
///用户名称
@property(nonatomic,copy)NSString *name;
@property(nonatomic,copy)NSString *chatRoomId;
@property(nonatomic,copy)NSString *roomDev;
///用户token
@property(nonatomic,copy)NSString *token;
@property(nonatomic,copy)NSString *sid;
@property(nonatomic,copy)NSString *yushiLoginName;
@property(nonatomic,copy)NSString *markType;
@property(nonatomic,copy)NSString *roomUid;
///用户头像
@property(nonatomic,copy)NSString *headImgUrl;
///用户设备
@property(nonatomic,assign)NSInteger device;
///用户加入时间
@property(nonatomic,assign)NSInteger joinTime;
///用户申请连麦时间
@property(nonatomic,assign)NSInteger applyTime;

@end

NS_ASSUME_NONNULL_END
