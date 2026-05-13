//
//  CJBannerAd.h
//  CJMobileAd
//
//  Created by shanghailingye 2022/2/26.
//  Copyright © 2022Jun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class CJBannerAd;
@protocol CJBannerAdDelegate <NSObject>

- (void)bannerAdDidLoad:(UIView *)bannerView resourceId:(NSString *)resourceId;

- (void)bannerAdOnShow:(id)bannerAd;

- (void)bannerAdLoadFailed:(id)bannerAd error:(NSError *)error;

- (void)bannerAdOnClicked:(id)bannerAd;

- (void)bannerAdOnClosed:(id)bannerAd;

@end

@interface CJBannerAd : NSObject

/// 判断广告是否有效（展示前判断）
@property (nonatomic, assign, readonly) BOOL isReady;

@property (nonatomic,weak) id <CJBannerAdDelegate> delegate;

- (instancetype)initWithResourceId:(NSString *)resourceId
            rootViewController:(UIViewController *)rootViewController
                          rect:(CGRect)rect;

/// 加载
- (void)loadAdData;

/// 加载并且显示
/// - Parameter containView: 内容view
- (void)loadAdDataAndShow:(UIView *)containView;

- (NSString *)getAdType;
// 加载成功时获取
- (NSInteger)getECpm;

@end

NS_ASSUME_NONNULL_END
