//
//  CJZFChannelSplashAdView.h
//  CJZFAdSDK-Channel
//
//  Created by 早范 on 2025/9/24.
//

#import <UIKit/UIKit.h>
#if __has_include(<CJZFAdSDK-Kit/CJZFUtilsKit.h>)
#import <CJZFAdSDK-Kit/CJZFUtilsKit.h>
#else
#import "CJZFUtilsKit.h"
#endif
#import "CJZFChannelSplashSkipButton.h"
#import "CJZFChannelCommonView.h"

NS_ASSUME_NONNULL_BEGIN

@class CJZFChannelAdData;

@interface CJZFChannelSplashAdView : CJZFChannelCommonView

@property (nonatomic, strong) CJZFChannelAdData *model;
/**
 开屏背景视图
 */
@property (nonatomic, strong) UIImageView *backgroundImgv;

/**
 开屏图片填充视图
 */
@property (nonatomic, strong, readonly) CJZFAnimatedImageView *mainImgv;

/**
 底部logo
 */
@property (nonatomic, strong, readwrite) UIView *bottomView;

/**
 默认启动图
 */
@property (nonatomic, strong, readwrite) UIImage *backgroundImage;

/**
 跳过按钮
 */
@property (nonatomic, strong, readwrite) CJZFChannelSplashSkipButton *skipBtn;

/**
 跳过按钮位置
 */
@property (nonatomic, assign) BOOL rightTop;


@property (nonatomic, copy) void (^clickReport)(CGPoint touchPoint, CGPoint sPoint, CGSize size);

#pragma mark - Action

/**
 广告内容点击回调, default is no
 */
- (void)setContentClickEnabled:(void (^)(CGPoint touchPoint))clicked;

/**
 跳过按钮点击回调, default is no
 */
- (void)setSkipClickEnabled:(void (^)(void))clicked;

/**
 展示容器
 */
- (void)showInWindow:(UIWindow *)window;

/**
 展示广告素材
 */
- (void)showAdMaterialAnimated:(BOOL)animated;

- (void)addShake;

/**
 关闭
 */
- (void)close;

#pragma mark - Timer

- (void)setCountDown:(int)countDown completion:(void (^)(void))completion;

@end

NS_ASSUME_NONNULL_END
