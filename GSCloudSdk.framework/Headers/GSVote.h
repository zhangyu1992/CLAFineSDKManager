//
//  GSVote.h
//  GSCloudSdk
//
//  Created by leo on 2022/3/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface GSVoteQuestionsAnswer : NSObject

@property (nonatomic, copy) NSString *Id;
@property (nonatomic, assign) NSInteger num;
@property (nonatomic, strong)NSArray *answer;

@end


@interface GSVote : NSObject

@property (nonatomic, assign) long confPaperId;
@property (nonatomic, strong)NSArray<GSVoteQuestionsAnswer *> *questionsAnswer;

@end

NS_ASSUME_NONNULL_END
