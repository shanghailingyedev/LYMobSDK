//
//  SplashVC.m
//  CJModileAdDemo
//
//  Created by CJ on 2022/3/7.
//

#import "SplashVC.h"
#import <CJMobileAd/CJMobileAd.h>
#import "CustomShowView.h"
#import "CJMobilePublic.h"

@interface SplashVC ()<CJSplashAdDelegate>

@property (nonatomic, strong) CJSplashAd *splashAd;

@end

@implementation SplashVC

@synthesize customView = _customView;

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setupUI];
    NSLog(@"------%@", [UIApplication sharedApplication].keyWindow.rootViewController);
}

- (void)dealloc
{
//    animationParameters
    NSLog(@"事件:%s", __FUNCTION__);
}

- (void)loadAdData {
    [self.customView canShowStatus:false errorMsg:@""];
    UIView *logo = [[UIView alloc] initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, 180)];
    logo.backgroundColor = [UIColor redColor];
    self.splashAd = [[CJSplashAd alloc] initWithResourceId:splashId rootViewController:self customLogoView:logo];
    self.splashAd.delegate = self;
    [self.splashAd loadAdData];
}

- (void)setupUI {
    self.title = @"SplashAd";
    [self.view addSubview:self.customView];
    self.customView.frame = CGRectMake(0, 100, 200, 200);
    self.customView.center = self.view.center;
}

- (void)handleEvent:(NSInteger)eve {
    if (eve == 0) {
        NSLog(@"事件:%s", __FUNCTION__);
        [self loadAdData];
        return;
    }
    [self.splashAd showSplashAdToWindow: [UIApplication sharedApplication].keyWindow];
}

- (CustomShowView *)customView {
    if (!_customView) {
        _customView = [[CustomShowView alloc] init];
        __weak SplashVC *weakSelf = self;
        _customView.event = ^(NSInteger eve) {
            [weakSelf handleEvent:eve];
        };
    }
    return _customView;
}

#pragma mark CJSplashAdDelegate
- (void)splashAdDidLoad:(CJSplashAd *)splashAd resourceId:(NSString *)resourceId {
    [self.customView canShowStatus:true errorMsg:@""];
    NSLog(@"cpm---%ld",[splashAd getECpm]);
    NSLog(@"事件-渠道-------->%@", [splashAd getAdType]);
//    [UIApplication sharedApplication].keyWindow.backgroundColor = [UIColor blueColor];
    [self.splashAd showSplashAdToWindow:[UIApplication sharedApplication].keyWindow];
    NSLog(@"事件:%s", __FUNCTION__);
}

- (void)splashAdOnShow:(CJSplashAd *)splashAd {
    NSLog(@"事件:%s", __FUNCTION__);
}

- (void)splashAdChannelOnShow:(CJSplashAd *)splashAd extraParams:(NSDictionary *)params {
    NSLog(@"事件:%s--%@", __FUNCTION__, params);
}

- (void)splashAdChannelOnClicked:(CJSplashAd *)splashAd extraParams:(NSDictionary *)params {
    NSLog(@"事件:%s--%@", __FUNCTION__, params);
}

- (void)splashAdLoadFailed:(CJSplashAd *)splashAd error:(NSError *)error {
    [self.customView canShowStatus:false errorMsg:error.description];
    NSLog(@"事件:%s ---  %@", __FUNCTION__, error.debugDescription);
}

- (void)splashAdOnClicked:(CJSplashAd *)splashAd {
    NSLog(@"事件:%s", __FUNCTION__);
}

- (void)splashAdOnClosed:(CJSplashAd *)splashAd {
    self.splashAd = nil;
    [self.customView canShowStatus:false errorMsg:@""];
    NSLog(@"事件:%s", __FUNCTION__);
}


@end
