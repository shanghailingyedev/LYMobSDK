//
//  LYBKNativeAdObject.h
//  LYBKAdSDK
//
//  Created by coderqi on 2025/12/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <LYBKAdSDK/LYBKNativeAdData.h>
#import <LYBKAdSDK/LYBKNativeExpressView.h>
#import <LYBKAdSDK/LYBK_VideoPlayerView.h>
#import <LYBKAdSDK/LYBKBaseAd.h>

@class LYBKAdMetaData;
@class LYBKNativeAdObject;
NS_ASSUME_NONNULL_BEGIN

@protocol LYBKNativeAdObjectDelegate <NSObject>

/**
 * 广告展示
 * @param adObject  广告数据
 */
- (void)lybk_NativeAdShow:(LYBKNativeAdObject *)adObject;

/**
 * 广告点击
 * @param adObject  广告数据
 */
- (void)lybk_NativeAdClicked:(LYBKNativeAdObject *)adObject;
/**
 * 广告关闭
 * @param adObject  广告数据
 */
- (void)lybk_NativeAdClosed:(LYBKNativeAdObject *)adObject;

/**
 * 广告关闭
 * @param adObject  广告数据
 */
- (void)lybk_NativeAdWebPageClosed:(LYBKNativeAdObject *)adObject;

@end

@interface LYBKNativeAdObject : NSObject

/// 是否是模板广告
@property (nonatomic, assign) BOOL isExpress;

/// 获取广告模板视图
///  非模板广告时，返回空
- (LYBKNativeExpressView *)getExpressView;

/// 获取广告的视频播放器
- (LYBKVideoPlayerView *)getMediaView;

@property (nonatomic, weak) id <LYBKNativeAdObjectDelegate> delegate;

/// 广告的原始数据
@property (nonatomic, strong, readonly) LYBKNativeAdData *adData;

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
 * 获取广告素材信息（素材ID + 视频素材地址）。
 * 仅当全局拓展字段 c_g_m_i=1（canGetMaterialInfo）时返回有效对象，否则返回 nil；
 * 非视频广告时 videoUrl 为 nil。
 */
- (nullable LYBKMaterialInfo *)getMaterialInfo;

/**
 * 获取落地页地址
 */
- (NSString *)getLandpageUrl;

@end

NS_ASSUME_NONNULL_END
