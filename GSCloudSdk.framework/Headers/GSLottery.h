//
//  GSLottery.h
//  GSCloudSdk
//
//  Created by gensee on 2022/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSWinnerVerifyInfo : NSObject
@property (nonatomic, strong) NSString *infoType;  //兑奖名称
@property (nonatomic, strong) NSString *remark;    //兑奖提示
@property (nonatomic, strong) NSString *infoValue; //兑奖值
@end

@interface GSWinner : NSObject
@property (nonatomic, strong) NSString *Id;
@property (nonatomic, strong) NSString *nickname;    //昵称
@property (nonatomic, strong) NSString *moblilePhone;//手机
@property (nonatomic, strong) NSString *raffleId;     //抽奖Id
@property (nonatomic, strong) NSString *sendTime;
@property (nonatomic, strong) NSString *title;        //奖品名称
@property (nonatomic, strong) NSString *userId;       //中奖用户Id
@property (nonatomic, strong) NSString *username;     //中奖用户名
@property (nonatomic, strong) NSString *winnerCode;   //中奖码
@property (nonatomic, copy) NSArray <GSWinnerVerifyInfo *> *winnerVerifyArray; //兑奖信息
@end

//抽奖
@interface GSLotteryDraw : NSObject
@property (nonatomic, strong) NSString *title;           //奖品名称
@property (nonatomic, assign) NSInteger candidatesRange; //参与人员 0-全部 1-未中奖者
@property (nonatomic, strong) NSArray *candidatesUserId; //预中奖用户Id
@property (nonatomic, strong) NSString *luckName;        //预中奖昵称
@property (nonatomic, assign) BOOL needCheck;            //结果是否下发
@property (nonatomic, assign) NSInteger raffleCount;     //预中奖人数
@property (nonatomic, assign) NSArray <GSWinnerVerifyInfo *> *winnerVerifyInfo; //兑奖信息
@end

//中奖
@interface GSLottery : NSObject
@property (nonatomic, strong) NSString *title;           //奖品名称
@property (nonatomic, assign) BOOL isWinner;             //是否有中奖用户
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *Id;                //抽奖Id
@property (nonatomic, copy) NSString *winnerCode;        //中奖码
@property (nonatomic, assign) BOOL resultIssuedStatus;   //结果是否下发
@property (nonatomic, copy) NSArray <GSWinnerVerifyInfo *> *winnerVerifyArray; //中奖信息
@property (nonatomic, strong) NSArray <GSWinner *> *winners; //中奖列表
@end

NS_ASSUME_NONNULL_END
