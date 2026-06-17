//
//  CJZFChannelAdCacheManager.h
//  CJZFAdSDK-Channel
//
//  Created by 早范 on 2025/7/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class CJZFChannelAdData;

@interface CJZFChannelAdCacheManager : NSObject

+ (instancetype)sharedInstance;

- (CJZFChannelAdData *)adData:(NSString *)cacheId;

- (BOOL)cacheAlive:(NSString *)cacheId;

- (void)cacheAdData:(CJZFChannelAdData *)adData cacheId:(NSString *)cacheId;

- (void)cacheAdDataList:(NSArray<CJZFChannelAdData *> *)adDataList cacheId:(NSString *)cacheId;

@end

NS_ASSUME_NONNULL_END
