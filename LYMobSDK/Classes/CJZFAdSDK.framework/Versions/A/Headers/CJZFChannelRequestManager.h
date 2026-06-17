//
//  CJZFChannelRequestManager.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/4/17.
//

#import <Foundation/Foundation.h>
#if __has_include(<CJZFAdSDK-Adapter/CJZFAdSDKAdapter.h>)
#import <CJZFAdSDK-Adapter/CJZFAdSDKAdapter.h>
#else
#import "CJZFAdSDKAdapter.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class CJZFChannelAdData;

@protocol CJZFChannelAdRequestDelegate <NSObject>

@optional

//- (void)requestAdSuccess:(CJZFChannelAdData *)adData;

- (void)requestAdSuccessAdList:(NSArray<CJZFChannelAdData *> *)adDataList;

- (void)requestAdFailed:(NSError *)error;

- (void)requestAdCacheSuccess:(NSString *)posId;

@end

@interface CJZFChannelAdRequestContext : NSObject

@property (nonatomic, copy) NSString *appid;

@property (nonatomic, copy) NSString *posid;
// 广告类型, 1:开屏广告， 2:信息流广告， 3:banner广告 ，4:插屏广告, 5:激励视频广告
@property (nonatomic, assign) NSInteger ad_type;

@property (nonatomic, assign) NSInteger loadCount;

@property (nonatomic, strong) NSDictionary *scenes;

@property (nonatomic, copy) NSString *cacheId;

@property (nonatomic, assign) BOOL isCache;

@property (nonatomic, copy) CJZFAdapterPlatform platform;

@property (nonatomic, assign) BOOL isGame;

@property (nonatomic, copy) NSString *requestDomain;

@property (nonatomic, strong) NSString *requestId;

@end

@interface CJZFChannelRequestManager : NSObject

@property (nonatomic, strong) CJZFChannelAdRequestContext *requestCtx;

@property (nonatomic, weak) id<CJZFChannelAdRequestDelegate> delegate;

- (void)requestAdWithRequestContext:(CJZFChannelAdRequestContext *)requestCtx;

@end

NS_ASSUME_NONNULL_END
