//
//  CJZFAdapterGameRequestContext.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2025/8/26.
//

#import "CJZFAdapterCommonRequestContext.h"

NS_ASSUME_NONNULL_BEGIN
@interface CJZFAdapterGameRequestContext : CJZFAdapterCommonRequestContext

@property (nonatomic, assign) int refershTime;

@property (nonatomic, assign) CGSize adSize;

@property (nonatomic, copy) NSString *bannerSize;

@property (nonatomic, assign) BOOL isForceRefresh;

@property (nonatomic, strong) NSDictionary *scenes;


@end

NS_ASSUME_NONNULL_END
