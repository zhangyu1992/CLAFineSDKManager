//
//  AMRAudioEncoder.h
//  AMRAudioRecording
//
//  Created by YIYIMAMA on 15/8/28.
//
//

#ifndef _AMR_AUDIO_ENCODER_H_
#define _AMR_AUDIO_ENCODER_H_

#import <CoreAudio/CoreAudioTypes.h>

#include "AudioMemoryQueue.h"

//enum Mode;

#ifndef AMR_FILE_TYPE
#define AMR_FILE_TYPE
typedef enum
{
    AMRFileTypeNone = 0,
    AMRFileTypeAMRNB = 1,
    AMRFileTypeAMRWB = 2
    
} AMRFileType;
#endif

@interface AMRAudioEncoder : NSObject

@property (nonatomic, assign) FILE *    file;
@property (nonatomic, assign) void *    amr;
@property (nonatomic, assign) int       dtx;
@property (nonatomic, assign) int       mode; //= MR122;
@property (nonatomic, assign) int       bytes;

@property (nonatomic, assign) int       format; //SInt16
@property (nonatomic, assign) int       sampleRate; //AMR_SAMPLE_RATE
@property (nonatomic, assign) int       channels; //AMR_NUM_CHANNELS
@property (nonatomic, assign) int       bitsPerSample; //AMR_BITS_PER_CHANNELS

@property (nonatomic, assign) float     volume; //编码音量 0-1.0
@property (nonatomic, assign) float     scale;  //音量放大倍数 1.0-4.0
@property (nonatomic, assign) uint64_t	totalLength;
@property (nonatomic, assign) double	totalDuration;

@property (nonatomic, strong) NSRecursiveLock * lock;
@property (nonatomic, strong) AudioMemoryQueue * memoryQueue;

@property (nonatomic, assign) uint8_t * inputBuffer;
@property (nonatomic, assign) int       inputBufferSize;

- (instancetype)initWithInputFormat:(AudioStreamBasicDescription)inputFormat;

- (FILE *)encoderAMRFile:(NSString *)fileAMR; //1
- (int)enqueueEncoderData:(NSData *)pcm; //2
- (void)closeEncoderAMRFile; //3

- (NSString *)currentTimeString;
- (double)currentTime; //秒

@end

#endif //_AMR_AUDIO_INFO_H_