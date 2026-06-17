//
//  CJZFChannelGameRequestManager.h
//  CJZFAdSDK-Channel
//
//  Created by 早范 on 2025/9/2.
//

#import <Foundation/Foundation.h>
#if __has_include(<CJZFAdSDK-Adapter/CJZFAdSDKAdapter.h>)
#import <CJZFAdSDK-Adapter/CJZFAdSDKAdapter.h>
#else
#import "CJZFAdSDKAdapter.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class CJZFChannelAdData;

@protocol CJZFChannelGameAdRequestDelegate <NSObject>

@optional

- (void)requestGameAdSuccess:(CJZFChannelAdData *)adData;

- (void)requestGameAdFailed:(NSError *)error;

@end

@interface CJZFChannelGameRequestManager : NSObject

@property (nonatomic, weak) id<CJZFChannelGameAdRequestDelegate> delegate;

@property (nonatomic, copy) CJZFAdapterPlatform platform;

@property (nonatomic, copy) NSString *appid;

@property (nonatomic, copy) NSString *posid;

@property (nonatomic, copy) NSString *requestDomain;

- (void)requestAd;

@end

NS_ASSUME_NONNULL_END
