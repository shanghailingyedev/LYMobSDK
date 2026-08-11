//
//  LYNativeExpressView.h
//  LYAdSDK
//
//  Created by coderqi on 2025/12/10.
//

#import <UIKit/UIKit.h>
#import <LYAdSDK/LYNativeAdData.h>


NS_ASSUME_NONNULL_BEGIN

@interface LYNativeExpressView : UIView

/// 根据广告数据源创建广告View
- (instancetype)initWithAdData:(LYNativeAdData *)adData;

/**
 * 释放广告
 */
- (void)destory;

@end

NS_ASSUME_NONNULL_END
