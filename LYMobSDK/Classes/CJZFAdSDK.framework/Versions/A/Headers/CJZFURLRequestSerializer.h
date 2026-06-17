//
//  CJZFURLRequestSerializer.h
//  CJZFNetworking
//
//  Created by 早范 on 2025/7/7.
//  
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Returns a percent-escaped string following RFC 3986 for a query string key or value.
 RFC 3986 states that the following characters are "reserved" characters.
 - General Delimiters: ":", "#", "[", "]", "@", "?", "/"
 - Sub-Delimiters: "!", "$", "&", "'", "(", ")", "*", "+", ",", ";", "="
 
 In RFC 3986 - Section 3.4, it states that the "?" and "/" characters should not be escaped to allow
 query strings to include a URL. Therefore, all "reserved" characters with the exception of "?" and "/"
 should be percent-escaped in the query string.
 
 @param string The string to be percent-escaped.
 
 @return The percent-escaped string.
 */
FOUNDATION_EXPORT NSString *CJZFPercentEscapedStringFromString(NSString *string);

/**
 A helper method to generate encoded url query parameters for appending to the end of a URL.
 
 @param parameters A dictionary of key/values to be encoded.
 
 @return A url encoded query string
 */
FOUNDATION_EXPORT NSString *CJZFQueryStringFromParameters(NSDictionary *parameters);


@protocol CJZFURLRequestSerializer <NSObject, NSSecureCoding, NSCopying>

- (nullable NSURLRequest *)requestBySerializingRequest:(NSURLRequest *)request
                                        withParameters:(nullable id)parameters
                                                 error:(NSError * _Nullable __autoreleasing *)error;

@end


#pragma mark -

@interface CJZFHTTPRequestSerializer : NSObject <CJZFURLRequestSerializer>

/// The string encoding used to serialize parameters. `NSUTF8StringEncoding` by default.
@property (nonatomic, assign) NSStringEncoding stringEncoding;

/// default is 'YES'
@property (nonatomic, assign) BOOL allowsCellularAccess;
/// default is "NSURLRequestUseProtocolCachePolicy'
@property (nonatomic, assign) NSURLRequestCachePolicy cachePolicy;
/// default is 'YES'
@property (nonatomic, assign) BOOL HTTPShouldHandleCookies;
/// default is 'NO'
@property (nonatomic, assign) BOOL HTTPShouldUsePipelining;
/// default is 'NSURLNetworkServiceTypeDefault'
@property (nonatomic, assign) NSURLRequestNetworkServiceType networkServiceType;
/// default is 60 seconds
@property (nonatomic, assign) NSTimeInterval timeoutInterval;

@property (nonatomic, readonly, strong) NSDictionary<NSString *, NSString *> *HTTPRequestHeaders;
- (void)setValue:(id)value forHTTPHeaderField:(nonnull NSString *)field;

/// HTTP methods for which serialized requests will encode parameters as a query string. `GET`, `HEAD`, and `DELETE` by default.
@property (nonatomic, strong) NSSet<NSString *> *HTTPMethodsEncodingParametersInURI;

- (NSMutableURLRequest *)requestWithMethod:(NSString *)method
                                 URLString:(NSString *)URLString
                                parameters:(id)parameters
                                     error:(NSError *__autoreleasing *)error;

@end

#pragma mark -

@interface CJZFJSONRequestSerializer : CJZFHTTPRequestSerializer

/// default is '0', see the `NSJSONSerialization` documentation section "NSJSONWritingOptions"
@property (nonatomic, assign) NSJSONWritingOptions writingOptions;

+ (instancetype)serializerWithWritingOptions:(NSJSONWritingOptions)writingOptions;

@end

NS_ASSUME_NONNULL_END
