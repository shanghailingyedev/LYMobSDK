//
//  LYBKNativeAd.h
//  LYBKAdSDK
//
//  Created by coderqi on 2025/11/14.
//

#import <Foundation/Foundation.h>
#import <LYBKAdSDK/LYBKNativeAdObject.h>
#import <LYBKAdSDK/LYBKNativeAdSlot.h>
#import <LYBKAdSDK/LYBKBaseAd.h>

NS_ASSUME_NONNULL_BEGIN

@class LYBKNativeAdSlot;
@class LYBKNativeAd;

@protocol LYBKNativeAdDelegate <NSObject>

- (void)lybk_nativeAdLoadSuccess:(LYBKNativeAd *)nativeAd;

- (void)lybk_nativeAdLoadFail:(LYBKNativeAd *)nativeAd withError:(NSError *)error;



@end

@interface LYBKNativeAd : LYBKBaseAd
/// 广告请求参数
@property (nonatomic, strong, readonly) LYBKNativeAdSlot *adSlot;

@property (nonatomic, weak) id <LYBKNativeAdDelegate> delegate;

/// 广告对象，在lybk_nativeAdLoadSuccess回调后有值
@property (nonatomic, strong, readonly, nullable) NSArray <LYBKNativeAdObject *> *nativeAdObjects;

/**
 * @brief 初始化view
 */
- (instancetype)initWithSlot:(LYBKNativeAdSlot *)slot;

/**
 *  加载广告
 */
- (void)loadAd;

/**
 *  注册自渲染view
 *  @param containerView     广告渲染容器
 *  @param clickableViews   广告可点击的views，不传：默认整个广告可响应点击
 *  @return 返回错误，检查adItem、containerView、clickableViews是否存在问题
 */
- (NSError *)registerWithAdObject:(LYBKNativeAdObject *)adObject
                       containerView:(UIView *)containerView
                      clickableViews:(NSArray<UIView *> *_Nullable)clickableViews
                        closeView:(NSArray<UIView *> *_Nullable)closeableViews;

/**
 *  销毁广告
 */
- (void)destory;

@end

NS_ASSUME_NONNULL_END
