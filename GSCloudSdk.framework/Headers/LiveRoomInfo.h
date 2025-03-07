//
//  LiveRoomInfo.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class LiveSettingInfo;
@class LiveRoomStatus;
@class LiveRoomTags;
@class VoipInfo;
@class PlaybackConfigVO;
@class PrivacyStatement;
@class LiveWatchInfo;
@interface LiveRoomInfo : NSObject
@property(nonatomic, assign)NSInteger allowedEntryTime;
@property(nonatomic, copy)NSString *assistant_url;
@property(nonatomic, assign)NSInteger autoRecording;  //是否开启自动录制, 1-打开 2-关闭
@property(nonatomic, copy)NSString *background;
@property(nonatomic, copy)NSString *Id;//直播间id
@property(nonatomic, copy)NSString *chatRoomId;//聊天室id
@property(nonatomic, copy)NSString *confId;//场次id
@property(nonatomic, copy)NSString *cid;
@property(nonatomic, assign)NSInteger confStartTime;  //    场次开始时间 单位秒
@property(nonatomic, assign)NSInteger contractStatus;  //    0-正常, 1-需要提示合同状态异常
@property(nonatomic, assign)NSInteger currentTime;
@property(nonatomic, assign)NSInteger endTime; //直播间结束时间
@property(nonatomic, assign)NSInteger guestSeeAuth; //嘉宾是否可以看见观众: 1-可以 2-不可以
@property(nonatomic, assign)NSInteger hostUsersDuration; //主播是否显示用户在线时长
@property(nonatomic, copy)NSString *headImgUrl;//头像
@property(nonatomic, copy)NSString *logo;
@property(nonatomic, assign)NSInteger meetStatus; //关联会议状态
@property(nonatomic, copy)NSString *meetingId;//会议id
@property(nonatomic, copy)NSString *nickName;//昵称
@property(nonatomic, copy)NSString * specialGuestnickName;//指定嘉宾昵称
@property(nonatomic, copy)NSString * specialGuestnickID;//指定嘉宾ID
@property(nonatomic, copy)NSString *specialToGuestPassword;//指定嘉宾对应的普通嘉宾的密码

@property(nonatomic, copy)NSString *openId;
@property(nonatomic, copy)NSString *player_url;
@property(nonatomic, copy)NSString *posterId;//海报ID
@property(nonatomic, assign)YBUserRole role; //用户角色
@property(nonatomic, assign)BOOL isSpecialGuest;// 是指定嘉宾
@property(nonatomic, assign)NSInteger start_time;
@property(nonatomic, copy)NSString *theme;
@property(nonatomic, copy)NSString *title;//标题
@property(nonatomic, copy)NSString *token;//用户token
@property(nonatomic, copy)NSString *authCheckToken;//用户token cavp
@property(nonatomic, assign)NSInteger type;
@property(nonatomic, copy)NSString *userId;//用户id
@property(nonatomic, copy)NSString *webcastToken;//直播间token
@property(nonatomic, strong)LiveSettingInfo *broadcastSettingInfo;
@property(nonatomic, strong)LiveRoomStatus *liveRoomStatus;
@property(nonatomic, strong)VoipInfo *voipInfo;
@property(nonatomic, strong)PlaybackConfigVO *playbackConfigVO;
@property(nonatomic, strong)PrivacyStatement *privacy_statement;
@property(nonatomic, strong)LiveWatchInfo *watchConfig; //直播间配置 

//feature object todo
@end

@interface LiveSettingInfo : NSObject
@property(nonatomic, copy)NSString *background;
@property(nonatomic, copy)NSString *guide_map;
@property(nonatomic, assign)BOOL is_answer; //答题
@property(nonatomic, assign)BOOL is_chat;
@property(nonatomic, assign)BOOL is_check_in;
@property(nonatomic, assign)BOOL is_commodity;
@property(nonatomic, assign)BOOL is_host_users_show;//    主播端是否显示人数
@property(nonatomic, assign)BOOL is_lottery;
@property(nonatomic, assign)BOOL is_online_number;
@property(nonatomic, assign)BOOL is_phone_connect;//是否开启电话连线
@property(nonatomic, assign)BOOL is_playback;
@property(nonatomic, assign)BOOL is_privacy_statement;
@property(nonatomic, assign)BOOL is_questionnaire; //问卷
@property(nonatomic, assign)BOOL is_reward; //打赏
@property(nonatomic, assign)BOOL is_voice_calls;
/// 是否开启超高清 开启则订阅1080P
@property(nonatomic, assign)BOOL is_ultra_hd;
@property(nonatomic, assign)BOOL is_watch_address_sharing; //是否开启分享 1：开启 0 关闭
@property(nonatomic, assign)BOOL liveondemandVoiceStatus; //插播是否静音


