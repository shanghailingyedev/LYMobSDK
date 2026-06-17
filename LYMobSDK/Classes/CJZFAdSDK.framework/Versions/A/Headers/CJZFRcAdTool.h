//
//  CJZFRcAdTool.h
//  CJZFAdSDK-RC
//
//  Created by 早范 on 2025/6/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define CJZFRcErrorDomain @"com.CJZFRC.error"

FOUNDATION_EXPORT NSError *CJZFRcError(NSErrorDomain domain, NSInteger code, NSString *localizedDescription);

FOUNDATION_EXPORT NSError *CJZFRcErrorDefaultDomain(NSInteger code, NSString *localizedDescription);

@interface CJZFRcAdTool : NSObject

+ (NSString *)encodeSpecialUrlString:(NSString *)string;

+ (NSString *)changeAdverUrl:(NSString *)url;

+ (NSString *)randomString:(NSInteger)number;

+ (NSString *)requestParam;

+ (NSDictionary *)decryptData:(NSData *)data;

+ (NSString *)sdkVersion;

@end

NS_ASSUME_NONNULL_END
