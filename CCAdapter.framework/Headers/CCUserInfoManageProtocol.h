//
//  CCUserInfoManageProtocol.h
//  CCAdapter
//
//  Created by 张小鱼 on 2019/11/13.
//  Copyright © 2019 jinxiangkun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCMessageInfoManager.h"

NS_ASSUME_NONNULL_BEGIN
@protocol CCUserInfoManageProtocolDelegate <NSObject>

- (void)receiveSyncHistoryMessage:(NSDictionary *)historyMessage;


@end

@interface CCUserInfoManageProtocol : NSObject
@end

NS_ASSUME_NONNULL_END
