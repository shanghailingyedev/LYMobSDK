//
//  CJZFAdapterInterstitialCallBack.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/13.
//

#ifndef CJZFAdapterInterstitialCallBack_h
#define CJZFAdapterInterstitialCallBack_h

#import "CJZFAdapterCommonCallBack.h"
@class CJZFAdapterInterstitialAdapter;

NS_ASSUME_NONNULL_BEGIN

@protocol CJZFAdapterInterstitialCallBack <CJZFAdapterCommonCallBack>

- (void)interstitialSuccessToLoadCallBack:(CJZFAdapterInterstitialAdapter *)adapter;

- (void)interstitialFailToLoadCallBack:(CJZFAdapterInterstitialAdapter *)adapter error:(nullable NSError *)error;

- (void)interstitialDidPresentCallBack:(CJZFAdapterInterstitialAdapter *)adapter;

- (void)interstitialFailToPresentCallBack:(CJZFAdapterInterstitialAdapter *)adapter error:(nullable NSError *)error;

- (void)interstitialDidClickCallBack:(CJZFAdapterInterstitialAdapter *)adapter loadingPageURL:(NSString *)loadingPageURL;

- (void)interstitialDidCloseCallBack:(CJZFAdapterInterstitialAdapter *)adapter;

- (void)interstitialDidExposureCallBack:(CJZFAdapterInterstitialAdapter *)adapter;

- (void)interstitialDidExposureReportCallBack:(CJZFAdapterInterstitialAdapter *)adapter;

- (void)interstitialDidClickReportCallBack:(CJZFAdapterInterstitialAdapter *)adapter;

- (void)interstitialCloseLandingPageCallBack:(CJZFAdapterInterstitialAdapter *)adapter;

@end

NS_ASSUME_NONNULL_END

#endif /* CJZFAdapterInterstitialCallBack_h */
