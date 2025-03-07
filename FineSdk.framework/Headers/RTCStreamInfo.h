//
//  RTCStreamInfo.h
//  FineSdk
//
//  Created by 张俞 on 2022/5/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCShareStreamInfo : NSObject
///共享流类型 屏幕 、插播
@property (nonatomic, assign) RTCShareStreamType shareStreamType;
///共享流来自那个端
@property (nonatomic, assign) RTCDevicesType shareDeviceType;
///共享人名字
@property (nonatomic, copy) NSString * shareName;

///共享参会人id
@property (nonatomic, copy) NSString * participantId;
/// 是不是自己的流
@property (nonatomic, assign) BOOL isSelf;

- (instancetype)initWithStreamType:(RTCShareStreamType)shareStreamType Plantform:(RTCDevicesType)shareDeviceType Name:(NSString *)shareName ParticipantId:(NSString *)participantId;
@end

NS_ASSUME_NONNULL_END
