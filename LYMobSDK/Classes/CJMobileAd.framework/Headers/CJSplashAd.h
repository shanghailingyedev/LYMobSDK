//
//  CJSplashAd.h
//  CJMobileAd
//
//  Created by shanghailingye 2022/2/22.
//  Copyright © 2022Jun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class CJSplashAd;
@protocol CJSplashAdDelegate <NSObject>

@optional
/// 广告位加载成功
/// - Parameters:
///   - splashAd: 广告实例
///   - resourceId: 广告位ID
- (void)splashAdDidLoad:(CJSplashAd *)splashAd resourceId:(NSString *)resourceId;

/// 广告位展示成功
/// - Parameter splashAd: 广告实例
- (void)splashAdOnShow:(CJSplashAd *)splashAd;

/// 广告位加载失败
/// - Parameters:
///   - splashAd: 实例
///   - error: 失败信息
- (void)splashAdLoadFailed:(CJSplashAd *)splashAd error:(NSError *)error;

/// 点击回调
/// - Parameter splashAd: 实例
- (void)splashAdOnClicked:(CJSplashAd *)splashAd;

/// 自定义渠道点击回调
/// - Parameters:
///   - splashAd: 广告实例
///   - params: 回调参数, key: landing_url  落地页地址
- (void)splashAdChannelOnClicked:(CJSplashAd *)splashAd extraParams:(NSDictionary *)params;

/// 自定义渠道onShow回调
/// - Parameters:
///   - splashAd: 广告实例
///   - params: 回调参数, key: resourceId  落地页地址
- (void)splashAdChannelOnShow:(CJSplashAd *)splashAd extraParams:(NSDictionary *)params;

/// 广告位关闭回调
/// - Parameter splashAd: 广告实例
- (void)splashAdOnClosed:(CJSplashAd *)splashAd;

@end

@interface CJSplashAd : NSObject

@property (nonatomic, weak) id <CJSplashAdDelegate> delegate;

/// 初始化开屏
/// - Parameters:
///   - resourceId: 广告位ID
///   - rootViewController: 绑定控制器，不绑定广告无法正常跳转
///   - logoView: 开屏底部logoView，不能超过屏幕的20%，超过会影响广告收益
- (instancetype)initWithResourceId:(NSString *)resourceId
                rootViewController:(UIViewController *)rootViewController
                    customLogoView:(UIView *)logoView;

/// 加载广告
- (void)loadAdData;

/// 展示广告：请在加载成功之后调用
/// - Parameter window: 当前最外层window
- (void)showSplashAdToWindow:(UIWindow *)window;

/// 加载成功时获取有效
- (NSInteger)getECpm;

- (NSString *)getAdType;

@end



NS_ASSUME_NONNULL_END
