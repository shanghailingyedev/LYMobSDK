//
//  CJZFHttpOperation.h
//  CJZFNetworking
//
//  Created by 早范 on 2025/7/7.
//
//

#import <Foundation/Foundation.h>

@class CJZFHttpOperation;
typedef void(^CJZFHttpOperationCompletionBlock)(CJZFHttpOperation *operation, NSURLSessionDataTask *dataTask, NSData *data, NSError *error);

@interface CJZFHttpOperation : NSOperation

@property (nonatomic, strong, readonly) NSURLRequest *URLRequest;
@property (nonatomic, strong, readonly) NSURLSessionDataTask *dataTask;

@property (nonatomic, readonly, strong) NSURLResponse *response;
@property (nonatomic, readonly, strong) NSData *responseObject;
@property (nonatomic, readonly, strong) NSError *error;

+ (instancetype)operationWithRequest:(NSURLRequest *)URLRequest;
- (instancetype)initWithRequest:(NSURLRequest *)URLRequest;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

- (void)setCompletion:(CJZFHttpOperationCompletionBlock)completion;

@end
