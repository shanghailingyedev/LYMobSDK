//
//  CJZFChannelCommonAd.h
//  CJZFAdSDK-Channel
//
//  Created by 早范 on 2026/6/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CJZFChannelCommonAd : NSObject

@property (nonatomic, copy) NSString *domain;

@property (nonatomic, copy) NSString *appId;

@property (nonatomic, copy) NSString *posId;

- (void)shouldClickReport:(void (^)(BOOL isReport, NSError *error))reportHandle;

@end

NS_ASSUME_NONNULL_END
