//
//  CCModelKeyUtility.h
//  CCAdapterUI
//
//  Created by yiyimama on 2017/6/6.
//  Copyright © 2017年 yiyimama. All rights reserved.
//

#import <Foundation/Foundation.h>

// CachedUserList
// 缓存用户数量超出从后面移除，常选中的往前移动
// 选中的部门缓存数据库的用户，选中用户的联网查询的用户

#define MySafeString(idStr) (idStr?idStr:@"")

// 是否是用户缓存key
#define MyCachedIsUserKey(strKey) \
[CCModelKeyUtility isUserCachedKey:(id)strKey]
// 是否是组织缓存key
#define MyCachedIsDeptKey(strKey) \
[CCModelKeyUtility isDepartmentCachedKey:(id)strKey]

// 创建用户缓存key
#define MyCachedUserKey(idStr,cidStr) \
(MyCachedStringKey(idStr,cidStr,CCItemInfoTypeUser))
// 创建组织缓存key
#define MyCachedDeptKey(idStr,cidStr) \
(MyCachedStringKey(idStr,cidStr,CCItemInfoTypeDepart))

// 获得第一项的缓存值
#define MyCachedFirstSubitem(strKey) \
[CCModelKeyUtility getFirstItemWithCachedKey:(id)strKey]
// 获得第二项的缓存值
#define MyCachedSecondSubitem(strKey) \
[CCModelKeyUtility getSecondItemWithCachedKey:(id)strKey]
// 获得第三项的缓存值
#define MyCachedThirdSubitem(strKey) \
[CCModelKeyUtility getThirdItemWithCachedKey:(id)strKey]
// 获得第四项的缓存值
#define MyCachedFourthSubitem(strKey) \
[CCModelKeyUtility getFourthItemWithCachedKey:(id)strKey]
// 获得第五项的缓存值
#define MyCachedFiftehSubitem(strKey) \
[CCModelKeyUtility getFiftehItemWithCachedKey:(id)strKey]

// 创建群组缓存key
#define MyCachedGroupKey(idStr,cidStr) \
(MyCachedStringKey(idStr,cidStr,CCItemInfoTypeGroup))
// 创建群组用户缓存key
#define MyCachedGroupUserKey(idStr,cidStr,uidStr,ucidStr) \
(MyCachedItemStringKey(idStr,cidStr,uidStr,ucidStr,CCItemInfoTypeUser))

// 创建群组缓存key iType = CCItemInfoType
#define MyCachedStringKey(idStr,cidStr,iType) \
([NSString stringWithFormat:@"%@::%@::%d", \
MySafeString(idStr), MySafeString(cidStr), (int)iType]) //CCItemInfoType

// 创建群组缓存key iType = CCItemInfoType
#define MyCachedItemStringKey(idStr,cidStr,uidStr,ucidStr,iType) \
([NSString stringWithFormat:@"%@::%@::%@::%@::%d", \
MySafeString(idStr), MySafeString(cidStr), \
MySafeString(uidStr), MySafeString(ucidStr), (int)iType]) //CCItemInfoType

@interface CCModelKeyUtility : NSObject

+ (BOOL)isUserCachedKey:(NSString *)strKey;
+ (BOOL)isDepartmentCachedKey:(NSString *)strKey;

// 找出节点字符串
+ (NSString *)getFirstItemWithCachedKey:(NSString *)strKey;
+ (NSString *)getSecondItemWithCachedKey:(NSString *)strKey;
+ (NSString *)getThirdItemWithCachedKey:(NSString *)strKey;
+ (NSString *)getFourthItemWithCachedKey:(NSString *)strKey;
+ (NSString *)getFiftehItemWithCachedKey:(NSString *)strKey;

@end