@property(nonatomic, assign)BOOL is_like;//点赞  1：开启 0 关闭
//默认直播源 默认直播源 0 主播端 1 接收第三方推流 2 拉取第三方流
@property(nonatomic, assign)NSInteger defalut_streaming_source;
//是否多流直播
@property(nonatomic, assign)BOOL is_many_streaming;
//视频源比例 0 16:9  1 9:16
@property(nonatomic, assign)YBVideoCropMode video_source_ratio;

@property(nonatomic, copy)NSString *logo;
@property(nonatomic, assign)NSInteger max_resolution;
@property(nonatomic, assign)NSInteger mode; //直播模式 mode=0 主播控制，不可转移 mode=1 默认主播，允许助手控制
@end

@interface LiveRoomStatus : NSObject
@property(nonatomic, assign)NSInteger liveStatus; //直播间状态:0=未开始，1=准备中，2=直播中,3=已过期
@property(nonatomic, assign)NSInteger opType;//流类型0 云视流 1第三方推流 2第三方拉流 3伪直播流
@property(nonatomic, assign)NSInteger pushStreamStatus; //    流状态 0有流 1无流 2获取流中
@property(nonatomic, assign)NSInteger max_resolution;
@property(nonatomic, assign)NSInteger recordStatus; // 0开始 1结束
@property(nonatomic, assign)NSInteger used;//    是否正在使用中 0启用 1未启用
@end

@interface LoginResult : NSObject
@property(nonatomic, copy)NSString *cid;
@property(nonatomic, assign)BOOL control_live_SendAndView_chat;
@property(nonatomic, assign)BOOL control_live_StartAndStop;
@property(nonatomic, assign)BOOL control_live_announcement;
@property(nonatomic, assign)BOOL control_live_answer;
@property(nonatomic, assign)BOOL control_live_chat;
@property(nonatomic, assign)BOOL control_live_check_in;
@property(nonatomic, assign)BOOL control_live_commodity;
@property(nonatomic, assign)BOOL control_live_layout;
@property(nonatomic, assign)BOOL control_live_lottery;
@property(nonatomic, assign)BOOL control_live_online_number_rules;
@property(nonatomic, assign)BOOL control_live_push_stream;
@property(nonatomic, assign)BOOL control_live_Paper;
@property(nonatomic, assign)BOOL control_live_record;
@property(nonatomic, assign)BOOL control_live_rtmp_stream;
@property(nonatomic, assign)BOOL control_live_user_management;
@property(nonatomic, assign)BOOL control_live_video_surveillance;
@property(nonatomic, assign)BOOL control_live_voice_calls;
//id
@property(nonatomic, assign)BOOL is_succeed;
@property(nonatomic, copy)NSString *nickname;
@property(nonatomic, copy)NSString *password;
@property(nonatomic, copy)NSString *role;
@property(nonatomic, copy)NSString *sid;
@property(nonatomic, copy)NSString *token;
@property(nonatomic, copy)NSString *uid;
@property(nonatomic, copy)NSString *webcast_id;
@end

@interface PlaybackConfigVO : NSObject
@property(nonatomic, assign)NSInteger joinType;//    观看限制模式0=无限制 1=密码观看
@property(nonatomic, copy)NSString *playbackFileid; //关联录制件id
@property(nonatomic, assign)NSInteger playbackMode;//    播放方式0=不自动跳转 1=直播间过期时跳转 2=非直播中状态是跳转
@property(nonatomic, copy)NSString *playbackTitle; //回放主题
@property(nonatomic, copy)NSString *playbackUrl; //回放url
@end

@interface PrivacyStatement : NSObject
@property(nonatomic, copy)NSString *content;
@property(nonatomic, copy)NSString *title;
@property(nonatomic, copy)NSString *type;
@end

