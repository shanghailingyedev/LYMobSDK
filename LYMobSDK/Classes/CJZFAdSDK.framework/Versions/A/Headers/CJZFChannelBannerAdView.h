//
//  CJZFChannelBannerAdView.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/4/17.
//

#import <UIKit/UIKit.h>
#import "CJZFUtilsKit.h"
#import "CJZFChannelCommonView.h"

NS_ASSUME_NONNULL_BEGIN

@class CJZFChannelBannerAdView;

@class CJZFChannelAdData;

@protocol CJZFChannelBannerAdViewDelegate <NSObject>

- (void)channelBannerAdViewExposure:(CJZFChannelBannerAdView *)bannerAdView;

- (void)channelBannerAdViewClicked:(CJZFChannelBannerAdView *)bannerAdView loadingPageURL:(NSString *)loadingPageURL;

- (void)channelBannerAdViewClose:(CJZFChannelBannerAdView *)bannerAdView;

- (void)channelBannerAdViewCloseLandingPage:(CJZFChannelBannerAdView *)bannerAdView;

- (void)channelBannerAdViewErrorReport:(CJZFChannelBannerAdView *)bannerAdView error:(NSError *)error;

@optional

- (UIViewController *)channelAdViewController;

- (CJZFAdSDKLandingPageType)channelAdViewLandingPageType;

- (CGFloat)channelHalfLandingPageBackgroundColorAlpha;

- (CGSize)bannerAdCloseViewSize;

@end

@interface CJZFChannelBannerAdView : CJZFChannelCommonView

@property (nonatomic, weak) id<CJZFChannelBannerAdViewDelegate> delegate;

@property (nonatomic, assign) BOOL customLoadingPage;

@property (nonatomic, strong) CJZFChannelAdData *model;

@property (nonatomic, assign) BOOL nonstandard;

@property (nonatomic, copy) void (^successBlock)(UIViewController *viewController);

@property (nonatomic, copy) void (^clickReport)(CGPoint sPoint, CGPoint point);

/**
 是否展示关闭按钮，默认展示，为YES则不展示
*/
@property (nonatomic, assign) BOOL hiddenCloseView;

/// [必填] 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak) UIViewController *currentViewController;

- (NSError *)renderBannerAdView:(CJZFChannelAdData *)adData;

- (void)reloadData;

@end

NS_ASSUME_NONNULL_END
