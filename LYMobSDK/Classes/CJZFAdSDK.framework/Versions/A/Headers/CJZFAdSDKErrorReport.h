//
//  CJZFAdSDKErrorReport.h
//  CJZFAdSDK-Core
//
//  Created by 早范 on 2025/11/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdSDKErrorReport : NSObject

+ (void)reportError:(NSError *)error posid:(NSString *)posid;

@end

NS_ASSUME_NONNULL_END
