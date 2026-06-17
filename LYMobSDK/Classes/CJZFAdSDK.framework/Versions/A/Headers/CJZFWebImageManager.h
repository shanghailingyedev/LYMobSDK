/*
 * This file is part of the CJZFWebImage package.
 * (c) Olivier Poitrey <>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
#import <UIKit/UIKit.h>
#import "CJZFWebImageCompat.h"
#import "CJZFWebImageOperation.h"
#import "CJZFImageCacheDefine.h"
#import "CJZFImageLoader.h"
#import "CJZFImageTransformer.h"
#import "CJZFWebImageCacheKeyFilter.h"
#import "CJZFWebImageCacheSerializer.h"
#import "CJZFWebImageOptionsProcessor.h"

typedef void(^CJZFExternalCompletionBlock)(UIImage * _Nullable image, NSError * _Nullable error, CJZFImageCacheType cacheType, NSURL * _Nullable imageURL);

typedef void(^CJZFInternalCompletionBlock)(UIImage * _Nullable image, NSData * _Nullable data, NSError * _Nullable error, CJZFImageCacheType cacheType, BOOL finished, NSURL * _Nullable imageURL);

/**
 A combined operation representing the cache and loader operation. You can use it to cancel the load process.
 */
@interface CJZFWebImageCombinedOperation : NSObject <CJZFWebImageOperation>

/**
 Cancel the current operation, including cache and loader process
 */
- (void)cancel;

/// Whether the operation has been cancelled.
@property (nonatomic, assign, readonly, getter=isCancelled) BOOL cancelled;

/**
 The cache operation from the image cache query
 */
@property (strong, nonatomic, nullable, readonly) id<CJZFWebImageOperation> cacheOperation;

/**
 The loader operation from the image loader (such as download operation)
 */
@property (strong, nonatomic, nullable, readonly) id<CJZFWebImageOperation> loaderOperation;

@end


@class CJZFWebImageManager;

/**
 The manager delegate protocol.
 */
@protocol CJZFWebImageManagerDelegate <NSObject>

@optional

/**
 * Controls which image should be downloaded when the image is not found in the cache.
 *
 * @param imageManager The current `CJZFWebImageManager`
 * @param imageURL     The url of the image to be downloaded
 *
 * @return Return NO to prevent the downloading of the image on cache misses. If not implemented, YES is implied.
 */
- (BOOL)imageManager:(nonnull CJZFWebImageManager *)imageManager shouldDownloadImageForURL:(nonnull NSURL *)imageURL;

/**
 * Controls the complicated logic to mark as failed URLs when download error occur.
 * If the delegate implement this method, we will not use the built-in way to mark URL as failed based on error code;
 @param imageManager The current `CJZFWebImageManager`
 @param imageURL The url of the image
 @param error The download error for the url
 @return Whether to block this url or not. Return YES to mark this URL as failed.
 */
- (BOOL)imageManager:(nonnull CJZFWebImageManager *)imageManager shouldBlockFailedURL:(nonnull NSURL *)imageURL withError:(nonnull NSError *)error;

@end

/**
 * The CJZFWebImageManager is the class behind the UIImageView+CJZFWebCache category and likes.
 * It ties the asynchronous downloader (CJZFWebImageDownloader) with the image cache store (CJZFImageCache).
 * You can use this class directly to benefit from web image downloading with caching in another context than
 * a UIView.
 *
 * Here is a simple example of how to use CJZFWebImageManager:
 *
 * @code

CJZFWebImageManager *manager = [CJZFWebImageManager sharedManager];
[manager loadImageWithURL:imageURL
                  options:0
                 progress:nil
                completed:^(UIImage *image, NSData *data, NSError *error, CJZFImageCacheType cacheType, BOOL finished, NSURL *imageURL) {
                    if (image) {
                        // do something with image
                    }
                }];

 * @endcode
 */
@interface CJZFWebImageManager : NSObject

/**
 * The delegate for manager. Defaults to nil.
 */
@property (weak, nonatomic, nullable) id <CJZFWebImageManagerDelegate> delegate;

/**
 * The image cache used by manager to query image cache.
 */
@property (strong, nonatomic, readonly, nonnull) id<CJZFImageCache> imageCache;

/**
 * The image loader used by manager to load image.
 */
