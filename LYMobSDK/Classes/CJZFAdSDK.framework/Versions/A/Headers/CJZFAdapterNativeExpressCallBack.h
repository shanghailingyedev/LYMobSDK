//
//  CJZFAdapterNativeExpressCallBack.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/4/9.
//

#import <Foundation/Foundation.h>
#import "CJZFAdapterCommonCallBack.h"

@class CJZFAdapterNativeExpressAdapter;

@protocol CJZFAdapterNativeExpressAdViewDelegate <CJZFAdapterPriceDelegate>

- (void)render;

- (void)close;

- (void)cjzf_setRootViewController:(UIViewController *)controller;

@end

@protocol CJZFAdapterNativeExpressCallBack <CJZFAdapterCommonCallBack>

- (void)nativeExpressAdSuccessToLoadCallBack:(CJZFAdapterNativeExpressAdapter *)adapter
                         nativeExpressAdView:(NSArray<__kindof UIView <CJZFAdapterNativeExpressAdViewDelegate> *> *)nativeExpressAdViewArray;

- (void)nativeExpressAdFailToLoadCallBack:(CJZFAdapterNativeExpressAdapter *)adapter
                             error:(NSError *)error;

- (void)nativeExpressAdRenderSuccessCallBack:(CJZFAdapterNativeExpressAdapter *)adapter
                         nativeExpressAdView:(__kindof UIView <CJZFAdapterNativeExpressAdViewDelegate> *)nativeExpressAdView;

- (void)nativeExpressAdRenderFailCallBack:(CJZFAdapterNativeExpressAdapter *)adapter
                      nativeExpressAdView:(__kindof UIView <CJZFAdapterNativeExpressAdViewDelegate> *)nativeExpressAdView;

- (void)nativeExpressAdExposureCallBack:(CJZFAdapterNativeExpressAdapter *)adapter
                    nativeExpressAdView:(__kindof UIView <CJZFAdapterNativeExpressAdViewDelegate> *)nativeExpressAdView;

- (void)nativeExpressAdExposureReportCallBack:(CJZFAdapterNativeExpressAdapter *)adapter
                    nativeExpressAdView:(__kindof UIView <CJZFAdapterNativeExpressAdViewDelegate> *)nativeExpressAdView;

- (void)nativeExpressAdClickedCallBack:(CJZFAdapterNativeExpressAdapter *)adapter
                   nativeExpressAdView:(__kindof UIView <CJZFAdapterNativeExpressAdViewDelegate> *)nativeExpressAdView  loadingPageURL:(NSString *)loadingPageURL;

- (void)nativeExpressAdClickedReportCallBack:(CJZFAdapterNativeExpressAdapter *)adapter
                   nativeExpressAdView:(__kindof UIView <CJZFAdapterNativeExpressAdViewDelegate> *)nativeExpressAdView;

- (void)nativeExpressAdCloseCallBack:(CJZFAdapterNativeExpressAdapter *)adapter
                 nativeExpressAdView:(__kindof UIView <CJZFAdapterNativeExpressAdViewDelegate> *)nativeExpressAdView;

- (void)nativeExpressAdCloseLandingPageCallBack:(CJZFAdapterNativeExpressAdapter *)adapter
                 nativeExpressAdView:(__kindof UIView <CJZFAdapterNativeExpressAdViewDelegate> *)nativeExpressAdView;


@end
