//
//  LYBKRewardVideoAd.h
//  LYBKAdSDK
//
//  Created by coderqi on 2025/11/14.
//

#import <Foundation/Foundation.h>
#import <LYBKAdSDK/LYBKRewardVideoSlot.h>
#import <LYBKAdSDK/LYBKBaseAd.h>

NS_ASSUME_NONNULL_BEGIN

@class LYBKRewardVideoAd;
@class LYBKRewardVideoSlot;

@protocol LYBKRewardVideoAdDelegate <NSObject>

@optional
/**
 *  广告加载成功
 * @param rewardAd  广告对象
 */
- (void)lybk_RewardAdLoadSuccess:(LYBKRewardVideoAd *)rewardAd;

/**
 *  广告加载失败
 * @param rewardAd  广告对象
 * @param error  错误信息
 */
- (void)lybk_RewardAdLoadFail:(LYBKRewardVideoAd *)rewardAd withError:(NSError *)error;


/**
 * 广告展示成功
 * @param rewardAd  广告对象
 */
- (void)lybk_RewardAdShowSuccess:(LYBKRewardVideoAd *)rewardAd;

/**
 * 广告展示失败
 * @param rewardAd  广告对象
 */
- (void)lybk_RewardAdShowFail:(LYBKRewardVideoAd *)rewardAd withError:(NSError *)error;

/**
 * 广告播放开始
 * @param rewardAd  广告对象
 */
- (void)lybk_RewardAdPlayStart:(LYBKRewardVideoAd *)rewardAd;

/**
 * 广告播放结束
 * @param rewardAd  广告对象
 */
- (void)lybk_RewardAdPlayFinished:(LYBKRewardVideoAd *)rewardAd;

/**·
 * 广告点击
 * @param rewardAd  广告对象
 */
- (void)lybk_RewardAdDidClicked:(LYBKRewardVideoAd *)rewardAd;

/**
 * 广告关闭
 * @param rewardAd  广告对象
 */
- (void)lybk_RewardAdDidClosed:(LYBKRewardVideoAd *)rewardAd;

/**
 * 广告点击跳过
 * @param rewardAd  广告对象
 */
- (void)lybk_RewardAdDidSkiped:(LYBKRewardVideoAd *)rewardAd;

/**
 * sdk广告跳转落地页关闭回调
 * @param rewardAd  广告对象
 */
- (void)lybk_RewardAdWebPageClose:(LYBKRewardVideoAd *)rewardAd;

/**
 *  广告任务完成
 *  @param rewardAd  广告对象
 */
- (void)lybk_RewardAdTaskCompleted:(LYBKRewardVideoAd *)rewardAd;

@end

@interface LYBKRewardVideoAd : LYBKBaseAd

/// 广告请求参数
@property (nonatomic, strong, readonly) LYBKRewardVideoSlot *adSlot;

@property (nonatomic, weak) id <LYBKRewardVideoAdDelegate> delegate;

/**
 * @brief 初始化view
 */
- (instancetype)initWithSlot:(LYBKRewardVideoSlot *)slot;

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
