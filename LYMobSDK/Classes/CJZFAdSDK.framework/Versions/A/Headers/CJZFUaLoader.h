//
//  CJZFUaLoader.h
//  CJZFAdSDK-Kit
//
//  Created by 早范 on 2025/11/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CJZFUaLoader : NSObject

+ (instancetype)sharedInstance;

- (void)loadUserAgent;

- (void)setDefaultUserAgent:(NSString *)ua;

- (NSString *)useragent;

@end

NS_ASSUME_NONNULL_END
