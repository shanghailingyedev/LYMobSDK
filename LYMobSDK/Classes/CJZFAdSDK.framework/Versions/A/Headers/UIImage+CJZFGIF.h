/*
 * This file is part of the CJZFWebImage package.
 * (c) Olivier Poitrey <>
 * (c) Laurin Brandner
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <UIKit/UIKit.h>
#import "CJZFWebImageCompat.h"

/**
 This category is just use as a convenience method. For more detail control, use methods in `UIImage+CJZFMultiFormat.h` or directly use `CJZFImageCoder`.
 */
@interface UIImage (CJZFGIF)

/**
 Creates an animated UIImage from an NSData.
 This will create animated image if the data is Animated GIF. And will create a static image is the data is Static GIF.

 @param data The GIF data
 @return The created image
 */
+ (nullable UIImage *)cjzf_imageWithGIFData:(nullable NSData *)data;

@end
