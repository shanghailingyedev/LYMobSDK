//
//  CJFeedNativeAd.h
//  CJMobileAd
//
//  Created by shanghailingye on 2024/4/9.
//  Copyright © 2024 Jun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CJFeedAdMaterial.h"
#import "CJFeedNaiveConfig.h"
@class CJFeedNativeAd;
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, CJFeedVideoStatus) {
    // 开始播放
    CJFeedVideoStartPlay,
    // 已暂停
    CJFeedVideoPause,
    // 播放错误
    CJFeedVideoPlayError,
    // 播放结束
    CJFeedVideoEnd,
};

@protocol CJNativeFeedAdDelegate <NSObject>

/// 自渲染素材加载成功
/// - Parameter feedAdMaterials: 素材
- (void)feedNativeMaterialsOnDidLoad:(id)feedAd feedAdMaterials:(NSArray<CJFeedAdMaterial *> *)feedAdMaterials;

/// 自渲染渲染成功
/// - Parameter feedNativeView: view
- (void)feedNativeMaterialsOnRenderSuccess:(id)feedAd feedNativeView:(UIView *)feedNativeView;

/// 自渲染展示成功
/// - Parameter feedNativeView: 自渲染view
- (void)feedNativeMaterialsOnShow:(id)feedAd feedNativeView:(UIView *)feedNativeView;

/// 素材加载失败
/// - Parameters:
///   - feedAd: 广告实例
///   - error: 错误信息
- (void)feedNativeMaterialsOnLoadFailed:(id)feedAd error:(NSError *)error;

/// 素材渲染失败
/// - Parameters:
///   - feedAd: 广告实例
///   - error: 错误信息
- (void)feedNativeMaterialsOnRenderFailed:(id)feedAd error:(NSError *)error;

/// 素材点击
/// - Parameter feedNativeView: view
- (void)feedNativeMaterialsOnClick:(id)feedAd feedNativeView:(UIView *)feedNativeView;

/// 素材关闭
/// - Parameter feedNativeView: view
- (void)feedNativeMaterialsOnClose:(id)feedAd feedNativeView:(UIView *)feedNativeView;

/// 视频播放状态监听
/// - Parameter feedNativeView: view
- (void)feedNativeMaterialsOnStatusChange:(UIView *)feedNativeView videoStatus:(CJFeedVideoStatus)status;

@end

@interface CJFeedNativeAd : NSObject

/// 自渲染delegate
@property (nonatomic, weak) id<CJNativeFeedAdDelegate> delegate;

/// 自渲染初始化
/// - Parameters:
///   - slotId: 广告位ID
///   - extend: 拓展参数
- (instancetype)initWithSlotId:(NSString *)slotId extend:(NSString *)extend;

/// 加载自渲染
- (void)loadFeedAdData;

/// 展示自渲染
/// - Parameter contentView: 绑定容器view
/// - Parameter config: 主要是对内部播放器的设置
/// - Parameter currentVC: 当前控制器，用来跳转
- (void)bindFeedNativeContentView:(UIView *)contentView config:(CJFeedNaiveConfig *)config currentVC:(UIViewController *)currentVC;

/// 广告销毁
- (void)destoryAd;

- (NSString *)getAdType;

/// 获取ecpm（竞价模式下生效）
- (NSInteger)getECpm;

@end

NS_ASSUME_NONNULL_END
