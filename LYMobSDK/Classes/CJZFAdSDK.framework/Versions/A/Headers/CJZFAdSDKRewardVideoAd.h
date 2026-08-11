//
//  CJZFAdSDKRewardVideoAd.h
//  CJZFAdSDK-Core
//
//  Created by 早范 on 2025/2/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol CJZFAdSDKRewardVideoAdDelegate;

@interface CJZFAdSDKRewardVideoAd : NSObject

/**
 *  广告是否有效，以下情况会返回NO，建议在展示广告之前判断，否则会影响计费或展示失败
 *  a.广告未拉取成功
 *  b.广告已经曝光过
 *  c.广告过期
 *
 */
@property (nonatomic, readonly) BOOL isAdValid;

/**
 广告是否静音播放，默认非静音播放
*/
@property (nonatomic) BOOL videoMuted;

/**
 广告生命周期代理
*/
@property (nonatomic, weak) id <CJZFAdSDKRewardVideoAdDelegate> delegate;

/*
 viewControllerForPresentingModalView
 详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

/**
 广告位id
*/
@property (nonatomic, copy) NSString *posId;

/**
 加载广告方法
 */
- (void)loadAdData;
/**
 展示广告方法

 @param rootViewController 用于 present 激励视频 VC
 */
- (void)showRewardVideoAdFromRootViewController:(UIViewController *)rootViewController;

/**
 设置激励视频场景id
 */
- (void)setRewardVideoAdScenes:(NSDictionary *)scenes;

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

@protocol CJZFAdSDKRewardVideoAdDelegate <NSObject>

@optional


/**
 广告数据加载成功回调

 @param rewardedVideoAd CJZFAdSDKRewardVideoAd 实例
 */
- (void)CJZF_rewardVideoAdDidLoad:(CJZFAdSDKRewardVideoAd *)rewardedVideoAd;

///**
// 视频数据下载成功回调，已经下载过的视频会直接回调
//
// @param rewardedVideoAd CJZFAdSDKRewardVideoAd 实例
// */
//- (void)CJZF_rewardVideoAdVideoDidLoad:(CJZFAdSDKRewardVideoAd *)rewardedVideoAd;

/**
 视频播放页即将展示回调

 @param rewardedVideoAd CJZFAdSDKRewardVideoAd 实例
 */
- (void)CJZF_rewardVideoAdWillVisible:(CJZFAdSDKRewardVideoAd *)rewardedVideoAd;

/**
 视频广告曝光回调

 @param rewardedVideoAd CJZFAdSDKRewardVideoAd 实例
 */
- (void)CJZF_rewardVideoAdDidExposed:(CJZFAdSDKRewardVideoAd *)rewardedVideoAd;

/**
 视频广告曝光上报回调（只会回调一次）

 @param rewardedVideoAd CJZFAdSDKRewardVideoAd 实例
 */
- (void)CJZF_rewardVideoAdDidExposeReport:(CJZFAdSDKRewardVideoAd *)rewardedVideoAd;

/**
 视频播放页关闭回调

 @param rewardedVideoAd CJZFAdSDKRewardVideoAd 实例
 */
- (void)CJZF_rewardVideoAdDidClose:(CJZFAdSDKRewardVideoAd *)rewardedVideoAd;

/**
 视频广告信息点击回调（可能回调多次）

 @param rewardedVideoAd CJZFAdSDKRewardVideoAd 实例
 */
- (void)CJZF_rewardVideoAdDidClicked:(CJZFAdSDKRewardVideoAd *)rewardedVideoAd;

/**
 视频广告信息点击上报回调（只会回调一次）

 @param rewardedVideoAd CJZFAdSDKRewardVideoAd 实例
 */
- (void)CJZF_rewardVideoAdDidClickReport:(CJZFAdSDKRewardVideoAd *)rewardedVideoAd;

/**
 视频广告各种错误信息回调

 @param rewardedVideoAd CJZFAdSDKRewardVideoAd 实例
 @param error 具体错误信息
 */
- (void)CJZF_rewardVideoAd:(CJZFAdSDKRewardVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error;


/**
 视频广告播放达到激励条件回调

 @param rewardedVideoAd CJZFAdSDKRewardVideoAd 实例
 */
- (void)CJZF_rewardVideoAdDidRewardEffective:(CJZFAdSDKRewardVideoAd *)rewardedVideoAd;

/**
 视频广告视频播放完成

 @param rewardedVideoAd CJZFAdSDKRewardVideoAd 实例
 */
- (void)CJZF_rewardVideoAdDidPlayFinish:(CJZFAdSDKRewardVideoAd *)rewardedVideoAd;

@end

NS_ASSUME_NONNULL_END
