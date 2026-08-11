//
//  CJZFAdSDKNativeAd.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/4/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol CJZFAdSDKNativeAdDelegate;

@interface CJZFAdSDKNativeAd : NSObject

/**
 代理回调
*/
@property (nonatomic, weak) id<CJZFAdSDKNativeAdDelegate> delegate;

/*
 viewControllerForPresentingModalView
 详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

/**
 自定义处理广告落地页，当渠道为bwt时有效，点击回调中会带有广告落地页地址
*/
@property (nonatomic, assign) BOOL customLoadingPage;

/**
 广告位id
*/
@property (nonatomic, copy) NSString *posId;

/**
 是否静音，默认静音
 */
@property (nonatomic, assign) BOOL isMuted;

/**
 信息流自动播放，默认WiFi自动播放 开启后WiFi/4G自动播放
 */
@property(nonatomic ,assign) BOOL autoPlay;

/**
 加载广告

 @param count 拉取几条广告,建议区间 1~5, 超过可能无法拉取到
 */
- (void)load:(int)count;

/**
 是否正在加载广告
 */
- (BOOL)isLoadingAd;

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
 获取广告的请求id，为空字符串则表示未成功发起广告请求
 */
- (NSString *)getRequestId;

@end

@protocol CJZFAdapterNativeAdViewDelegate;

@protocol CJZFAdSDKNativeAdDelegate <NSObject>

@optional

/**
 信息流原生广告请求成功

 @param nativeAd 广告实例
 @param adViewArray 广告模板集合
 */
- (void)CJZF_nativeAdSucessToLoad:(CJZFAdSDKNativeAd *)nativeAd
                      adViewArray:(NSArray<__kindof UIView<CJZFAdapterNativeAdViewDelegate> *> *)adViewArray;

/**
 信息流广告请求失败

 @param nativeAd 广告实例
 @param error 请求错误描述
 */
- (void)CJZF_nativeAdFailToLoad:(CJZFAdSDKNativeAd *)nativeAd
                     error:(NSError *)error;

/**
 信息流广告被点击

 @param nativeAd 广告模板
 */
- (void)CJZF_nativeAdClicked:(CJZFAdSDKNativeAd *)nativeAd
                     adView:(__kindof UIView<CJZFAdapterNativeAdViewDelegate> *)adView loadingPageURL:(NSString *)loadingPageURL DEPRECATED_MSG_ATTRIBUTE("该回调即将废弃，请使用CJZF_nativeAdClickedReport:adView:回调方法");

/**
 信息流广告被关闭
 
 @param nativeAd 广告模板
 */
- (void)CJZF_nativeAdClose:(CJZFAdSDKNativeAd *)nativeAd
                    adView:(__kindof UIView<CJZFAdapterNativeAdViewDelegate> *)adView;

/**
 信息流广告被展示
 
 @param nativeAd 广告实例
 */
- (void)CJZF_nativeAdExposure:(CJZFAdSDKNativeAd *)nativeAd
                      adView:(__kindof UIView<CJZFAdapterNativeAdViewDelegate> *)adView DEPRECATED_MSG_ATTRIBUTE("该回调即将废弃，请使用CJZF_nativeAdExposureReport:adView:回调方法");

/**
 信息流广告展示上报
 
 @param nativeAd 广告实例
 */
- (void)CJZF_nativeAdExposureReport:(CJZFAdSDKNativeAd *)nativeAd
                       adView:(__kindof UIView<CJZFAdapterNativeAdViewDelegate> *)adView;

/**
 信息流广告点击上报

 @param nativeAd 广告模板
 */
- (void)CJZF_nativeAdClickedReport:(CJZFAdSDKNativeAd *)nativeAd
                           adView:(__kindof UIView<CJZFAdapterNativeAdViewDelegate> *)adView;

/**
 信息流广告落地页被关闭
 
 @param nativeAd 广告实例
 */
- (void)CJZF_nativeAdCloseLandingPage:(CJZFAdSDKNativeAd *)nativeAd
                       adView:(__kindof UIView<CJZFAdapterNativeAdViewDelegate> *)adView;

@end

NS_ASSUME_NONNULL_END
