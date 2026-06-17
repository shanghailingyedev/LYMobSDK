//
//  CJZFAdapterCommonCallBack.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2025/1/5.
//

#ifndef CJZFAdapterCommonCallBack_h
#define CJZFAdapterCommonCallBack_h

#import <UIKit/UIKit.h>
#import "CJZFUtilsKit.h"
NS_ASSUME_NONNULL_BEGIN

@protocol CJZFAdapterCommonCallBack <NSObject>

- (UIViewController *)CJZF_rootViewController;

- (void)CJZF_errorReport:(NSError *)error;

@optional

- (CJZFAdSDKLandingPageType)CJZF_landingPageType;

- (CGFloat)CJZF_halfLandingPageBackgroundColorAlpha;

@end

@protocol CJZFAdapterPriceDelegate <NSObject>

@optional

- (NSInteger)CJZF_getPrice;

- (void)CJZF_sendWinNotice:(NSInteger)price;

- (void)CJZF_sendLossNotice:(NSInteger)price;

@end
NS_ASSUME_NONNULL_END

#endif /* CJZFAdapterCommonCallBack_h */
