//
//  CJZFNewNetworkReportClient.h
//  CJZFAdSDK-Kit
//
//  Created by 早范 on 2026/6/30.
//

#import <Foundation/Foundation.h>
#import "CJZFNewNetworking.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFNewNetworkReportClient : NSObject

+ (instancetype)sharedManager;

- (void)sendResponesHTTPGetRequest:(NSString *)url parameters:(id _Nullable)parameters header:(NSDictionary *)header success:(nullable void (^)(id responseObject))success failure:(nullable void (^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
