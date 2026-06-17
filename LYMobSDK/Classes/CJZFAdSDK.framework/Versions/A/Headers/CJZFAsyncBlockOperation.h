/*
 * This file is part of the CJZFWebImage package.
 * (c) Olivier Poitrey <>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
#import <UIKit/UIKit.h>
#import "CJZFWebImageCompat.h"

@class CJZFAsyncBlockOperation;
typedef void (^CJZFAsyncBlock)(CJZFAsyncBlockOperation * __nonnull asyncOperation);

/// A async block operation, success after you call `completer` (not like `NSBlockOperation` which is for sync block, success on return)
@interface CJZFAsyncBlockOperation : NSOperation

- (nonnull instancetype)initWithBlock:(nonnull CJZFAsyncBlock)block;
+ (nonnull instancetype)blockOperationWithBlock:(nonnull CJZFAsyncBlock)block;
- (void)complete;

@end
