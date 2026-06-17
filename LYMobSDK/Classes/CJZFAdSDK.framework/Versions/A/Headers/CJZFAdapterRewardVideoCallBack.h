//
//  CJZFAdapterRewardVideoCallBack.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2025/2/24.
//

#ifndef CJZFAdapterRewardVideoCallBack_h
#define CJZFAdapterRewardVideoCallBack_h

#import "CJZFAdapterCommonCallBack.h"
@class CJZFAdapterRewardVideoAdAdapter;

NS_ASSUME_NONNULL_BEGIN

@protocol CJZFAdapterRewardVideoCallBack <CJZFAdapterCommonCallBack>

- (void)rewardVideoAdLoadSuccessCallBack:(CJZFAdapterRewardVideoAdAdapter *)adapter;

- (void)rewardVideoAdLoadFailCallBack:(CJZFAdapterRewardVideoAdAdapter *)adapter error:(nullable NSError *)error;

- (void)rewardVideoAdSuccessToPresentCallBack:(CJZFAdapterRewardVideoAdAdapter *)adapter;

- (void)rewardVideoAdFailToPresentCallBack:(CJZFAdapterRewardVideoAdAdapter *)adapter error:(nullable NSError *)error;

- (void)rewardVideoAdExposureCallBack:(CJZFAdapterRewardVideoAdAdapter *)adapter;

- (void)rewardVideoAdClickedCallBack:(CJZFAdapterRewardVideoAdAdapter *)adapter loadingPageURL:(NSString *)loadingPageURL;

- (void)rewardVideoAdExposureReportCallBack:(CJZFAdapterRewardVideoAdAdapter *)adapter;

- (void)rewardVideoAdClickReportCallBack:(CJZFAdapterRewardVideoAdAdapter *)adapter;

- (void)rewardVideoAdClosedCallBack:(CJZFAdapterRewardVideoAdAdapter *)adapter;

- (void)rewardVideoAdCloseLandingPageCallBack:(CJZFAdapterRewardVideoAdAdapter *)adapter;

- (void)rewardVideoAdSkipedCallBack:(CJZFAdapterRewardVideoAdAdapter *)adapter;

- (void)rewardVideoAdFinishCallBack:(CJZFAdapterRewardVideoAdAdapter *)adapter;

- (void)rewardVideoAdDidRewardEffectiveCallBack:(CJZFAdapterRewardVideoAdAdapter *)adapter;

@end

NS_ASSUME_NONNULL_END

#endif /* CJZFAdapterRewardVideoCallBack_h */
