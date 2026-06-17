//
//  CJZFHttpRequestAgent.h
//  CJZFNetworking
//
//  Created by 早范 on 2025/7/7.
//  
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class CJZFHttpRequest;

@interface CJZFHttpRequestAgent : NSObject

@property (nonatomic, readonly, strong) NSOperationQueue *operationQueue;

+ (CJZFHttpRequestAgent *)sharedAgent;

- (void)addRequest:(CJZFHttpRequest *)request;
- (void)cancelRequest:(CJZFHttpRequest *)request;
- (BOOL)containsRequest:(CJZFHttpRequest *)request;
- (void)cancelAllRequest;

@end

NS_ASSUME_NONNULL_END
