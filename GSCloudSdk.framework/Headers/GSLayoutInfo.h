//
//  GSLayoutInfo.h
//  GSCloudSdk
//
//  Created by leo on 2022/4/26.
//

#import <Foundation/Foundation.h>
@class GSLayout;
@class GSLayoutConten;
@class bgColor;
@class GSLayoutTypeContent;
@class GSRegion;
@class GSLayoutUser;
NS_ASSUME_NONNULL_BEGIN
@interface GSLayoutInfo : NSObject
@property (nonatomic,assign) NSInteger Id;///ID
@property (nonatomic,copy) NSString *layoutName;///布局名称
@property (nonatomic,copy) NSString *roomId;///会议id
@property (nonatomic,copy) NSString *layoutJson;///布局详细信息
@property (nonatomic,assign) NSInteger layoutType;
@property (nonatomic,assign) NSInteger layoutCheck;///布局是否选中
@property (nonatomic,assign) NSInteger layoutVersion;
@property (nonatomic,copy) NSString *createTime;
@property (nonatomic,copy) NSString *updateTime;
@property (nonatomic,copy) NSString *ext1; ///占位图
@property (nonatomic,copy) NSString *ext2;
@property (nonatomic,copy) NSString *ext3;
@property (nonatomic,assign) NSInteger weight;
@property (nonatomic,assign) NSInteger layoutJsonVersion;
@property (nonatomic,strong) GSLayout *layout; ///布局详细信息
@end

@interface GSLayout : NSObject
@property (nonatomic,strong) GSLayoutConten *layout;
@end

@interface GSLayoutConten : NSObject
@property (nonatomic,strong) bgColor *bgColor;
@property (nonatomic,copy) NSString *bgPicture;
@property (nonatomic, strong) GSLayoutTypeContent *typeContent;
@end

@interface  GSLayoutTypeContent: NSObject
@property (nonatomic, strong) bgColor *bgColor;
@property (nonatomic, copy) NSString *Id;
@property (nonatomic, copy) NSString *bgPicture;
@property (nonatomic, strong) NSArray<GSRegion *> *region;
@end

@interface bgColor : NSObject
@property (nonatomic,assign) NSInteger r;
@property (nonatomic,assign) NSInteger g;
@property (nonatomic,assign) NSInteger b;
@end

@interface  GSArea: NSObject
@property (nonatomic, copy) NSString *top;
@property (nonatomic, copy) NSString *left;
@property (nonatomic, copy) NSString *width;
@property (nonatomic, copy) NSString *height;
@end

@interface  GSRegion: NSObject ///位置
@property (nonatomic, strong) GSArea *area;
@property (nonatomic, copy) NSString *shape;
@property (nonatomic, copy) NSString *Id;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, strong) GSLayoutUser *user;
@end

@interface  GSLayoutUser: NSObject ///视频源对象
///视频源名字
@property (nonatomic,copy) NSString *name;
///视频源userid
@property (nonatomic,copy) NSString *uid;
///视频源cid
@property (nonatomic,copy) NSString *cid;
///视频源头像地址
@property (nonatomic,copy) NSString *imageUrl;

@end


NS_ASSUME_NONNULL_END
