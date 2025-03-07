//
//  GSVoteCard.h
//  GSCloudSdk
//
//  Created by leo on 2022/3/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *   问卷中问题的题型
 */
typedef NS_ENUM(NSUInteger, GSVoteQuestionType) {
    
    GSVoteQuestionTypeSingleChoice,//单选
    
    GSVoteQuestionTypeMultiChoice,//多选
   
    GSVoteQuestionTypeEssay,//问答
};


//@interface GSCardOptions : NSObject
//
//@property (nonatomic, copy) NSString *number;
//@property (nonatomic, copy) NSString *item;
//@property (nonatomic, assign)BOOL isSelected;
//
//@end

@class GSCardOption;
@interface GSVoteQuestions : NSObject

@property (nonatomic, assign) NSInteger Id;
@property (nonatomic, assign) NSInteger num;
@property (nonatomic, assign) GSVoteQuestionType type;
@property (nonatomic, assign) NSInteger questionScore;
@property (nonatomic, assign) NSInteger paperId;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, strong) NSMutableArray<GSCardOption *> *options;
@property (nonatomic, strong) NSMutableArray *rightAnswers;

@end


@interface GSVoteCard : NSObject

@property (nonatomic, assign) long confPaperId;
@property (nonatomic, assign) long Id;
@property (nonatomic, assign) NSInteger webcastId;
@property (nonatomic, assign) NSInteger state;
@property (nonatomic, assign) YBPaperStatus stateV2;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, strong) NSMutableArray<GSVoteQuestions *> *questions;
@property (nonatomic, copy) NSString *createTime;

@end

//回复问卷消息
@interface GSPaperReplay : NSObject

@property (nonatomic,assign) long Id;
@property (nonatomic,copy) NSString *state;
@property (nonatomic,assign) long submitCount;
@property (nonatomic,assign) long siteId;
@property (nonatomic,copy) NSString *webcastTitle;
@property (nonatomic,assign) long confPaperId;
@property (nonatomic,assign) long confId;
@property (nonatomic,assign) long paperCount;
@property (nonatomic,copy) NSString *roomId;
@property (nonatomic,assign) YBUserRole userRole;
@property (nonatomic,assign) long webcastId;
@property (nonatomic,copy) NSString *nickname;
@end

@interface GSQuestionAnswer : NSObject

@property (nonatomic,strong) NSMutableArray *answer;
@property (nonatomic,assign) long num;
@property (nonatomic,copy) NSString *title;
@property (nonatomic,assign) long questionId;

@end

@interface GSUserQuestionDetails :NSObject

@property (nonatomic,copy) NSString *userId;
@property (nonatomic,copy) NSString *nickname;
@property (nonatomic,copy) NSString *sumitTime;
@property (nonatomic,strong) NSMutableArray<GSQuestionAnswer*> *questionAnswers;


@end

@interface GSOptionsStatistic: NSObject

@property (nonatomic,copy) NSString *number;
@property (nonatomic,assign) long selectCount;
@property (nonatomic,assign) double percent;
@property (nonatomic,copy) NSString *item;

@end

@interface GSQuestionStatistics: NSObject

@property (nonatomic,assign) long num;
@property (nonatomic,copy) NSString *title;
@property (nonatomic,assign) long questionId;
@property (nonatomic,copy) NSString *questionType;
@property (nonatomic,strong) NSMutableArray<GSOptionsStatistic*> *optionsStatistics;


@end

////问卷详情
@interface GSPaperDetails : NSObject

@property (nonatomic,assign) long paperId;
@property (nonatomic,assign) long confId;
@property (nonatomic,assign) long confPaperId;
@property (nonatomic,copy) NSString *title;
@property (nonatomic,copy) NSString *stopTime;
@property (nonatomic,assign) long  answerPeopleCount;
@property (nonatomic,assign) long paperCount;
@property (nonatomic,assign) long state;
@property (nonatomic,assign) YBPaperStatus stateV2;
@property (nonatomic,assign) long rounds;
@property (nonatomic,strong) NSMutableArray<GSUserQuestionDetails*> *userQuestionDetails;
@property (nonatomic,strong) NSMutableArray<GSQuestionStatistics*> *questionStatistics;

@end


NS_ASSUME_NONNULL_END
