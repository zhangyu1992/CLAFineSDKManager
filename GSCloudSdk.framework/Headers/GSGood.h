//
//  Goods.h
//  GSCloudSdk
//
//  Created by gensee on 2022/3/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSGood : NSObject
@property(nonatomic, copy) NSString *categoryId;
@property(nonatomic, copy) NSString *categoryName;
@property(nonatomic, assign) NSInteger count;
@property(nonatomic, copy) NSString *desc;
@property(nonatomic, copy) NSString *ext1;
@property(nonatomic, copy) NSString *ext2;
@property(nonatomic, copy) NSString *ext3;
@property(nonatomic, copy) NSString *goodsId;
@property(nonatomic, assign) NSInteger goodsOrder;
@property(nonatomic, copy) NSString *icon;
@property(nonatomic, copy) NSString *iconFile;
@property(nonatomic, assign) BOOL isPush;
@property(nonatomic, copy) NSString *miniProgramId;
@property(nonatomic, copy) NSString *miniProgramPath;
@property(nonatomic, copy) NSString *name;
@property(nonatomic, assign) NSInteger ownership;
@property(nonatomic, copy) NSString *price;
@property(nonatomic, assign) NSInteger publishStatus;
@property(nonatomic, copy) NSString *publishStatusText;
@property(nonatomic, copy) NSString *publishTime;
@property(nonatomic, assign) BOOL pushing;
@property(nonatomic, copy) NSString *salePrice;
@property(nonatomic,assign) BOOL shelvesStatus;
@property(nonatomic, copy) NSString *source;
@property(nonatomic, copy) NSString *sourceGoodsId;
@property(nonatomic, copy) NSString *tag1;
@property(nonatomic, copy) NSString *tag2;
@property(nonatomic, copy) NSString *tag3;
@property(nonatomic, copy) NSString *triggerName;
@property(nonatomic, copy) NSString *updateTime;
@property(nonatomic, copy) NSString *webUrl;
@end

@interface GSGoodsTags : NSObject
@property(nonatomic, copy) NSString *createTime;
@property(nonatomic, copy) NSString *ext1;
@property(nonatomic, copy) NSString *ext2;
@property(nonatomic, copy) NSString *ext3;
@property(nonatomic, copy) NSString *goodsId;
@property(nonatomic, copy) NSString *name;
@property(nonatomic, copy) NSString *tagId;
@property(nonatomic,assign)NSInteger Id;
@property(nonatomic, copy) NSString *updateTime;
@end

NS_ASSUME_NONNULL_END
