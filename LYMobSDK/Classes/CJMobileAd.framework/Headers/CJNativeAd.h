//
//  CJNativeAd.h
//  CJMobileAd
//
//  Created by shanghailingye 2022/2/26.
//  Copyright © 2022Jun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class CJNativeAd;
@protocol CJNativeAdDelegate <NSObject>

- (void)nativeExpressAdDidLoad:(id)nativeExpressAd views:(NSArray *)nativeExpressViews;

- (void)nativeExpressAdOnShow:(id)nativeExpressView;

- (void)nativeExpressAdLoadFailed:(id)nativeExpressAd error:(NSError *)error;

- (void)nativeExpressAdOnClicked:(id)nativeExpressView;

- (void)nativeExpressAdOnClosed:(id)nativeExpressView;

@end

@interface CJNativeAd : NSObject

@property (nonatomic, weak) id <CJNativeAdDelegate> delegate;

/// 广告位ID
@property (nonatomic, readonly, copy) NSString *resourceId;

/// 广告渲染成功view，在加载成功回调中可以获取
@property (nonatomic, readonly, strong) UIView *adView;

- (instancetype)initWithSlotId:(NSString *)resourceId size:(CGSize)size rootViewController:(UIViewController *)rootViewController;

- (void)loadAdData:(NSInteger)count;

- (NSString *)getAdType;

- (NSInteger)getECpm;

/// 手动销毁，可以在没有主动触发onClose且需要关闭信息流时调用
- (void)destoryAd;

@end

NS_ASSUME_NONNULL_END
