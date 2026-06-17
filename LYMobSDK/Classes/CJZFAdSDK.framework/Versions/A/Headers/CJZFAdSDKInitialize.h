//
//  CJZFAdSDKInitialize.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/13.
//

#import <Foundation/Foundation.h>
#if __has_include(<CJZFAdSDK-Adapter/CJZFAdSDKAdapter.h>)
#import <CJZFAdSDK-Adapter/CJZFAdSDKAdapter.h>
#else
#import "CJZFAdSDKAdapter.h"
#endif


NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdSDKInitialize : NSObject

+ (void)initializeAllPlatform:(NSString *)appid;

+ (nullable NSString *)platformVersion:(CJZFAdapterPlatform)platform;

+ (nullable NSDictionary<CJZFAdapterPlatform, NSString *> *)allPlatformVersion;

@end

NS_ASSUME_NONNULL_END
