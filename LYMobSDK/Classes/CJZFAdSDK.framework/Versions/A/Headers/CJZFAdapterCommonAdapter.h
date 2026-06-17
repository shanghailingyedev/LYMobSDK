//
//  CJZFAdapterCommonAdapter.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/12.
//

#import <Foundation/Foundation.h>
#import "CJZFAdapterCommonDefine.h"
#import "CJZFAdapterCommonStatusTracker.h"
#import "CJZFAdapterCommonReportMark.h"
#import "CJZFAdSDKConfigModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterCommonAdapter : NSObject

@property (nonatomic, strong) CJZFAdapterCommonStatusTracker *tracker;

@property (nonatomic, strong) CJZFAdSDKPosModel *posModel;
/**
 是否展示关闭按钮，默认展示，为YES则不展示
*/
@property (nonatomic, assign) BOOL hiddenCloseView;

@property (nonatomic, copy) NSString *requestId;

- (nullable CJZFAdapterAdType)platformAdType;

- (nullable CJZFAdapterPlatform)platformType;

- (void)setUpPlatformAdPosModel:(CJZFAdSDKPosModel *)posModel userID:(NSString *)userID;

// request
- (void)sendRequestReportWithCount:(NSInteger)count;
- (void)sendRequestReportWithMark:(CJZFAdapterCommonReportMark *)mark;

// success
- (void)sendSuccessReportWithCount:(NSInteger)count;
- (void)sendSuccessReportWithCount:(NSInteger)count price:(NSInteger)price;
- (void)sendSuccessReportWithMark:(CJZFAdapterCommonReportMark *)mark;

// fail
- (void)sendFailureReportWithCount:(NSInteger)count;

// display
- (void)sendDisplayReportWithMark:(CJZFAdapterCommonReportMark *)mark;
- (void)sendDisplayReportWithMark:(CJZFAdapterCommonReportMark *)mark urlList:(NSArray<NSString *> *)urlList;

// click
- (void)sendClickReportWithMark:(CJZFAdapterCommonReportMark *)mark;
- (void)sendClickReportWithMark:(CJZFAdapterCommonReportMark *)mark urlList:(NSArray<NSString *> *)urlList;

// close
- (void)sendCloseReportWithMark:(CJZFAdapterCommonReportMark *)mark;

- (void)sendCoordinateReportMainDomain:(NSString *)mainDomain containerSize:(CGSize)containerSize sPoint:(CGPoint)sPoint point:(CGPoint)point mark:(CJZFAdapterCommonReportMark *)mark adType:(NSString *)adType;

@end

NS_ASSUME_NONNULL_END
