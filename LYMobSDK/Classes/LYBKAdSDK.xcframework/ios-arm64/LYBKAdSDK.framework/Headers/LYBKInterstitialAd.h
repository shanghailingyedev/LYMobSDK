//
//  LYBKInterstitialAd.h
//  LYBKAdSDK
//
//  Created by coderqi on 2025/11/14.
//

#import <Foundation/Foundation.h>
#import <LYBKAdSDK/LYBKInterstitialSlot.h>
#import <LYBKAdSDK/LYBKBaseAd.h>

NS_ASSUME_NONNULL_BEGIN

@class LYBKInterstitialAd;

@protocol LYBKInterstitialAdDelegate <NSObject>

@optional
/**
 *  广告加载成功
 * @param interstititalAd  广告对象
 */
- (void)lybk_InterAdLoadSuccess:(LYBKInterstitialAd *)interstititalAd;

/**
 *  广告加载失败
 * @param interstititalAd  广告对象
 * @param error  错误信息
 */
- (void)lybk_InterAdLoadFail:(LYBKInterstitialAd *)interstititalAd withError:(NSError *)error;


/**
 * 广告展示成功
 * @param interstititalAd  广告对象
 */
- (void)lybk_InterAdShowSuccess:(LYBKInterstitialAd *)interstititalAd;

/**
 * 广告展示失败
 * @param interstititalAd  广告对象
 */
- (void)lybk_InterAdShowFail:(LYBKInterstitialAd *)interstititalAd withError:(NSError *)error;

/**
 * 广告点击
 * @param interstititalAd  广告数据
 */
- (void)lybk_InterAdDidClicked:(LYBKInterstitialAd *)interstititalAd;

/**
 * 广告关闭
 * @param interstititalAd  广告数据
 */
- (void)lybk_InterAdDidClosed:(LYBKInterstitialAd *)interstititalAd;

/**
 * sdk广告跳转落地页关闭回调
 * @param interstititalAd  广告对象
 */
- (void)lybk_InterAdWebPageClose:(LYBKInterstitialAd *)interstititalAd;

@end

@interface LYBKInterstitialAd : LYBKBaseAd

/// 广告请求参数
@property (nonatomic, strong, readonly) LYBKInterstitialSlot *adSlot;

@property (nonatomic, weak) id <LYBKInterstitialAdDelegate> delegate;

/**
 * @brief 初始化view
 */
- (instancetype)initWithSlot:(LYBKInterstitialSlot *)slot;

/**
 *  加载广告
 */
- (void)loadAd;

/**
 *  展示开屏广告
 *  @param rootViewController 展示开屏广告的UIViewController
 *  曝光时，请确保rootViewController无presentedVC，否则影响广告展示、点击、落地页打开
 */
- (void)showAdFromRootViewController:(UIViewController *)rootViewController;

/**
 * 获取广告出价
 * 广告加载成功之后，才会有值
 *  单位：分
 */
- (NSInteger)getBidPrice;

/**
 * 聚合竞价结果回传
 */
- (void)sendBidResultNotificationWithInfo:(NSDictionary *)infoDic andResut:(BOOL)isSucc;

/**
 * 获取图片素材地址
 */
- (NSArray<NSString *> *)getImageFileUrls;

/**
 * 获取视频素材地址
 */
- (NSArray<NSString *> *)getVideoFileUrls;

/**
 * 获取广告素材信息（素材ID + 视频素材地址）。
 * 仅当全局拓展字段 c_g_m_i=1（canGetMaterialInfo）时返回有效对象，否则返回 nil；
 * 非视频广告时 videoUrl 为 nil。
 */
- (nullable LYBKMaterialInfo *)getMaterialInfo;

/**
 * 获取落地页地址
 */
- (NSString *)getLandpageUrl;

@end

NS_ASSUME_NONNULL_END
