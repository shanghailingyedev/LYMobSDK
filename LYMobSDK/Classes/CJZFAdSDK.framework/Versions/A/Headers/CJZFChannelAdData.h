//
//  CJZFChannelAdData.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/4/17.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#if __has_include(<CJZFAdSDK-Kit/CJZFUtilsKit.h>)
#import <CJZFAdSDK-Kit/CJZFUtilsKit.h>
#else
#import "CJZFUtilsKit.h"
#endif
NS_ASSUME_NONNULL_BEGIN

@interface CJZFChannelAdVideoEndCardData : NSObject
// 1:图片；2：网页；3：HTML代码
@property (nonatomic, assign) NSInteger type;
// 图片地址
@property (nonatomic, copy) NSString *url;
// 网页地址
@property (nonatomic, copy) NSString *html;
// 标题
@property (nonatomic, copy) NSString *title;
// 描述
@property (nonatomic, copy) NSString *desc;

- (instancetype)initModelWithJson:(NSDictionary *)json NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

@end

@interface CJZFChannelAdVideoTracker : NSObject

@property (nonatomic, strong) NSArray<NSString *> *mutedReport;
@property (nonatomic, strong) NSArray<NSString *> *closeReport;
@property (nonatomic, strong) NSArray<NSString *> *skipReport;
@property (nonatomic, strong) NSArray<NSString *> *recoverReport;
@property (nonatomic, strong) NSArray<NSString *> *pauseReport;
@property (nonatomic, strong) NSArray<NSString *> *finishReport;
@property (nonatomic, strong) NSArray<NSString *> *quarterReport;
@property (nonatomic, strong) NSArray<NSString *> *threeQuarterReport;
@property (nonatomic, strong) NSArray<NSString *> *halfReport;
@property (nonatomic, strong) NSArray<NSString *> *startReport;
@property (nonatomic, strong) NSArray<NSString *> *videoRewardReoprt;

@property (nonatomic, strong) NSArray<NSString *> *webLoadFinishReport;
@property (nonatomic, strong) NSArray<NSString *> *webClosedReport;
@property (nonatomic, strong) NSArray<NSString *> *webActionReport;

- (instancetype)initModelWithJson:(NSArray<NSDictionary *> *)json NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

@end

@interface CJZFChannelAdVideoData : NSObject

@property (nonatomic, copy) NSString *url;

@property (nonatomic, assign) NSInteger type;

@property (nonatomic, copy) NSString *cover;

@property (nonatomic, copy) NSString *mime;

@property (nonatomic, assign) NSInteger width;

@property (nonatomic, assign) NSInteger height;

@property (nonatomic, assign) NSInteger size;
// 视频时长
@property (nonatomic, assign) NSInteger duration;
// 是否支持跳过，0：不支持；1：支持；
@property (nonatomic, assign) NSInteger skip;
// 最小跳过时间
@property (nonatomic, assign) NSInteger min_time;
// 视频过期时间
@property (nonatomic, assign) NSInteger expires;
//
@property (nonatomic, strong) CJZFChannelAdVideoEndCardData *endCardData;

- (instancetype)initModelWithJson:(NSDictionary *)json NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

@end

typedef NSString * CJZFChannelMoment NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXPORT CJZFChannelMoment _Nonnull const CJZFChannelMomentOn;

FOUNDATION_EXPORT CJZFChannelMoment _Nonnull const CJZFChannelMomentBefore;

@interface CJZFChannelAdData : NSObject

@property (nonatomic, copy) NSString *ldp;

@property (nonatomic, copy) NSString *deeplink;

@property (nonatomic, copy) NSString *img;

@property (nonatomic, copy) NSString *title;

@property (nonatomic, copy) NSString *desc;

@property (nonatomic, copy) NSString *icon;

@property (nonatomic, assign) NSInteger bidPrice;

@property (nonatomic, assign) NSTimeInterval timeInterval;

@property (nonatomic, assign) BOOL keen;

@property (nonatomic, assign) NSInteger acceleration;

@property (nonatomic, copy) CJZFChannelMoment moment;

@property (nonatomic, assign) NSInteger ctype;

@property (nonatomic, copy) NSString *wechatId;

@property (nonatomic, copy) NSString *wechatPath;

@property (nonatomic, copy) NSString *ulink;

@property (nonatomic, strong) CJZFChannelAdVideoData *videoData;

@property (nonatomic, strong) CJZFChannelAdVideoTracker *trackers;

@property (nonatomic, strong) NSArray<NSString *> *displayReport;

@property (nonatomic, strong) NSArray<NSString *> *clickReport;

@property (nonatomic, strong) NSArray<NSString *> *dpt;

@property (nonatomic, strong) NSArray<NSString *> *dps;

@property (nonatomic, strong) NSArray<NSString *> *dpf;

- (instancetype)initModelWithJson:(NSDictionary *)json NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

- (BOOL)isAdValid;

- (void)sendGameDisplayReport;

- (void)loadImageSuccessBlock:(void (^)(void))successBlock failedBlock:(void (^)(NSError * _Nullable error))failedBlock;

- (void)openLandingPage:(UIViewController *)currentController dismissBlock:(void (^)(void))dismissBlock leaveApplicationBlock:(void (^)(void))leaveApplicationBlock screenPoint:(CGPoint)sPoint point:(CGPoint)point size:(CGSize)size;

- (void)setGameAdInterView:(UIView *)view block:(void (^)(UIViewController *viewController))block;

- (NSArray<NSString *> *)getReportList:(NSString *)status;

- (void)sendPlayingMutedReportUrlList;

- (void)sendPlayPauseReportUrlList;

- (void)sendPlaySkipReportUrlList;

- (void)sendPlayRecoverReportUrlList;

- (void)sendPlayCloseReportUrlList;

- (void)setLDPType:(CJZFAdSDKLandingPageType)landingPageType;

- (void)setHalfLandingPageBackgroundColorAlpha:(CGFloat)alpha;

@end

NS_ASSUME_NONNULL_END
