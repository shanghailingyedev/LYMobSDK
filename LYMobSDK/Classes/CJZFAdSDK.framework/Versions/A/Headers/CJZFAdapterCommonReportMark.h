//
//  CJZFAdapterCommonReportMark.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterCommonReportMark : NSObject

@property (nonatomic, assign) BOOL requestReported;
@property (nonatomic, assign) BOOL successReported;
@property (nonatomic, assign) BOOL failureReported;
@property (nonatomic, assign) BOOL displayReported;
@property (nonatomic, assign) BOOL clickReported;
@property (nonatomic, assign) BOOL closeReported;
@property (nonatomic, assign) BOOL coordinateReported;

@property (nonatomic, assign) NSInteger adPrice;

- (void)refreshStatus;

- (void)setDisplayStatus:(BOOL)status;
- (BOOL)getDisplayStatus;

- (void)setClickStatus:(BOOL)status;
- (BOOL)getClickStatus;

@end

NS_ASSUME_NONNULL_END
