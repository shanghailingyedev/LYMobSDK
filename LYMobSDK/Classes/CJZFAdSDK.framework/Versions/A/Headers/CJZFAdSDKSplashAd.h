//
//  CJZFAdSDKSplashAd.h
//  CJZFAdSDK-Core
//
//  Created by 早范 on 2025/9/25.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@protocol CJZFAdSDKSplashAdDelegate;

@interface CJZFAdSDKSplashAd : NSObject

/**
 广告生命周期代理
*/
@property (nonatomic, weak) id<CJZFAdSDKSplashAdDelegate> delegate;

/**
 广告位id
*/
@property (nonatomic, copy) NSString *posId;

/**
 应用id
*/
@property (nonatomic, copy) NSString *appId;


/**
 *  广告是否有效，以下情况会返回NO，建议在展示广告之前判断，否则会影响计费或展示失败
 *  a.广告未拉取成功
 *  b.广告已经曝光过
 *  c.广告过期
 *
 */
@property (nonatomic, readonly) BOOL isAdValid;

/**
 自定义处理广告落地页，当渠道为bwt时有效，点击回调中会带有广告落地页地址
*/
@property (nonatomic, assign) BOOL customLoadingPage;

/**
 展示时间，对渠道广点通无效，默认为5s
 */
@property (nonatomic, assign) NSInteger showTime;

/**
 设置广告跳过按钮位置，默认为右下角，只针对channel和zhike渠道
 */
@property (nonatomic, assign) BOOL setSkipButtonToRightTop;


/// 开屏广告的背景图片, 可以设置背景图片作为开屏加载时的默认背景
@property (nonatomic, strong) UIImage *backgroundImage;

/**
 开屏广告底部视图
 */
@property (nonatomic, strong) UIView *bottomView;

/**
 viewControllerForPresentingModalView
 详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

/**
 广告发起请求并展示在Window中
 */
- (void)loadAndShowSplashAdInWindow:(UIWindow *)window DEPRECATED_MSG_ATTRIBUTE("接口已经废弃，请使用loadSplashAd和showSplashAdInWindow:接口");

/**
 请求开屏广告，只拉取不展示
 */
- (void)loadSplashAd;

/**
 展示开屏广告
 */
- (void)showSplashAdInWindow:(UIWindow *)window;

/**
 携带底部视图，展示开屏广告
 */
- (void)showSplashInWindow:(UIWindow *)window bottomView:(UIView *)bottomView DEPRECATED_MSG_ATTRIBUTE("接口已经废弃，请使用showSplashAdInWindow:接口，并提前设置底部视图");

/**
 设置开屏场景id
 */
- (void)setSplashAdScenes:(NSDictionary *)scenes;

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


@protocol CJZFAdSDKSplashAdDelegate <NSObject>

@optional

/**
 开屏广告点击回调, 可能会打开 AppStore, WebView, ThirdApp etc.

 @param splashAd 开屏广告
 @param loadingPageURL 广告落地页地址，当渠道为bwt，并且customLoadingPage为YES时有值
 */
- (void)CJZF_splashAdDidClick:(CJZFAdSDKSplashAd *)splashAd loadingPageURL:(NSString *)loadingPageURL;

/**
 开屏广告点击上报回调

 @param splashAd 开屏广告
 @discussion 当开屏广告成功点击时，SDK会调用此方法。接入方可以在此回调中进行广告点击的数据统计。
 */
- (void)CJZF_splashAdDidClickReport:(CJZFAdSDKSplashAd *)splashAd;

/**
 开屏广告关闭回调, 触发条件: 点击广告, 点击跳过, 超时关闭

 @param splashAd 开屏对象
 */
- (void)CJZF_splashAdDidClose:(CJZFAdSDKSplashAd *)splashAd;

/**
 开屏广告展示回调

 @param splashAd 开屏对象
 */
- (void)CJZF_splashAdExposured:(CJZFAdSDKSplashAd *)splashAd;

/**
 开屏广告展示上报回调

 @param splashAd 开屏对象
 @discussion 当开屏广告成功展示给用户时，SDK会调用此方法。接入方可以在此回调中进行广告曝光的数据统计。
 */
- (void)CJZF_splashAdExposuredReport:(CJZFAdSDKSplashAd *)splashAd;


/**
 开屏广告加载成功
 
 @param splashAd 开屏对象
 */
- (void)CJZF_splashAdDidLoad:(CJZFAdSDKSplashAd *)splashAd;

/**
 开屏广告加载失败
 
 @param splashAd 开屏对象
 */
- (void)CJZF_splashAdDidFailToLoad:(CJZFAdSDKSplashAd *)splashAd error:(NSError *)error;

/**
 *  开屏广告成功展示
 *
 *  @param splashAd 开屏对象
 */
- (void)CJZF_splashAdSuccessPresentScreen:(CJZFAdSDKSplashAd *)splashAd;

/**
 *  开屏广告展示失败
 *
 *  @param splashAd 开屏对象
 */
- (void)CJZF_splashAdFailToPresent:(CJZFAdSDKSplashAd *)splashAd withError:(NSError *)error;

/**
 *  开屏广告关闭落地页
 *
 *  @param splashAd 开屏对象
 */
- (void)CJZF_splashAdCloseLandingPage:(CJZFAdSDKSplashAd *)splashAd;

@end


NS_ASSUME_NONNULL_END
