//
//  MtShareMediaModel.h
//  CCAdapter
//
//  Created by 张俞 on 2021/8/24.
//  Copyright © 2021 jinxiangkun. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef enum : NSUInteger {
    MTPlayStatusInDownload = 0,// 下载中
    MTPlayStatusReady = 1,// 准备好
    MTPlayStatusPlay = 2,// 播放
    MTPlayStatusPause = 3,// 暂停
    MTPlayStatusStop = 4,// 停止
    MTPlayStatusError = 5,// 异常
} MTPlayStatus;

typedef enum : NSUInteger {
    MTMediaAction_play,
    MTMediaAction_pause,
    MTMediaAction_resume,
    MTMediaAction_stop,
    MTMediaAction_stoplive,
    MTMediaAction_seek,
} MTMediaAction;

NS_ASSUME_NONNULL_BEGIN
@interface MtShareMediaRecordsModel : NSObject
/// 某个插播件地址
@property (nonatomic,copy) NSString * url;
/// 某个插播件文件名称
@property (nonatomic,copy) NSString * name;
/// 某个插播件ID
@property (nonatomic,copy) NSString * fileId;


@end
@interface MtShareMediaInfo : NSObject
/// 某个插播件id
@property (nonatomic,copy) NSString * fileId;
/// 某个插播件地址
@property (nonatomic,copy) NSString * url;
/// 某个插播件文件名称
@property (nonatomic,copy) NSString * name;
///  插播件总时长，单位ms,其中0表示还未获取到（下载中），ffffffffffffff为文件解析异常
@property (nonatomic,assign) NSInteger duration;
/// 播放状态，0表示准备中，还在下载中，1表示准备好了可以播放，2表示播放，3表示暂停，4表示停止，5表示异常
@property (nonatomic,assign) MTPlayStatus status;


/// 表示records列表中的第几个立即播放，如果和当前播放相同则继续播放，否则停止前面的，从这个开始播放
@property (nonatomic,assign) int nowplayseq;
/// "looporder":[1,2,3],循环顺序，0，1，2表示对应records的顺序
@property (nonatomic,copy) NSArray * looporder;

/// <0表示无限循环，0表示不开启不开启列表循环，其它值表示循环次数
@property (nonatomic,assign) int totalloopnum;
/// 是否有视频
@property (nonatomic,assign) BOOL haveVideo;
/// 当前的播放进度
@property (nonatomic,assign) NSInteger timestamp;
/// owner   - uid
@property (nonatomic,copy) NSString * owneruid;
/// owner   - cid
@property (nonatomic,copy) NSString * ownercid;

@end
@interface MtShareMediaModel : NSObject

@property (nonatomic, strong) MtShareMediaInfo * playingMediaInfo;

/// 对应的操作 play pause resume stop
@property (nonatomic,assign) MTMediaAction action;
/// 某个插播件地址
@property (nonatomic,copy) NSString * recordurl;
///  uint64，偏移时间点，该时间点相对于该文件开始0时刻的ms数 
@property (nonatomic,assign) NSInteger seektime;

/// 插播件列表(保存MeetShareMediaRecordsModel对象)
@property (nonatomic,copy) NSArray * records;
/// 表示records列表中的第几个立即播放，如果和当前播放相同则继续播放，否则停止前面的，从这个开始播放
@property (nonatomic,assign) int nowplayseq;
/// "looporder":[1,2,3],循环顺序，0，1，2表示对应records的顺序
@property (nonatomic,copy) NSArray * looporder;

/// <0表示无限循环，0表示不开启不开启列表循环，其它值表示循环次数
@property (nonatomic,assign) int totalloopnum;

/// uint32,递增，循环（超出上限后从0开始)表明某次请求，回复也会返回该值
@property (nonatomic,assign) NSInteger seqid;

@end



NS_ASSUME_NONNULL_END
