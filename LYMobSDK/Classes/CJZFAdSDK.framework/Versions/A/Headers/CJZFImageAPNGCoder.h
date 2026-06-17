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
 Built in coder using ImageIO that supports APNG encoding/decoding
 */
@interface CJZFImageAPNGCoder : CJZFImageIOAnimatedCoder <CJZFProgressiveImageCoder, CJZFAnimatedImageCoder>

@property (nonatomic, class, readonly, nonnull) CJZFImageAPNGCoder *sharedCoder;

@end
