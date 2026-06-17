//
//  CJZFAdapterNativeRequestProtocol.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/5/4.
//

#import <Foundation/Foundation.h>
#import "CJZFAdapterCommonRequestProtocol.h"
@class CJZFAdapterNativeAdapter;

@protocol CJZFAdapterNativeRequestProtocol <CJZFAdapterCommonRequestProtocol>

- (void)requestWithAdapter:(CJZFAdapterNativeAdapter *)adapter;

@end
