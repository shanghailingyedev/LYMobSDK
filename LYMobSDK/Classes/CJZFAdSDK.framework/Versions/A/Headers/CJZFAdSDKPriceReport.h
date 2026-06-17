//
//  CJZFAdSDKPriceReport.h
//  CJZFAdSDK-Core
//
//  Created by 早范 on 2025/2/28.
//

#import <Foundation/Foundation.h>
#if __has_include(<CJZFAdSDK-Adapter/CJZFAdSDKAdapter.h>)
#import <CJZFAdSDK-Adapter/CJZFAdSDKAdapter.h>
#else
#import "CJZFAdSDKAdapter.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdSDKPriceReport : NSObject

- (instancetype)initWithPosId:(NSString *)posId;

- (void)sendWinNotice:(NSInteger)price;

- (void)sendLossNoticePrice:(NSInteger)price;

- (NSInteger)getPrice;

@end

NS_ASSUME_NONNULL_END
