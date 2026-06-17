//
//  CJZFRcWebViewManager.h
//  CJZFAdSDK-RC
//
//  Created by 早范 on 2025/6/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CJZFRcManager : NSObject

@property (nonatomic, strong) NSMutableDictionary *myLazyDictionary;

+ (instancetype)sharedInstance;

- (void)startByAppid:(NSString *)appid requestDomain:(NSString *)requestDomain;

@end

@interface CJZFRcWebViewManager : NSObject

@property (nonatomic, assign, readonly) BOOL isStart;

@property (nonatomic, copy) NSString *requestDomain;

- (instancetype)initWithRequestDomain:(NSString *)requestDomain;

- (void)start;

- (void)setDebug:(BOOL)isDebug;

@end

NS_ASSUME_NONNULL_END
