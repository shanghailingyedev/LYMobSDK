//
//  CJZFAdSDKServiceAdView.h
//  CJZFAdSDK-Core
//
//  Created by 早范 on 2025/1/4.
//

#import <UIKit/UIKit.h>
#import "CJZFAdSDKCoreConfig.h"

NS_ASSUME_NONNULL_BEGIN

@protocol CJZFSDKServiceAdViewDelegate;

@interface CJZFAdSDKServiceAdView : UIView

/**
 广告生命周期代理
*/
@property (nonatomic, weak) id<CJZFSDKServiceAdViewDelegate> delegate;

/**
 广告位id
*/
@property (nonatomic, copy) NSString *posId;

/**
 广告刷新时间间隔，30-120s之间.
*/
@property (nonatomic, assign) int refershTime;

/**
 自定义处理广告落地页，当渠道为bwt时有效，点击回调中会带有广告落地页地址
*/
@property (nonatomic, assign) BOOL customLoadingPage;

/**
 是否展示关闭按钮，默认不展示，为YES则展示
*/
@property (nonatomic, assign) BOOL showCloseView;

/**
 viewControllerForPresentingModalView
 详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
*/
@property (nonatomic, weak) UIViewController *controller;

- (id)new NS_UNAVAILABLE;
- (id)init NS_UNAVAILABLE;

/*
 初始化bannerView
 @param frame 期望的banner视图尺寸
*/
- (instancetype)initWithFrame:(CGRect)frame;

/**
 拉取并展示广告
*/
- (void)loadAndShow;

- (void)reloadData;

- (void)setAdScenes:(NSDictionary *)scenes;

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

@protocol CJZFSDKServiceAdViewDelegate <NSObject>

/**
 广告获取成功
 
 @param serviceAdView banner实例
 */
- (void)CJZF_serviceAdViewDidReceived:(CJZFAdSDKServiceAdView *)serviceAdView;

/**
 广告拉取失败
 
 @param serviceAdView banner实例
 @param error 错误描述
 */
- (void)CJZF_serviceAdViewFailToReceived:(CJZFAdSDKServiceAdView *)serviceAdView error:(NSError *)error;

/**
 广告点击
 
 @param serviceAdView 广告实例
 @param loadingPageURL 广告落地页地址，当渠道为*，并且customLoadingPage为YES时有值
 */
- (void)CJZF_serviceAdViewClicked:(CJZFAdSDKServiceAdView *)serviceAdView loadingPageURL:(NSString *)loadingPageURL DEPRECATED_MSG_ATTRIBUTE("该回调即将废弃，请使用CJZF_serviceAdViewClickedReport:回调方法");

/**
 广告关闭
 
 @param serviceAdView 广告实例
 */
- (void)CJZF_serviceAdViewClose:(CJZFAdSDKServiceAdView *)serviceAdView;

/**
 广告展示
 
 @param serviceAdView 广告实例
 */
- (void)CJZF_serviceAdViewExposure:(CJZFAdSDKServiceAdView *)serviceAdView DEPRECATED_MSG_ATTRIBUTE("该回调即将废弃，请使用CJZF_serviceAdViewExposureReport:回调方法");

/**
 广告展示上报
 
 @param serviceAdView 广告实例
 @discussion 当非标广告成功展示时，SDK会调用此方法。接入方可以在此回调中进行广告曝光的数据统计。
 */
- (void)CJZF_serviceAdViewExposureReport:(CJZFAdSDKServiceAdView *)serviceAdView;

/**
 广告点击上报
 
 @param serviceAdView 广告实例
 @discussion 当非标广告成功点击时，SDK会调用此方法。接入方可以在此回调中进行广告点击的数据统计。
 */
- (void)CJZF_serviceAdViewClickedReport:(CJZFAdSDKServiceAdView *)serviceAdView;

/**
 关闭落地页
 
 @param serviceAdView 广告实例
 */
- (void)CJZF_serviceAdViewCloseLandingPage:(CJZFAdSDKServiceAdView *)serviceAdView;

@optional

- (CJZFLandingPageType)CJZF_landingPageType;

- (CGFloat)CJZF_halfLandingPageBackgroundColorAlpha;

- (CGSize)CJZF_closeViewSize;

@end
NS_ASSUME_NONNULL_END
