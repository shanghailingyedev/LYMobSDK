//
//  CJZFAdImpressionTimer.h
//  Test
//
//  Created by 早范 on 2025/1/29.
//  Copyright © 2025 早范. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol CJZFAdImpressionTimerDelegate <NSObject>

- (void)adViewWillLogImrepssion:(UIView *)adView;

@end

@interface CJZFAdImpressionTimer : NSObject

@property (nonatomic, weak) id<CJZFAdImpressionTimerDelegate> delegate;

+ (BOOL)visibilityView:(UIView *)view percent:(CGFloat)percent;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 初始化一个视图的监听对象, 然后回调给外部该视图是否达到展示要求

 @param requiredSecondsForImpression 展示时间 [0, infinite]
 @param requiredViewVisibilityPixels 展示像素 [0, infinite]
 */
- (instancetype)initWithRequiredSecondsForImpression:(NSTimeInterval)requiredSecondsForImpression requiredViewVisibilityPixels:(CGFloat)requiredViewVisibilityPixels NS_DESIGNATED_INITIALIZER;

/**
 初始化一个视图的监听对象, 然后回调给外部该视图是否达到展示要求

 @param requiredSecondsForImpression 展示时间 [0, infinite]
 @param visibilityPercentage 视图展示比例 [0, 1], 1代表100%
 */
- (instancetype)initWithRequiredSecondsForImpression:(NSTimeInterval)requiredSecondsForImpression requiredViewVisibilityPercentage:(CGFloat)visibilityPercentage NS_DESIGNATED_INITIALIZER;

- (void)startTrackingView:(UIView *)adView;

@end

static inline BOOL CJZFViewIsVisible(UIView *view);
static inline BOOL CJZFViewHasHiddenAncestor(UIView *view);
static inline BOOL CJZFViewIntersectsParentWindow(UIView *view);
static inline BOOL CJZFViewIntersectsParentWindowWithPercent(UIView *view, CGFloat percentVisible);
static inline UIWindow * CJZFViewGetParentWindow(UIView *view);