@property (strong, nonatomic, readonly, nonnull) id<CJZFImageLoader> imageLoader;

/**
 The image transformer for manager. It's used for image transform after the image load finished and store the transformed image to cache, see `CJZFImageTransformer`.
 Defaults to nil, which means no transform is applied.
 @note This will affect all the load requests for this manager if you provide. However, you can pass `CJZFWebImageContextImageTransformer` in context arg to explicitly use that transformer instead.
 */
@property (strong, nonatomic, nullable) id<CJZFImageTransformer> transformer;

/**
 * The cache filter is used to convert an URL into a cache key each time CJZFWebImageManager need cache key to use image cache.
 *
 * The following example sets a filter in the application delegate that will remove any query-string from the
 * URL before to use it as a cache key:
 *
 * @code
 CJZFWebImageManager.sharedManager.cacheKeyFilter =[CJZFWebImageCacheKeyFilter cacheKeyFilterWithBlock:^NSString * _Nullable(NSURL * _Nonnull url) {
    url = [[NSURL alloc] initWithScheme:url.scheme host:url.host path:url.path];
    return [url absoluteString];
 }];
 * @endcode
 */
@property (nonatomic, strong, nullable) id<CJZFWebImageCacheKeyFilter> cacheKeyFilter;

/**
 * The cache serializer is used to convert the decoded image, the source downloaded data, to the actual data used for storing to the disk cache. If you return nil, means to generate the data from the image instance, see `CJZFImageCache`.
 * For example, if you are using WebP images and facing the slow decoding time issue when later retrieving from disk cache again. You can try to encode the decoded image to JPEG/PNG format to disk cache instead of source downloaded data.
 * @note The `image` arg is nonnull, but when you also provide an image transformer and the image is transformed, the `data` arg may be nil, take attention to this case.
 * @note This method is called from a global queue in order to not to block the main thread.
 * @code
 CJZFWebImageManager.sharedManager.cacheSerializer = [CJZFWebImageCacheSerializer cacheSerializerWithBlock:^NSData * _Nullable(UIImage * _Nonnull image, NSData * _Nullable data, NSURL * _Nullable imageURL) {
    CJZFImageFormat format = [NSData cjzf_imageFormatForImageData:data];
    switch (format) {
        case CJZFImageFormatWebP:
            return image.images ? data : nil;
        default:
            return data;
    }
}];
 * @endcode
 * The default value is nil. Means we just store the source downloaded data to disk cache.
 */
@property (nonatomic, strong, nullable) id<CJZFWebImageCacheSerializer> cacheSerializer;

/**
 The options processor is used, to have a global control for all the image request options and context option for current manager.
 @note If you use `transformer`, `cacheKeyFilter` or `cacheSerializer` property of manager, the input context option already apply those properties before passed. This options processor is a better replacement for those property in common usage.
 For example, you can control the global options, based on the URL or original context option like the below code.
 
 @code
 CJZFWebImageManager.sharedManager.optionsProcessor = [CJZFWebImageOptionsProcessor optionsProcessorWithBlock:^CJZFWebImageOptionsResult * _Nullable(NSURL * _Nullable url, CJZFWebImageOptions options, CJZFWebImageContext * _Nullable context) {
     // Only do animation on `CJZFAnimatedImageView`
     if (!context[CJZFWebImageContextAnimatedImageClass]) {
        options |= CJZFWebImageDecodeFirstFrameOnly;
     }
     // Do not force decode for png url
     if ([url.lastPathComponent isEqualToString:@"png"]) {
        options |= CJZFWebImageAvoidDecodeImage;
     }
     // Always use screen scale factor
     CJZFWebImageMutableContext *mutableContext = [NSDictionary dictionaryWithDictionary:context];
     mutableContext[CJZFWebImageContextImageScaleFactor] = @(UIScreen.mainScreen.scale);
     context = [mutableContext copy];
 
     return [[CJZFWebImageOptionsResult alloc] initWithOptions:options context:context];
 }];
 @endcode
 */
@property (nonatomic, strong, nullable) id<CJZFWebImageOptionsProcessor> optionsProcessor;

/**
 * Check one or more operations running
 */
@property (nonatomic, assign, readonly, getter=isRunning) BOOL running;

