//
//  RTCRoomInfo.h
//  FineSdk
//
//  Created by 张俞 on 2021/6/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// 会议信息类
@interface RTCRoomInfo : NSObject
/// 房间id
@property (nonatomic, copy) NSString * roomId;
/// 房间名称
@property (nonatomic, copy) NSString * roomName;
/// 主持人id
@property (nonatomic, copy) NSString * compereId;

/// 创建时间
@property (nonatomic, assign) long long createdTime;
/// 创建者id
@property (nonatomic, copy) NSString * initiator;
/// 创建者名字
@property (nonatomic, copy) NSString * initiatorName;

/// 主持人链接
@property (nonatomic, copy) NSString * hostshortlink;
/// 参会人链接
@property (nonatomic, copy) NSString * shortlink;
/// 房间支持的最大分辨率
@property (nonatomic, copy) NSString * resolution;
/// 房间支持的方数
@property (nonatomic, assign) NSInteger partyLimit;


/// 录制状态
@property (nonatomic, assign) BOOL recordStatus;
/// 语音激励状态
@property (nonatomic, assign) BOOL voiceActivatedStatus;
/// 会议室音频权限
@property (nonatomic, assign) BOOL roomAudioAuth;
/// 会议室视频权限
@property (nonatomic, assign) BOOL roomVideoAuth;
/// 会议室共享权限
@property (nonatomic, assign) BOOL roomShareAuth;
/// 会议室发言权限
@property (nonatomic, assign) BOOL roomSpeakAuth;
/// 会议室批注权限
@property (nonatomic, assign) BOOL roomNoteAuth;
/// 会议室加锁
@property (nonatomic, assign) BOOL roomLock;

@end

NS_ASSUME_NONNULL_END
