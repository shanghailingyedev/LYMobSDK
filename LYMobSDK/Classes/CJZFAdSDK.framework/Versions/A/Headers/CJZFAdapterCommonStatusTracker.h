//
//  CJZFAdapterCommonStatusTracker.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/13.
//

#import <Foundation/Foundation.h>
#import "CJZFAdapterCommonDefine.h"

NS_ASSUME_NONNULL_BEGIN

@class CJZFAdSDKPosModel;

@interface CJZFAdapterCommonStatusTracker : NSObject

@property (nonatomic, copy) CJZFAdapterPlatform platform;

@property (nonatomic, copy) CJZFAdapterAdType adType;

@property (nonatomic, copy) NSString *requestId;

- (instancetype)initWithPosModel:(CJZFAdSDKPosModel *)posModel userID:(NSString *)userID;

- (void)sendReportWithStatus:(CJZFAdapterReportStatus)status
                      number:(NSInteger)number
                       price:(NSInteger)price;


- (void)sendReportWithStatus:(CJZFAdapterReportStatus)status
                      number:(NSInteger)number
               reportURLList:(NSArray<NSString *> *)reportURLList
                       price:(NSInteger)price;

- (void)sendCoordinateReportMainDomain:(NSString *)mainDomain containerSize:(CGSize)containerSize sPoint:(CGPoint)sPoint point:(CGPoint)point adType:(NSString *)adType;

@end

NS_ASSUME_NONNULL_END
