//
//  CJZFAdapterGameRequestProtocol.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2025/8/26.
//

#ifndef CJZFAdapterGameRequestProtocol_h
#define CJZFAdapterGameRequestProtocol_h

#import "CJZFAdapterCommonRequestProtocol.h"
@class CJZFAdapterGameAdapter;

@protocol CJZFAdapterGameRequestProtocol <CJZFAdapterCommonRequestProtocol>

- (UIView *)requestViewWithAdapter:(CJZFAdapterGameAdapter *)adapter;

- (void)loadAndShow;

@end

#endif /* CJZFAdapterGameRequestProtocol_h */
