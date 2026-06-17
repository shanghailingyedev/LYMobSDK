//
//  CJZFChannelVideoView.h
//  CJZFAdSDK-Channel
//
//  Created by 早范 on 2025/2/11.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol CJZFChannelVideoViewDelegate;
@class CJZFChannelAdData;

@interface CJZFChannelVideoView : UIView

@property (nonatomic, weak) id<CJZFChannelVideoViewDelegate> delegate;

@property (nonatomic, strong) CJZFChannelAdData *adData;

@property (nonatomic, strong) NSData *videoData;

@property (nonatomic, assign, readonly) BOOL isPlaying; // 是否正在播放

@property (nonatomic, assign) BOOL videoMuted;
//@property (nonatomic, weak)

- (void)play; // 播放
- (void)pause; // 暂停

- (void)loadVideoData;

@end

@protocol CJZFChannelVideoViewDelegate <NSObject>

- (void)channelVideoViewDidLoad:(CJZFChannelVideoView *)videoView;

- (void)channelVideoViewLoadFailed:(CJZFChannelVideoView *)videoView error:(NSError *)error;

- (void)channelVideoViewExpose:(CJZFChannelVideoView *)videoView;

- (void)channelVideoViewClick:(CJZFChannelVideoView *)videoView ldp:(NSString *)ldp;

- (void)channelVideoViewClose:(CJZFChannelVideoView *)videoView;

- (void)channelVideoViewCloseLandingPageView:(CJZFChannelVideoView *)videoView;

- (void)channelVideoViewReadyToPlay:(CJZFChannelVideoView *)videoView;

- (void)channelVideoViewPlayStart:(CJZFChannelVideoView *)videoView;

- (void)channelVideoViewPlayFinish:(CJZFChannelVideoView *)videoView;

- (void)channelVideoViewPlayStop:(CJZFChannelVideoView *)videoView error:(NSError *)error;

- (void)channelVideoViewErrorReport:(CJZFChannelVideoView *)videoView error:(NSError *)error;

- (void)channelVideoViewQuarterReport:(CJZFChannelVideoView *)videoView;

- (void)channelVideoViewHalfReport:(CJZFChannelVideoView *)videoView;

- (void)channelVideoViewThreeQuarterReport:(CJZFChannelVideoView *)videoView;

- (void)channelVideoViewDidRewardEffective:(CJZFChannelVideoView *)videoView;

- (UIViewController *)channelAdViewController;

@end

NS_ASSUME_NONNULL_END
