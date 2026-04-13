//
//  SplashAdViewController.m
//  CJMobileAd_Example
//
//  Created by shanghailingye俊 on 2025/10/13.
//  Copyright © 2025 wade.xiong. All rights reserved.
//

#import "SplashAdViewController.h"
#import <CJMobileAd/CJMobileAd.h>
#import "CJMobilePublic.h"
#import "CJEntranceController.h"

@interface SplashAdViewController ()<CJSplashAdDelegate>

@property (nonatomic, strong) UIView *launchView;
@property (nonatomic, strong) CJSplashAd *splashAd;
@property (nonatomic, assign) BOOL isClick;

@end

@implementation SplashAdViewController

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.view addSubview:self.launchView];
    [self setupSDK];
//    NSThread *thread = [[NSThread alloc] initWithTarget:self selector:@selector(setupSDK) object:nil];
//    [thread start];
}

- (UIView *)launchView {
    if (!_launchView) {
        _launchView = [[UIView alloc] initWithFrame:CGRectMake(0, 64, jScreenW, jScreenH)];
        _launchView.backgroundColor = [UIColor cyanColor];
    }
    return _launchView;
}

- (void)setupSDK {
    [CJADManager setEnableShake:false];
    [CJADManager openDebugLog];
    NSLog(@"thread----current---%@", [NSThread currentThread]);
    [CJADManager configure:appID completeHandle:^(BOOL success, NSError * _Nullable error) {
        if (success) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [self loadDataAd];
            });
        } else {
            // 初始化失败可以在这里移除启动页
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                [self setupMainRootVC];
            });
        }
    }];
}

- (void)setupMainRootVC {
    CJEntranceController *rootVC = [CJEntranceController new];
    self.currentWindow.rootViewController = [[UINavigationController alloc] initWithRootViewController:rootVC];
    [self.currentWindow makeKeyAndVisible];
}

- (void)loadDataAd {
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, jScreenW, 160)];
    view.backgroundColor = [UIColor blueColor];
    self.splashAd = [[CJSplashAd alloc] initWithResourceId:splashId rootViewController:self customLogoView:view];
    self.splashAd.delegate = self;
    [self.splashAd loadAdData];
}

#pragma mark CJSplashAdDelegate
- (void)splashAdDidLoad:(CJSplashAd *)splashAd resourceId:(NSString *)resourceId {
//    NSLog(@"getCurrentAdMaterialsInfo----%@", [self.splashAd getCurrentAdMaterialsInfo]);
    [splashAd showSplashAdToWindow:self.currentWindow];
    NSInteger cpm = splashAd.getECpm;
    NSLog(@"-------->%ld", splashAd.getECpm);
    NSLog(@"事件-渠道-------->%@", [splashAd getAdType]);
//    NSLog(@"事件-素材ID-------->%@", [splashAd getResId]);
//    NSLog(@"素材资料-------->%@", [splashAd getCurrentAdMaterialsInfo]);
    NSLog(@"事件:%s", __FUNCTION__);
}

- (void)splashAdOnShow:(CJSplashAd *)splashAd {
    NSLog(@"事件:%s", __FUNCTION__);
//    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//        self.splashAd = nil;
//    });
}

- (void)splashAdLoadFailed:(CJSplashAd *)splashAd error:(NSError *)error {
    NSLog(@"事件:%s %@", __FUNCTION__, error.description);
    [self setupMainRootVC];
}

- (void)splashAdOnClicked:(CJSplashAd *)splashAd {
    NSLog(@"事件:%s", __FUNCTION__);
    NSLog(@"launchView----%@", self.launchView);
}

- (void)splashAdOnClosed:(CJSplashAd *)splashAd {
    [self setupMainRootVC];
    NSLog(@"事件:%s", __FUNCTION__);
}


@end
