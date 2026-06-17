//
//  CJZFAdapterBannerRequestContext.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/12.
//

#import "CJZFAdapterCommonRequestContext.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterBannerRequestContext : CJZFAdapterCommonRequestContext

@property (nonatomic, assign) int refershTime;

@property (nonatomic, assign) CGSize adSize;

@property (nonatomic, copy) NSString *bannerSize;

@property (nonatomic, assign) BOOL isForceRefresh;

@property (nonatomic, strong) NSDictionary *scenes;

@property (nonatomic, assign) BOOL nonstandard;

@end

NS_ASSUME_NONNULL_END
