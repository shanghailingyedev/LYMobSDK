//
//  CJZFAdapterNativeExpressRequestProtocol.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/4/9.
//

#import <Foundation/Foundation.h>
#import "CJZFAdapterCommonRequestProtocol.h"

@class CJZFAdapterNativeExpressAdapter;

@protocol CJZFAdapterNativeExpressRequestProtocol <CJZFAdapterCommonRequestProtocol>

- (void)requestWithAdapter:(CJZFAdapterNativeExpressAdapter *)adapter;

@end
