//
//  CJMobilePublic.h
//  CJMobileAdDemo
//
//  Created by Gaodun_Jun on 2022/6/29.
//
 
#ifndef CJMobilePublic_h
#define CJMobilePublic_h

#define appID  @"96ff49947661db62"

#define splashId           @"1a96cf66c57d477a"

#define rewardVideoId      @"49509859533bebe4"
// 全屏视频测试ID
#define fullscreenVideoId  @"1b39ddacd00f47b7"
// 信息流测试ID
#define nativeId           @"dd37c33f175bd42d"
// 插屏测试ID
#define intersititialId    @"adff31af1088e962"
// 短视频测试ID
#define shortVideoId       @"be537b85a50e9954"
// banner测试ID
#define bannerId           @"684b9db51e75327c"
// 自渲染测试ID
#define feedNativeId       @"4ba892bb489d9c01"
// Draw信息流测试ID
#define drawNativeId       @"a2d845ba762585f9"

#define jScreenBounds      [UIScreen mainScreen].bounds.size
#define jScreenW           [UIScreen mainScreen].bounds.size.width
#define jScreenH           [UIScreen mainScreen].bounds.size.height
#define jRGBA(r,g,b,a)     [UIColor colorWithRed:r/255 green:g/255 blue:b/255 alpha:a]


//#import <Masonry/Masonry.h>
#import "InterstitialVC.h"
#import "SplashVC.h"
#import "RewardVideoVC.h"

#endif /* CJMobilePublic_h */
