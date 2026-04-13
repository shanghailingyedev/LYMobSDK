//
//  CJADManager.h
//  CJMobileAd
//
//  Created by shanghailingye on 2022/2/23.
//  Copyright © 2022 shanghailingye. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void (^CJAdCompletionHandler)(BOOL success, NSError * _Nullable error);

NS_ASSUME_NONNULL_BEGIN

@interface CJADManager : NSObject

/// SDK同步初始化
/// - Parameter configId: 媒体ID
+ (void)configure:(NSString *)configId;

/// SDK异步初始化(推荐)
/// - Parameters:
///   - configId: 媒体ID
///   - completionHandler: 回调初始化状态
+ (void)configure:(NSString *)configId completeHandle:(CJAdCompletionHandler)completionHandler;

/// 用于用户广告溯源，排查广告素材，在用户登录后设置就行
/// - Parameter userId: App 自己的用户ID
+ (void)setAppUserId:(NSString *)userId;

/// 可选，启用个性化推荐，默认为YES
/// - Parameter enable: 是否开启
/// 初始化SDK前调用，否则有可能不生效
+ (void)setEnablePersonalRecommend:(BOOL)enable;

/// 可选，启用摇一摇，默认为YES
/// - Parameter enable: 是否开启
/// 初始化SDK前调用，否则有可能不生效
+ (void)setEnableShake:(BOOL)enable;

/// SDK版本号
+ (NSString *)version;

/// 打开日志模式
+ (void)openDebugLog;

/// 获取设备唯一ID
+ (NSString *)deviceId;

@end

NS_ASSUME_NONNULL_END
