//
//  CJZFChannelVideoCache.h
//  CJZFAdSDK-Channel
//
//  Created by 早范 on 2025/2/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol CJZFChannelVideoCacheDelegate <NSObject>

- (void)channelVideoCacheAlreadyExists:(NSString *)videoAddress;

- (void)channelVideoCacheFailed:(NSString *)videoAddress error:(NSError *)error;

- (void)channelVideoCacheSuccess:(NSString *)videoAddress;

@end

@interface CJZFChannelVideoCache : NSObject

@property (nonatomic, weak) id<CJZFChannelVideoCacheDelegate> delegate;

- (void)loadVideoData:(NSString *)videoAddress finishBlock:(void (^)(NSString *cacheKey))finishBlock failedBlock:(void (^)(NSError *error))failedBlock;

@end

NS_ASSUME_NONNULL_END
