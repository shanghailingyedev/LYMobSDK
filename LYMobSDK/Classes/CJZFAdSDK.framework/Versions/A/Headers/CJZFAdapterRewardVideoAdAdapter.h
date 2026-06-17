//
//  CJZFAdapterRewardVideoAdAdapter.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2025/2/24.
//

#import "CJZFAdapterCommonAdapter.h"
#import "CJZFAdapterRewardVideoAdRequestContext.h"
#import "CJZFAdapterRewardVideoCallBack.h"
#import "CJZFAdapterRewardVideoReportMark.h"


NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterRewardVideoAdAdapter : CJZFAdapterCommonAdapter

@property (nonatomic, strong) CJZFAdapterRewardVideoAdRequestContext *requestContext;

@property (nonatomic, weak) id<CJZFAdapterRewardVideoCallBack> delegate;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithPlatformPosModel:(CJZFAdSDKPosModel *)posModel
                                  userID:(NSString *)userID
                                  scenes:(NSDictionary *)scenes
                                 cacheId:(NSString *)cacheId
                       customLoadingPage:(BOOL)customLoadingPage
                            platformType:(NSString *)platformType videoMuted:(BOOL)videoMuted;

- (void)sendFinishReportWithMark:(CJZFAdapterRewardVideoReportMark *)mark urlList:(NSArray<NSString *> *)urlList;

- (void)sendRewardReportWithMark:(CJZFAdapterRewardVideoReportMark *)mark urlList:(NSArray<NSString *> *)urlList;

- (void)sendThreeQuarterReportWithMark:(CJZFAdapterRewardVideoReportMark *)mark urlList:(NSArray<NSString *> *)urlList;

- (void)sendHalfReportWithMark:(CJZFAdapterRewardVideoReportMark *)mark urlList:(NSArray<NSString *> *)urlList;

- (void)sendQuarterReportWithMark:(CJZFAdapterRewardVideoReportMark *)mark urlList:(NSArray<NSString *> *)urlList;

- (void)sendPlayStartReportWithMark:(CJZFAdapterRewardVideoReportMark *)mark urlList:(NSArray<NSString *> *)urlList;

- (void)sendPlayPauseReportUrlList:(NSArray<NSString *> *)urlList;

- (void)sendPlaySkipReportUrlList:(NSArray<NSString *> *)urlList;

- (void)sendPlayRecoverReportUrlList:(NSArray<NSString *> *)urlList;

- (void)sendPlayCloseReportUrlList:(NSArray<NSString *> *)urlList;

- (void)sendPlayingMutedReportUrlList:(NSArray<NSString *> *)urlList;

@end

NS_ASSUME_NONNULL_END
