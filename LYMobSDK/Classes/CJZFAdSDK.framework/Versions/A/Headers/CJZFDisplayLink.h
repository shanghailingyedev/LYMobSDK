/*
* This file is part of the CJZFWebImage package.
* (c) Olivier Poitrey <>
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "CJZFWebImageCompat.h"

/// Cross-platform display link wrapper. Do not retain the target
/// Use `CADisplayLink` on iOS/tvOS, `CVDisplayLink` on macOS, `NSTimer` on watchOS
@interface CJZFDisplayLink : NSObject

@property (readonly, nonatomic, weak, nullable) id target;
@property (readonly, nonatomic, assign, nonnull) SEL selector;
@property (readonly, nonatomic) NSTimeInterval duration; // elapsed time in seconds of previous callback. (or it's first callback, use the time between `start` and callback). Always zero when display link not running
@property (readonly, nonatomic) BOOL isRunning;

+ (nonnull instancetype)displayLinkWithTarget:(nonnull id)target selector:(nonnull SEL)sel;

- (void)addToRunLoop:(nonnull NSRunLoop *)runloop forMode:(nonnull NSRunLoopMode)mode;
- (void)removeFromRunLoop:(nonnull NSRunLoop *)runloop forMode:(nonnull NSRunLoopMode)mode;

- (void)start;
- (void)stop;

@end
