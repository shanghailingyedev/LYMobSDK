//
//  CJZFAdapterRewardVideoAdRequestContext.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2025/2/24.
//

#import "CJZFAdapterCommonRequestContext.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterRewardVideoAdRequestContext : CJZFAdapterCommonRequestContext

@property (nonatomic, strong) NSDictionary *scenes;

@property (nonatomic, assign) BOOL videoMuted;

@end

NS_ASSUME_NONNULL_END
