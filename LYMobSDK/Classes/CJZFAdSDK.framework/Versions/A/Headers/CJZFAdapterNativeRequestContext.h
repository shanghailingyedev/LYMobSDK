//
//  CJZFAdapterNativeRequestContext.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/5/4.
//

#import "CJZFAdapterCommonRequestContext.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterNativeRequestContext : CJZFAdapterCommonRequestContext

@property (nonatomic, assign) BOOL muted;

@property (nonatomic, assign) CGSize adSize;

@property (nonatomic, assign) NSInteger loadCount;

@property (nonatomic, assign) BOOL autoPlay;

@property (nonatomic, strong) NSDictionary *scenes;

@end

NS_ASSUME_NONNULL_END
