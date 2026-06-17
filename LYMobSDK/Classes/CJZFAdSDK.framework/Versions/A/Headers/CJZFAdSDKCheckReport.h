//
//  CJZFAdSDKCheckReport.h
//  CJZFAdSDK-Core
//
//  Created by 早范 on 2025/9/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdSDKCheckReport : NSObject

+ (instancetype)sharedInstance;

- (void)startCheck:(NSString *)requestDomain appid:(NSString *)appid;

@end

NS_ASSUME_NONNULL_END
