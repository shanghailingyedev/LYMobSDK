//
//  CJZFAdSDKNoticeAd.h
//  
//
//  Created by 早范 on 2026/5/15.
//

#import <Foundation/Foundation.h>

typedef NSString * CJZFAdSDKNoticeStyleType NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXPORT CJZFAdSDKNoticeStyleType _Nonnull const CJZFAdSDKNoticeStyleTypeSmall;

FOUNDATION_EXPORT CJZFAdSDKNoticeStyleType _Nonnull const CJZFAdSDKNoticeStyleTypeMedium;

FOUNDATION_EXPORT CJZFAdSDKNoticeStyleType _Nonnull const CJZFAdSDKNoticeStyleTypeLarge;

NS_ASSUME_NONNULL_BEGIN

@protocol CJZFAdSDKNoticeAdDelegate;

@interface CJZFAdSDKNoticeAd : NSObject

/**
 代理回调
*/
@property (nonatomic, weak) id<CJZFAdSDKNoticeAdDelegate> delegate;

/*
 viewControllerForPresentingModalView
 详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

/**
 广告位id
*/
@property (nonatomic, copy) NSString *posId;

/**
 自定义处理广告落地页，当渠道为bwt时有效，点击回调中会带有广告落地页地址
*/
@property (nonatomic, assign) BOOL customLoadingPage;

/**
 悬屏广告的样式类型，默认为small
*/
@property (nonatomic, assign) CJZFAdSDKNoticeStyleType styleType;

/**
 加载广告数据
*/
- (void)loadAdData;

/**
 在window中展示广告
 
 @param window 广告承载容器
 @param screenBottom 是否在屏幕下面弹出，默认为false，在屏幕上方弹出
*/
- (void)showAdInWindow:(UIWindow *)window screenBottom:(BOOL)screenBottom;

/**
 设置场景参数
 
 @param scenes 场景参数
*/
- (void)setScenes:(NSDictionary *)scenes;

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

@protocol CJZFAdSDKNoticeAdDelegate <NSObject>

/**
 CJZFAdSDKNoticeAd请求成功回调
 
 @param noticeAd 悬屏广告实例对象
*/
- (void)CJZF_noticeAdSuccedToLoad:(CJZFAdSDKNoticeAd *)noticeAd;

/**
 CJZFAdSDKNoticeAd请求失败回调

 @param noticeAd 悬屏广告实例对象
 @param error 失败原因
*/
- (void)CJZF_noticeAdFailedToLoad:(CJZFAdSDKNoticeAd *)noticeAd error:(NSError *)error;

/**
 CJZFAdSDKNoticeAd展示在屏幕内回调

 @param noticeAd 悬屏广告实例对象
*/
- (void)CJZF_noticeAdDidPresent:(CJZFAdSDKNoticeAd *)noticeAd;

/**
 CJZFAdSDKNoticeAd展示在屏幕内失败回调

 @param noticeAd 悬屏广告实例对象
*/
- (void)CJZF_noticeAdFailedToPresent:(CJZFAdSDKNoticeAd *)noticeAd error:(NSError *)error;

/**
 CJZFAdSDKNoticeAd点击回调

 @param noticeAd 悬屏广告实例对象
 @param loadingPageURL 广告落地页地址，当渠道为*，并且customLoadingPage为YES时有值
*/
- (void)CJZF_noticeAdDidClick:(CJZFAdSDKNoticeAd *)noticeAd loadingPageURL:(NSString *)loadingPageURL DEPRECATED_MSG_ATTRIBUTE("该回调即将废弃，请使用CJZF_noticeAdDidClickReport:回调方法");

/**
 CJZFAdSDKNoticeAd关闭回调

 @param noticeAd 悬屏广告实例对象
*/
- (void)CJZF_noticeAdDidClose:(CJZFAdSDKNoticeAd *)noticeAd;

/**
 CJZFAdSDKNoticeAd展示回调
 
 @param noticeAd 广告实例
 */
- (void)CJZF_noticeAdExposure:(CJZFAdSDKNoticeAd *)noticeAd DEPRECATED_MSG_ATTRIBUTE("该回调即将废弃，请使用CJZF_noticeAdExposureReport:回调方法");

/**
 CJZFAdSDKNoticeAd展示上报回调
 
 @param noticeAd 广告实例
 */
- (void)CJZF_noticeAdExposureReport:(CJZFAdSDKNoticeAd *)noticeAd;


/**
 CJZFAdSDKNoticeAd点击上报回调

 @param noticeAd 悬屏广告实例对象
*/
- (void)CJZF_noticeAdDidClickReport:(CJZFAdSDKNoticeAd *)noticeAd;

/**
 CJZFAdSDKNoticeAd关闭落地页回调
 
 @param noticeAd 广告实例
 */
- (void)CJZF_noticeAdCloseLandingPage:(CJZFAdSDKNoticeAd *)noticeAd;

@end

NS_ASSUME_NONNULL_END
