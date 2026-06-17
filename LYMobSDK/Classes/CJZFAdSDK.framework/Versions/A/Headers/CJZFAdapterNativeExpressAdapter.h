//
//  CJZFAdapterNativeExpressAdapter.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/4/9.
//

#import "CJZFAdapterCommonAdapter.h"
#import "CJZFAdapterNativeExpressCallBack.h"
#import "CJZFAdapterNativeExpressRequestContext.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterNativeExpressAdapter : CJZFAdapterCommonAdapter

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)new NS_UNAVAILABLE;

@property (nonatomic, weak) id<CJZFAdapterNativeExpressCallBack> delegate;

@property (nonatomic, strong) CJZFAdapterNativeExpressRequestContext *requestContext;

- (instancetype)initWithPlatformPosModel:(CJZFAdSDKPosModel *)posModel
                                  userID:(NSString *)userID
                          viewController:(UIViewController *)viewController
                                   muted:(BOOL)muted
                               loadCount:(int)loadCount
                                  adSize:(CGSize)adSize
                                autoPlay:(BOOL)autoPlay
                       customLoadingPage:(BOOL)customLoadingPage
                             expressType:(CJZFAdapterNativeExpressType)expressType
                                  scenes:(NSDictionary *)scenes
                                 cacheId:(NSString *)cacheId
                            platformType:(NSString *)platformType;

@end

NS_ASSUME_NONNULL_END
