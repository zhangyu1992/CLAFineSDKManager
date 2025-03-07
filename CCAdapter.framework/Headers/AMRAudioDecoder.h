//
//  AMRAudioDecoder.h
//  AudioQueuePlayerAMR
//
//  Created by YIYIMAMA on 15/8/28.
//  Copyright (c) 2015年 yiyimama. All rights reserved.
//

#ifndef _AMR_AUDIO_DECODER_H_
#define _AMR_AUDIO_DECODER_H_



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

@interface AMRAudioDecoder : NSObject

@property (nonatomic, assign) FILE *    file;
@property (nonatomic, assign) AMRFileType type;

@property (nonatomic, strong) NSData *  bytes;
@property (nonatomic, assign) int       currentPos;

@property (nonatomic, assign) void *    amr;
@property (nonatomic, assign) int       dtx;
@property (nonatomic, assign) int       mode; //= MR122;

@property (nonatomic, assign) int       format; //SInt16
@property (nonatomic, assign) int       sampleRate; //AMR_SAMPLE_RATE
@property (nonatomic, assign) int       channels; //AMR_NUM_CHANNELS
@property (nonatomic, assign) int       bitsPerSample; //AMR_BITS_PER_CHANNELS

@property (nonatomic, strong) NSRecursiveLock * lock;
@property (nonatomic, strong) AudioMemoryQueue * memoryQueue;
@property (nonatomic, assign) uint8_t * outputBuffer;
@property (nonatomic, assign) int       outputBufferSize;

@property (nonatomic, assign) float     volume; //编码音量 0-1.0
@property (nonatomic, assign) float     scale;  //音量放大倍数 1.0-4.0
@property (nonatomic, assign) uint64_t	totalLength;
@property (nonatomic, assign) double	totalDuration;

- (BOOL)decoderAMRFile:(NSString *)fileAMR; //1
- (BOOL)decoderAMRData:(NSData *)fileData; //1
- (int)render:(UInt8*)intoBuffer number:(UInt32)inNumBytes; //2
- (void)closeDecoderAMRFile; //3
- (void)closeDecoderAMRData; //3

- (int)seekToSecond:(int)second;

- (NSString *)currentTimeString;
- (double)currentTime; //秒

@end

#endif //_AMR_AUDIO_DECODER_H_