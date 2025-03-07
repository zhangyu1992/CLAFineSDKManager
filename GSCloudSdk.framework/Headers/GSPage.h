//
//  GSPage.h
//  GSCloudSdk
//
//  Created by leo on 2022/11/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSPageContent : NSObject

@property (nonatomic,copy) NSString *file;
@property (nonatomic,copy) NSString *origin;
@property (nonatomic,copy) NSString *small;
@property (nonatomic,assign) NSInteger heigh;
@property (nonatomic,assign) NSInteger pageno;
@property (nonatomic,assign) NSInteger title;
@property (nonatomic,assign) NSInteger width;

@end

@interface GSPageInfo : NSObject

@property (nonatomic,strong)GSPageContent *page;

@end


@interface GSPage : NSObject
/// 当前文档id
@property (nonatomic,assign) NSInteger filehandle;
@property (nonatomic,copy) NSString *flag;
/// 当前文档名称
@property (nonatomic,copy) NSString *name;
/// 页码前缀
@property (nonatomic,copy) NSString *pageUrl;

@property (nonatomic,strong) NSMutableArray<GSPageInfo *> *pageinfo;


@end

NS_ASSUME_NONNULL_END
