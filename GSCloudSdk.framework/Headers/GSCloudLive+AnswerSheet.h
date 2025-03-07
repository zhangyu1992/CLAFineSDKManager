//
//  GSCloudLive+AnswerSheet.h
//  GSCloudSdk
//
//  Created by 胡亚磊 on 2022/4/29.
//

#import <GSCloudSdk/GSCloudSdk.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSCloudLive (AnswerSheet)

#pragma mark  获取答题卡列表
- (void)AnswerSheet_queryAnswerSheetListSuccess:(void(^)(NSMutableArray<GSCardListInfo*>*cardList))success
                                        failure:(void(^)(YBError *error))failure;

#pragma mark 新增答题
- (void)AnswerSheet_AddWithCard:(GSCard*)card
                        success:(void(^)(void))success
                        failure:(void(^)(YBError *error))failure;

#pragma mark 查看答题详情
- (void)AnswerSheet_queryDetailsWithAnswerSheetId:(long)answerSheetId
                                          success:(void (^)(GSCardInfoDetail* detailInfo))success
                                          failure:(void(^)(YBError *error))failure;

#pragma mark 编辑答题
- (void)AnswerSheet_updateWithCard:(GSCard*)card
                     answerSheetId:(long)answerSheetId
                        success:(void(^)(void))success
                           failure:(void(^)(YBError *error))failure;

#pragma mark 删除答题
- (void)AnswerSheet_deletWithAnswerSheetId:(long)answerSheetId
                                   success:(void(^)(void))success
                                   failure:(void(^)(YBError *error))failure;

#pragma mark 发布答题
/// @param answerSheetId 答题卡ID
/// @param duration 限时答题时间，单位s  不限时为 -1
- (void)AnswerSheet_publishWithAnswerSheetId:(long)answerSheetId
                                    duration:(int)duration
                                     success:(void(^)(NSDictionary * response))success
                                     failure:(void(^)(YBError *error))failure;

#pragma mark 结束答题
- (void)AnswerSheet_stopAnswerWithAnswerSheetId:(long)answerSheetId
                                        success:(void(^)(void))success
                                        failure:(void(^)(YBError *error))failure;

#pragma mark 查看答题结果(不包含观众答题记录)
- (void)AnswerSheet_queryAnswerResultWithConfAnswerSheetId:(long)confAnswerSheetId
                                               success:(void(^)(GSCard *card))success
                                               failure:(void(^)(YBError *error))failure;
#pragma mark 查看答题结果(包括观众的答题记录)
- (void)AnswerSheet_queryAnswerDetailResultWithConfAnswerSheetId:(long)confAnswerSheetId
                                                         pageNum:(int)pageNum
                                                        pageSize:(int)pageSize
                                                         success:(void(^)(GSCard *card))success
                                                         failure:(void(^)(YBError *error))failure;

#pragma mark 根据场次答题卡id推送答题结果
- (void)AnswerSheet_pushResultWithConfAnswerSheetId:(long)confAnswerSheetId
                                        success:(void(^)(void))success
                                            failure:(void(^)(YBError *error))failure;

#pragma mark --下载答题结果
/// @param confAnswerSheetId 答题卡ID
/// @param filePath 保存结果的文件夹名称
- (void)AnswerSheet_downLoadResultWithConfAnswerSheetId:(long)confAnswerSheetId
                                           downLoadPath:(NSString*)filePath
                                                success:(void(^)(NSString* resultPath))success
                                                failure:(void(^)(YBError *error))failure;

@end

NS_ASSUME_NONNULL_END
