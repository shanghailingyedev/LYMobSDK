/*
 * This file is part of the CJZFWebImage package.
 * (c) Olivier Poitrey <>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
#import <UIKit/UIKit.h>
#import "CJZFWebImageCompat.h"

@interface UIColor (CJZFHexString)

/**
 Convenience way to get hex string from color. The output should always be 32-bit RGBA hex string like `#00000000`.
 */
@property (nonatomic, copy, readonly, nonnull) NSString *cjzf_hexString;

@end
