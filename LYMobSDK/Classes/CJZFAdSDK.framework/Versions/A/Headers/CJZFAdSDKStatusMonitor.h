//
//  CJZFAdSDKStatusMonitor.h
//  CJZFAdSDK-Core
//
//  Created by 早范 on 2026/3/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdSDKStatusMonitor : NSObject

+ (NSError *)isSendError;

+ (BOOL)isStartTimer;

+ (BOOL)isUAReady;

+ (BOOL)isUaEmpty;

+ (NSError *)getErrorWhenTimeStop;

+ (BOOL)isSkipLoop;

@end

NS_ASSUME_NONNULL_END
