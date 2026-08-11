//
//  CJZFChannelNoticeAdView.h
//  CJZFAdSDK-Channel
//
//  Created by 早范 on 2026/5/14.
//

#import "CJZFChannelCommonView.h"
#import "CJZFChannelAdData.h"
#if __has_include(<CJZFAdSDK-Adapter/CJZFAdSDKAdapter.h>)
#import <CJZFAdSDK-Adapter/CJZFAdSDKAdapter.h>
#else
#import "CJZFAdSDKAdapter.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@protocol CJZFChannelNoticeAdViewDelegate;

@interface CJZFChannelNoticeAdView : CJZFChannelCommonView

@property (nonatomic, weak) id<CJZFChannelNoticeAdViewDelegate> delegate;

@property (nonatomic, assign) BOOL customLoadingPage;

@property (nonatomic, assign) NSInteger noticeCountDown;

/// [必填] 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak) UIViewController *currentViewController;

- (instancetype)initWithStyleType:(CJZFAdSDKNoticeAdStyleType)styleType;

- (NSError *)renderAdView:(CJZFChannelAdData *)adData;

- (void)showNoticeInWindow:(UIWindow *)window screenBottom:(BOOL)screenBottom;

- (void)showNoticeInController:(UIViewController *)controller screenBottom:(BOOL)screenBottom;

@end

@protocol CJZFChannelNoticeAdViewDelegate <NSObject>

- (void)channelNoticeAdViewExposure:(CJZFChannelNoticeAdView *)noticeAdView;

- (void)channelNoticeAdViewClicked:(CJZFChannelNoticeAdView *)noticeAdView loadingPageURL:(NSString *)loadingPageURL;

- (void)channelNoticeAdViewClose:(CJZFChannelNoticeAdView *)noticeAdView;

- (void)channelNoticeAdViewCloseLandingPage:(CJZFChannelNoticeAdView *)noticeAdView;

- (void)channelNoticeAdViewErrorReport:(CJZFChannelNoticeAdView *)noticeAdView error:(NSError *)error;

- (void)channelNoticeAdViewDidPresent:(CJZFChannelNoticeAdView *)noticeAdView;

@optional

- (UIViewController *)channelAdViewController;

- (CJZFAdSDKLandingPageType)channelAdViewLandingPageType;

- (CGFloat)channelHalfLandingPageBackgroundColorAlpha;
@end

NS_ASSUME_NONNULL_END
