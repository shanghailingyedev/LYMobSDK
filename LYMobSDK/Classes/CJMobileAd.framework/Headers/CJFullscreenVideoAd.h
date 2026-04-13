//
//  CJFullscreenVideoAd.h
//  CJMobileAd
//
//  Created by shanghailingye 2022/2/26.
//  Copyright © 2022Jun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class CJFullscreenVideoAd;
@protocol CJFullscreenVideoAdDelegate <NSObject>

- (void)fullscreenVideoAdDidLoad:(CJFullscreenVideoAd *)fullscreenAd resourceId:(NSString *)resourceId;

- (void)fullscreenVideoAdLoadFailed:(CJFullscreenVideoAd *)fullscreenAd error:(NSError *)error;

- (void)fullscreenVideoAdOnShow:(CJFullscreenVideoAd *)fullscreenAd;

- (void)fullscreenVideoAdOnClicked:(CJFullscreenVideoAd *)fullscreenAd;

- (void)fullscreenVideoAdOnClosed:(CJFullscreenVideoAd *)fullscreenAd;

@end

@interface CJFullscreenVideoAd : NSObject

@property (nonatomic,weak) id <CJFullscreenVideoAdDelegate> delegate;

- (instancetype)initWithResourceId:(NSString *)resourceId;

- (void)loadAdData;

- (void)showFromRootViewController:(UIViewController *)rootViewController;

- (NSString *)getAdType;

/// 加载成功时获取有效
- (NSInteger)getECpm;

@end

NS_ASSUME_NONNULL_END
