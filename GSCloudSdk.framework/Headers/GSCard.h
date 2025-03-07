//
//  GSCard.h
//  GSCloudSdk
//
//  Created by gensee on 2022/3/24.
//

#import <Foundation/Foundation.h>
@class GSCardOption;
@class GSCardResult;
@class GSUserSubmitAnswers;
NS_ASSUME_NONNULL_BEGIN

@interface GSCard : NSObject
@property (nonatomic, strong) NSString *answerSheetTitle;
@property (nonatomic, assign) NSInteger duration;
@property (nonatomic, strong) NSMutableArray<GSCardOption*> *options;
@property (nonatomic, strong) NSString *questionType; //单选 多选  评分 投票
@property (nonatomic, strong) NSMutableArray *rightAnswers; //正确答案
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) GSCardResult *cardResult;
@property (nonatomic,strong) GSUserSubmitAnswers *userSubmitAnswers;
@end

@interface GSCardOption : NSObject
@property (nonatomic, strong) NSString *item;
@property (nonatomic, strong) NSString *number;
@property (nonatomic, assign)BOOL isSelected;
@end

@interface GSCardOptionSelectInfo : NSObject
@property (nonatomic, strong) NSString *number;
@property (nonatomic, strong) NSString *item;
@property (nonatomic, strong) NSString *selectCount;
@property (nonatomic, strong) NSString *selectPeoplePercent;
@end

@interface GSCardAnswerStatistics : NSObject
@property (nonatomic, strong) NSString *answerCorrectPercent;
@property (nonatomic, strong) NSArray *rightAnswers;
@property (nonatomic, assign) long answerCorrectCount;
@property (nonatomic, strong) NSString *averageScore;
@end

@interface GSCardResult : NSObject
@property (nonatomic, assign) BOOL hasRightAnswer;
@property (nonatomic, assign) NSInteger answerPeopleCount;
@property (nonatomic, strong) GSCardAnswerStatistics *answerStatistics;
@property (nonatomic, strong) NSString *questionType;
@property (nonatomic, strong) NSString *questionTitle;
@property (nonatomic, strong) NSArray<GSCardOptionSelectInfo*>  *optionSelectInfoList;
@end

@interface GSCardListInfo : NSObject

@property (nonatomic, assign) long webcastAnswerSheetId;
@property (nonatomic, copy) NSString *answerSheetTitle;
@property (nonatomic, assign) long questionId;
@property (nonatomic, assign) long confAnswerSheetId;
@property (nonatomic, assign) YBAnswerSheetStatus answerSheetState;
@property (nonatomic, assign) YBAnswerSheetStatus answerSheetStateV2;

@end

@interface GSCardInfoDetail : GSCard
@property (nonatomic, assign) long webcastAnswerSheetId;
@property (nonatomic, assign) long questionId;
@property (nonatomic, assign) YBAnswerSheetStatus answerSheetState;
@property (nonatomic, assign) YBAnswerSheetStatus answerSheetStateV2;
@property (nonatomic, assign) long answerCorrectCount;
@property (nonatomic, strong) NSString *answerCorrectPercent;
@property (nonatomic, strong) NSString *averageScore;

@end

@interface GSReplayAnswerInfo:NSObject

@property (nonatomic,strong) NSArray *answers;
@property (nonatomic,copy) NSString *nickName;
@property (nonatomic,copy) NSString *submitTime;
@property (nonatomic,copy) NSString *userId;

@end

@interface GSUserSubmitAnswers : NSObject

@property (nonatomic,strong) NSArray<GSReplayAnswerInfo*> *list;
@property (nonatomic,assign) NSInteger pageCount;
@property (nonatomic,assign) NSInteger pageNum;
@property (nonatomic,assign) NSInteger pageSize;

@end


NS_ASSUME_NONNULL_END
