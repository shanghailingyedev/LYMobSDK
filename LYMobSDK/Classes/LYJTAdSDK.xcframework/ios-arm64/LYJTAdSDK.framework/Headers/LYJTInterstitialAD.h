//
//  JTInteractionAD.h
//  JTAdSDK
//
//  Created by Frank on 2025/6/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class LYJTInterstitialAD;

@protocol JTInterstitialAdDelegate <NSObject>

@optional

// 插屏广告加载成功
- (void)jtInterstitialAdLoadSuccess:(LYJTInterstitialAD *)interstitial;

// 插屏广告加载失败回调
- (void)jtInterstitialAdLoadFail:(LYJTInterstitialAD *)interstitial error:(NSError *)error;

// 插屏广告展示成功
- (void)jtInterstitialAdExposureSuccess:(LYJTInterstitialAD *)interstitial;

// 插屏广告展示失败
- (void)jtInterstitialAdExposureFail:(LYJTInterstitialAD *)interstitial error:(NSError *)error;

// 插屏广告点击回调
- (void)jtInterstitialAdClickContent:(LYJTInterstitialAD *)interstitial;

// 插屏广告关闭回调
- (void)jtInterstitialAdClosed:(LYJTInterstitialAD *)interstitial;

@end

@interface LYJTInterstitialAD : LYJTBaseAdModel

/// 插屏广告事件回调
@property (nonatomic, weak, nullable) id<JTInterstitialAdDelegate> delegate;

/// 广告位模型
@property (nonatomic, strong, readonly) LYJTAdSlot *slot;

/// 通过Slot ID初始化插屏广告
/// - Parameters:
///   - itemId: 广告位ID
- (instancetype)initWithSlotID:(NSString *)itemId;

/// 装载广告
- (void)loadAdData;

/// 展示插屏广告
/// - Parameters:
///   - rootVC: 根控制器
- (void)showInterstitialAdFromRootViewController:(UIViewController *)rootVC;

@end

NS_ASSUME_NONNULL_END
