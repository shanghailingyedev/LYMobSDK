/*
 * This file is part of the CJZFWebImage package.
 * (c) Olivier Poitrey <>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "CJZFImageIOAnimatedCoder.h"

/**
 Built in coder using ImageIO that supports animated GIF encoding/decoding
 @note `CJZFImageIOCoder` supports GIF but only as static (will use the 1st frame).
 @note Use `CJZFImageGIFCoder` for fully animated GIFs. For `UIImageView`, it will produce animated `UIImage`(`NSImage` on macOS) for rendering. For `CJZFAnimatedImageView`, it will use `CJZFAnimatedImage` for rendering.
 @note The recommended approach for animated GIFs is using `CJZFAnimatedImage` with `CJZFAnimatedImageView`. It's more performant than `UIImageView` for GIF displaying(especially on memory usage)
 */
@interface CJZFImageGIFCoder : CJZFImageIOAnimatedCoder <CJZFProgressiveImageCoder, CJZFAnimatedImageCoder>

@property (nonatomic, class, readonly, nonnull) CJZFImageGIFCoder *sharedCoder;

@end
