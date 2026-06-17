//
//  CJZFWebImageOperation.h
//  CJZFAdSDK-Kit
//
//  Created by 早范 on 2025/9/10.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

/// A protocol represents cancelable operation.
@protocol CJZFWebImageOperation <NSObject>

/// Cancel the operation
- (void)cancel;

@optional

/// Whether the operation has been cancelled.
@property (nonatomic, assign, readonly, getter=isCancelled) BOOL cancelled;

@end

/// NSOperation conform to `CJZFWebImageOperation`.
@interface NSOperation (CJZFWebImageOperation) <CJZFWebImageOperation>

@end
