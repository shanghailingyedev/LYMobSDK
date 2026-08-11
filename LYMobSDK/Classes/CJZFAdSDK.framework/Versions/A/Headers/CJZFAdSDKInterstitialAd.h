//
//  CJZFAdSDKIntertitialAd.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol CJZFAdSDKInterstitialAdDelegate;

@interface CJZFAdSDKInterstitialAd : NSObject

/**
 代理回调
*/
@property (nonatomic, weak) id<CJZFAdSDKInterstitialAdDelegate> delegate;

/*
 viewControllerForPresentingModalView
 详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

/**
 请求超时时间,默认为4s,需要设置3s及以上
 */
@property (nonatomic, assign) NSInteger tolerateTimeout;

/**
 广告位id
*/
@property (nonatomic, copy) NSString *posId;

/**
 广告尺寸，需与平台所申请广告位比例一致，否则会导致素材压缩
 */
@property (nonatomic, assign) CGSize adSize;

/**
 是否静音，默认静音
 */
@property (nonatomic, assign) BOOL isMuted;

/**
 是否展示关闭按钮，默认展示，为YES则不展示
*/
@property (nonatomic, assign) BOOL hiddenCloseView;

/**
 *  广告是否有效，以下情况会返回NO，建议在展示广告之前判断，否则会影响计费或展示失败
 *  a.广告未拉取成功
 *  b.广告已经曝光过
 *  c.广告过期
 *
 */
@property (nonatomic, readonly) BOOL isAdValid;

/**
 自定义处理广告落地页，当渠道为bwt时有效，点击回调中会带有广告落地页地址
*/
@property (nonatomic, assign) BOOL customLoadingPage;

/**
 插屏展示时间，对渠道广点通无效，默认为0（为0则需要用户手动关闭）
 */
@property (nonatomic, assign) NSInteger showTime DEPRECATED_MSG_ATTRIBUTE("参数已经废弃，设置该参数无效");

/**
 点击插屏空白处关闭广告，对渠道广点通无效，默认为false
 */
@property (nonatomic, assign) BOOL touchClose DEPRECATED_MSG_ATTRIBUTE("参数已经废弃，设置该参数无效");

/**
 加载广告数据
*/
- (void)loadAdData;

/**
 展示广告
*/
- (void)show;

- (void)setInterstitialScenes:(NSDictionary *)scenes;

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

@protocol CJZFAdSDKInterstitialAdDelegate <NSObject>

/**
 CJZFAdSDKIntertitialAd请求成功回调
 
 @param interstitialAd 插屏广告实例对象
*/
- (void)CJZF_interstitialAdSuccedToLoad:(CJZFAdSDKInterstitialAd *)interstitialAd;

/**
 CJZFAdSDKIntertitialAd请求失败回调

 @param interstitialAd 插屏广告实例对象
 @param error 失败原因
*/
- (void)CJZF_interstitialAdFailedToLoad:(CJZFAdSDKInterstitialAd *)interstitialAd error:(NSError *)error;

/**
 CJZFAdSDKIntertitialAd展示在屏幕内回调

 @param interstitialAd 插屏广告实例对象
*/
- (void)CJZF_interstitialAdDidPresent:(CJZFAdSDKInterstitialAd *)interstitialAd;

/**
 CJZFAdSDKIntertitialAd展示在屏幕内失败回调

 @param interstitialAd 插屏广告实例对象
*/
- (void)CJZF_interstitialAdFailedToPresent:(CJZFAdSDKInterstitialAd *)interstitialAd error:(NSError *)error;

/**
 CJZFAdSDKIntertitialAd点击回调

 @param interstitialAd 插屏广告实例对象
 @param loadingPageURL 广告落地页地址，当渠道为*，并且customLoadingPage为YES时有值
*/
- (void)CJZF_interstitialAdDidClick:(CJZFAdSDKInterstitialAd *)interstitialAd loadingPageURL:(NSString *)loadingPageURL DEPRECATED_MSG_ATTRIBUTE("该回调即将废弃，请使用CJZF_interstitialAdDidClickReport:回调方法");

/**
 CJZFAdSDKIntertitialAd关闭回调

 @param interstitialAd 插屏广告实例对象
*/
- (void)CJZF_interstitialAdDidClose:(CJZFAdSDKInterstitialAd *)interstitialAd;

/**
 CJZFAdSDKIntertitialAd展示回调
 
 @param interstitialAd 广告实例
 */
- (void)CJZF_interstitialAdExposure:(CJZFAdSDKInterstitialAd *)interstitialAd DEPRECATED_MSG_ATTRIBUTE("该回调即将废弃，请使用CJZF_interstitialAdExposureReport:回调方法");;

/**
 CJZFAdSDKIntertitialAd展示上报回调
 
 @param interstitialAd 广告实例
 */
- (void)CJZF_interstitialAdExposureReport:(CJZFAdSDKInterstitialAd *)interstitialAd;


/**
 CJZFAdSDKIntertitialAd点击上报回调

 @param interstitialAd 插屏广告实例对象
*/
- (void)CJZF_interstitialAdDidClickReport:(CJZFAdSDKInterstitialAd *)interstitialAd;

/**
 CJZFAdSDKIntertitialAd关闭落地页回调
 
 @param interstitialAd 广告实例
 */
- (void)CJZF_interstitialAdCloseLandingPage:(CJZFAdSDKInterstitialAd *)interstitialAd;

@end

NS_ASSUME_NONNULL_END
