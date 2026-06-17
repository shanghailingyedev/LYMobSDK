//
//  CJZFAdapterNativeAdViewDelegate.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/5/4.
//

#ifndef CJZFAdapterNativeAdViewDelegate_h
#define CJZFAdapterNativeAdViewDelegate_h

#import "CJZFAdapterCommonDefine.h"
#import "CJZFAdapterCommonCallBack.h"

NS_ASSUME_NONNULL_BEGIN

@class CJZFAdapterNativeAdData;

@protocol CJZFAdapterNativeAdViewDelegate <CJZFAdapterPriceDelegate>
/**
 平台类型
 */
- (nullable CJZFAdapterPlatform)cjzf_platform;

/**
 注册广告视图
 */
- (void)cjzf_registViews:(NSArray<UIView *> *_Nullable)clickViews;

/**
 取消注册
 */
- (void)cjzf_unRegistView;

/**
 广告关闭事件，手动调用
 */
- (void)cjzf_close;


- (nullable CJZFAdapterNativeAdData *)cjzf_nativeAdData;

/**
 获取视频视图
 */
- (nullable UIView *)cjzf_mediaViewForWidth:(CGFloat)width;

/**
 平台logo视图
 */
- (nullable UIView *)cjzf_logoView;

/**
 加载图片
 */
- (void)cjzf_loadImage:(UIImageView *)imageView placeholder:(UIImage *_Nullable)placeholder;

/**
 重新设置rootViewController
 */
- (void)cjzf_setRootViewController:(UIViewController *)rootViewController;

/**
 注册谷歌的媒体视图，仅谷歌平台生效
 */
- (void)cjzf_registerAdMobView:(UIView *)view viewType:(CJZFAdSDKNativeAdMobAssetType)viewType;

/**
 平台标记视图，内部使用的标记视图，外部媒体请勿使用
 */
- (nullable UIButton*)cjzf_tagBtn;

@end

NS_ASSUME_NONNULL_END

#endif /* CJZFAdapterNativeAdViewDelegate_h */
