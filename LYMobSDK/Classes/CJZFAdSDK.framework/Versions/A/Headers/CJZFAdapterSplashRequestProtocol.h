//
//  CJZFAdapterSplashRequestProtocol.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2025/9/21.
//

#ifndef CJZFAdapterSplashRequestProtocol_h
#define CJZFAdapterSplashRequestProtocol_h

#import "CJZFAdapterCommonRequestProtocol.h"
@class CJZFAdapterSplashAdapter;

@protocol CJZFAdapterSplashRequestProtocol <CJZFAdapterCommonRequestProtocol>

- (void)requestSplashWithAdapter:(CJZFAdapterSplashAdapter *)adapter;

- (void)showSplashInWindow:(UIWindow *)window;

- (void)showSplashInWindow:(UIWindow *)window bottomView:(UIView *)bottomView;

- (BOOL)isAdValid;

- (void)loadAndShowSplash:(CJZFAdapterSplashAdapter *)adapter window:(UIWindow *)window;

@end
#endif /* CJZFAdapterSplashRequestProtocol_h */
