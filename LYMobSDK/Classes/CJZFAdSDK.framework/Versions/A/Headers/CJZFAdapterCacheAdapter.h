//
//  CJZFAdapterCacheAdapter.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/27.
//

#import "CJZFAdapterCommonAdapter.h"
#import "CJZFAdapterCacheRequestContext.h"
#import "CJZFAdapterCacheCallBack.h"

NS_ASSUME_NONNULL_BEGIN

@class CJZFAdSDKPosModel;

@interface CJZFAdapterCacheAdapter : CJZFAdapterCommonAdapter

@property (nonatomic, strong) CJZFAdapterCacheRequestContext *requestContext;

@property (nonatomic, weak) id<CJZFAdapterCacheCallBack> delegate;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithPlatformPosModel:(CJZFAdSDKPosModel *)posModel
                                  userID:(NSString *)userID
                                  scenes:(NSDictionary *)scenes
                               loadCount:(NSInteger)loadCount
                                  adtype:(NSInteger)adtype
                                 cacheId:(NSString *)cacheId
                            platformType:(NSString *)platformType;

@end

NS_ASSUME_NONNULL_END
