//
//  AudioMemoryQueue.h
//  AMRAudioRecording
//
//  Created by YIYIMAMA on 15/8/27.
//
//

#ifndef _AUDIO_MEMORY_QUEUE_H_
#define _AUDIO_MEMORY_QUEUE_H_

#import <Foundation/Foundation.h>

typedef struct
{
    UInt32    size;
    UInt8 *   head;
    UInt8 *   tail;
    UInt8 *   data;
    UInt8 *   last;
    UInt32    length;
    
} MemoryQueue;

@interface AudioMemoryQueue : NSObject

@property (nonatomic, assign) MemoryQueue data;
@property (nonatomic, strong) NSRecursiveLock * lock;

- (instancetype)initWithQueueSize:(UInt32)queueSize;

- (UInt32)enqueue:(UInt8 *)srcBuffer len:(UInt32)length;
- (UInt32)dequeue:(UInt8 *)destBuffer len:(UInt32)length;
- (void)emptyBufferQueue;

- (UInt32)queueLength;

@end

#endif