/*
 * This file is part of the CJZFWebImage package.
 * (c) Olivier Poitrey <>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <UIKit/UIKit.h>
#import "CJZFWebImageCompat.h"
#import "NSData+CJZFImageContentType.h"
#import "CJZFImageCoder.h"

/**
 UIImage category for image metadata, including animation, loop count, format, incremental, etc.
 */
@interface UIImage (CJZFMetadata)

/**
 * UIKit:
 * For static image format, this value is always 0.
 * For animated image format, 0 means infinite looping.
 * Note that because of the limitations of categories this property can get out of sync if you create another instance with CGImage or other methods.
 * AppKit:
 * NSImage currently only support animated via `NSBitmapImageRep`(GIF) or `CJZFAnimatedImageRep`(APNG/GIF/WebP) unlike UIImage.
 * The getter of this property will get the loop count from animated imageRep
 * The setter of this property will set the loop count from animated imageRep
 */
@property (nonatomic, assign) NSUInteger cjzf_imageLoopCount;

/**
 * UIKit:
 * Returns the `images`'s count by unapply the patch for the different frame durations. Which matches the real visible frame count when displaying on UIImageView.
 * See more in `CJZFImageCoderHelper.animatedImageWithFrames`.
 * Returns 1 for static image.
 * AppKit:
 * Returns the underlaying `NSBitmapImageRep` or `CJZFAnimatedImageRep` frame count.
 * Returns 1 for static image.
 */
@property (nonatomic, assign, readonly) NSUInteger cjzf_imageFrameCount;

/**
 * UIKit:
 * Check the `images` array property.
 * AppKit:
 * NSImage currently only support animated via GIF imageRep unlike UIImage. It will check the imageRep's frame count.
 */
@property (nonatomic, assign, readonly) BOOL cjzf_isAnimated;

/**
 * UIKit:
 * Check the `isSymbolImage` property. Also check the system PDF(iOS 11+) && SVG(iOS 13+) support.
 * AppKit:
 * NSImage supports PDF && SVG && EPS imageRep, check the imageRep class.
 */
@property (nonatomic, assign, readonly) BOOL cjzf_isVector;

/**
 * The image format represent the original compressed image data format.
 * If you don't manually specify a format, this information is retrieve from CGImage using `CGImageGetUTType`, which may return nil for non-CG based image. At this time it will return `CJZFImageFormatUndefined` as default value.
 * @note Note that because of the limitations of categories this property can get out of sync if you create another instance with CGImage or other methods.
 */
@property (nonatomic, assign) CJZFImageFormat cjzf_imageFormat;

/**
 A bool value indicating whether the image is during incremental decoding and may not contains full pixels.
 */
@property (nonatomic, assign) BOOL cjzf_isIncremental;

/**
 A bool value indicating that the image is transformed from original image, so the image data may not always match original download one.
 */
@property (nonatomic, assign) BOOL cjzf_isTransformed;

/**
 A bool value indicating that the image is using thumbnail decode with smaller size, so the image data may not always match original download one.
 @note This just check `cjzf_decodeOptions[.decodeThumbnailPixelSize] > CGSize.zero`
 */
@property (nonatomic, assign, readonly) BOOL cjzf_isThumbnail;

/**
 A dictionary value contains the decode options when decoded from CJZFWebImage loading system (say, `CJZFImageCacheDecodeImageData/CJZFImageLoaderDecode[Progressive]ImageData`)
 It may not always available and only image decoding related options will be saved. (including [.decodeScaleFactor, .decodeThumbnailPixelSize, .decodePreserveAspectRatio, .decodeFirstFrameOnly])
 @note This is used to identify and check the image is from thumbnail decoding, and the callback's data **will be nil** (because this time the data saved to disk does not match the image return to you. If you need full size data, query the cache with full size url key)
 @warning You should not store object inside which keep strong reference to image itself, which will cause retain cycle.
 @warning This API exist only because of current CJZFWebImageDownloader bad design which does not callback the context we call it. There will be refactor in future (API break), use with caution.
 */
@property (nonatomic, copy) CJZFImageCoderOptions *cjzf_decodeOptions;

@end
