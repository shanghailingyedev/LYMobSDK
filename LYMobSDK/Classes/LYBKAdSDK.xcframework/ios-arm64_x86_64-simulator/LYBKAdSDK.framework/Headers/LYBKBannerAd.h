//
//  LYBKBannerAd.h
//  LYBKAdSDK
//
//  Created by coderqi on 2025/11/13.
//

#import <UIKit/UIKit.h>
#import <LYBKAdSDK/LYBKBannerSlot.h>
#import <LYBKAdSDK/LYBKBannerView.h>
#import <LYBKAdSDK/LYBKBaseAd.h>

NS_ASSUME_NONNULL_BEGIN

@class LYBKBannerSlot;
@class LYBKBannerAd;

@protocol LYBKBannerAdDelegate <NSObject>

/**
 *  广告加载成功
 * @param bannerAd  广告对象
 */
- (void)lybk_BannerAdLoadSuccess:(LYBKBannerAd *)bannerAd;

/**
 *  广告加载失败
 * @param bannerAd  广告对象
 * @param error  错误信息
 */
- (void)lybk_BannerAdLoadFail:(LYBKBannerAd *)bannerAd withError:(NSError *)error;


/**
 * 广告展示成功
 * @param bannerAd  广告对象
 */
- (void)lybk_BannerAdShowSuccess:(LYBKBannerAd *)bannerAd;

/**
 * 广告展示失败
 * @param bannerAd  广告对象
 */
- (void)lybk_BannerAdShowFail:(LYBKBannerAd *)bannerAd withError:(NSError *)error;

/**
 * 广告点击
 * @param bannerAd  广告数据
 */
- (void)lybk_BannerAdDidClicked:(LYBKBannerAd *)bannerAd;

/**
 * 广告关闭
 * @param bannerAd  广告数据
 */
- (void)lybk_BannerAdDidClosed:(LYBKBannerAd *)bannerAd;

/**
 * sdk广告跳转落地页关闭回调
 * @param bannerAd  广告对象
 */
- (void)lybk_BannerAdWebPageClose:(LYBKBannerAd *)bannerAd;

@end

@interface LYBKBannerAd : LYBKBaseAd

/// 广告请求参数
@property (nonatomic, strong, readonly) LYBKBannerSlot *adSlot;

@property (nonatomic, weak) id <LYBKBannerAdDelegate> delegate;

/**
 * @brief 初始化view
 */
- (instancetype)initWithSlot:(LYBKBannerSlot *)slot;

/**
 *  加载广告
 */
- (void)loadAd;

/**
 *   获取广告View
 */
- (LYBKBannerView *)getBannerViewError:(NSError **)error;

/**
 * 销毁广告
 */
- (void)destoryAd;

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
 * 获取落地页地址
 */
- (NSString *)getLandpageUrl;

@end

NS_ASSUME_NONNULL_END
