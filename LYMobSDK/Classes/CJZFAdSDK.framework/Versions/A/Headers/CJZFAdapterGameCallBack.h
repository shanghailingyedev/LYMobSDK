//
//  CJZFAdapterGameCallBack.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2025/8/26.
//

#ifndef CJZFAdapterGameCallBack_h
#define CJZFAdapterGameCallBack_h

#import "CJZFAdapterCommonCallBack.h"
@class CJZFAdapterGameAdapter;
NS_ASSUME_NONNULL_BEGIN

@protocol CJZFAdapterGameCallBack <CJZFAdapterCommonCallBack>

- (void)gameAdViewDidReceivedCallBack:(CJZFAdapterGameAdapter *)adapter;

- (void)gameAdViewFailToReceivedCallBack:(CJZFAdapterGameAdapter *)adapter error:(nullable NSError *)error;

- (void)gameAdViewClickedCallBack:(CJZFAdapterGameAdapter *)adapter loadingPageURL:(NSString *)loadingPageURL;

- (void)gameAdViewExposureCallBack:(CJZFAdapterGameAdapter *)adapter;

- (void)gameAdViewExposureReportCallBack:(CJZFAdapterGameAdapter *)adapter;

- (void)gameAdViewClickedReportCallBack:(CJZFAdapterGameAdapter *)adapter;

- (void)gameAdViewCloseCallBack:(CJZFAdapterGameAdapter *)adapter;

- (void)gameAdCloseLandingPageCallBack:(CJZFAdapterGameAdapter *)adapter;

@end
NS_ASSUME_NONNULL_END

#endif /* CJZFAdapterGameCallBack_h */
