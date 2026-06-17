//
//  CJZFAdapterSplashAdapter.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2025/9/21.
//

#import "CJZFAdapterCommonAdapter.h"
#import "CJZFAdapterSplashRequestContext.h"
#import "CJZFAdapterSplashCallBack.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterSplashAdapter : CJZFAdapterCommonAdapter

@property (nonatomic, strong) CJZFAdapterSplashRequestContext *requestContext;

@property (nonatomic, weak) id<CJZFAdapterSplashCallBack> delegate;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithPlatformPosModel:(CJZFAdSDKPosModel *)posModel
                                  userID:(NSString *)userID
                          viewController:(UIViewController *)viewController
                                  scenes:(NSDictionary *)scenes
                              rootWindow:(UIWindow *)window
                         backgroundImage:(UIImage *)backgroundImage
                              bottomView:(nullable UIView *)bottomView
                                showTime:(NSInteger)showTime
                                 cacheId:(NSString *)cacheId
                       customLoadingPage:(BOOL)customLoadingPage
                            platformType:(NSString *)platformType rightTop:(BOOL)rightTop;

@end

NS_ASSUME_NONNULL_END
