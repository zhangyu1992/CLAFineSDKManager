//
//  RTMSession.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/6/9.
//

#import <Foundation/Foundation.h>
#import <FineSdk/RTMMessage.h>
#import <FineSdk/RTMGroup.h>
#import <FineSdk/RTMAcount.h>
#import <FineSdk/RTMLinker.h>
#import <FineSdk/RTMRoster.h>
#import <FineSdk/RTMChatRoom.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTMSession : NSObject

@property (nonatomic, strong, readonly) RTMLinker *linker;
@property (nonatomic, strong, readonly) RTMMessage *message;
@property (nonatomic, strong, readonly) RTMGroup *group;
@property (nonatomic, strong, readonly) RTMAcount *acount;
@property (nonatomic, strong, readonly) RTMRoster *roster;
@property (nonatomic, strong, readonly) RTMChatRoom *chatRoom;


@end

NS_ASSUME_NONNULL_END
