//
//  GSDoc.h
//  GSCloudSdk
//
//  Created by gensee on 2022/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSWhiteBoardPage : NSObject

@property (nonatomic,copy) NSString *Id;
@property (nonatomic,copy) NSString *cid;
@property (nonatomic,copy) NSString *createTime;
@property (nonatomic,assign) NSInteger page;
@property (nonatomic,copy) NSString *roomId;
@property (nonatomic,assign) NSInteger state;
@property (nonatomic,copy) NSString *title;
@property (nonatomic,copy) NSString *uid;
@property (nonatomic,copy) NSString *updateTime;
@property (nonatomic,copy) NSString *whiteBoardId;

- (instancetype)initWithDict:(NSDictionary*)dict;

@end

@interface GSDocResource : NSObject
@property (nonatomic, copy) NSString *cid;
@property (nonatomic, copy) NSString *ct;
@property (nonatomic, copy) NSString *fileId;
@property (nonatomic, copy) NSString *fileSuffix;
@property (nonatomic, copy) NSString *filename;      //文档名称
@property (nonatomic, copy) NSString *resourceEnities_id;
@property (nonatomic, copy) NSString *roomId;

@property (nonatomic, assign) NSInteger size;        //文档大小
@property (nonatomic, assign) NSInteger source;
@property (nonatomic, copy) NSString *srcFileId;
@property (nonatomic, assign) NSInteger status;      //转码状态 0: 未上传, 1: 上传成功, 2: 上传失败, 3: 上传中, 4: 转码中, 5: 转码成功, 6: 转码失败
@property (nonatomic, copy) NSString *transFileId;
@property (nonatomic, assign) NSInteger type;        //0: 共享文档;1: 插播文件
@property (nonatomic, copy) NSString *uid;
@property (nonatomic, copy) NSString *uploaderName;
@property (nonatomic, copy) NSString *ut;
@property (nonatomic,assign) NSInteger currentUploadSize;//当前上传进度

@end

@interface GSDoc : NSObject
@property (nonatomic, copy) NSString *webUrl;        //文档url
@property (nonatomic, copy) NSString *jsonStr;       //操作相关
@property (nonatomic, copy) NSString *InitJsonStr;   //初始化

@property (nonatomic, assign) NSInteger bindType;    //绑定状态，1-默认绑定到场次  2-绑定到高直播和场次
@property (nonatomic, assign) BOOL publish;          //发布状态
@property (nonatomic, copy) NSString *publishTime;
@property (nonatomic, copy) NSString *resource_id;    //文档资源Id
@property (nonatomic, strong) GSDocResource *resource;
@property(nonatomic, copy) NSString *shareId;         //共享id

//白板使用
@property (nonatomic,assign) NSInteger effCount;//白板总数量
@property (nonatomic,assign) NSInteger page;    //当前页码
@property (nonatomic,copy) NSString *  pageId;
@property (nonatomic,strong) NSMutableArray<GSWhiteBoardPage*> *whiteBoardPagesArray;

@property (nonatomic,copy) NSString *sharePageId;    //当前共享的pageId
@property (nonatomic,assign) NSInteger index;    //当前页码


@end


NS_ASSUME_NONNULL_END
