/*
 * This file is part of the CJZFWebImage package.
 * (c) Olivier Poitrey <>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <UIKit/UIKit.h>
#import "CJZFWebImageCompat.h"

/// CJZFCallbackPolicy controls how we execute the block on the queue, like whether to use `dispatch_async/dispatch_sync`, check if current queue match target queue, or just invoke without any context.
typedef NS_ENUM(NSUInteger, CJZFCallbackPolicy) {
    /// When the current queue is equal to callback queue, sync/async will just invoke `block` directly without dispatch. Else it use `dispatch_async`/`dispatch_sync` to dispatch block on queue. This is useful for UIKit rendering to ensure all blocks executed in the same runloop
    CJZFCallbackPolicySafeExecute = 0,
    /// Follow async/sync using the correspond `dispatch_async`/`dispatch_sync` to dispatch block on queue
    CJZFCallbackPolicyDispatch = 1,
    /// Ignore any async/sync and just directly invoke `block` in current queue (without `dispatch_async`/`dispatch_sync`)
    CJZFCallbackPolicyInvoke = 2
};

/// CJZFCallbackQueue is a wrapper used to control how the completionBlock should perform on queues, used by our `Cache`/`Manager`/`Loader`.
/// Useful when you call CJZFWebImage in non-main queue and want to avoid it callback into main queue, which may cause issue.
@interface CJZFCallbackQueue : NSObject

/// The shared main queue. This is the default value, has the same effect when passing `nil` to `CJZFWebImageContextCallbackQueue`
@property (nonnull, class, readonly) CJZFCallbackQueue *mainQueue;

/// The caller current queue. Using `dispatch_get_current_queue`. This is not a dynamic value and only keep the first call time queue.
@property (nonnull, class, readonly) CJZFCallbackQueue *currentQueue;

/// The global concurrent queue (user-initiated QoS). Using `dispatch_get_global_queue`.
@property (nonnull, class, readonly) CJZFCallbackQueue *globalQueue;

/// The current queue's callback policy, defaults to `CJZFCallbackPolicySafeExecute`, which behaves like the old macro  `dispatch_main_async_safe`
@property (assign, readwrite) CJZFCallbackPolicy policy;

- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new  NS_UNAVAILABLE;
/// Create the callback queue with a GCD queue
/// - Parameter queue: The GCD queue, should not be NULL
- (nonnull instancetype)initWithDispatchQueue:(nonnull dispatch_queue_t)queue NS_DESIGNATED_INITIALIZER;

#pragma mark - Execution Entry

/// Submits a block for execution and returns after that block finishes executing.
/// - Parameter block: The block that contains the work to perform.
- (void)sync:(nonnull dispatch_block_t)block;

/// Schedules a block asynchronously for execution.
/// - Parameter block: The block that contains the work to perform.
- (void)async:(nonnull dispatch_block_t)block;

@end
