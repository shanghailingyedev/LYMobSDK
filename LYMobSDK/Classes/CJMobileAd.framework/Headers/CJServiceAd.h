//
//  CJIconServiceAd.h
//  CJMobileAd
//
//  Created by shanghailignye on 2026/4/27.
//  Copyright © 2026 JUN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class CJServiceAd;
@protocol CJServiceAdDelegate <NSObject>

- (void)iconExpressAdDidLoad:(id)serviceAd views:(UIView *)serviceView;

- (void)iconExpressAdOnShow:(id)serviceView;

- (void)iconExpressAdLoadFailed:(id)serviceAd error:(NSError *)error;

- (void)iconExpressAdOnClicked:(id)serviceAd;

- (void)iconExpressAdOnClosed:(id)serviceAd;

@end

@interface CJServiceAd : NSObject

@property (nonatomic, weak) id <CJServiceAdDelegate> delegate;

/// 初始化icon类型广告
/// - Parameters:
///   - resourceId: 广告位ID
///   - size: icon尺寸
///   - refreshTime: 刷新间隔
///   - rootViewController: 当前控制器
- (instancetype)initWithSlotId:(NSString *)resourceId
                          size:(CGSize)size
                   refreshTime:(int)refreshTime
            rootViewController:(UIViewController *)rootViewController;

/// 加载数据
- (void)loadAdData;


@end

NS_ASSUME_NONNULL_END
