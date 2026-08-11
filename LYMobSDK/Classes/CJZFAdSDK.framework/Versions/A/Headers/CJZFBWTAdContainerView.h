//
//  CJZFBWTAdContainerView.h
//  CJZFAdSDK_Example
//
//  Created by 早范 on 2025/4/21.
//

#import <UIKit/UIKit.h>

typedef NSString * CJZFSDKAdapterAdType NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXPORT CJZFSDKAdapterAdType _Nonnull const CJZFSDKAdapterAdTypeBanner;

FOUNDATION_EXPORT CJZFSDKAdapterAdType _Nonnull const CJZFSDKAdapterAdTypeNativeExpress;

NS_ASSUME_NONNULL_BEGIN

@class CJZFBWTAdContainerView;

@protocol CJZFBWTAdContainerViewDelegate <NSObject>

- (void)adContainerViewDidReceived:(CJZFBWTAdContainerView *)adContainerView;

- (void)adContainerViewFailToReceived:(CJZFBWTAdContainerView *)adContainerView error:(NSError *)error;

- (void)adContainerViewClicked:(CJZFBWTAdContainerView *)adContainerView loadingPageURL:(NSString *)loadingPageURL DEPRECATED_MSG_ATTRIBUTE("该回调即将废弃，请使用adContainerViewClickedReport:回调方法");

- (void)adContainerViewExposure:(CJZFBWTAdContainerView *)adContainerView DEPRECATED_MSG_ATTRIBUTE("该回调即将废弃，请使用adContainerViewExposureReport:回调方法");

- (void)adContainerViewClickedReport:(CJZFBWTAdContainerView *)adContainerView;

- (void)adContainerViewExposureReport:(CJZFBWTAdContainerView *)adContainerView;

- (void)adContainerViewClose:(CJZFBWTAdContainerView *)adContainerView;

- (void)adContainerViewCloseLandingPage:(CJZFBWTAdContainerView *)adContainerView;

@end

@interface CJZFBWTAdContainerView : UIView
// 是否支持左滑关闭
@property (nonatomic, assign) BOOL swipeLeft DEPRECATED_MSG_ATTRIBUTE("参数已经废弃，设置该参数无效");
// 是否支持右滑关闭
@property (nonatomic, assign) BOOL swipeRight DEPRECATED_MSG_ATTRIBUTE("参数已经废弃，设置该参数无效");
// 广告展示时间，单位：秒，为0，则不限制展示时间，默认为0
@property (nonatomic, assign) NSInteger showTime;
// 请求广告类型，目前支持banner和信息流模板广告
@property (nonatomic, assign) CJZFSDKAdapterAdType adType;
// 背景颜色
@property (nonatomic, strong) UIColor *backgroundViewColor;
/**
 广告生命周期代理
*/
@property (nonatomic, weak) id<CJZFBWTAdContainerViewDelegate> delegate;
/**
 banner刷新时间间隔，30-120s之间,adType为banner必填
*/
@property (nonatomic, assign) int refershTime;

/**
 自定义处理广告落地页，当渠道为bwt时有效，点击回调中会带有广告落地页地址
*/
@property (nonatomic, assign) BOOL customLoadingPage;

/**
 是否静音，默认静音，信息流模版广告需要
 */
@property (nonatomic, assign) BOOL isMuted;

/**
 是否展示关闭按钮，默认不展示，为YES则展示
*/
@property (nonatomic, assign) BOOL showCloseView;

/**
 信息流自动播放，默认WiFi自动播放 开启后WiFi/4G自动播放，信息流模版广告需要
 */
@property(nonatomic ,assign) BOOL autoPlay;

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

- (void)setAdScenes:(NSDictionary *)scenes;

- (void)requestAdViewWithPosId:(NSString *)posid;

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

NS_ASSUME_NONNULL_END
