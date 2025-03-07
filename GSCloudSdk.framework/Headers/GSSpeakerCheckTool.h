//
//  RTCCheckSpeakerTool.h
//  FineSdk
//
//  Created by 张俞 on 2022/4/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GSSpeakerCheckToolDelegate <NSObject>

/// 检测扬声器的音频文件播放完成
- (void)checkSpeakerAudioFileDidFinishPlaying;

@end

@interface GSSpeakerCheckTool : NSObject
@property (nonatomic, weak) id<GSSpeakerCheckToolDelegate> speakerDelegate;

/// 检测音频文件地址
@property (nonatomic, copy) NSURL * checkFileUrl;
/// 初始化扬声器检测工具
/// @param fileUrl 检测音频文件地址
- (instancetype)initWithCheckSpeakerAudioFileUrl:(NSURL *)fileUrl;
/// 开始播放
- (BOOL)playCheckSpeakerAudioFile;
/// 暂停
- (BOOL)pauseCheckSpeakerAudioFile;
/// 停止
- (BOOL)stopCheckSpeakerAudioFile;
@end

NS_ASSUME_NONNULL_END
