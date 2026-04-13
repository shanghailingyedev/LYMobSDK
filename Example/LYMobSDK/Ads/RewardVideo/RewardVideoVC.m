//
//  RewardVideoVC.m
//  CJModileAdDemo
//
//  Created by JUN on 2022/3/6.
//

#import "RewardVideoVC.h"
#import "CustomShowView.h"
#import <CJMobileAd/CJMobileAd.h>
#import "CJMobilePublic.h"

@interface RewardVideoVC ()<CJRewardVideoAdDelegate>

@property (nonatomic, strong) CJRewardVideoAd *rewardVideoAd;

@end

@implementation RewardVideoVC

@synthesize customView = _customView;

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setupUI];
}

- (void)dealloc
{
    NSLog(@"事件:%s", __FUNCTION__);
}
 
- (void)loadAdData {
    [self.customView canShowStatus:false errorMsg:@""];
    self.rewardVideoAd = [[CJRewardVideoAd alloc] initWithResourceId:rewardVideoId userId:@"123" extend:@""];
    self.rewardVideoAd.delegate = self;
    [self.rewardVideoAd setMute:true];
    [self.rewardVideoAd loadAdData];
}

- (void)setupUI {
    self.title = @"RewardVideoAd";
    [self.view addSubview:self.customView];
    self.customView.frame = CGRectMake(0, 100, 200, 200);
    self.customView.center = self.view.center;
}

- (void)handleEvent:(NSInteger)eve {
    if (eve == 0) {
        [self loadAdData];
        return;
    }
    [self.rewardVideoAd showFromRootViewController:self];
}

- (CustomShowView *)customView {
    if (!_customView) {
        _customView = [[CustomShowView alloc] init];
        __weak RewardVideoVC *weakSelf = self;
        _customView.event = ^(NSInteger eve) {
            [weakSelf handleEvent:eve];
        };
    }
    return _customView;
}

#pragma mark CJRewardVideoAdDelegate
- (void)rewardVideoOnRewarded:(CJRewardVideoAd *)rewardAd requestId:(NSString *)requestId {
    NSLog(@"事件:%s", __FUNCTION__);
    if (requestId && ![requestId isEqualToString:@""]) {
        NSLog(@"the incentive validation callback succeeded");
    }
}

- (void)rewardVideoAdChannelOnClicked:(CJRewardVideoAd *)rewardAd extraParams:(NSDictionary *)param {
    NSLog(@"事件:%s", __FUNCTION__);
}

- (void)rewardVideoAdDidLoad:(CJRewardVideoAd *)rewardAd resourceId:(NSString *)resourceId {
    NSString *channel = [rewardAd getAdType];
    [self.customView canShowStatus:true errorMsg:@""];
    NSLog(@"事件:%s", __FUNCTION__);
    [rewardAd showFromRootViewController:self];
//    [self.rewardVideoAd showFromRootViewController:self];
}

- (void)rewardVideoAdOnShow:(CJRewardVideoAd *)rewardAd {
    NSLog(@"事件:%s", __FUNCTION__);
}

- (void)rewardVideoAdLoadFailed:(CJRewardVideoAd *)rewardAd error:(NSError *)error {
    [self.customView canShowStatus:false errorMsg:error.description];
    NSLog(@"事件:%s", __FUNCTION__);
}

- (void)rewardVideoAdOnClicked:(CJRewardVideoAd *)rewardAd {
    NSLog(@"事件:%s", __FUNCTION__);
}

- (void)rewardVideoAdOnClosed:(CJRewardVideoAd *)rewardAd {
    [self.customView canShowStatus:false errorMsg:@""];
    NSLog(@"事件:%s", __FUNCTION__);
}


@end
