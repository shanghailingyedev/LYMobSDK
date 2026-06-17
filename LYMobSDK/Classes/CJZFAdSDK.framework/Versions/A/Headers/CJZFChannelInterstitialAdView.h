//
//  CJZFChannelInterstitialAdView.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/4/17.
//

#import <UIKit/UIKit.h>
#import "CJZFUtilsKit.h"
#import "CJZFChannelCommonView.h"

NS_ASSUME_NONNULL_BEGIN

@class CJZFChannelInterstitialAdView;
@class CJZFChannelAdData;

@protocol CJZFChannelInterstitialAdViewDelegate <NSObject>

- (void)channelInterstitialAdViewExposure:(CJZFChannelInterstitialAdView *)interstitialAdView;

- (void)channelInterstitialAdViewClicked:(CJZFChannelInterstitialAdView *)interstitialAdView loadingPageURL:(NSString *)loadingPageURL;

- (void)channelInterstitialAdViewClose:(CJZFChannelInterstitialAdView *)interstitialAdView;

- (void)channelInterstitialAdViewCloseLandingPage:(CJZFChannelInterstitialAdView *)interstitialAdView;

@optional
- (UIViewController *)channelAdViewController;

- (CJZFAdSDKLandingPageType)channelAdViewLandingPageType;

- (CGFloat)channelHalfLandingPageBackgroundColorAlpha;

@end

@interface CJZFChannelInterstitialAdView : CJZFChannelCommonView

@property (nonatomic, weak) id<CJZFChannelInterstitialAdViewDelegate> delegate;

/// [必填] 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak) UIViewController *currentViewController;

@property (nonatomic, assign) BOOL customLoadingPage;

@property (nonatomic, strong) CJZFChannelAdData *model;

@property (nonatomic, copy) void (^clickReport)(CGPoint sPoint, CGPoint point);


/**
 是否展示关闭按钮，默认展示，为YES则不展示
*/
@property (nonatomic, assign) BOOL hiddenCloseView;

- (NSError *)renderInterstitialAdView:(CJZFChannelAdData *)adData;

@end

NS_ASSUME_NONNULL_END
