/*
* This file is part of the CJZFWebImage package.
* (c) Olivier Poitrey <>
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/
#import <UIKit/UIKit.h>
#import "CJZFWebImageCompat.h"

/// Copy the associated object from source image to target image. The associated object including all the category read/write properties.
/// @param source source
/// @param target target
FOUNDATION_EXPORT void CJZFImageCopyAssociatedObject(UIImage * _Nullable source, UIImage * _Nullable target);
