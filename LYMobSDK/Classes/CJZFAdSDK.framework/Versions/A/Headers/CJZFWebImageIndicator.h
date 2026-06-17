/*
 * This file is part of the CJZFWebImage package.
 * (c) Olivier Poitrey <>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
#import <UIKit/UIKit.h>
#import "CJZFWebImageCompat.h"

#if CJZF_UIKIT || CJZF_MAC

/**
 A protocol to custom the indicator during the image loading.
 All of these methods are called from main queue.
 */
@protocol CJZFWebImageIndicator <NSObject>

@required
/**
 The view associate to the indicator.

 @return The indicator view
 */
@property (nonatomic, strong, readonly, nonnull) UIView *indicatorView;

/**
 Start the animating for indicator.
 */
- (void)startAnimatingIndicator;

/**
 Stop the animating for indicator.
 */
- (void)stopAnimatingIndicator;

@optional
/**
 Update the loading progress (0-1.0) for indicator. Optional
 
 @param progress The progress, value between 0 and 1.0
 */
- (void)updateIndicatorProgress:(double)progress;

@end

#pragma mark - Activity Indicator

/**
 Activity indicator class.
 for UIKit(macOS), it use a `UIActivityIndicatorView`.
 for AppKit(macOS), it use a `NSProgressIndicator` with the spinning style.
 */
@interface CJZFWebImageActivityIndicator : NSObject <CJZFWebImageIndicator>

#if CJZF_UIKIT
@property (nonatomic, strong, readonly, nonnull) UIActivityIndicatorView *indicatorView;
#else
@property (nonatomic, strong, readonly, nonnull) NSProgressIndicator *indicatorView;
#endif

@end

/**
 Convenience way to use activity indicator.
 */
@interface CJZFWebImageActivityIndicator (Conveniences)

#if !CJZF_VISION
/// These indicator use the fixed color without dark mode support
/// gray-style activity indicator
@property (nonatomic, class, nonnull, readonly) CJZFWebImageActivityIndicator *grayIndicator;
/// large gray-style activity indicator
@property (nonatomic, class, nonnull, readonly) CJZFWebImageActivityIndicator *grayLargeIndicator;
/// white-style activity indicator
@property (nonatomic, class, nonnull, readonly) CJZFWebImageActivityIndicator *whiteIndicator;
/// large white-style activity indicator
@property (nonatomic, class, nonnull, readonly) CJZFWebImageActivityIndicator *whiteLargeIndicator;
#endif
/// These indicator use the system style, supports dark mode if available (iOS 13+/macOS 10.14+)
/// large activity indicator
@property (nonatomic, class, nonnull, readonly) CJZFWebImageActivityIndicator *largeIndicator;
/// medium activity indicator
@property (nonatomic, class, nonnull, readonly) CJZFWebImageActivityIndicator *mediumIndicator;

@end

#pragma mark - Progress Indicator

/**
 Progress indicator class.
 for UIKit(macOS), it use a `UIProgressView`.
 for AppKit(macOS), it use a `NSProgressIndicator` with the bar style.
 */
@interface CJZFWebImageProgressIndicator : NSObject <CJZFWebImageIndicator>

#if CJZF_UIKIT
@property (nonatomic, strong, readonly, nonnull) UIProgressView *indicatorView;
#else
@property (nonatomic, strong, readonly, nonnull) NSProgressIndicator *indicatorView;
#endif

@end

/**
 Convenience way to create progress indicator. Remember to specify the indicator width or use layout constraint if need.
 */
@interface CJZFWebImageProgressIndicator (Conveniences)

/// default-style progress indicator
@property (nonatomic, class, nonnull, readonly) CJZFWebImageProgressIndicator *defaultIndicator;
/// bar-style progress indicator
@property (nonatomic, class, nonnull, readonly) CJZFWebImageProgressIndicator *barIndicator API_UNAVAILABLE(macos, tvos);

@end

#endif
