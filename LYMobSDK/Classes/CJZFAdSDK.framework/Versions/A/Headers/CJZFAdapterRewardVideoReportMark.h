//
//  CJZFAdapterRewardVideoReportMark.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2025/2/27.
//

#import "CJZFAdapterCommonReportMark.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterRewardVideoReportMark : CJZFAdapterCommonReportMark

@property (nonatomic, assign) BOOL quarterReported;
@property (nonatomic, assign) BOOL halfReported;
@property (nonatomic, assign) BOOL threeQuarterReported;
@property (nonatomic, assign) BOOL finishReported;
@property (nonatomic, assign) BOOL startReported;
@property (nonatomic, assign) BOOL rewardReported;


- (void)refreshVideoStatus;

- (void)setQuarterStatus:(BOOL)status;
- (BOOL)getQuarterStatus;

- (void)setHalfStatus:(BOOL)status;
- (BOOL)getHalfStatus;

- (void)setThreeQuarterStatus:(BOOL)status;
- (BOOL)getThreeQuarterStatus;

- (void)setFinishStatus:(BOOL)status;
- (BOOL)getFinishStatus;

- (void)setStartStatus:(BOOL)status;
- (BOOL)getStartStatus;

- (void)setRewardStatus:(BOOL)status;
- (BOOL)getRewardStatus;

@end

NS_ASSUME_NONNULL_END
