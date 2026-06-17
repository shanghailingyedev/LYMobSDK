//
//  CJZFNewNetworkClient.h

#import <Foundation/Foundation.h>
#import "CJZFNewNetworking.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFNewNetworkClient : NSObject

+ (instancetype)sharedManager;

- (void)sendResponesHTTPGetRequest:(NSString *)url parameters:(id _Nullable)parameters header:(NSDictionary *)header success:(nullable void (^)(id responseObject))success failure:(nullable void (^)(NSError *error))failure;

- (void)sendResponesJSONGetRequest:(NSString *)url parameters:(id _Nullable)parameters header:(NSDictionary *)header success:(nullable void (^)(id responseObject))success failure:(nullable void (^)(NSError *error))failure;


- (void)postRequest:(NSString *)url parameters:(id _Nullable)parameters header:(NSDictionary *)header success:(nullable void (^)(id responseObject))success failure:(nullable void (^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
