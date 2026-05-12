//
//  JTNativeAD.h
//  JTAdSDK
//
//  Created by Frank on 2025/6/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class LYJTNativeAD,JTNativeAdView,LYJTMaterialMeta;

/// 信息流广告事件回调协议
@protocol JTNativeADDelegate <NSObject>

@optional

/// 信息流自渲染广告拉取成功
/// - Parameter nativeAd: 信息流广告模型
- (void)jtNativeADLoadSuccess:(LYJTNativeAD *)nativeAd;

/// 信息流自渲染广告拉取失败
/// - Parameters:
///   - nativeAd: 信息流广告模型
///   - error: 失败原因
- (void)jtNativeAdLoadFail:(LYJTNativeAD *)nativeAd error:(NSError *_Nullable)error;

/// 信息流自渲染广告曝光成功
/// - Parameter nativeAd: 信息流广告模型
- (void)jtNativeAdDidExposureSuccess:(LYJTNativeAD *)nativeAd;

/// 信息流自渲染广告曝光失败
/// - Parameter nativeAd: 信息流广告模型
/// - Parameter error: 报错error
- (void)jtNativeAdDidExposureFail:(LYJTNativeAD *)nativeAd error:(NSError *)error;

/// 信息流自渲染广告点击热区
/// - Parameter nativeAd: 信息流广告模型
- (void)jtNativeAdDidClick:(LYJTNativeAD *)nativeAd;

/// 信息流自渲染广告点击关闭按钮
/// - Parameter nativeAd: 信息流广告模型
- (void)jtNativeAdDidClose:(LYJTNativeAD *)nativeAd;

@end

/// 聚推信息流自渲染广告
@interface LYJTNativeAD : LYJTBaseAdModel

/// 广告位模型
@property (nonatomic, strong, readonly) LYJTAdSlot *slot;

/// 自渲染素材模型。在装载成功后，这里会存储自渲染所需要的所有数据。
@property (atomic, strong, readonly, nullable) LYJTMaterialMeta *materialData;

/// 信息流自渲染广告代理
@property (nonatomic, weak, nullable) id<JTNativeADDelegate> delegate;

/// 根控制器。很重要，没有的话会严重影响转化！！！
@property (nonatomic, weak) UIViewController *rootViewController;

/// 通过广告位模型初始化
/// - Parameters:
///   - itemItem: 广告位模型
///   - adSize: 广告尺寸。单位：pt。
- (instancetype)initWithSlot:(LYJTAdSlot *)itemItem adSize:(CGSize)adSize;

/// 装载数据
- (void)loadAdData;

/// 注册自渲染相关组件。
/// - Parameters:
///   - containerView: 广告自渲染内容容器
///   - clickableViews: 可响应点击事件的View数组。如果为空则默认整个广告均可点击。
- (void)registerContainer:(__kindof UIView *)containerView
       withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews
                closeView:(UIView * _Nullable)closeView;

@end

NS_ASSUME_NONNULL_END
