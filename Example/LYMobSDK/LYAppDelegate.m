//
//  LYAppDelegate.m
//  LYMobSDK
//
//  Created by xjCoder on 04/10/2026.
//  Copyright (c) 2026 xjCoder. All rights reserved.
//

#import "LYAppDelegate.h"
#import <CJMobileAd/CJMobileAd.h>
#import "SplashAdViewController.h"
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <AdSupport/AdSupport.h>

@implementation LYAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    NSLog(@"UUIDStr ing---%@", [[UIDevice currentDevice].identifierForVendor UUIDString]);
    SplashAdViewController *splashVC = [[SplashAdViewController alloc] init];
    self.window.rootViewController = splashVC;
    [self.window makeKeyAndVisible];
    splashVC.currentWindow = self.window;
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self requestIDFA];
    });
    
    return YES;
}

- (void)requestIDFA {
       if (@available(iOS 14, *)) {
        [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
            NSLog(@"advertisingIdentifier----%@",ASIdentifierManager.sharedManager.advertisingIdentifier.UUIDString);
            NSLog(@"advertisingIdentifier----%@",UIDevice.currentDevice.identifierForVendor);
        }];
    } else {
        
    }
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
