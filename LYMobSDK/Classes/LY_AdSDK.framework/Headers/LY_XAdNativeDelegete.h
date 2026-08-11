//
//  LY_XAdNativeDelegete.h
//  LY_AdWangMaiSDK
//
//  Created by 周泽浩 on 2023/3/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class LY_XAdNativeAdResponse;

@protocol LY_XAdNativeDelegete <NSObject>

@optional

/// 发起请求
- (void)nativeAdOnRequest;

/// 请求成功
/// @param natives 广告物料
- (void)nativeAdOnReady:(NSArray<LY_XAdNativeAdResponse *> *)natives;

/// 请求失败
/// @param error 错误信息
- (void)nativeAdOnError:(NSError *)error;

/// 广告展示
- (void)nativeAdOnShow;

/// 广告点击
- (void)nativeAdOnClick;

@end

NS_ASSUME_NONNULL_END
