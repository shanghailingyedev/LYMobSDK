//
//  CJZFAdapterBannerCallBack.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/13.
//

#ifndef CJZFAdapterBannerCallBack_h
#define CJZFAdapterBannerCallBack_h

#import "CJZFAdapterCommonCallBack.h"
@class CJZFAdapterBannerAdapter;
NS_ASSUME_NONNULL_BEGIN

@protocol CJZFAdapterBannerCallBack <CJZFAdapterCommonCallBack>

- (void)bannerAdViewDidReceivedCallBack:(CJZFAdapterBannerAdapter *)adapter;

- (void)bannerAdViewFailToReceivedCallBack:(CJZFAdapterBannerAdapter *)adapter error:(nullable NSError *)error;

- (void)bannerAdViewClickedCallBack:(CJZFAdapterBannerAdapter *)adapter loadingPageURL:(NSString *)loadingPageURL;

- (void)bannerAdViewExposureCallBack:(CJZFAdapterBannerAdapter *)adapter;

- (void)bannerAdViewExposureReportCallBack:(CJZFAdapterBannerAdapter *)adapter;

- (void)bannerAdViewClickedReportCallBack:(CJZFAdapterBannerAdapter *)adapter;

- (void)bannerAdViewCloseCallBack:(CJZFAdapterBannerAdapter *)adapter;

- (void)bannerAdCloseLandingPageCallBack:(CJZFAdapterBannerAdapter *)adapter;

@optional

- (CGSize)bannerAdCloseViewSize;

@end
NS_ASSUME_NONNULL_END

#endif /* CJZFAdapterBannerCallBack_h */
