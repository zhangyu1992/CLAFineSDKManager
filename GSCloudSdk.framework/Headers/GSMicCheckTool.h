//
//  GSMicCheckTool.h
//  GSCloudSdk
//
//  Created by 张俞 on 2022/4/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@protocol GSMicCheckToolDelegate <NSObject>

/// 本地麦克风音量值回调（1秒回调一次）
/// @param volume 音量值 在[0,10]之间
- (void)localMicVolumeCallback:(int)volume;

@end
@interface GSMicCheckTool : NSObject
@property (nonatomic, weak) id<GSMicCheckToolDelegate> micDelegate;

/// 开始检测麦克风音量
/// @param handler 返回是否成功开启麦克风检测
- (void)startCheckLocalMicVolumeCompletionHandler:(void(^)(BOOL isSuccess))handler;
/// 停止检测麦克风音量
- (void)stopCheckLocalMicVolume;
@end

NS_ASSUME_NONNULL_END
