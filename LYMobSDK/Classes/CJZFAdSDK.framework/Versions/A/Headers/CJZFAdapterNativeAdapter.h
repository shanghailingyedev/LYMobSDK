//
//  CJZFAdapterNativeAdapter.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/5/4.
//

#import "CJZFAdapterCommonAdapter.h"
#import "CJZFAdapterNativeCallBack.h"
#import "CJZFAdapterNativeRequestContext.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterNativeAdapter : CJZFAdapterCommonAdapter

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)new NS_UNAVAILABLE;

@property (nonatomic, weak) id<CJZFAdapterNativeCallBack> delegate;

@property (nonatomic, strong) CJZFAdapterNativeRequestContext *requestContext;

- (instancetype)initWithPlatformPosModel:(CJZFAdSDKPosModel *)posModel
                                  userID:(NSString *)userID
                          viewController:(UIViewController *)viewController
                                   muted:(BOOL)muted
                               loadCount:(int)loadCount
                                  adSize:(CGSize)adSize
                                autoPlay:(BOOL)autoPlay
                       customLoadingPage:(BOOL)customLoadingPage
                                  scenes:(NSDictionary *)scenes
                                 cacheId:(NSString *)cacheId
                            platformType:(NSString *)platformType;

@end

NS_ASSUME_NONNULL_END
