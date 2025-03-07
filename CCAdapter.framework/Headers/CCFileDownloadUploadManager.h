//
//  CCFileDownloadUploadManager.h
//  Net263CCLiteDemo_IOS
//
//  Created by XuGuangwei on 15/10/28.
//
//

#import <Foundation/Foundation.h>

extern NSString * const CCResourceFilePath;
extern NSString * const CCResourceResponseObject;
extern NSString * const CCResourceProgress;

extern NSString * const CCFileDownloadUploadManagerProgressNotification;
extern NSString * const CCFileDownloadUploadManagerSuccessNotification;
extern NSString * const CCFileDownloadUploadManagerFailedNotification;

typedef NS_ENUM(unsigned long long, CCResourceManagerType){
    CCResourceManagerType_Picture,
    CCResourceManagerType_Voice,
    CCResourceManagerType_AppDetail,
};

typedef NS_ENUM(unsigned long long, CCResourceManagerBehavior) {
    CCResourceManagerBehavior_Upload,
    CCResourceManagerBehavior_Download,
};

typedef NS_ENUM(unsigned long long, CCResourceManagerResult) {
    CCResourceManagerResult_Wating = (1LL << 0),
    CCResourceManagerResult_Progress = (1LL << 1),
    CCResourceManagerResult_Success = (1LL << 2),
    CCResourceManagerResult_Failed = (1LL << 3),
    CCResourceManagerResult_Error = (1LL << 16),
};

@interface CCResourceManagerItem : NSObject <NSCopying>
@property (nonatomic, strong) NSString *identityID;
@property (nonatomic, strong) NSURL *requestUrl;
@property (nonatomic, strong) id operationObject;
@property (nonatomic, strong) id operation;
@property (nonatomic, strong) NSNumber *type;
@property (nonatomic, strong) NSNumber *behavior;
@property (nonatomic, strong) NSNumber *operationResult;
@property (nonatomic, strong) NSMutableDictionary *otherInfos;
@property (nonatomic, strong) NSError *error;
@property (nonatomic, strong) NSString *filePath;
@property (nonatomic, strong) NSMutableDictionary *httpHeaderInfos;
@property (nonatomic, strong) NSString *resourceFilePath;
@property (nonatomic, strong) NSDate *startDate;
@end

//此类主要用于管理文件的上传与下载
@interface CCFileDownloadUploadManager : NSObject 

+ (CCFileDownloadUploadManager *)shareResourceManagerCenter;

- (void)setPictureServerDomain:(NSString *)pictureServerDomain;
- (void)setOfflineServerDomain:(NSString *)offlineServerDomain;
- (void)setOfflineServerPort:(NSString *)offlineServerPort;
- (void)setOfflineServerPassword:(NSString *)offlineServerPassword;

//下载附件
- (void)downloadAttachmentWithRequest:(NSURLRequest *)request
                             filePath:(NSString *)mFilePath
                             progress:(void (^)(NSUInteger bytesRead,
                                                long long totalBytesRead,
                                                long long totalBytesExpectedToRead))progress
                              success:(void (^)(id operation, id responseObject))success
                              failure:(void (^)(id operation, NSError *error))failure;

//下载图片
- (void)downloadShowPictureFileWithMessage:(id)message;
- (void)downloadBigPictureFileWithMessage:(id)message;
- (void)uploadPictureFileWithMessage:(id)message;

- (void)downloadVoiceFileWithMessage:(id)message;
- (void)uploadVoiceFileWithMessage:(id)message;


@end
