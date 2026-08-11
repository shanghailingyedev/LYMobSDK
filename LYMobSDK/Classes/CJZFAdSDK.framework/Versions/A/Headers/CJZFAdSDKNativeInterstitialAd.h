//
//  CJZFAdSDKNativeInterstitialAd.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/5/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol CJZFAdSDKNativeInterstitialAdDelegate;

@interface CJZFAdSDKNativeInterstitialAd : NSObject

/**
 代理回调
*/
@property (nonatomic, weak) id<CJZFAdSDKNativeInterstitialAdDelegate> delegate;

/*
 viewControllerForPresentingModalView
 详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

/**
 是否静音，默认静音
 */
@property (nonatomic, assign) BOOL isMuted;

/**
 自定义处理广告落地页，当渠道为*时有效，点击回调中会带有广告落地页地址
*/
@property (nonatomic, assign) BOOL customLoadingPage;

/**
 信息流自动播放，默认WiFi自动播放 开启后WiFi/4G自动播放
 */
@property(nonatomic ,assign) BOOL autoPlay;

/**
 插屏展示时间，默认为0（为0则需要用户手动关闭）
 */
@property (nonatomic, assign) NSInteger showTime DEPRECATED_MSG_ATTRIBUTE("参数已经废弃，设置该参数无效");

/**
 点击插屏空白处关闭广告，默认为false
 */
@property (nonatomic, assign) BOOL touchClose DEPRECATED_MSG_ATTRIBUTE("参数已经废弃，设置该参数无效");

/**
 背景视图颜色，默认为#000000，透明度0.1，透明度最大为0.1
 */
@property (nonatomic, strong) UIColor *backgroundColor;

/**
 插屏的广告视图，和背景视图顶部的距离
 */
@property (nonatomic, assign) CGFloat viewY;

/**
 是否展示插屏广告底部关闭按钮
 */
@property (nonatomic, assign) BOOL showBottomCloseBtn;

/**
 广告是否准备好被展示
 */
- (BOOL)isAdValid;

/**
 展示广告，如果需要自定义布局，则修改.m文件中的setUpAdView函数
 */
- (void)showAdView;

/**
 加载广告
 */
- (void)loadAd:(NSString *)posId;

/**
 设置场景参数
 */
- (void)setAdScenes:(NSDictionary *)scenes;

/**
 获取广告的竞价价格，单位分，为0则表示未成功获取到广告，或者不支持竞价，开启该功能需要联系媒介商务
 */
- (NSInteger)getBidPrice;
/**
 发送竞价成功上报
 @param price 赢价价格，单位分
 */
- (void)sendWinNotice:(NSInteger)price;

/**
 发送竞价失败上报
 @param price 赢价价格，单位分
 */
- (void)sendLossNotice:(NSInteger)price;

/**
 移除信息流插屏广告
 */
- (void)removeInteratitialAdView;

/**
 获取广告的请求id，为空字符串则表示未成功发起广告请求
 */
- (NSString *)getRequestId;

@end

@protocol CJZFAdSDKNativeInterstitialAdDelegate <NSObject>

- (void)nativeInterstitialAdSuccessToLoad:(CJZFAdSDKNativeInterstitialAd *)nativeInterstitialAd;

- (void)nativeInterstitialAdFailedToLoad:(CJZFAdSDKNativeInterstitialAd *)nativeInterstitialAd error:(NSError *)error;
- (void)nativeInterstitialAdExposure:(CJZFAdSDKNativeInterstitialAd *)nativeInterstitialAd;

- (void)nativeInterstitialAdClick:(CJZFAdSDKNativeInterstitialAd *)nativeInterstitialAd loadingPageURL:(NSString *)loadingPageURL;

- (void)nativeInterstitialAdClose:(CJZFAdSDKNativeInterstitialAd *)nativeInterstitialAd;

- (void)nativeInterstitialAdLoadingPageViewClose:(CJZFAdSDKNativeInterstitialAd *)nativeInterstitialAd;


/**
 CJZFAdSDKIntertitialAd展示上报回调
 @discussion 当插屏广告成功展示给用户时，SDK会调用此方法。接入方可以在此回调中进行广告曝光的数据统计。
 */
- (void)nativeInterstitialAdExposureReport:(CJZFAdSDKNativeInterstitialAd *)nativeInterstitialAd;
/**
 CJZFAdSDKIntertitialAd点击上报回调
 @discussion 当插屏广告成功点击时，SDK会调用此方法。接入方可以在此回调中进行广告点击的数据统计。
 */
- (void)nativeInterstitialAdClickReport:(CJZFAdSDKNativeInterstitialAd *)nativeInterstitialAd;

@end

NS_ASSUME_NONNULL_END
