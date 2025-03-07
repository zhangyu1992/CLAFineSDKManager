//
//  RTMGroupInfoModel.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/6/28.
//

#import <Foundation/Foundation.h>
#import <FineSdk/RTMGroupUserInfoModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTMGroupInfoModel : NSObject

@property (nonatomic,copy) NSString * gid; //群ID
@property (nonatomic,copy) NSString * cid; //群客户ID
@property (nonatomic,copy) NSString * name; //群名字

@property (nonatomic,assign) NSInteger auth;// 入群权限
@property (nonatomic,assign) NSInteger sort; //排序值
@property (nonatomic,assign) NSInteger audio; //音频权限
@property (nonatomic,assign) NSInteger video; //视频权限
@property (nonatomic,assign) NSInteger share; //共享权限
@property (nonatomic,assign) NSInteger note; //批注权限
@property (nonatomic,assign) NSInteger speak; //发言权限

@property (nonatomic,copy) NSString * topic; //群公告
@property (nonatomic,assign) NSInteger maxnumber; //最大人数
@property (nonatomic,assign) NSInteger currentnumber; //当前人数
@property (nonatomic,assign) long long createtime; //创建时间，单位是毫秒
@property (nonatomic,assign) long long updatetime; //更新时间，单位是毫秒
@property (nonatomic, strong) NSMutableDictionary *userInfos; //群成员信息


@end

NS_ASSUME_NONNULL_END
