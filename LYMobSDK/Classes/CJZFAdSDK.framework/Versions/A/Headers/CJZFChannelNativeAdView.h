//
//  CJZFChannelNativeAdView.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/5/7.
//

#import <UIKit/UIKit.h>
#import "CJZFChannelCommonView.h"
#if __has_include(<CJZFAdSDK-Adapter/CJZFAdSDKAdapter.h>)
#import <CJZFAdSDK-Adapter/CJZFAdSDKAdapter.h>
#else
#import "CJZFAdSDKAdapter.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@protocol CJZFChannelNativeAdViewDelegate;
@class CJZFChannelAdData;
@class CJZFAdapterCommonReportMark;

@interface CJZFChannelNativeAdView : CJZFChannelCommonView<CJZFAdapterNativeAdViewDelegate>

@property (nonatomic, weak) id<CJZFChannelNativeAdViewDelegate> delegate;

@property (nonatomic, strong) CJZFAdapterCommonReportMark *mark;

@property (nonatomic, assign) NSInteger countDown;

@property (nonatomic, assign) BOOL customLoadingPage;

/// [必填] 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak) UIViewController *currentViewController;

@property (nonatomic, copy) void (^clickReport)(CGPoint sPoint, CGPoint point, CGSize size, NSString *adType);

- (void)setNativeAdData:(CJZFChannelAdData *)adData;

@end

@protocol CJZFChannelNativeAdViewDelegate <NSObject>

- (void)channelNativeAdViewExpose:(CJZFChannelNativeAdView *)adView;

- (void)channelNativeAdViewClick:(CJZFChannelNativeAdView *)adView ldp:(NSString *)ldp;

- (void)channelNativeAdViewClose:(CJZFChannelNativeAdView *)adView;

- (void)channelNativeAdViewCloseLandingPageView:(CJZFChannelNativeAdView *)adView;

- (void)channelNativeAdViewErrorReport:(CJZFChannelNativeAdView *)adView error:(NSError *)error;

- (UIViewController *)channelAdViewController;

- (CJZFAdSDKLandingPageType)channelAdViewLandingPageType;

- (CGFloat)channelHalfLandingPageBackgroundColorAlpha;

@end

NS_ASSUME_NONNULL_END
