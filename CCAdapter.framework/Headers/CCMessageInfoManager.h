//
//  CCMessageInfoManager.h
//  CCAdapterUI
//
//  Created by yiyimama on 2017/6/6.
//  Copyright © 2017年 yiyimama. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCModelMessage.h"
#import "CCNotificationKeys.h"
#import "CCMessageInfoManager.h"

//是否缓存文件路径信息
#define CCMessageCachedPathInfo (0x1)

//缩略图的最大显示宽度与高度
#define CCMessageImageThumbNailMaxWidth (180.0)
#define CCMessageImageThumbNailMaxHeight (180.0)

//消息缓存类型
#define MyMessageFileTypeImage (CCMessageItemTypeImage)
#define MyMessageFileTypeVoice (CCMessageItemTypeVoice)

//创建一个消息的缓存Key
#define MyMakeMessageFileKey(id_,cid,msgid,key) \
[NSString stringWithFormat:@"%@::%@::%@::%@",id_,cid,msgid,key]

@interface CCMessageInfoManager : NSObject

//单例消息管理类
+ (id)shareMessageManager;

// 上传完成时，添加到上传文件路径

// 上传文件只有原图模式，缩略图由图片服务器产生

//上传消息所用的文件，更新模式 updateThumbNail = YES,上传缩略图
- (void)updateMessageFile:(BOOL)updateThumbNail
                 fileInfo:(CCNameSpace(CCMethodUpFileInfo) *)sni
                   result:(void (^)(CCCallState state,
                                    CCNameSpace(CCMethodUpFileResult) *result))block;

//上传消息所用的文件，更新模式 updateThumbNail = YES,上传缩略图
- (void)uploadMessageFile:(BOOL)updateThumbNail
                  message:(CCNameSpace(CCMessageChatInfo) *)aMessage
                   result:(void (^)(CCCallState state,
                                    NSMutableDictionary * retInfos))block;

//上传消息所用的文件，更新模式 updateThumbNail = YES,上传缩略图
- (void)uploadMessageFile:(BOOL)updateThumbNail
                  message:(CCNameSpace(CCMessageChatInfo) *)aMessage
                  msgItem:(CCNameSpace(CCMessageItemBase) *)msgItem
                   result:(void (^)(CCCallState state,
                                    CCNameSpace(CCMethodUpFileResult) *result))block;

// 缓存完成时，添加到下载文件路径

//获得消息对像的缓存信息路径
- (void)cachedMessageFile:(BOOL)updateThumbNail
                  message:(CCNameSpace(CCMessageChatInfo) *)aMessage
                  msgItem:(CCNameSpace(CCMessageItemBase) *)msgItem
                   result:(void (^)(CCCallState state, NSString *localUrl))block;

//下载消息所用的文件，更新模式 updateThumbNail = YES,下载缩略图
- (void)downloadMessageFile:(BOOL)updateThumbNail
                    message:(CCNameSpace(CCMessageChatInfo) *)aMessage
                     result:(void (^)(CCCallState state,
                                      NSMutableDictionary * retInfos))block;

//下载消息所用的文件，更新模式 updateThumbNail = YES,下载缩略图
- (void)downloadMessageFile:(BOOL)updateThumbNail
                    message:(CCNameSpace(CCMessageChatInfo) *)aMessage
                    msgItem:(CCNameSpace(CCMessageItemBase) *)msgItem
                     result:(void (^)(CCCallState state,
                                      CCNameSpace(CCMethodDownFileResult) *result))block;

@end
