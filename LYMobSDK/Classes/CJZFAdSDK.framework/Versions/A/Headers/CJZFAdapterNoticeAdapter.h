//
//  CJZFAdapterNoticeAdapter.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2026/5/15.
//

#import "CJZFAdapterCommonAdapter.h"
#import "CJZFAdapterNoticeRequestContext.h"
#import "CJZFAdapterNoticeCallBack.h"

NS_ASSUME_NONNULL_BEGIN

@class CJZFAdSDKPosModel;

@interface CJZFAdapterNoticeAdapter : CJZFAdapterCommonAdapter

@property (nonatomic, strong) CJZFAdapterNoticeRequestContext *requestContext;

@property (nonatomic, weak) id<CJZFAdapterNoticeCallBack> delegate;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithPlatformPosModel:(CJZFAdSDKPosModel *)posModel
                                  userID:(NSString *)userID
                          viewController:(UIViewController *)viewController
                       customLoadingPage:(BOOL)customLoadingPage
                                  scenes:(NSDictionary *)scenes
                                 cacheId:(NSString *)cacheId
                            styleType:(CJZFAdSDKNoticeAdStyleType)styleType;

@end

NS_ASSUME_NONNULL_END
