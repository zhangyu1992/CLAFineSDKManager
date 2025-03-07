//
//  GSGoodEvent.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 *商品相关回调
 */
@protocol GSGoodEvent <NSObject>
/**
 *商品上架推送(bool isPub,GSGood)
 */
-(void)onGoodPublish:(BOOL)isPub goods:(GSGood *)goods;

/**
 *商品变化onGoodChange()
 */
-(void)onGoodChange:(YBGoodsLiveStatusChange)status goodsId:(NSString*)goodsId;

@end

NS_ASSUME_NONNULL_END
