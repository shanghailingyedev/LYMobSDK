/*
* This file is part of the CJZFWebImage package.
* (c) Olivier Poitrey <>
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/
#import <UIKit/UIKit.h>
#import "CJZFWebImageCompat.h"

#if CJZF_MAC

#import <QuartzCore/QuartzCore.h>

/// Helper method for Core Animation transition
FOUNDATION_EXPORT CAMediaTimingFunction * _Nullable CJZFTimingFunctionFromAnimationOptions(CJZFWebImageAnimationOptions options);
FOUNDATION_EXPORT CATransition * _Nullable CJZFTransitionFromAnimationOptions(CJZFWebImageAnimationOptions options);

#endif
