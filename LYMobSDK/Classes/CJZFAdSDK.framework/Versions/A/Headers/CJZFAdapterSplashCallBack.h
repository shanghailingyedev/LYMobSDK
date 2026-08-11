//
//  CJZFAdapterSplashCallBack.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2025/9/21.
//

#ifndef CJZFAdapterSplashCallBack_h
#define CJZFAdapterSplashCallBack_h

#import "CJZFAdapterCommonCallBack.h"
@class CJZFAdapterSplashAdapter;

NS_ASSUME_NONNULL_BEGIN

@protocol CJZFAdapterSplashCallBack <CJZFAdapterCommonCallBack>

- (void)splashAdLoadSuccessCallBack:(CJZFAdapterSplashAdapter *)adapter;

- (void)splashAdLoadFailCallBack:(CJZFAdapterSplashAdapter *)adapter error:(nullable NSError *)error;

- (void)splashAdSuccessToPresentCallBack:(CJZFAdapterSplashAdapter *)adapter;

- (void)splashAdFailToPresentCallBack:(CJZFAdapterSplashAdapter *)adapter error:(nullable NSError *)error;

- (void)splashAdExposureCallBack:(CJZFAdapterSplashAdapter *)adapter;

- (void)splashAdExposureReportCallBack:(CJZFAdapterSplashAdapter *)adapter;

- (void)splashAdClickedCallBack:(CJZFAdapterSplashAdapter *)adapter loadingPageURL:(NSString *)loadingPageURL;

- (void)splashAdClickedReportCallBack:(CJZFAdapterSplashAdapter *)adapter;

- (void)splashAdClosedCallBack:(CJZFAdapterSplashAdapter *)adapter;

- (void)splashAdCloseLandingPageCallBack:(CJZFAdapterSplashAdapter *)adapter;

- (void)splashAdSkipedCallBack:(CJZFAdapterSplashAdapter *)adapter;

- (void)splashAdLifeTimeCallBack:(CJZFAdapterSplashAdapter *)adapter time:(NSUInteger)time;

@end

NS_ASSUME_NONNULL_END
#endif /* CJZFAdapterSplashCallBack_h */
