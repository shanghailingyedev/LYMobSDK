//
//  LYBKSplashAd.h
//  LYBKAdSDK
//
//  Created by coderqi on 2025/11/13.
//

#import <UIKit/UIKit.h>
#import <LYBKAdSDK/LYBKBaseAd.h>
#import <LYBKAdSDK/LYBKSplashAdSlot.h>



NS_ASSUME_NONNULL_BEGIN

@class LYBKSplashAd;
@protocol LYBKSplashAdDelegate <NSObject>
/**
 *  广告请求返回物料并解析成功。竞价/取价可在此进行；展示建议等到素材缓存完成。
 */
- (void)lybk_SplashAdDidLoad:(LYBKSplashAd *)splashAd;

/**
 *  广告请求失败
 *  @param error 失败原因
 */
- (void)lybk_SplashAdFailedToLoad:(LYBKSplashAd *)splashAd withError:(NSError *)error;

/**
 *  广告素材下载完成，可在此调用 showAd 展示
 */
- (void)lybk_SplashAdDidCacheFinished:(LYBKSplashAd *)splashAd;

/**
 *  广告即将展示
 */
- (void)lybk_SplashAdWillShow:(LYBKSplashAd *)splashAd;

/**
 *  广告展示完毕
 */
- (void)lybk_SplashAdDidShow:(LYBKSplashAd *)splashAd;

/**
 *  广告展示失败，未能正确显示在屏幕上: 如调用showAd时，window不是keywindow
 *  @param error 失败原因
 */
- (void)lybk_SplashAdFailedToShow:(LYBKSplashAd *)splashAd withError:(NSError *)error;
/**
 *  广告点击回调
 */
- (void)lybk_SplashAdDidClick:(LYBKSplashAd *)splashAd;

/**
 *  广告关闭回调：跳过/倒计时结束/点击广告后广告view被移除
 */
- (void)lybk_SplashAdDidClose:(LYBKSplashAd *)splashAd isSkip:(BOOL)isSkip;

/**
 *  广告转化完成：关闭落地页或者跳转到其他应用
 */
//- (void)apSplashAdDidFinishConversion:(LYBKSplashAd *)splashAd interactionType:(UBiXAdInteractionType)interactionType;

@end

@interface LYBKSplashAd : LYBKBaseAd

/// 广告请求参数
@property (nonatomic, strong, readonly) LYBKSplashAdSlot *adSlot;

/// 回调委托对象
@property (nonatomic, weak) id<LYBKSplashAdDelegate> delegate;

/// @required 用于打开落地页，确保ta当前无presentedVC，否则将无法打开落地页
@property (nonatomic, weak) UIViewController *rootViewController;

@property (nonatomic, strong) UIView *bottomView;

/**
 *  构造方法
 *  @param slot 广告位请求参数
 */
- (instancetype)initWithSlot:(LYBKSplashAdSlot *)slot;

/**
 *  加载广告
 */
- (void)loadAd;

/**
 *  展示开屏广告
 *  @param window 展示开屏广告的UIWindow
 *  @param bottomView 开发者自定义底部logo，建议高度不超过屏幕高度的1/4
 *  曝光时，请确保window.rootViewController无presentedVC，否则影响广告展示、点击、落地页打开
 */
- (void)showAdToWindow:(UIWindow *)window bottomView:(UIView * _Nullable)bottomView;

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
 * 关闭并销毁广告
 */
- (void)destoryAd;

/**
 * 获取图片素材地址
 */
- (NSArray<NSString *> *)getImageFileUrls;

/**
 * 获取视频素材地址
 */
- (NSArray<NSString *> *)getVideoFileUrls;

/**
 * 获取落地页地址
 */
- (NSString *)getLandpageUrl;

/**
 * 获取广告素材信息（素材ID + 视频素材地址）。
 * 仅当全局拓展字段 c_g_m_i=1（canGetMaterialInfo）时返回有效对象，否则返回 nil；
 * 非视频广告时 videoUrl 为 nil。
 */
- (nullable LYBKMaterialInfo *)getMaterialInfo;

@end

NS_ASSUME_NONNULL_END
