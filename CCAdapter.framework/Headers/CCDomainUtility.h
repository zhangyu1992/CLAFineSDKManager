//
//  CCDomainUtility.h
//  Net263CCLite_IOS
//
//  Created by yiyimama on 16/11/19.
//  Copyright © 2016年 net263. All rights reserved.
//

#import "CCRuntime.h"


#define CCRandomAddress(domain) \
[CCNameSpace(EMDomainResolve) \
    addressString:(NSString *)domain \
        random:(BOOL)YES]

@interface CCNameSpace(CCDomainUtility) : NSObject

// 返回一个IP地址列表，输入域名
+ (NSMutableArray *)addressList:(NSString *)domain;

// 返回一个IP地址，默认第一个
+ (NSString *)addressString:(NSString *)domain;

// 返回一个IP地址，随机选择
+ (NSString *)addressString:(NSString *)domain random:(BOOL)random;


@end
