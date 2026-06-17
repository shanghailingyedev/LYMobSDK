/*
 * This file is part of the CJZFWebImage package.
 * (c) Olivier Poitrey <>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
#import <UIKit/UIKit.h>
#import "CJZFWebImageCompat.h"
#import "CJZFWebImageDefine.h"
#import "CJZFWebImageManager.h"
#import "CJZFWebImageTransition.h"
#import "CJZFWebImageIndicator.h"
#import "UIView+CJZFWebCacheOperation.h"
#import "UIView+CJZFWebCacheState.h"

/**
 The value specify that the image progress unit count cannot be determined because the progressBlock is not been called.
 */
FOUNDATION_EXPORT const int64_t CJZFWebImageProgressUnitCountUnknown; /* 1LL */

typedef void(^CJZFSetImageBlock)(UIImage * _Nullable image, NSData * _Nullable imageData, CJZFImageCacheType cacheType, NSURL * _Nullable imageURL);

/**
 Integrates CJZFWebImage async downloading and caching of remote images with UIView subclass.
 */
@interface UIView (CJZFWebCache)

/**
 * Get the current image operation key. Operation key is used to identify the different queries for one view instance (like UIButton).
 * See more about this in `CJZFWebImageContextSetImageOperationKey`.
 *
 * @note You can use method `UIView+CJZFWebCacheOperation` to investigate different queries' operation.
 * @note For the history version compatible, when current UIView has property exactly called `image`, the operation key will use `NSStringFromClass(self.class)`. Include `UIImageView.image/NSImageView.image/NSButton.image` (without `UIButton`)
 * @warning This property should be only used for single state view, like `UIImageView` without highlighted state. For stateful view like `UIBUtton` (one view can have multiple images loading), check their header to call correct API, like `-[UIButton cjzf_imageOperationKeyForState:]`
 */
@property (nonatomic, strong, readonly, nullable) NSString *cjzf_latestOperationKey;

#pragma mark - State

/**
 * Get the current image URL.
 * This simply translate to `[self cjzf_imageLoadStateForKey:self.cjzf_latestOperationKey].url` from v5.18.0
 *
 * @note Note that because of the limitations of categories this property can get out of sync if you use setImage: directly.
 * @warning This property should be only used for single state view, like `UIImageView` without highlighted state. For stateful view like `UIBUtton` (one view can have multiple images loading), use `cjzf_imageLoadStateForKey:` instead. See `UIView+CJZFWebCacheState.h` for more information.
 */
@property (nonatomic, strong, readonly, nullable) NSURL *cjzf_imageURL;

/**
 * The current image loading progress associated to the view. The unit count is the received size and excepted size of download.
 * The `totalUnitCount` and `completedUnitCount` will be reset to 0 after a new image loading start (change from current queue). And they will be set to `CJZFWebImageProgressUnitCountUnknown` if the progressBlock not been called but the image loading success to mark the progress finished (change from main queue).
 * @note You can use Key-Value Observing on the progress, but you should take care that the change to progress is from a background queue during download(the same as progressBlock). If you want to using KVO and update the UI, make sure to dispatch on the main queue. And it's recommend to use some KVO libs like KVOController because it's more safe and easy to use.
 * @note The getter will create a progress instance if the value is nil. But by default, we don't create one. If you need to use Key-Value Observing, you must trigger the getter or set a custom progress instance before the loading start. The default value is nil.
 * @note Note that because of the limitations of categories this property can get out of sync if you update the progress directly.
 * @warning This property should be only used for single state view, like `UIImageView` without highlighted state. For stateful view like `UIBUtton` (one view can have multiple images loading), use `cjzf_imageLoadStateForKey:` instead. See `UIView+CJZFWebCacheState.h` for more information.
 */
@property (nonatomic, strong, null_resettable) NSProgress *cjzf_imageProgress;

/**
 * Set the imageView `image` with an `url` and optionally a placeholder image.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param options        The options to use when downloading the image. @see CJZFWebImageOptions for the possible values.
 * @param context        A context contains different options to perform specify changes or processes, see `CJZFWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 * @param setImageBlock  Block used for custom set image code. If not provide, use the built-in set image code (supports `UIImageView/NSImageView` and `UIButton/NSButton` currently)
 * @param progressBlock  A block called while image is downloading
 *                       @note the progress block is executed on a background queue
 * @param completedBlock A block called when operation has been completed.
 *   This block has no return value and takes the requested UIImage as first parameter and the NSData representation as second parameter.
 *   In case of error the image parameter is nil and the third parameter may contain an NSError.
 *
 *   The forth parameter is an `CJZFImageCacheType` enum indicating if the image was retrieved from the local cache
 *   or from the memory cache or from the network.
 *
 *   The fifth parameter normally is always YES. However, if you provide CJZFWebImageAvoidAutoSetImage with CJZFWebImageProgressiveLoad options to enable progressive downloading and set the image yourself. This block is thus called repeatedly with a partial image. When image is fully downloaded, the
 *   block is called a last time with the full image and the last parameter set to YES.
 *
 *   The last parameter is the original image URL
 *  @return The returned operation for cancelling cache and download operation, typically type is `CJZFWebImageCombinedOperation`
 */
- (nullable id<CJZFWebImageOperation>)cjzf_internalSetImageWithURL:(nullable NSURL *)url
                                              placeholderImage:(nullable UIImage *)placeholder
                                                       options:(CJZFWebImageOptions)options
                                                       context:(nullable CJZFWebImageContext *)context
                                                 setImageBlock:(nullable CJZFSetImageBlock)setImageBlock
                                                      progress:(nullable CJZFImageLoaderProgressBlock)progressBlock
                                                     completed:(nullable CJZFInternalCompletionBlock)completedBlock;

/**
 * Cancel the current image load
 * This simply translate to `[self cjzf_cancelImageLoadOperationWithKey:self.cjzf_latestOperationKey]` from v5.18.0
 * 
 * @warning This method should be only used for single state view, like `UIImageView` without highlighted state. For stateful view like `UIBUtton` (one view can have multiple images loading), use `cjzf_cancelImageLoadOperationWithKey:` instead. See `UIView+CJZFWebCacheOperation.h` for more information.
 */
- (void)cjzf_cancelCurrentImageLoad;

#if CJZF_UIKIT || CJZF_MAC

#pragma mark - Image Transition

/**
 The image transition when image load finished. See `CJZFWebImageTransition`.
 If you specify nil, do not do transition. Defaults to nil.
 @warning This property should be only used for single state view, like `UIImageView` without highlighted state. For stateful view like `UIBUtton` (one view can have multiple images loading), write your own implementation in `setImageBlock:`, and check current stateful view's state to render the UI.
 */
@property (nonatomic, strong, nullable) CJZFWebImageTransition *cjzf_imageTransition;

#pragma mark - Image Indicator

/**
 The image indicator during the image loading. If you do not need indicator, specify nil. Defaults to nil
 The setter will remove the old indicator view and add new indicator view to current view's subview.
 @note Because this is UI related, you should access only from the main queue.
 @warning This property should be only used for single state view, like `UIImageView` without highlighted state. For stateful view like `UIBUtton` (one view can have multiple images loading), write your own implementation in `setImageBlock:`, and check current stateful view's state to render the UI.
 */
@property (nonatomic, strong, nullable) id<CJZFWebImageIndicator> cjzf_imageIndicator;

#endif

@end
