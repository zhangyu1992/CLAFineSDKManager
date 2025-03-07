//
//  GSLayoutCheckInfo.h
//  GSCloudSdk
//
//  Created by leo on 2022/4/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSLayoutUserInfo : NSObject
///选择的视频源位置 GSRegion id
@property (nonatomic,copy) NSString *Id;
///视频源名字
@property (nonatomic,copy) NSString *name;
///视频源userid
@property (nonatomic,copy) NSString *uid;
///视频源cid
@property (nonatomic,copy) NSString *cid;
///视频源头像
@property (nonatomic, copy) NSString *imageUrl;
///视频源占位图
@property (nonatomic, copy) NSString *placehold_img;
///共享布局默认"forward" 视频布局不需要
@property (nonatomic, copy) NSString *targetType;

@end

@interface GSLayoutCheckInfo : NSObject
///选择的共享布局id
@property (nonatomic,copy) NSString *commonId;
///选择的视频布局id
@property (nonatomic,copy) NSString *videoId;
///视频布局的视频源
@property (nonatomic, strong)NSArray<GSLayoutUserInfo *> *meetingUser;
///共享布局的视频源
@property (nonatomic, strong)NSArray<GSLayoutUserInfo *> *screenSharingUser;

@end

NS_ASSUME_NONNULL_END
