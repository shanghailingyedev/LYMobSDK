//
//  LY_XAdWMNativeAdDelegate.h
//  LY_AdWangMaiSDK
//
//  Created by xiang shi on 2024/9/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class LY_XAdWMNativeAdData;
@protocol LY_XAdWMNativeAdDelegate <NSObject>

/// 发起请求
- (void)wmNativeAdOnRequest;

/// 请求成功
/// @param natives 广告物料
- (void)wmNativeAdOnReady:(NSArray<LY_XAdWMNativeAdData *> *)natives;

/// 请求失败
/// @param error 错误信息
- (void)wmNativeAdOnError:(NSError *)error;

/// 广告展示
- (void)wmNativeAdOnShow;

/// 广告点击
- (void)wmNativeAdOnClick;

/// 广告详情页关闭
- (void)wmNativeAdDidCloseOtherController;

@end

NS_ASSUME_NONNULL_END
