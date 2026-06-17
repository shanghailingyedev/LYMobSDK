//
//  CJZFAdapterGameAdapter.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2025/8/26.
//

#import "CJZFAdapterCommonAdapter.h"
#import "CJZFAdapterGameRequestContext.h"
#import "CJZFAdapterGameCallBack.h"

NS_ASSUME_NONNULL_BEGIN

@class CJZFAdSDKPosModel;

@interface CJZFAdapterGameAdapter : CJZFAdapterCommonAdapter

@property (nonatomic, strong) CJZFAdapterGameRequestContext *requestContext;

@property (nonatomic, weak) id<CJZFAdapterGameCallBack> delegate;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithPlatformPosModel:(CJZFAdSDKPosModel *)posModel
                                  userID:(NSString *)userID
                          viewController:(UIViewController *)viewController
                                  adSize:(CGSize)adSize
                              bannerSize:(NSString *)bannerSize
                       customLoadingPage:(BOOL)customLoadingPage
                                  scenes:(NSDictionary *)scenes
                                 cacheId:(NSString *)cacheId
                            platformType:(NSString *)platformType;


@end

NS_ASSUME_NONNULL_END
