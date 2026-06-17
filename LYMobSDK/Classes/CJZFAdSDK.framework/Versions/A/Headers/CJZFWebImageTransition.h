//
//  CJZFWebImageTransition.h
//  CJZFAdSDK-Kit
//
//  Created by 早范 on 2025/9/10.
//
#import <UIKit/UIKit.h>
#import "CJZFWebImageCompat.h"

#if CJZF_UIKIT || CJZF_MAC
#import "CJZFImageCache.h"

#if CJZF_UIKIT
typedef UIViewAnimationOptions CJZFWebImageAnimationOptions;
#else
typedef NS_OPTIONS(NSUInteger, CJZFWebImageAnimationOptions) {
    CJZFWebImageAnimationOptionAllowsImplicitAnimation   = 1 << 0, // specify `allowsImplicitAnimation` for the `NSAnimationContext`
    
    CJZFWebImageAnimationOptionCurveEaseInOut            = 0 << 16, // default
    CJZFWebImageAnimationOptionCurveEaseIn               = 1 << 16,
    CJZFWebImageAnimationOptionCurveEaseOut              = 2 << 16,
    CJZFWebImageAnimationOptionCurveLinear               = 3 << 16,
    
    CJZFWebImageAnimationOptionTransitionNone            = 0 << 20, // default
    CJZFWebImageAnimationOptionTransitionFlipFromLeft    = 1 << 20,
    CJZFWebImageAnimationOptionTransitionFlipFromRight   = 2 << 20,
    CJZFWebImageAnimationOptionTransitionCurlUp          = 3 << 20,
    CJZFWebImageAnimationOptionTransitionCurlDown        = 4 << 20,
    CJZFWebImageAnimationOptionTransitionCrossDissolve   = 5 << 20,
    CJZFWebImageAnimationOptionTransitionFlipFromTop     = 6 << 20,
    CJZFWebImageAnimationOptionTransitionFlipFromBottom  = 7 << 20,
};
#endif

typedef void (^CJZFWebImageTransitionPreparesBlock)(__kindof UIView * _Nonnull view, UIImage * _Nullable image, NSData * _Nullable imageData, CJZFImageCacheType cacheType, NSURL * _Nullable imageURL);
typedef void (^CJZFWebImageTransitionAnimationsBlock)(__kindof UIView * _Nonnull view, UIImage * _Nullable image);
typedef void (^CJZFWebImageTransitionCompletionBlock)(BOOL finished);

/**
 This class is used to provide a transition animation after the view category load image finished. Use this on `cjzf_imageTransition` in UIView+CJZFWebCache.h
 for UIKit(iOS & tvOS), we use `+[UIView transitionWithView:duration:options:animations:completion]` for transition animation.
 for AppKit(macOS), we use `+[NSAnimationContext runAnimationGroup:completionHandler:]` for transition animation. You can call `+[NSAnimationContext currentContext]` to grab the context during animations block.
 @note These transition are provided for basic usage. If you need complicated animation, consider to directly use Core Animation or use `CJZFWebImageAvoidAutoSetImage` and implement your own after image load finished.
 */
@interface CJZFWebImageTransition : NSObject

/**
 By default, we set the image to the view at the beginning of the animations. You can disable this and provide custom set image process
 */
@property (nonatomic, assign) BOOL avoidAutoSetImage;
/**
 The duration of the transition animation, measured in seconds. Defaults to 0.5.
 */
@property (nonatomic, assign) NSTimeInterval duration;
/**
 The timing function used for all animations within this transition animation (macOS).
 */
@property (nonatomic, strong, nullable) CAMediaTimingFunction *timingFunction API_UNAVAILABLE(ios, tvos, watchos) API_DEPRECATED("Use CJZFWebImageAnimationOptions instead, or grab NSAnimationContext.currentContext and modify the timingFunction", macos(10.10, 10.10));
/**
 A mask of options indicating how you want to perform the animations.
 */
@property (nonatomic, assign) CJZFWebImageAnimationOptions animationOptions;
/**
 A block object to be executed before the animation sequence starts.
 */
@property (nonatomic, copy, nullable) CJZFWebImageTransitionPreparesBlock prepares;
/**
 A block object that contains the changes you want to make to the specified view.
 */
@property (nonatomic, copy, nullable) CJZFWebImageTransitionAnimationsBlock animations;
/**
 A block object to be executed when the animation sequence ends.
 */
@property (nonatomic, copy, nullable) CJZFWebImageTransitionCompletionBlock completion;

@end

/**
 Convenience way to create transition. Remember to specify the duration if needed.
 for UIKit, these transition just use the correspond `animationOptions`. By default we enable `UIViewAnimationOptionAllowUserInteraction` to allow user interaction during transition.
 for AppKit, these transition use Core Animation in `animations`. So your view must be layer-backed. Set `wantsLayer = YES` before you apply it.
 */
@interface CJZFWebImageTransition (Conveniences)

/// Fade-in transition.
@property (nonatomic, class, nonnull, readonly) CJZFWebImageTransition *fadeTransition;
/// Flip from left transition.
@property (nonatomic, class, nonnull, readonly) CJZFWebImageTransition *flipFromLeftTransition;
/// Flip from right transition.
@property (nonatomic, class, nonnull, readonly) CJZFWebImageTransition *flipFromRightTransition;
/// Flip from top transition.
@property (nonatomic, class, nonnull, readonly) CJZFWebImageTransition *flipFromTopTransition;
/// Flip from bottom transition.
@property (nonatomic, class, nonnull, readonly) CJZFWebImageTransition *flipFromBottomTransition;
/// Curl up transition.
@property (nonatomic, class, nonnull, readonly) CJZFWebImageTransition *curlUpTransition;
/// Curl down transition.
@property (nonatomic, class, nonnull, readonly) CJZFWebImageTransition *curlDownTransition;

/// Fade-in transition with duration.
/// @param duration transition duration, use ease-in-out
+ (nonnull instancetype)fadeTransitionWithDuration:(NSTimeInterval)duration NS_SWIFT_NAME(fade(duration:));

/// Flip from left  transition with duration.
/// @param duration transition duration, use ease-in-out
+ (nonnull instancetype)flipFromLeftTransitionWithDuration:(NSTimeInterval)duration NS_SWIFT_NAME(flipFromLeft(duration:));

/// Flip from right transition with duration.
/// @param duration transition duration, use ease-in-out
+ (nonnull instancetype)flipFromRightTransitionWithDuration:(NSTimeInterval)duration NS_SWIFT_NAME(flipFromRight(duration:));

/// Flip from top transition with duration.
/// @param duration transition duration, use ease-in-out
+ (nonnull instancetype)flipFromTopTransitionWithDuration:(NSTimeInterval)duration NS_SWIFT_NAME(flipFromTop(duration:));

/// Flip from bottom transition with duration.
/// @param duration transition duration, use ease-in-out
+ (nonnull instancetype)flipFromBottomTransitionWithDuration:(NSTimeInterval)duration NS_SWIFT_NAME(flipFromBottom(duration:));

///  Curl up transition with duration.
/// @param duration transition duration, use ease-in-out
+ (nonnull instancetype)curlUpTransitionWithDuration:(NSTimeInterval)duration NS_SWIFT_NAME(curlUp(duration:));

/// Curl down transition with duration.
/// @param duration transition duration, use ease-in-out
+ (nonnull instancetype)curlDownTransitionWithDuration:(NSTimeInterval)duration NS_SWIFT_NAME(curlDown(duration:));

@end

#endif

