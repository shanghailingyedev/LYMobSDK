/*
 * This file is part of the CJZFWebImage package.
 * (c) Olivier Poitrey <>
 * (c) Fabrice Aneche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "CJZFWebImageCompat.h"

/**
 You can use switch case like normal enum. It's also recommended to add a default case. You should not assume anything about the raw value.
 For custom coder plugin, it can also extern the enum for supported format. See `CJZFImageCoder` for more detailed information.
 */
typedef NSInteger CJZFImageFormat NS_TYPED_EXTENSIBLE_ENUM;
static const CJZFImageFormat CJZFImageFormatUndefined = -1;
static const CJZFImageFormat CJZFImageFormatJPEG      = 0;
static const CJZFImageFormat CJZFImageFormatPNG       = 1;
static const CJZFImageFormat CJZFImageFormatGIF       = 2;
static const CJZFImageFormat CJZFImageFormatTIFF      = 3;
static const CJZFImageFormat CJZFImageFormatWebP      = 4;
static const CJZFImageFormat CJZFImageFormatHEIC      = 5;
static const CJZFImageFormat CJZFImageFormatHEIF      = 6;
static const CJZFImageFormat CJZFImageFormatPDF       = 7;
static const CJZFImageFormat CJZFImageFormatSVG       = 8;
static const CJZFImageFormat CJZFImageFormatBMP       = 9;
static const CJZFImageFormat CJZFImageFormatRAW       = 10;

/**
 NSData category about the image content type and UTI.
 */
@interface NSData (CJZFImageContentType)

/**
 *  Return image format
 *
 *  @param data the input image data
 *
 *  @return the image format as `CJZFImageFormat` (enum)
 */
+ (CJZFImageFormat)cjzf_imageFormatForImageData:(nullable NSData *)data;

/**
 *  Convert CJZFImageFormat to UTType
 *
 *  @param format Format as CJZFImageFormat
 *  @return The UTType as CFStringRef
 *  @note For unknown format, `kCJZFUTTypeGIFImage` abstract type will return
 */
+ (nonnull CFStringRef)cjzf_UTTypeFromImageFormat:(CJZFImageFormat)format CF_RETURNS_NOT_RETAINED NS_SWIFT_NAME(cxh_UTType(from:));

/**
 *  Convert UTType to CJZFImageFormat
 *
 *  @param uttype The UTType as CFStringRef
 *  @return The Format as CJZFImageFormat
 *  @note For unknown type, `CJZFImageFormatUndefined` will return
 */
+ (CJZFImageFormat)cjzf_imageFormatFromUTType:(nonnull CFStringRef)uttype;

@end
