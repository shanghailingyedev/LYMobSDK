//
//  LYNativeAdObject.h
//  LYAdSDK
//
//  Created by coderqi on 2025/12/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <LYAdSDK/LYNativeAdData.h>
#import <LYAdSDK/LYNativeExpressView.h>
#import <LYAdSDK/LY_VideoPlayerView.h>

@class LYAdMetaData;
@class LYNativeAdObject;
NS_ASSUME_NONNULL_BEGIN

@protocol LYNativeAdObjectDelegate <NSObject>

/**
 * 广告展示
 * @param adObject  广告数据
 */
- (void)ly_NativeAdShow:(LYNativeAdObject *)adObject;

/**
 * 广告点击
 * @param adObject  广告数据
 */
- (void)ly_NativeAdClicked:(LYNativeAdObject *)adObject;
/**
 * 广告关闭
 * @param adObject  广告数据
 */
- (void)ly_NativeAdClosed:(LYNativeAdObject *)adObject;

/**
 * 广告关闭
 * @param adObject  广告数据
 */
- (void)ly_NativeAdWebPageClosed:(LYNativeAdObject *)adObject;

@end

@interface LYNativeAdObject : NSObject

/// 是否是模板广告
@property (nonatomic, assign) BOOL isExpress;

/// 获取广告模板视图
///  非模板广告时，返回空
- (LYNativeExpressView *)getExpressView;

/// 获取广告的视频播放器
- (LYVideoPlayerView *)getMediaView;

@property (nonatomic, weak) id <LYNativeAdObjectDelegate> delegate;

/// 广告的原始数据
@property (nonatomic, strong, readonly) LYNativeAdData *adData;

/**
 * 获取广告出价
 * 广告加载成功之后，才会有值
 *  单位：分
 */
- (NSInteger)getBidPrice;

/**
 * 聚合竞价结果回传
 */
- (void)sendBidResultNotificationWithInfo:(NSDictionary *)infoDic andResut:(BOOL)isSucc;

/**
 * 获取图片素材地址
 */
- (NSArray<NSString *> *)getImageFileUrls;

/**
 * 获取视频素材地址
 */
- (NSArray<NSString *> *)getVideoFileUrls;

/**
 * 获取落地页地址
 */
- (NSString *)getLandpageUrl;

@end

NS_ASSUME_NONNULL_END
