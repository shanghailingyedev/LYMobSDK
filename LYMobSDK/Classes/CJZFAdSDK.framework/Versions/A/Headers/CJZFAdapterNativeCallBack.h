//
//  CJZFAdapterNativeCallBack.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/5/4.
//

#ifndef CJZFAdapterNativeCallBack_h
#define CJZFAdapterNativeCallBack_h
#import "CJZFAdapterCommonCallBack.h"
#import "CJZFAdapterNativeAdViewDelegate.h"

@class CJZFAdapterNativeAdapter;

@protocol CJZFAdapterNativeCallBack <CJZFAdapterCommonCallBack>

- (void)nativeAdSuccessToLoadCallBack:(CJZFAdapterNativeAdapter *)adapter
                         nativeExpressAdView:(NSArray<__kindof UIView <CJZFAdapterNativeAdViewDelegate> *> *)nativeExpressAdViewArray;

- (void)nativeAdFailToLoadCallBack:(CJZFAdapterNativeAdapter *)adapter
                             error:(NSError *)error;

//- (void)nativeAdRenderSuccessCallBack:(CJZFAdapterNativeAdapter *)adapter
//                         nativeExpressAdView:(__kindof UIView <CJZFAdapterNativeAdViewDelegate> *)nativeExpressAdView;
//
//- (void)nativeAdRenderFailCallBack:(CJZFAdapterNativeAdapter *)adapter
//                      nativeExpressAdView:(__kindof UIView <CJZFAdapterNativeAdViewDelegate> *)nativeExpressAdView;

- (void)nativeAdExposureCallBack:(CJZFAdapterNativeAdapter *)adapter
                    nativeExpressAdView:(__kindof UIView <CJZFAdapterNativeAdViewDelegate> *)nativeAdView;

- (void)nativeAdExposureReportCallBack:(CJZFAdapterNativeAdapter *)adapter
                    nativeExpressAdView:(__kindof UIView <CJZFAdapterNativeAdViewDelegate> *)nativeAdView;

- (void)nativeAdClickedCallBack:(CJZFAdapterNativeAdapter *)adapter
                   nativeExpressAdView:(__kindof UIView <CJZFAdapterNativeAdViewDelegate> *)nativeAdView  loadingPageURL:(NSString *)loadingPageURL;

- (void)nativeAdClickedReportCallBack:(CJZFAdapterNativeAdapter *)adapter
                   nativeExpressAdView:(__kindof UIView <CJZFAdapterNativeAdViewDelegate> *)nativeAdView;

- (void)nativeAdCloseCallBack:(CJZFAdapterNativeAdapter *)adapter
                 nativeExpressAdView:(__kindof UIView <CJZFAdapterNativeAdViewDelegate> *)nativeAdView;

- (void)nativeAdCloseLandingPageCallBack:(CJZFAdapterNativeAdapter *)adapter
                 nativeExpressAdView:(__kindof UIView <CJZFAdapterNativeAdViewDelegate> *)nativeAdView;


@end

#endif /* CJZFAdapterNativeCallBack_h */
