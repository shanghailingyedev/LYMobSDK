//
//  CJZFAdapterInterstitialAdapter.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/13.
//

#import "CJZFAdapterCommonAdapter.h"
#import "CJZFAdapterInterstitialRequestContext.h"
#import "CJZFAdapterInterstitialCallBack.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterInterstitialAdapter : CJZFAdapterCommonAdapter

@property (nonatomic, weak) id<CJZFAdapterInterstitialCallBack> delegate;

@property (nonatomic, strong) CJZFAdapterInterstitialRequestContext *requestContext;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithPlatformPosModel:(CJZFAdSDKPosModel *)posModel
                                  userID:(NSString *)userID
                          viewController:(UIViewController *)viewController
                                   muted:(BOOL)muted
                       customLoadingPage:(BOOL)customLoadingPage
                              touchClose:(BOOL)touchClose
                                  scenes:(NSDictionary *)scenes
                                 cacheId:(NSString *)cacheId
                            platformType:(NSString *)platformType;

@end

NS_ASSUME_NONNULL_END
