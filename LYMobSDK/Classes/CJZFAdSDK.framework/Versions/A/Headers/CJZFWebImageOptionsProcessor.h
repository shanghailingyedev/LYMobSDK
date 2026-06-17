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
#import "CJZFWebImageDefine.h"

@class CJZFWebImageOptionsResult;

typedef CJZFWebImageOptionsResult * _Nullable(^CJZFWebImageOptionsProcessorBlock)(NSURL * _Nullable url, CJZFWebImageOptions options, CJZFWebImageContext * _Nullable context);

/**
 The options result contains both options and context.
 */
@interface CJZFWebImageOptionsResult : NSObject

/**
 WebCache options.
 */
@property (nonatomic, assign, readonly) CJZFWebImageOptions options;

/**
 Context options.
 */
@property (nonatomic, copy, readonly, nullable) CJZFWebImageContext *context;

/**
 Create a new options result.

 @param options options
 @param context context
 @return The options result contains both options and context.
 */
- (nonnull instancetype)initWithOptions:(CJZFWebImageOptions)options context:(nullable CJZFWebImageContext *)context;

@end

/**
 This is the protocol for options processor.
 Options processor can be used, to control the final result for individual image request's `CJZFWebImageOptions` and `CJZFWebImageContext`
 Implements the protocol to have a global control for each indivadual image request's option.
 */
@protocol CJZFWebImageOptionsProcessor <NSObject>

/**
 Return the processed options result for specify image URL, with its options and context

 @param url The URL to the image
 @param options A mask to specify options to use for this request
 @param context A context contains different options to perform specify changes or processes, see `CJZFWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 @return The processed result, contains both options and context
 */
- (nullable CJZFWebImageOptionsResult *)processedResultForURL:(nullable NSURL *)url
                                                    options:(CJZFWebImageOptions)options
                                                    context:(nullable CJZFWebImageContext *)context;

@end

/**
 A options processor class with block.
 */
@interface CJZFWebImageOptionsProcessor : NSObject<CJZFWebImageOptionsProcessor>

- (nonnull instancetype)initWithBlock:(nonnull CJZFWebImageOptionsProcessorBlock)block;
+ (nonnull instancetype)optionsProcessorWithBlock:(nonnull CJZFWebImageOptionsProcessorBlock)block;

@end
