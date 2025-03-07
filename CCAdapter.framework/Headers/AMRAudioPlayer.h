//
//  AMRAudioPlayer.h
//  AudioQueuePlayerIOS
//
//  Created by YIYIMAMA on 15/8/31.
//  Copyright (c) 2015年 yiyimama. All rights reserved.
//

#ifndef _AMR_AUDIO_PLAYER_H_
#define _AMR_AUDIO_PLAYER_H_

#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>

#import "AMRAudioQueueBase.h"

@class AMRAudioDecoder;

@protocol AMRAudioPlayerDelegate;

typedef enum
{
    AMRAudioPlayerNone  = (0),
//  AMRAudioPlayerError = (1UL << 0),
    AMRAudioPlayerReady = (1UL << 1),
    AMRAudioPlayerPlay  = (1UL << 2),
    AMRAudioPlayerPause = (1UL << 3),
//  AMRAudioPlayerStop  = (1UL << 4),
    AMRAudioPlayerClose = (1UL << 5),
    
} AMRAudioPlayerStage;

//状态位标记测试宏
#ifndef AddBits
#define AddBits(status,flags) \
(uint32_t)((uint32_t)status|(uint32_t)flags)
#endif
#ifndef DelBits
#define DelBits(status,flags) \
(uint32_t)((uint32_t)status&(~(uint32_t)flags))
#endif
#ifndef HasBits
#define HasBits(status,flags) \
((uint32_t)flags==((uint32_t)status&(uint32_t)flags))
#endif

@interface AMRAudioPlayer : AMRAudioQueueBase

@property (nonatomic, assign) long long status;
@property (nonatomic, copy  ) NSString * fileAMR;
@property (nonatomic, strong) NSData * fileData;
@property (nonatomic, strong) AMRAudioDecoder * decoder;

+ (AMRAudioPlayer *)shareAMRAudioPlayer;

- (instancetype)initWithContentsOfFile:(NSString *)file error:(NSError **)outError;
- (instancetype)initWithContentsFileData:(NSData *)data error:(NSError **)outError;

/* methods that return BOOL return YES on success and NO on failure. */

- (BOOL)prepareToPlay;	/* get ready to play the sound. happens automatically on play. */
- (BOOL)play;			/* sound is played asynchronously. */
- (BOOL)playAtSecond:(int32_t)second; /* play a sound some time in the future. time is an second.*/
- (BOOL)pause;			/* pauses playback, but remains ready to play. */
- (BOOL)stop;			/* stops playback. no longer ready to play. */

@property (nonatomic, readonly, getter=isPlaying) BOOL playing; /* is it playing or not? */

@property (nonatomic, readonly) NSUInteger numberOfChannels;

@property (nonatomic, readonly) double duration; /* the duration of the second. */

/* the delegate will be sent messages from the AudioPlayerDelegate protocol */
@property (nonatomic, weak  ) id<AMRAudioPlayerDelegate> delegate;

- (void)setVolume:(float)vol; //编码音量 0-1.0
- (float)getVolume;

- (void)setScale:(float)scale; //音量放大倍数 1.0-4.0
- (float)getScale;

- (void)closeForRelease;

@end

@protocol AMRAudioPlayerDelegate <NSObject>
@optional

// 中断开始时，如果播放就暂停，中断结束时，继续播放；
- (void)audioPlayerHandleShouldPaused:(AMRAudioPlayer *)player; //notification
- (void)audioPlayerHandleShouldPlaying:(AMRAudioPlayer *)player; //notification

/* audioPlayerCallbackProcess:current: is called playing time in main queue. */
- (void)audioPlayerCallbackProcess:(AMRAudioPlayer *)player current:(double)duration;

/* audioPlayerDidFinishPlaying:successfully: is called when a sound has finished playing. 
    This method is NOT called if the player is stopped due to an interruption. */
- (void)audioPlayerDidFinishPlaying:(AMRAudioPlayer *)player successfully:(BOOL)flag;

/* if an error occurs while decoding it will be reported to the delegate. */
- (void)audioPlayerDecodeErrorDidOccur:(AMRAudioPlayer *)player error:(NSError *)error;

@end

#endif //_AMR_AUDIO_PLAYER_H_
