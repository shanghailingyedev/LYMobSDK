/*
 * This file is part of the CJZFWebImage package.
 * (c) Olivier Poitrey <>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
#import <UIKit/UIKit.h>
#import "CJZFWebImageCompat.h"

#if CJZF_UIKIT

#import "CJZFWebImageManager.h"

/**
 * Integrates CJZFWebImage async downloading and caching of remote images with UIImageView for highlighted state.
 */
@interface UIImageView (CJZFHighlightedWebCache)

#pragma mark - Highlighted Image

/**
 * Get the current highlighted image URL.
 */
@property (nonatomic, strong, readonly, nullable) NSURL *cjzf_currentHighlightedImageURL;

/**
 * Set the imageView `highlightedImage` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the image.
 */
- (void)cjzf_setHighlightedImageWithURL:(nullable NSURL *)url NS_REFINED_FOR_SWIFT;

/**
 * Set the imageView `highlightedImage` with an `url` and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url     The url for the image.
 * @param options The options to use when downloading the image. @see CJZFWebImageOptions for the possible values.
 */
- (void)cjzf_setHighlightedImageWithURL:(nullable NSURL *)url
                              options:(CJZFWebImageOptions)options NS_REFINED_FOR_SWIFT;

/**
 * Set the imageView `highlightedImage` with an `url`, custom options and context.
 *
 * The download is asynchronous and cached.
 *
 * @param url     The url for the image.
 * @param options The options to use when downloading the image. @see CJZFWebImageOptions for the possible values.
 * @param context     A context contains different options to perform specify changes or processes, see `CJZFWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 */
- (void)cjzf_setHighlightedImageWithURL:(nullable NSURL *)url
                              options:(CJZFWebImageOptions)options
                              context:(nullable CJZFWebImageContext *)context;

/**
 * Set the imageView `highlightedImage` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)cjzf_setHighlightedImageWithURL:(nullable NSURL *)url
                            completed:(nullable CJZFExternalCompletionBlock)completedBlock NS_REFINED_FOR_SWIFT;

/**
 * Set the imageView `highlightedImage` with an `url` and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param options        The options to use when downloading the image. @see CJZFWebImageOptions for the possible values.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)cjzf_setHighlightedImageWithURL:(nullable NSURL *)url
                              options:(CJZFWebImageOptions)options
                            completed:(nullable CJZFExternalCompletionBlock)completedBlock;

/**
 * Set the imageView `highlightedImage` with an `url` and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param options        The options to use when downloading the image. @see CJZFWebImageOptions for the possible values.
 * @param progressBlock  A block called while image is downloading
 *                       @note the progress block is executed on a background queue
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)cjzf_setHighlightedImageWithURL:(nullable NSURL *)url
                              options:(CJZFWebImageOptions)options
                             progress:(nullable CJZFImageLoaderProgressBlock)progressBlock
                            completed:(nullable CJZFExternalCompletionBlock)completedBlock;

/**
 * Set the imageView `highlightedImage` with an `url`, custom options and context.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param options        The options to use when downloading the image. @see CJZFWebImageOptions for the possible values.
 * @param context     A context contains different options to perform specify changes or processes, see `CJZFWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 * @param progressBlock  A block called while image is downloading
 *                       @note the progress block is executed on a background queue
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)cjzf_setHighlightedImageWithURL:(nullable NSURL *)url
                              options:(CJZFWebImageOptions)options
                              context:(nullable CJZFWebImageContext *)context
                             progress:(nullable CJZFImageLoaderProgressBlock)progressBlock
                            completed:(nullable CJZFExternalCompletionBlock)completedBlock;

/**
 * Cancel the current highlighted image load (for `UIImageView.highlighted`)
 * @note For normal image, use `cjzf_cancelCurrentImageLoad`
 */
- (void)cjzf_cancelCurrentHighlightedImageLoad;

@end

#endif
