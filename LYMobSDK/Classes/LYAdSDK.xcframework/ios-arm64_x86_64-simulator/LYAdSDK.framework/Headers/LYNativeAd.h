//
//  LYNativeAd.h
//  LYAdSDK
//
//  Created by coderqi on 2025/11/14.
//

#import <Foundation/Foundation.h>
#import <LYAdSDK/LYNativeAdObject.h>
#import <LYAdSDK/LYNativeAdSlot.h>
#import <LYAdSDK/LYBaseAd.h>

NS_ASSUME_NONNULL_BEGIN

@class LYNativeAdSlot;
@class LYNativeAd;

@protocol LYNativeAdDelegate <NSObject>

- (void)ly_nativeAdLoadSuccess:(LYNativeAd *)nativeAd;

- (void)ly_nativeAdLoadFail:(LYNativeAd *)nativeAd withError:(NSError *)error;



@end

@interface LYNativeAd : LYBaseAd
/// 广告请求参数
@property (nonatomic, strong, readonly) LYNativeAdSlot *adSlot;

@property (nonatomic, weak) id <LYNativeAdDelegate> delegate;

/// 广告对象，在ly_nativeAdLoadSuccess回调后有值
@property (nonatomic, strong, readonly, nullable) NSArray <LYNativeAdObject *> *nativeAdObjects;

/**
 * @brief 初始化view
 */
- (instancetype)initWithSlot:(LYNativeAdSlot *)slot;

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
- (NSError *)registerWithAdObject:(LYNativeAdObject *)adObject
                       containerView:(UIView *)containerView
                      clickableViews:(NSArray<UIView *> *_Nullable)clickableViews
                        closeView:(NSArray<UIView *> *_Nullable)closeableViews;

/**
 *  销毁广告
 */
- (void)destory;

@end

NS_ASSUME_NONNULL_END
