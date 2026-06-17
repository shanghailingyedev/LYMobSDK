//
//  CJZFBWTLandingPageViewController.h
//  Test
//
//  Created by 早范 on 2025/1/24.
//  Copyright © 2025 早范. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NSString * CJZFAdSDKLandingPageType NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXPORT CJZFAdSDKLandingPageType _Nonnull const CJZFAdSDKLandingPageTypeNormal;

FOUNDATION_EXPORT CJZFAdSDKLandingPageType _Nonnull const CJZFAdSDKLandingPageTypeHalf;

NS_ASSUME_NONNULL_BEGIN

@interface CJZFBWTLandingPageViewController : UIViewController

@property (nonatomic, copy) NSString *url;

@property (nonatomic, copy) CJZFAdSDKLandingPageType landingPageType;

@property (nonatomic, assign) CGFloat halfBackgroundColorAlpha;

@property (nonatomic, copy) void (^dismissBlock)(void);

@property (nonatomic, copy) void (^leaveApplicationBlock)(void);

@property (nonatomic, copy) void (^tryDeeplink)(void);

@property (nonatomic, copy) void (^successDeeplink)(void);

@property (nonatomic, copy) void (^failDeeplink)(void);

@property (nonatomic, copy) void (^webLoadFinish)(NSTimeInterval loadFinishTime);
@property (nonatomic, copy) void (^webClose)(NSTimeInterval loadFinishTime, NSTimeInterval webCloseTime);
@property (nonatomic, copy) void (^webAction)(NSInteger action);

- (void)setGameAdInterView:(UIView *)view block:(void (^)(UIViewController *viewController))block;

@end

NS_ASSUME_NONNULL_END
