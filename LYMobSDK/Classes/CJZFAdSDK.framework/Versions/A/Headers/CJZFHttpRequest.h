//
//  CJZFHttpRequest.h
//  CJZFNetworking
//
//  Created by 早范 on 2025/7/7.
//  
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, CJZFHttpRequestSerializerType) {
    CJZFHttpRequestSerializerTypeHTTP = 0,
    CJZFHttpRequestSerializerTypeJSON,
};

typedef NS_ENUM(NSInteger, CJZFHttpResponseSerializerType) {
    // nsdata serializer
    CJZFHttpResponseSerializerTypeHTTP = 0,
    // json serializer
    CJZFHttpResponseSerializerTypeJSON,
    // xml serializer
    CJZFHttpResponseSerializerTypeXMLParser,
};

@class CJZFHttpRequest;
@protocol CJZFHttpRequestDelegate <NSObject>

- (void)CJZF_httpRequestSuccess:(CJZFHttpRequest *)request;
- (void)CJZF_httpRequestFail:(CJZFHttpRequest *)request;

@end

typedef void(^CJZFHttpRequestCompletionBlock)(CJZFHttpRequest *request);

@interface CJZFHttpRequest : NSObject

#pragma mark - Getter

@property (nonatomic, strong, readonly) NSURLSessionTask *requestTask;
@property (nonatomic, strong, readonly) NSHTTPURLResponse *response;
@property (nonatomic, strong, readonly) id responseObject;
@property (nonatomic, strong, readonly, nullable) NSError *error;

@property (nonatomic, readonly, getter=isCancelled) BOOL cancelled;
@property (nonatomic, readonly, getter=isExecuting) BOOL execution;

#pragma mark - Construction Setter

@property (nonatomic, copy) NSString *baseUrl;
@property (nonatomic, copy) NSString *requestUrl;
@property (nonatomic, copy) NSString *HTTPMethod;
/// default is 10 seconds
@property (nonatomic, assign) NSTimeInterval timeoutInterval;
/// default is 'CJZFHttpRequestSerializerTypeHTTP'
@property (nonatomic, assign) CJZFHttpRequestSerializerType requestSerializerType;
/// default is 'CJZFHttpRequestSerializerTypeJSON'
@property (nonatomic, assign) CJZFHttpResponseSerializerType responseSerializerType;
@property (nonatomic, strong, nullable) id requestArguments;
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *HTTPHeaderFields;

#pragma mark - Callback setter

@property (nonatomic, copy, nullable) CJZFHttpRequestCompletionBlock successBlcok;
@property (nonatomic, copy, nullable) CJZFHttpRequestCompletionBlock failureBlock;

@property (nonatomic, weak, nullable) id<CJZFHttpRequestDelegate> delegate;

#pragma mark - Action

- (void)send;

- (void)cancel;

@end

NS_ASSUME_NONNULL_END
