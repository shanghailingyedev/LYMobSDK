//
//  CJInterstitialAd.h
//  CJMobileAd
//
//  Created by shanghailingye 2022/2/26.
//  Copyright © 2022Jun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class CJInterstitialAd;
@protocol CJInterstitialAdDelegate <NSObject>

/// 插屏加载成功回调
/// - Parameter interstitialAd: 实例
- (void)interstitialAdDidLoad:(CJInterstitialAd *)interstitialAd resourceId:(NSString *)resourceId;

/// 插屏加载失败回调
/// - Parameter interstitialAd: 实例
- (void)interstitialAdLoadFailed:(CJInterstitialAd *)interstitialAd error:(NSError *)error;

/// 插屏展示回调
/// - Parameter interstitialAd: 实例
- (void)interstitialAdOnShow:(CJInterstitialAd *)interstitialAd;

/// 插屏点击回调
/// - Parameter interstitialAd: 实例
- (void)interstitialAdOnClicked:(CJInterstitialAd *)interstitialAd;

/// 自定义渠道点击回调
/// - Parameters:
///   - splashAd: 广告实例
///   - params: 回调参数, key: landing_url  落地页地址
- (void)interstitialAdChannelOnClicked:(CJInterstitialAd *)interstitialAd extraParams:(NSDictionary *)params;

/// 自定义渠道onShow回调
/// - Parameters:
///   - splashAd: 广告实例
///   - params: 回调参数, key: resourceId  广告位ID
- (void)interstitialAdChannelOnShow:(CJInterstitialAd *)interstitialAd extraParams:(NSDictionary *)params;

/// 插屏关闭回调
/// - Parameter interstitialAd: 实例
- (void)interstitialAdOnClosed:(CJInterstitialAd *)interstitialAd;


@end

@interface CJInterstitialAd : NSObject

/// 判断广告是否有效（展示前判断）
@property (nonatomic, assign, readonly) BOOL isReady;

@property (nonatomic,weak) id <CJInterstitialAdDelegate> delegate;

- (instancetype)initWithResourceId:(NSString *)resourceId;

- (void)loadAdData;

- (void)showFromRootViewController:(UIViewController *)rootViewController;

- (NSString *)getAdType;

- (NSInteger)getECpm;

@end

NS_ASSUME_NONNULL_END
