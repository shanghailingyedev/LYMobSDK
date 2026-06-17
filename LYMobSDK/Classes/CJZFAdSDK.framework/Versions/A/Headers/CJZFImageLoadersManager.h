/*
 * This file is part of the CJZFWebImage package.
 * (c) Olivier Poitrey <>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
#import <UIKit/UIKit.h>
#import "CJZFImageLoader.h"

/**
 A loaders manager to manage multiple loaders
 */
@interface CJZFImageLoadersManager : NSObject <CJZFImageLoader>

/**
 Returns the global shared loaders manager instance. By default we will set [`CJZFWebImageDownloader.sharedDownloader`] into the loaders array.
 */
@property (nonatomic, class, readonly, nonnull) CJZFImageLoadersManager *sharedManager;

/**
 All image loaders in manager. The loaders array is a priority queue, which means the later added loader will have the highest priority
 */
@property (nonatomic, copy, nullable) NSArray<id<CJZFImageLoader>>* loaders;

/**
 Add a new image loader to the end of loaders array. Which has the highest priority.
 
 @param loader loader
 */
- (void)addLoader:(nonnull id<CJZFImageLoader>)loader;

/**
 Remove an image loader in the loaders array.
 
 @param loader loader
 */
- (void)removeLoader:(nonnull id<CJZFImageLoader>)loader;

@end
