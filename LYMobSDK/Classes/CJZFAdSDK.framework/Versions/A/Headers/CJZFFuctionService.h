//
//  CJZFFuctionService.h
//  CJZFAdSDK-Core
//
//  Created by 早范 on 2025/9/2.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol CJZFFuctionServiceDelegate;

@interface CJZFFuctionService : UIView

/**
 广告生命周期代理
*/
@property (nonatomic, weak) id<CJZFFuctionServiceDelegate> delegate;

/**
 广告位id
*/
@property (nonatomic, copy) NSString *posId;

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

/**
 设置场景参数
*/
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

@protocol CJZFFuctionServiceDelegate <NSObject>

/**
 广告获取成功
 
 @param fuctionService banner实例
 */
- (void)CJZF_fuctionServiceDidReceived:(CJZFFuctionService *)fuctionService;

/**
 广告拉取失败
 
 @param fuctionService banner实例
 @param error 错误描述
 */
- (void)CJZF_fuctionServiceFailToReceived:(CJZFFuctionService *)fuctionService error:(NSError *)error;

/**
 广告点击
 
 @param fuctionService 广告实例
 @param loadingPageURL 广告落地页地址，当渠道为*，并且customLoadingPage为YES时有值
 */
- (void)CJZF_fuctionServiceClicked:(CJZFFuctionService *)fuctionService loadingPageURL:(NSString *)loadingPageURL DEPRECATED_MSG_ATTRIBUTE("该回调即将废弃，请使用CJZF_fuctionServiceClickedReport:回调方法");

/**
 广告点击上报
 
 @param fuctionService 广告实例
 */
- (void)CJZF_fuctionServiceClickedReport:(CJZFFuctionService *)fuctionService;

/**
 广告关闭
 
 @param fuctionService 广告实例
 */
- (void)CJZF_fuctionServiceClose:(CJZFFuctionService *)fuctionService;

/**
 广告展示
 
 @param fuctionService 广告实例
 */
- (void)CJZF_fuctionServiceExposure:(CJZFFuctionService *)fuctionService DEPRECATED_MSG_ATTRIBUTE("该回调即将废弃，请使用CJZF_fuctionServiceExposureReport:回调方法");

/**
 广告展示上报
 
 @param fuctionService 广告实例
 */
- (void)CJZF_fuctionServiceExposureReport:(CJZFFuctionService *)fuctionService;

/**
 关闭落地页
 
 @param fuctionService 广告实例
 */
- (void)CJZF_fuctionServiceCloseLandingPage:(CJZFFuctionService *)fuctionService;

@end

NS_ASSUME_NONNULL_END
