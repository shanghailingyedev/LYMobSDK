//
//  CJZFAdapterBannerRequestProtocol.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/12.
//

#ifndef CJZFAdapterBannerRequestProtocol_h
#define CJZFAdapterBannerRequestProtocol_h

#import "CJZFAdapterCommonRequestProtocol.h"
@class CJZFAdapterBannerAdapter;

@protocol CJZFAdapterBannerRequestProtocol <CJZFAdapterCommonRequestProtocol>

- (UIView *)requestViewWithAdapter:(CJZFAdapterBannerAdapter *)adapter;

- (void)loadAndShow;

- (void)reloadData;

@end

#endif /* CJZFAdapterBannerRequestProtocol_h */
