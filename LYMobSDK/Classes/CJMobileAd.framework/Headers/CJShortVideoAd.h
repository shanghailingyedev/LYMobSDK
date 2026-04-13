//
//  CJShortVideoAd.h
//  CJMobileAd
//
//  Created by shanghailingye on 2022/4/11.
//  Copyright © 2022 Jun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, CJShortVideoStatus) {
    // 播放中
    CJShortVideoPlaying,
    // 已暂停
    CJShortVideoPause,
    // 播放结束
    CJShortVideoEnd,
    // 播放停止
    CJShortVideoStop,
    // 播放错误
    CJShortVideoError,
    // 未知状态
    CJShortVideoUnKnow
};

NS_ASSUME_NONNULL_BEGIN
@class CJShortVideoAd;
@protocol CJShortVideoDelegate <NSObject>

- (void)shortAdDidLoad:(CJShortVideoAd *)shortVideoAd resourceId:(NSString *)resourceId;

- (void)shortVideoAdLoadFailed:(CJShortVideoAd *)shortVideoAd error:(NSError *)error;

- (void)shortVideoStateChange:(CJShortVideoStatus)status
                        error:(nullable NSError *)error;

// 带内容标识的回调方法
- (void)shortVideoStateChange:(CJShortVideoStatus)status
                    contentId: (NSString *)contentId
                        error:(nullable NSError *)error;

@end
@interface CJShortVideoAd : NSObject

@property (nonatomic, weak) id<CJShortVideoDelegate> delegate;

- (instancetype)initWithSlotId:(NSString *)resourceId;

- (void)loadAdData;
// 以rootViewController.view为容器
- (void)showFromRootViewController:(UIViewController *)rootViewController;
// 以contentView为容器
- (void)showFromRootViewController:(UIViewController *)rootViewController contentView:(UIView *)contentView;


@end

NS_ASSUME_NONNULL_END
