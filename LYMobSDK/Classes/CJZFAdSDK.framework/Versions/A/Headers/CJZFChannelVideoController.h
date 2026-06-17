//
//  CJZFChannelVideoController.h
//  CJZFAdSDK-Channel
//
//  Created by 早范 on 2025/2/11.
//

#import <UIKit/UIKit.h>
#import "CJZFChannelAdData.h"

NS_ASSUME_NONNULL_BEGIN
@protocol CJZFChannelVideoViewControllerDelegate;

@interface CJZFChannelVideoController : UIViewController

@property (nonatomic, weak) id<CJZFChannelVideoViewControllerDelegate> delegate;

@property (nonatomic, strong) CJZFChannelAdData *adData;

@property (nonatomic, assign) BOOL videoMuted;

- (BOOL)isPlaying;

@end

@protocol CJZFChannelVideoViewControllerDelegate <NSObject>

- (void)channelVideoViewControllerDidLoad;

- (void)channelVideoViewControllerLoadFailedError:(NSError *)error;

- (void)channelVideoViewControllerExpose;

- (void)channelVideoViewControllerClick;

- (void)channelVideoViewControllerClose;

- (void)channelVideoViewControllerCloseLandingPageView;

- (void)channelVideoViewControllerReadyToPlay;

- (void)channelVideoViewControllerPlayStart;

- (void)channelVideoViewControllerPlayStopError:(NSError *)error;

- (void)channelVideoViewControllerErrorReportError:(NSError *)error;

- (void)channelVideoViewControllerQuarterReport;

- (void)channelVideoViewControllerHalfReport;

- (void)channelVideoViewControllerThreeQuarterReport;

- (void)channelVideoViewControllerPlayFinish;

- (void)channelVideoViewControllerDidRewardEffective;


@end

NS_ASSUME_NONNULL_END
