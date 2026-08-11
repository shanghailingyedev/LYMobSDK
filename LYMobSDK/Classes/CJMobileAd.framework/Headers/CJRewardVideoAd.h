//
//  CJRewardVideoAd.h
//  CJMobileAd
//
//  Created by shanghailingye 2022/2/26.
//  Copyright © 2022Jun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class CJRewardVideoAd;
@protocol CJRewardVideoAdDelegate <NSObject>

/// 达成奖励条件
/// - Parameters:
///   - rewardAd: 广告实例
///   - requestId: 请求ID
- (void)rewardVideoOnRewarded:(CJRewardVideoAd *)rewardAd requestId:(NSString *)requestId;

/// 广告加载就绪
/// - Parameters:
///   - rewardAd: 广告实例
///   - resourceId: 广告位ID
- (void)rewardVideoAdDidLoad:(CJRewardVideoAd *)rewardAd resourceId:(NSString *)resourceId;

/// 广告位展示成功
/// - Parameter rewardAd: 广告实例
- (void)rewardVideoAdOnShow:(CJRewardVideoAd *)rewardAd;

/// 广告位加载失败
/// - Parameters:
///   - rewardAd: 广告位实例
///   - error: 错误信息
- (void)rewardVideoAdLoadFailed:(CJRewardVideoAd *)rewardAd error:(NSError *)error;

/// 广告位点击事件
/// - Parameter rewardAd: 广告位实例
- (void)rewardVideoAdOnClicked:(CJRewardVideoAd *)rewardAd;

/// 自定义渠道点击回调
/// - Parameters:
///   - splashAd: 广告实例
///   - params: 回调参数, key: landing_url  落地页地址
- (void)rewardVideoAdChannelOnClicked:(CJRewardVideoAd *)rewardAd extraParams:(NSDictionary *)params;

/// 自定义渠道onShow回调
/// - Parameters:
///   - splashAd: 广告实例
///   - params: 回调参数, key: resourceId  广告位ID
- (void)rewardVideoAdChannelOnShow:(CJRewardVideoAd *)rewardAd extraParams:(NSDictionary *)params;

/// 广告位关闭
/// - Parameter rewardAd: 广告位实例
- (void)rewardVideoAdOnClosed:(CJRewardVideoAd *)rewardAd;

@end

@interface CJRewardVideoAd : NSObject

/// 判断广告是否有效（展示前判断）
@property (nonatomic, assign, readonly) BOOL isReady;

@property (nonatomic,weak) id <CJRewardVideoAdDelegate> delegate;

// 无奖励验证
- (instancetype)initWithResourceId:(NSString *)resourceId;

// 含奖励验证（默认验证方式，推荐）
- (instancetype)initWithResourceId:(NSString *)resourceId
                            userId:(NSString *)userId
                            extend:(NSString *)extend;

// 含奖励验证(带验证方式配置mode： 0（默认在视频达到奖励时进行回调）1:提前在视频展示时进行回调)
- (instancetype)initWithResourceId:(NSString *)resourceId
                            userId:(NSString *)userId
                            extend:(NSString *)extend
                  verificationMode:(NSInteger)mode;

/// 回传拓展参数（加载成功-达成奖励之前）
/// - Parameter extend: 扩展参数
- (void)setExtend:(NSString *)extend;

/// 是否静音
/// - Parameter mute: 默认值false：不静音
/// ⚠️：需要在load之前进行设置才会生效，默认静音会影响激励视频单价
- (void)setMute:(BOOL)mute;

/// 加载激励视频
- (void)loadAdData;

/// 展示激励视频
- (void)showFromRootViewController:(UIViewController *)rootViewController;

- (NSString *)getAdType;
/// 加载成功时获取有效
- (NSInteger)getECpm;

@end

NS_ASSUME_NONNULL_END
