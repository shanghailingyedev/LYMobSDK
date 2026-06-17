//
//  CJZFChannelNativeExpressAdView.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/4/23.
//

#import <UIKit/UIKit.h>
#import "CJZFChannelAdData.h"
#import "CJZFChannelCommonView.h"
#if __has_include(<CJZFAdSDK-Adapter/CJZFAdSDKAdapter.h>)
#import <CJZFAdSDK-Adapter/CJZFAdSDKAdapter.h>
#else
#import "CJZFAdSDKAdapter.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class CJZFChannelNativeExpressAdView;

@protocol CJZFChannelNativeExpressAdViewDelegate <NSObject>

- (void)channelNativeExpressAdViewRenderSuccess:(CJZFChannelNativeExpressAdView *)nativeExpressAdView;

- (void)channelNativeExpressAdViewRenderFailed:(CJZFChannelNativeExpressAdView *)nativeExpressAdView error:(NSError *)error;

- (void)channelNativeExpressAdViewExposure:(CJZFChannelNativeExpressAdView *)nativeExpressAdView;

- (void)channelNativeExpressAdViewClicked:(CJZFChannelNativeExpressAdView *)nativeExpressAdView loadingPageURL:(NSString *)loadingPageURL;

- (void)channelNativeExpressAdViewClose:(CJZFChannelNativeExpressAdView *)nativeExpressAdView;

- (void)channelNativeExpressAdViewCloseLandingPage:(CJZFChannelNativeExpressAdView *)nativeExpressAdView;

- (void)channelNativeExpressAdViewErrorReport:(CJZFChannelNativeExpressAdView *)nativeExpressAdView error:(NSError *)error;

@optional

- (CJZFAdSDKLandingPageType)channelAdViewLandingPageType;

- (CGFloat)channelHalfLandingPageBackgroundColorAlpha;

@end

@interface CJZFChannelNativeExpressAdView : CJZFChannelCommonView<CJZFAdapterNativeExpressAdViewDelegate>

@property (nonatomic, weak) id<CJZFChannelNativeExpressAdViewDelegate> delegate;

/// [必填] 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak) UIViewController *currentViewController;

@property (nonatomic, strong) CJZFAdapterCommonReportMark *mark;

@property (nonatomic, strong) CJZFChannelAdData *adData;

@property (nonatomic, assign) BOOL customLoadingPage;

@property (nonatomic, copy) void (^clickReport)(CGPoint sPoint, CGPoint point, CGSize size);

/**
 是否展示关闭按钮，默认展示，为YES则不展示
*/
@property (nonatomic, assign) BOOL hiddenCloseView;

- (instancetype)initWithFrame:(CGRect)frame expressType:(CJZFAdapterNativeExpressType)expressType;

- (void)loadImageSuccessBlock:(void (^)(CJZFChannelNativeExpressAdView *))successBlock failedBlock:(void (^)(NSError * _Nullable error))failedBlock;

@end

NS_ASSUME_NONNULL_END
