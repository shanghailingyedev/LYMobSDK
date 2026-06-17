//
//  CJDrawNative.h
//  CJMobileAd
//
//  Created by shanghailingye on 2024/06/25.
//  Copyright © 2024 Jun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, CJDrawVideoStatus) {
    // 开始播放
    CJDrawVideoStartPlay,
    // 已暂停
    CJDrawVideoPause,
    // 恢复播放
    CJDrawVideoResume,
    // 播放结束
    CJDrawVideoEnd,
};

@class CJDrawNative;
@protocol CJDrawNativeAdDelegate <NSObject>

/// 加载成功
/// - Parameter drawAd: 实例
- (void)drawNativeAdDidLoad:(NSArray *)drawAd;

/// 加载失败
/// - Parameters:
///   - error: 失败信息
- (void)drawNativeAdLoadFailed:(id)drawAd error:(NSError *)error;

/// Draw信息流已经展示
- (void)drawNativeAdOnShow:(id)drawAd;

/// Draw信息流发生点击
- (void)drawNativeOnClicked:(id)drawAd;

/// 播放状态回调
/// - Parameter status: 状态
- (void)drawNativeOnPlayEvent:(CJDrawVideoStatus)status;

@end

@interface CJDrawNative : NSObject

@property (nonatomic, weak) id<CJDrawNativeAdDelegate> delegate;

/// 初始化Draw信息流
/// - Parameters:
///   - resourceId: 广告位ID
///   - contentView: 注册容器view
///   - rootViewController: 当前控制器
- (instancetype)initWithSlotId:(NSString *)resourceId rootViewController:(UIViewController *)rootViewController;

/// 加载Draw信息流
/// - Parameter count: 加载数量（当前仅支持1条）
- (void)loadAdData:(NSInteger)count;

/// 注册容器view，在加载成功时进行注册
/// - Parameter containView: 容器
- (void)registerContainer:(UIView *)containView;

@end

NS_ASSUME_NONNULL_END