/**
 The default image cache when the manager which is created with no arguments. Such as shared manager or init.
 Defaults to nil. Means using `CJZFImageCache.sharedImageCache`
 */
@property (nonatomic, class, nullable) id<CJZFImageCache> defaultImageCache;

/**
 The default image loader for manager which is created with no arguments. Such as shared manager or init.
 Defaults to nil. Means using `CJZFWebImageDownloader.sharedDownloader`
 */
@property (nonatomic, class, nullable) id<CJZFImageLoader> defaultImageLoader;

/**
 * Returns global shared manager instance.
 */
@property (nonatomic, class, readonly, nonnull) CJZFWebImageManager *sharedManager;

/**
 * Allows to specify instance of cache and image loader used with image manager.
 * @return new instance of `CJZFWebImageManager` with specified cache and loader.
 */
- (nonnull instancetype)initWithCache:(nonnull id<CJZFImageCache>)cache loader:(nonnull id<CJZFImageLoader>)loader NS_DESIGNATED_INITIALIZER;

/**
 * Downloads the image at the given URL if not present in cache or return the cached version otherwise.
 *
 * @param url            The URL to the image
 * @param options        A mask to specify options to use for this request
 * @param progressBlock  A block called while image is downloading
 *                       @note the progress block is executed on a background queue
 * @param completedBlock A block called when operation has been completed.
 *
 *   This parameter is required.
 * 
 *   This block has no return value and takes the requested UIImage as first parameter and the NSData representation as second parameter.
 *   In case of error the image parameter is nil and the third parameter may contain an NSError.
 *
 *   The forth parameter is an `CJZFImageCacheType` enum indicating if the image was retrieved from the local cache
 *   or from the memory cache or from the network.
 *
 *   The fifth parameter is set to NO when the CJZFWebImageProgressiveLoad option is used and the image is
 *   downloading. This block is thus called repeatedly with a partial image. When image is fully downloaded, the
 *   block is called a last time with the full image and the last parameter set to YES.
 *
 *   The last parameter is the original image URL
 *
 * @return Returns an instance of CJZFWebImageCombinedOperation, which you can cancel the loading process.
 */
- (nullable CJZFWebImageCombinedOperation *)loadImageWithURL:(nullable NSURL *)url
                                                   options:(CJZFWebImageOptions)options
                                                  progress:(nullable CJZFImageLoaderProgressBlock)progressBlock
                                                 completed:(nonnull CJZFInternalCompletionBlock)completedBlock;

/**
 * Downloads the image at the given URL if not present in cache or return the cached version otherwise.
 *
 * @param url            The URL to the image
 * @param options        A mask to specify options to use for this request
 * @param context        A context contains different options to perform specify changes or processes, see `CJZFWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 * @param progressBlock  A block called while image is downloading
 *                       @note the progress block is executed on a background queue
 * @param completedBlock A block called when operation has been completed.
 *
 * @return Returns an instance of CJZFWebImageCombinedOperation, which you can cancel the loading process.
 */
- (nullable CJZFWebImageCombinedOperation *)loadImageWithURL:(nullable NSURL *)url
                                                   options:(CJZFWebImageOptions)options
                                                   context:(nullable CJZFWebImageContext *)context
                                                  progress:(nullable CJZFImageLoaderProgressBlock)progressBlock
                                                 completed:(nonnull CJZFInternalCompletionBlock)completedBlock;

/**
 * Cancel all current operations
 */
- (void)cancelAll;

/**
 * Remove the specify URL from failed black list.
 * @param url The failed URL.
 */
- (void)removeFailedURL:(nonnull NSURL *)url;

/**
 * Remove all the URL from failed black list.
 */
- (void)removeAllFailedURLs;

/**
 * Return the cache key for a given URL, does not considerate transformer or thumbnail.
 * @note This method does not have context option, only use the url and manager level cacheKeyFilter to generate the cache key.
 */
- (nullable NSString *)cacheKeyForURL:(nullable NSURL *)url;

/**
 * Return the cache key for a given URL and context option.
 * @note The context option like `.thumbnailPixelSize` and `.imageTransformer` will effect the generated cache key, using this if you have those context associated.
*/
- (nullable NSString *)cacheKeyForURL:(nullable NSURL *)url context:(nullable CJZFWebImageContext *)context;

@end
