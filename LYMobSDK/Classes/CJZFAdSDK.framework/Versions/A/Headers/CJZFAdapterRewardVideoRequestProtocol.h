//
//  CJZFAdapterRewardVideoRequestProtocol.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2025/2/24.
//

#ifndef CJZFAdapterRewardVideoRequestProtocol_h
#define CJZFAdapterRewardVideoRequestProtocol_h

#import "CJZFAdapterCommonRequestProtocol.h"
@class CJZFAdapterRewardVideoAdAdapter;

@protocol CJZFAdapterRewardVideoRequestProtocol <CJZFAdapterCommonRequestProtocol>

- (BOOL)isAdValid;

- (void)loadRewardVideoAd:(CJZFAdapterRewardVideoAdAdapter *)adapter;

- (void)showRewardVideoAdFromRootViewController:(UIViewController *)viewController;

@end

#endif /* CJZFAdapterRewardVideoRequestProtocol_h */
