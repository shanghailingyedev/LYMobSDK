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
#import "CJZFImageCoder.h"

NS_ASSUME_NONNULL_BEGIN

/// A per-provider (provider means, AnimatedImage object) based frame pool, each player who use the same provider share the same frame buffer
@interface CJZFImageFramePool : NSObject

/// Register and return back a frame pool, also increase reference count
+ (instancetype)registerProvider:(id<CJZFAnimatedImageProvider>)provider;
/// Unregister a frame pool, also decrease reference count, if zero dealloc the frame pool
+ (void)unregisterProvider:(id<CJZFAnimatedImageProvider>)provider;

/// Prefetch the current frame, query using `frameAtIndex:` by caller to check whether finished.
- (void)prefetchFrameAtIndex:(NSUInteger)index;

/// Control the max buffer count for current frame pool, used for RAM/CPU balance, default unlimited
@property (nonatomic, assign) NSUInteger maxBufferCount;
/// Control the max concurrent fetch queue operation count, used for CPU balance, default 1
@property (nonatomic, assign) NSUInteger maxConcurrentCount;

// Frame Operations
@property (nonatomic, readonly) NSUInteger currentFrameCount;
- (nullable UIImage *)frameAtIndex:(NSUInteger)index;
- (void)setFrame:(nullable UIImage *)frame atIndex:(NSUInteger)index;
- (void)removeFrameAtIndex:(NSUInteger)index;
- (void)removeAllFrames;

NS_ASSUME_NONNULL_END

@end
