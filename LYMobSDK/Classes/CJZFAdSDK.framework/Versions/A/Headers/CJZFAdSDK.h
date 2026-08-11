//
//  CJZFAdSDK.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/13.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, CJZFSDKLogLevel) {
    /// No logs
    CJZFSDKLogLevelOff     = 0,
    /// Error logs only. 0...00001
    CJZFSDKLogLevelError   = (1 << 0),
    /// Error and warning logs, 0...00010
    CJZFSDKLogLevelWarning = (1 << 1),
    /// Error, warning, track logs, 0...00011
    CJZFSDKLogLevelTrack   = 3,
    /// Error, warning and info logs, 0...00100
    CJZFSDKLogLevelInfo    = (1 << 2),
    /// Error, warning, info and debug logs, 0...01000
    CJZFSDKLogLevelDebug   = (1 << 3),
    /// Error, warning, info, debug and verbose logs, 0...10000
    CJZFSDKLogLevelVerbose = (1 << 4),
    /// All logs. 1...11111
    CJZFSDKLogLevelAll     = NSUIntegerMax
};

NS_ASSUME_NONNULL_BEGIN

@class CJZFChannelInfo;

@interface CJZFAdSDK : NSObject

/**
使用默认域名 https://sdk.hzzfcm.com 初始化SDK

@param appId 给定的唯一appid
@param completion 启动完成回调
*/
+ (void)initWithAppId:(NSString *)appId completionBlock:(nullable void(^)(NSError *_Nullable error))completion;

/**
初始化SDK

@param appId 给定的唯一appid
@param requestDomain 请求域名，格式为协议加域名
@param completion 启动完成回调
*/
+ (void)initWithAppId:(NSString *)appId requestDomain:(NSString *)requestDomain completionBlock:(nullable void(^)(NSError *_Nullable error))completion;

/**
 SDK Version
 */
+ (NSString *)getSDKVersion;

/**
 SDK Package Version
 */
+ (NSDictionary *)getAllPlatformVersion;

/**
 SDK init config cache succeed or not
 
 @param appId 给定的唯一appid
 */
+ (BOOL)initConfigCacheSucceed:(NSString *)appId;

/**
 设置日志输出等级
 
 @param logLevel 日志输出等级
 */
+ (void)setLogLevel:(CJZFSDKLogLevel)logLevel;

/**
 设置WebView的原始UA
 原始UA示例：Mozilla/5.0 (iPhone; CPU iPhone OS 15_5 like Mac OS X) AppleWebKit/605.1.15 (KHTML, like Gecko) Mobile/15E148
 原始UA应满足正则表达式‘^Mozilla.*?Mobile\/[0-9A-Z]+’
 @param originalUA WebView的原始UA
 */
+ (NSError *)setOriginalUA:(NSString *)originalUA;

/**
 设置渠道信息
 
 @param channelInfoList 渠道信息列表
 */
+ (void)setChannelInfoList:(NSArray<CJZFChannelInfo *> *)channelInfoList;

/**
 设置请求域名
 
 @param requestDomain 请求域名，格式为协议加域名，例如：https://ad.bwton.com
 @param appId 给定的唯一appid
 */
+ (void)setRequestDomain:(NSString *)requestDomain appId:(NSString *)appId;

/**
 设置停止广告请求
 */
+ (void)setNoAd;


@end

NS_ASSUME_NONNULL_END