@interface StreamData : NSObject
@property(nonatomic, copy)NSString *ld;
@property(nonatomic, copy)NSString *hd;
@property(nonatomic, copy)NSString *ud;
@property(nonatomic, copy)NSString *audio;
@end

@interface StreamExpiretime : NSObject
@property(nonatomic, assign)NSInteger flv;
@property(nonatomic, assign)NSInteger m3u8;
@property(nonatomic, assign)NSInteger rtmp;
@property(nonatomic, assign)NSInteger rts;
@end

@interface PullStreamUrl : NSObject
@property(nonatomic, assign)YBLiveTimeDelay live_time_delay;// 0=RTS 1=FLV 2=HLS
@property(nonatomic, strong)StreamData *flv;
@property(nonatomic, strong)StreamData *hls;
@property(nonatomic, strong)StreamData *rts;
@property(nonatomic, assign)BOOL watchurlauth;
@property(nonatomic, strong)StreamExpiretime *expiretime;
@end

@interface LiveRoomTags : NSObject
@property(nonatomic, copy)NSString *content;
@property(nonatomic, assign)NSInteger create_time;
@property(nonatomic, copy)NSString *create_user_id;
//id
@property(nonatomic, assign)NSInteger Id;
@property(nonatomic, assign)BOOL is_show;
@property(nonatomic, assign)NSInteger modify_time;
@property(nonatomic, copy)NSString *modify_user_id;
@property(nonatomic, assign)NSInteger sort;
@property(nonatomic, copy)NSString *title;
@property(nonatomic, assign)NSInteger type;
@property(nonatomic, copy)NSString *webcast_id;
@end

@interface VoipData : NSObject
@property(nonatomic, copy)NSString *name;
@property(nonatomic, copy)NSString *userId;
@end
@interface VoipInfo : NSObject
@property(nonatomic, assign)NSInteger enabled;
@property(nonatomic, assign)NSInteger isJoinVoip;
@property(nonatomic, assign)NSInteger isSystemJoinVoip;
@property(nonatomic, assign)NSInteger meetIsJoin;
@property(nonatomic, assign)NSInteger status;
@property(nonatomic, strong)VoipData *voip;

@end

@interface LiveWatchInfo : NSObject

///微信分享标题 0-默认, 1-自定义
@property(nonatomic, assign)NSInteger weixinShareTitleType;
///微信分享标题
@property (nonatomic,copy) NSString *weixinShareTitle;
///微信分享的描述
@property (nonatomic,copy) NSString *weixinShareDesc;
///微信分享的封面 0-默认, 1-自定义
@property(nonatomic, assign)NSInteger weixinShareConverType;
///微信分享的封面
@property (nonatomic,copy) NSString *weixinShareConver;
///微信分享的链接 0-默认, 1-自定义
@property(nonatomic, assign)NSInteger weixinShareLink;
///微信分享的链接
@property (nonatomic,copy) NSString *weixinShareLinkType;

@end


@interface LiveCloudSettingModel : NSObject

///创建时间
@property (nonatomic,copy) NSString *create_time;
///创建时间
@property (nonatomic,copy) NSString *create_user_id;
///修改时间
@property (nonatomic,copy) NSString *modify_time;
///cid
@property (nonatomic,copy) NSString *cid;
///助手端title
@property (nonatomic,copy) NSString *clh_title;
///主播端title
@property (nonatomic,copy) NSString *cla_title;
///后台title
@property (nonatomic,copy) NSString *clm_title;
///icon
@property (nonatomic,copy) NSString *icon;
///登录页图片
@property (nonatomic,copy) NSString *login_banner;
///登录页背景图片
@property (nonatomic,copy) NSString *login_background;
///隐藏263标识
@property (nonatomic,assign) BOOL is_hidden_263;
///是否开启混合云
@property (nonatomic,assign) BOOL is_hybrid_cloud;
///在线客服开关
@property (nonatomic,assign) BOOL is_customer_service;
///展动回放配置
@property (nonatomic,assign) BOOL is_gensee;
///展动回放配置
@property (nonatomic,assign) BOOL is_gensee_billing_merge;

@end

NS_ASSUME_NONNULL_END
