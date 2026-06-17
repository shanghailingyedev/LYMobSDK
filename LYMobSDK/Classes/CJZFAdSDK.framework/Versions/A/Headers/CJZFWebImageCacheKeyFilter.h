/*
 * This file is part of the CJZFWebImage package.
 * (c) Olivier Poitrey <>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "CJZFWebImageCompat.h"

typedef NSString * _Nullable(^CJZFWebImageCacheKeyFilterBlock)(NSURL * _Nonnull url);

/**
 This is the protocol for cache key filter.
 We can use a block to specify the cache key filter. But Using protocol can make this extensible, and allow Swift user to use it easily instead of using `@convention(block)` to store a block into context options.
 */
@protocol CJZFWebImageCacheKeyFilter <NSObject>

- (nullable NSString *)cacheKeyForURL:(nonnull NSURL *)url;

@end

/**
 A cache key filter class with block.
 */
@interface CJZFWebImageCacheKeyFilter : NSObject <CJZFWebImageCacheKeyFilter>

- (nonnull instancetype)initWithBlock:(nonnull CJZFWebImageCacheKeyFilterBlock)block;
+ (nonnull instancetype)cacheKeyFilterWithBlock:(nonnull CJZFWebImageCacheKeyFilterBlock)block;

@end
