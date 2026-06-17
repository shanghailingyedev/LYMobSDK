//
//  CJZFAdapterBannerAdapter.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/12.
//

#import "CJZFAdapterCommonAdapter.h"
#import "CJZFAdapterBannerRequestContext.h"
#import "CJZFAdapterBannerCallBack.h"


NS_ASSUME_NONNULL_BEGIN

@class CJZFAdSDKPosModel;

@interface CJZFAdapterBannerAdapter : CJZFAdapterCommonAdapter

@property (nonatomic, strong) CJZFAdapterBannerRequestContext *requestContext;

@property (nonatomic, weak) id<CJZFAdapterBannerCallBack> delegate;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithPlatformPosModel:(CJZFAdSDKPosModel *)posModel
                                  userID:(NSString *)userID
                          viewController:(UIViewController *)viewController
                             refershTime:(int)refershTime
                                  adSize:(CGSize)adSize
                              bannerSize:(NSString *)bannerSize
                       customLoadingPage:(BOOL)customLoadingPage
                                  scenes:(NSDictionary *)scenes
                                 cacheId:(NSString *)cacheId
                             nonstandard:(BOOL)nonstandard
                            platformType:(NSString *)platformType;

@end

NS_ASSUME_NONNULL_END
