//
//  CJZFAdSDKInterstitialSkipView.h
//  CJZFAdSDK-Core
//
//  Created by 早范 on 2025/8/18.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdSDKInterstitialSkipView : UIView

// default is NO
- (void)setClickEnabled:(void (^)(void))clicked;

- (void)setCountDown:(int)countDown;

@end

NS_ASSUME_NONNULL_END
