//
//  MtBaseConverter.h
//  MtAdapter
//
//  Created by jinxiangkun on 2019/1/11.
//  Copyright © 2019年 jinxiangkun. All rights reserved.
//

#ifndef Mt_Base_Converter_h
#define Mt_Base_Converter_h

#import <Foundation/Foundation.h>

#include "MtSdk.h"

#import "CCRuntime.h"
#import "CCObjectHeader.h"

#import "MtBaseObjects.h"
using namespace mtsdk;

@interface MtBaseConverter : NSObject

+ (Sip)convertToSip:(const MtSipInfo *)src;
+ (MtSipInfo *)convertFromSip:(const Sip &)src;

+ (Notifying)convertToNotifying:(const MtNotifying *)src;
+ (MtNotifying *)convertFromNotifying:(const Notifying &)src;

+ (Transcoding)convertToTranscoding:(const MtTranscoding *)src;
+ (MtTranscoding *)convertFromTranscoding:(const Transcoding &)src;

+ (TranscodingVideo)convertToTranscodingVideo:(const MtTranscodingVideo *)src;
+ (MtTranscodingVideo *)convertFromTranscodingVideo:(const TranscodingVideo &)src;

+ (Permission)convertToPermission:(const MtPermission *)src;
+ (MtPermission *)convertFromPermission:(const Permission &)src;

+ (VideoFormat)convertToVideoFormat:(const MtVideoFormat *)src;
+ (MtVideoFormat *)convertFromVideoFormat:(const VideoFormat &)src;

+ (AudioFormat)convertToAudioFormat:(const MtAudioFormat *)src;
+ (MtAudioFormat *)convertFromAudioFormat:(const AudioFormat &)src;

+ (BGColor)convertToBGColor:(const MtRgbColor *)src;
+ (MtRgbColor *)convertFromBGColor:(const BGColor &)src;

+ (Area)convertToAreaRect:(const MtAreaRect *)src;
+ (MtAreaRect *)convertFromAreaRect:(const Area &)src;

//+ (Territory)convertToTerritory:(const MtTerritory *)src;
//+ (MtTerritory *)convertFromTerritory:(const Territory &)src;

+ (Resolution)convertToResolution:(const MtResolution *)src;
+ (MtResolution *)convertFromResolution:(const Resolution &)src;

+ (Parameters)convertToParameters:(const MtParameters *)src;
+ (MtParameters *)convertFromParameters:(const Parameters &)src;

+ (Templates)convertToTemplates:(const MtTemplates *)src;
+ (MtTemplates *)convertFromTemplates:(const Templates &)src;

+ (VideoLayout)convertToVideoLayout:(const MtVideoLayout *)src;
+ (MtVideoLayout *)convertFromVideoLayout:(const VideoLayout &)src;

+ (ViewVideo)convertToViewVideo:(const MtViewVideo *)src;
+ (MtViewVideo *)convertFromViewVideo:(const ViewVideo &)src;

+ (ViewAudio)convertToViewAudio:(const MtViewAudio *)src;
+ (MtViewAudio *)convertFromViewAudio:(const ViewAudio &)src;

+ (View)convertToViewObject:(const MtViewObject *)src;
+ (MtViewObject *)convertFromViewObject:(const View &)src;

+ (MediaIn)convertToMediaIn:(const MtMediaIn *)src;
+ (MtMediaIn *)convertFromMediaIn:(const MediaIn &)src;

+ (MediaOut)convertToMediaOut:(const MtMediaOut *)src;
+ (MtMediaOut *)convertFromMediaOut:(const MediaOut &)src;

+ (MediaOutViedeo)convertToMediaOutVideo:(const MtMediaOutVideo *)src;
+ (MtMediaOutVideo *)convertFromMediaOutVideo:(const MediaOutViedeo &)src;

+ (MediaOutVideoParameters)convertToMediaOutVideoParameters:(const MtMediaOutVideoParameters *)src;
+ (MtMediaOutVideoParameters *)convertFromMediaOutVideoParameters:(const MediaOutVideoParameters &)src;

+ (Action)convertToAction:(const MtAction *)src;
+ (MtAction *)convertFromAction:(const Action &)src;

+ (Role)convertToRoleInfo:(const MtRoleInfo *)src;
+ (MtRoleInfo *)convertFromRoleInfo:(const Role &)src;

+ (Room)convertToRoomInfo:(const MtRoomInfo *)src;
+ (MtRoomInfo *)convertFromRoomInfo:(const Room &)src;


+ (StUserInfo)convertToStUserInfo:(const MtStUserInfo *)src;
+ (MtStUserInfo *)convertFromStUserInfo:(const StUserInfo &)src;

+ (JoinRoomReq)convertToJoinRoomReq:(const MtStMeetInfo *)meetInfo;
+ (MtStMeetInfo *)convertFromJoinRoomRes:(const JoinRoomRes&)roomRes;


+ (CreateRoomReq)convertToCreateRoomReq:(const MtStRoomInfo *)roomInfo;
//+ (MtStRoomInfo * )convertToMtStRoomInfo:(RoomConfig)roomConfig;
+ (MtRoomInfoDetails * )convertToMtStRoomInfoDetails:(mtsdk::GetRoomInfoRes)roomConfig;

+ (KickParticipantReq)convertToKickParticipantReq:(const MtStParticipantInfo * )participantInfo;
+ (MtStRoomStatus *)convertToMtStRoomStatus:(GetRoomStatusRes)roomStatus;
+ (GetRoomStatusRes)convertToRoomStatus:(MtStRoomStatus *)rStatus;
+ (NSMutableArray *)convertToParticipantList:(GetParticipantRes)participants;
+ (StartRecordingReq)convertToStartRecordingReq:(MtStRecording *)recording;
+ (StopRecordingReq)convertToStopRecordingReq:(MtStRecordingRes *)recordingRes;
+ (NSMutableArray *)convertToStreamsList:(GetAllStreamsRes)streams;

+ (UpdateStreamsReq)convertToUpdateStreamsReq:(MtStOpStream*)opStream;

+ (RoomViewMode)convertToRoomViewModeWithRoomLayout:(MtStRoomLayout *)roomLayout;
+ (NSString *)transfromWith:(const FRACTION_MIXINFO &)fraction;
// 插播 模型转换
+ (NSString *)transformMTMediaAction:(MTMediaAction)mediaAction;
// 插播操作
+ (InterCutPlayReq)transformInterCutPlayReqWithMtShareMediaModel:(MtShareMediaModel*)mediaModel;
// 插播信息
+ (InterCutQueryInfo)transfromInterCutQueryInfoWithMShareMediaInfo:(MtShareMediaInfo *)mediaInfo;
+ (MtShareMediaInfo *)transfromMtShareMediaInfoWithInterCutQueryInfo:( InterCutQueryInfo)intercutQueryInfo;
// 插播地址
+ (InterCutPlayRecord)transformInterCutPlayRecordWithMtShareMediaRecordsModel:(MtShareMediaRecordsModel * )recordsModel;

+ (MtShareMediaRecordsModel *)transformMtShareMediaRecordsModelWithInterCutPlayRecord:(InterCutPlayRecord)intercutPlayRecord;

//共享文档信息
+ (NSMutableDictionary *)transformMtShareDocumentWithRequestResult:(DocShareInfoRes)result;

@end

#endif //Mt_Base_Converter_h
