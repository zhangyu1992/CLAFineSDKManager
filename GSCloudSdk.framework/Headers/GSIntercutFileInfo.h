//
//  GSIntercutFileInfo.h
//  GSCloudSdk
//
//  Created by 胡亚磊 on 2022/4/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSIntercutFileResource : NSObject

@property (nonatomic,copy) NSString *fileId;
@property (nonatomic,copy) NSString *filename;
@property (nonatomic,copy) NSString *cid;
@property (nonatomic,copy) NSString *ct;
@property (nonatomic,copy) NSString *fileSuffix;
@property (nonatomic,assign) int resourceEnities_id;
@property (nonatomic,assign) long roomId;
@property (nonatomic,assign) long size;
@property (nonatomic,assign) int source;
@property (nonatomic,copy) NSString *srcFileId;
@property (nonatomic,assign) int status;
@property (nonatomic,copy) NSString *transFileId;
@property (nonatomic,assign) int type;
@property (nonatomic,copy) NSString* uid;
@property (nonatomic,copy) NSString *uploaderName;
@property (nonatomic,copy) NSString *ut;

@end

@interface GSIntercutFileInfo : NSObject

@property (nonatomic,copy) NSString *resource_id;
@property (nonatomic,assign) int publish;
@property (nonatomic,assign) int publishTime;
@property (nonatomic,assign) int bindType;
@property (nonatomic,strong) NSDictionary *record;
@property (nonatomic,strong) GSIntercutFileResource* resource;

@end

@interface GSIntercutPlayingRecords :NSObject

@property (nonatomic,copy) NSString *url;
@property (nonatomic,copy) NSString *name;
@property (nonatomic,copy) NSString *Id;

-(instancetype)initRecordsWithDict:(NSDictionary*)dict;

@end

@interface GSIntercutPlayingFileInfo : NSObject

@property (nonatomic,strong) NSMutableArray<GSIntercutPlayingRecords*> *records;
/// 表示records列表中的第几个立即播放，如果和当前播放相同则继续播放，否则停止前面的，从这个开始播放
@property (nonatomic,assign) NSInteger nowplayseq;
/// "looporder":[1,2,3],循环顺序，0，1，2表示对应records的顺序
@property (nonatomic,strong) NSMutableArray *looporder;
/// <0表示不开启列表循环，-1 为循环播放  其它值表示循环次数
@property (nonatomic,assign) NSInteger totalloopnum;
@property (nonatomic,assign) YBIntercutFileStatus status;
@property (nonatomic,assign) long duration; //时长 单位 ms
@property (nonatomic,assign) long long timestamp;
@property (nonatomic,assign) bool havevedio;
@property (nonatomic,copy) NSString *owneruid;
@property (nonatomic,copy) NSString *ownercid;

/// uint32,递增，循环（超出上限后从0开始)表明某次请求，回复也会返回该值
@property (nonatomic,assign) NSInteger seqid;

@end

@interface GSIntercutPlayingFileChangeInfo :NSObject

@property (nonatomic,assign) YBIntercutFileStatus action;
@property (nonatomic,copy) NSString *actionCid;
@property (nonatomic,copy) NSString *actionUid;
@property (nonatomic,copy) NSString *cmd;
@property (nonatomic,copy) NSString *confid;
@property (nonatomic,assign) bool havevedio;
@property (nonatomic,strong) GSIntercutPlayingFileInfo *playinfo;
@property (nonatomic,copy) NSString *url;


@end


NS_ASSUME_NONNULL_END
