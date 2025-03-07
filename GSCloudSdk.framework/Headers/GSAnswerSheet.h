//
//  GSAnswerSheet.h
//  GSCloudSdk
//
//  Created by 胡亚磊 on 2022/5/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSAnswerSheet : NSObject

@end

@interface GSAnswerSheetSubmit : NSObject

@property (nonatomic,assign) long confId;
@property (nonatomic,copy) NSString *webcastTitle;
@property (nonatomic,assign) NSInteger submitCount;
@property (nonatomic,copy) NSString *nickname;
@property (nonatomic,copy) NSString *siteId;
@property (nonatomic,copy) NSString *Id;
@property (nonatomic,assign) long webcastId;
@property (nonatomic,copy) NSString *event;
@property (nonatomic,assign) YBUserRole userRole;
@property (nonatomic,copy) NSString *userId;
@property (nonatomic,copy) NSString *roomId;


@end

NS_ASSUME_NONNULL_END
