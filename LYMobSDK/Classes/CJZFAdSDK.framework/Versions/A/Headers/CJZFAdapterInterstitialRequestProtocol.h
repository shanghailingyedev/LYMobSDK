//
//  CJZFAdapterInterstitialRequestProtocol.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/13.
//

#ifndef CJZFAdapterInterstitialRequestProtocol_h
#define CJZFAdapterInterstitialRequestProtocol_h

#import "CJZFAdapterCommonRequestProtocol.h"
@class CJZFAdapterInterstitialAdapter;

@protocol CJZFAdapterInterstitialRequestProtocol <CJZFAdapterCommonRequestProtocol>

- (void)loadIntertitialAd:(CJZFAdapterInterstitialAdapter *)adapter;

- (void)showFromRootViewController:(UIViewController *)viewController;

- (void)showFromRootViewController:(UIViewController *)viewController showTime:(NSInteger)showTime;

- (BOOL)isIntertitialAdValid;

@end

#endif /* CJZFAdapterInterstitialRequestProtocol_h */
