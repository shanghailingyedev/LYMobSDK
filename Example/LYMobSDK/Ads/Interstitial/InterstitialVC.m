//
//  InterstitialVC.m
//  CJModileAdDemo
//
//  Created by CJ on 2022/3/7.
//

#import "InterstitialVC.h"
#import <CJMobileAd/CJMobileAd.h>
#import "CustomShowView.h"
#import "CJMobilePublic.h"

@interface InterstitialVC ()<CJInterstitialAdDelegate>

@property (nonatomic, strong) CJInterstitialAd *interstitialAd;
@property (nonatomic, assign) BOOL isIntertitialAdShow;

@end

@implementation InterstitialVC

@synthesize customView = _customView;

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
}


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
    self.interstitialAd = [[CJInterstitialAd alloc] initWithResourceId:intersititialId];
    self.interstitialAd.delegate = self;
    NSLog(@"事件：开始加载");
    [self.interstitialAd loadAdData];
}

- (void)setupUI {
    self.title = @"InterstitialAd";
    [self.view addSubview:self.customView];
    self.customView.frame = CGRectMake(0, 100, 200, 200);
    self.customView.center = self.view.center;
}

- (void)handleEvent:(NSInteger)eve {
    if (eve == 0) {
        [self loadAdData];
        return;
    }
    [self.interstitialAd showFromRootViewController:self];
}

- (CustomShowView *)customView {
    if (!_customView) {
        _customView = [[CustomShowView alloc] init];
        __weak InterstitialVC *weakSelf = self;
        _customView.event = ^(NSInteger eve) {
            [weakSelf handleEvent:eve];
        };
    }
    return _customView;
}

#pragma mark CJInterstitialAdDelegate
- (void)interstitialAdDidLoad:(CJInterstitialAd *)interstitialAd resourceId:(NSString *)resourceId {
    NSLog(@"事件:%s", __FUNCTION__);
    [self.customView canShowStatus:true errorMsg:@""];
}

- (void)backEvent {
    [self dismissViewControllerAnimated:true completion:nil];
}

- (void)interstitialAdOnShow:(CJInterstitialAd *)interstitialAd {
    NSLog(@"事件:%s", __FUNCTION__);
    self.isIntertitialAdShow = true;
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//        [self.interstitialAd destoryInterstitialAd];
    });
}

- (void)interstitialAdChannelOnClicked:(CJInterstitialAd *)interstitialAd extraParams:(NSDictionary *)param {
    NSLog(@"事件:%s", __FUNCTION__);
}

- (void)interstitialAdLoadFailed:(CJInterstitialAd *)interstitialAd error:(NSError *)error {
    [self.customView canShowStatus:false errorMsg:error.description];
    NSLog(@"事件:%s", __FUNCTION__);
}

- (void)interstitialAdOnClicked:(CJInterstitialAd *)interstitialAd {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//        [self.interstitialAd destoryInterstitialAd];
    });
    NSLog(@"事件:%s", __FUNCTION__);
}

- (void)interstitialAdOnClosed:(CJInterstitialAd *)interstitialAd {
    [self.customView canShowStatus:false errorMsg:@""];
    self.isIntertitialAdShow = false;
    NSLog(@"事件:%s", __FUNCTION__);
}

@end
