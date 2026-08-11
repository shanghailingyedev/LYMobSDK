//
//  CJZFChannelCommonView.h
//  CJZFAdSDK-Channel
//
//  Created by 早范 on 2026/4/20.
//

#import <UIKit/UIKit.h>
#import "CJZFChannelAdData.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFChannelCommonView : UIView

@property (nonatomic, assign) BOOL isCaptured;

@property (nonatomic, assign) BOOL enterBackground;

@property (nonatomic, strong) CJZFChannelAdData *model;

- (void)addShake:(void (^)(float shakeV, NSError *error))shakeHandle;

- (UIViewController *)topMostViewControllerFrom:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
