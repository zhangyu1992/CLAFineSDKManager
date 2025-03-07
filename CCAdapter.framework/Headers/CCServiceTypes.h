//
//  CCServiceTypes.h
//  adapter
//
//  Created by jinxiangkun on 2017/5/9.
//  Copyright © 2017年 yiyimama. All rights reserved.
//

#ifndef CCServiceTypes_h
#define CCServiceTypes_h

// 本地认证服务状态
enum CCLocalAuthState
{
    //未执行本地认证
    CCAuthLocalNone = 0,
    //本地认证成功
    CCAuthLocalOK = 1,
    //本地认证失败
    CCAuthLocalFailed = -1,
};
typedef \
enum CCLocalAuthState CCLocalAuthState;

// 本地认证服务状态
enum CCOnlineAuthState
{
    //未执行线上认证
    CCAuthOnlineNone = 0,
    //线上联机认证成功
    CCAuthOnlineOK = 2,
    //线上联机认证失败
    CCAuthOnlineFailed = -2,
};
typedef \
enum CCOnlineAuthState CCOnlineAuthState;

// 定位服务状态码
enum CCLocalStatusCode
{
    //未执行状态
    CCLocalNone = 0,
    //正常
    CCLocalOK = 200,
    //错误访问, 请求非法
    CCLocalBadRequest = 400,
    //未授权, 用户不存在
    CCLocalUnauthorized = 401,
    //禁止访问, 未分配节点
    CCLocalPaymentRequired = 402,
    //请求超时, 未知错误(服务器地址错)
    CCLocalRequestTimeout = 408,
    //服务出现异常, 服务器出现异常
    CCLocalInternalServerError = 500,
};
typedef \
enum CCLocalStatusCode CCLocalStatusCode;

// 认证服务状态码
enum CCLoginStatusCode
{
    //未执行状态
    CCLoginNone = 0,
    //正常
    CCLoginOK = 200,
    //错误访问, 请求非法
    CCLoginBadRequest = 400,
    //未授权, 用户不存在
    CCLoginUnauthorized = 401,
    //禁止访问, 用户密码错误
    CCLoginPaymentRequired = 402,
    //禁止访问, 登录无效
    CCLoginInvalidLogin = 403,
    //未找到, 无法使用
    CCLoginNotFound = 404,
    //方法禁用, 账号被锁
    CCLoginNotAllowed = 405,
    //不接受, 系统维护中
    CCLoginNotAcceptable = 406,
    //需要代理授权, 密码过期
    CCLoginProxyRequired = 407,
    //请求超时, 未知错误(服务器地址错)
    CCLoginRequestTimeout = 408,
    // 请求错误，需要验证码
    CCLoginErrorNeedCaptcha = 409,
    // q验证码错误
    CCLoginFailedErrorCaptcha = 410,

    //服务出现异常, 服务器出现异常
    CCLoginInternalServerError = 500,
};
typedef \
enum CCLoginStatusCode CCLoginStatusCode;

// Websocket接入服务返回的状态码
enum CCWebsocketStatusCode
{
    //未执行状态
    CCWebsocketNone = 0,
    //正常
    CCWebsocketOK = 200,
    //错误访问, 请求非法
    CCWebsocketBadRequest = 400,
    //未授权, 会话验证失败
    CCWebsocketUnauthorized = 401,
    //禁止访问, 登录无效, 禁止访问
    CCWebsocketInvalidLogin = 403,
    //服务出现异常, 服务器出现异常
    CCWebsocketInternalServerError = 500,
};
typedef \
enum CCWebsocketStatusCode CCWebsocketStatusCode;

// Websocket调用错误状态
enum CCWebsocketState
{
    CCWebsocketFailed = -1, //无原因错误
    CCWebsocketCallOK = 0, //调用成功返回
    CCWebsocketNoAuthSid = 1, //没有会话id
    CCWebsocketNoSameLoginUser = 2, //不相同的用户连接
    CCWebsocketStreamNetworkFailed = 3, //接入服务器打开不成功，网络不通
    CCWebsocketStreamOpenFailed = 4, //接入服务器打开不成功，或网络不通
    CCWebsocketStreamSessionFailed = 5, //接入服务器会话验证失败（网络通）
    CCWebsocketNoAccessServerAddress = 20, //未定位到接入服务器地址
};
typedef enum CCWebsocketState CCWebsocketState;

// 缓存数据库分类
enum CCCacheType
{
    CCCacheTypeNone = 0,
    CCCacheTypeGlobal = 1, //清空全局缓存数据
    CCCacheTypeUserAll = 2, //清空个人所有缓存信息
    CCCacheTypeUserGlobal = 3, //清空个人全局缓存信息
    CCCacheTypeUserRoster = 4, //清空个人组织缓存信息
    CCCacheTypeUserConfig = 5, //清空个人配置缓存信息
    CCCacheTypeUserMessage = 6, //清空个人全部消息缓存信息
};
typedef enum CCCacheType CCCacheType;

// 调用状态！
enum CCCallState
{
    CCFailed = -1, //无原因错误
    CCCallOK = 0, //调用成功返回
    CCUninitialize = 1, //已关闭后再调用
    CCErrorInit = 2,//未初始化调用
    CCErrorMalloc = 3, //分配内存错误
    CCErrorFormat = 4, //调用格式错误
    CCErrorArgument = 5, //调用参数错误
    CCErrorThread = 6, //调用线程错误
    CCErrorTimeOut = 7, //调用线程超时
    CCErrorReachability = 8, //调用网络问题，不通
    CCErrorDevInfo = 9, //未传入设备信息
    CCErrorLocationServer = 10, //未设定服务器地址
    CCErrorDatabaseUser = 11, //未设定用户数据库
    CCErrorDatabaseGlobal = 12, //未设定全局数据库
    CCErrorNoLogin = 13, //未认证服务(sid为空)，或只离线状态
    CCErrorNoLoginWebSocket = 14, //未登陆聊天服务器
    CCErrorWebSocketBreak = 15, //登陆聊天服务器的网络异常中断
    CCErrorException = 16, //调用异常错误
    CCErrorNoAuthInfo = 17, //没有当前用户的认证信息
    CCErrorNoSameLoginUser = 18, //返回结果时调用者与当前登陆用户不相同
    CCErrorDatabaseUserCreate = 19, //未创建用户数据库
    CCErrorAccessServerAddress = 20, //未定位到接入服务器地址
    CCErrorDataUserOpenTempFile = 21, //写入创建用户数据的文件错误
    CCErrorUnknow = 0xff, //调用有错误，未知错误
};
typedef enum CCCallState CCCallState;


#endif /* CCServiceTypes_h */
