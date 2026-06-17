//
//  CJZFAdapterInterstitialRequestContext.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/13.
//

#import "CJZFAdapterCommonRequestContext.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterInterstitialRequestContext : CJZFAdapterCommonRequestContext

@property (nonatomic, assign) BOOL isMuted;

@property (nonatomic, assign) BOOL isFullScreen;

@property (nonatomic, strong) NSDictionary *scenes;

@property (nonatomic, assign) BOOL touchClose;

@end

NS_ASSUME_NONNULL_END
