//
//  AMRAudioRecorder.h
//  AudioQueuePlayerIOS
//
//  Created by yiyimama on 15/9/6.
//  Copyright (c) 2015年 yiyimama. All rights reserved.
//

#ifndef _AMR_AUDIO_RECORDER_H_
#define _AMR_AUDIO_RECORDER_H_



#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>

#import "AMRAudioQueueBase.h"

@class AMRAudioEncoder;

#define NUM_BUFFERS 3

@protocol AMRAudioRecorderDelegate;

typedef struct
{
//  FILE *                      audioFile;
    AudioStreamBasicDescription dataFormat;
    AudioQueueRef               queue;
    AudioQueueBufferRef         buffers[NUM_BUFFERS];
    UInt32                      bufferByteSize;
    SInt64                      currentPacket;
    BOOL                        recording;
    
} RecordState;

@interface AMRAudioRecorder : AMRAudioQueueBase

@property (nonatomic, assign) uint32_t status;
@property (nonatomic, copy  ) NSString * fileAMR;
@property (nonatomic, strong) AMRAudioEncoder * worker;
@property (nonatomic, assign) RecordState * recordState;

/* the delegate will be sent messages from the AudioPlayerDelegate protocol */
@property (nonatomic, weak  ) id<AMRAudioRecorderDelegate> delegate;

- (BOOL) isRecording;
- (double)averagePower;
- (double)peakPower;
- (double)currentTime;
- (BOOL) startRecording:(NSString *)fileAMR;
- (void) stopRecording;
- (void) pause;
- (BOOL) resume;

@end

@protocol AMRAudioRecorderDelegate <NSObject>
@optional

/* audioPlayerCallbackProcess:current: is called playing time in main queue. */
- (void)audioRecorderCallbackProcess:(AMRAudioRecorder *)player current:(double)duration;

/* audioPlayerDidFinishPlaying:successfully: is called when a sound has finished playing.
 This method is NOT called if the player is stopped due to an interruption. */
- (void)audioRecorderDidFinishEncoder:(AMRAudioRecorder *)player successfully:(BOOL)flag;

/* if an error occurs while decoding it will be reported to the delegate. */
//- (void)audioRecorderErrorForEncoder:(AMRAudioRecorder *)player error:(NSError *)error;

@end


#endif //_AMR_AUDIO_RECORDER_H_