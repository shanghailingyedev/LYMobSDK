//
//  CJSceneRequest.h
//  CJMobileAd
//
//  Created by shanghailingye 2022/12/2.
//  Copyright © 2022 Jun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/** 广告位场景类型枚举*/
typedef NS_ENUM(NSInteger, CJSceneRequestType) {
    // 成语游戏
    CJSceneRequestIdiomGame,
    // 小游戏合集
    CJSceneRequestReferenceGame,
    // 那年今日
    CJSceneRequestHistory,
    // 今日油价
    CJSceneRequestOilPrice,
    // 性格测试
    CJSceneRequestPersonalityTest,
    // 星座运势
    CJSceneRequestHoroscope,
    // 新闻资讯
    CJSceneRequestNews,
    // 增强短视频
    CJSceneRequestEnhanceVideoContent
};

/** 激励视频事件回调*/
typedef NS_ENUM(NSInteger, CJSceneRewardVideoEventType) {
    CJSceneRewardVideoEventOnReward,
    CJSceneRewardVideoEventOnShow,
    CJSceneRewardVideoEventOnClick,
    CJSceneRewardVideoEventOnClose,
    CJSceneRewardVideoEventOnError,
};

@interface CJSceneRequest : NSObject

// 相应场景下激励视频广告ID
@property (nonatomic, copy) NSString *rewardId;
// 相应场景下插屏广告ID
@property (nonatomic, copy) NSString *interstitialId;
// 相应场景下信息流ID
@property (nonatomic, copy) NSString *nativeTemplateId;
// 相应场景下内容视频ID
@property (nonatomic, copy) NSString *videoContentId;
// 激励视频事件回调
@property (nonatomic, copy) void (^rewardVideoEventCallback)(CJSceneRewardVideoEventType type, NSDictionary *params);
// 当前控制器
@property (nonatomic, weak) UIViewController *rootViewController;
// 场景类型
@property (nonatomic, assign) CJSceneRequestType scene;
// 广告间隔（仅针对性格测试配置广告间隔题目数）
@property (nonatomic, assign) NSInteger spacing;
// 新闻资讯(阅读时长)
@property (nonatomic, assign) NSInteger readTime;
// 新闻资讯(阅读新闻数)
@property (nonatomic, assign) NSInteger readCount;
// 增强短视频(奖励发放次数)
@property (nonatomic, assign) NSInteger rewardCount;
// 单次奖励倒计时时长(秒)
@property (nonatomic, assign) NSInteger rewardTime;



#pragma mark style color
// 导航栏背景颜色
@property (nonatomic, strong) UIColor *navigationBackgroundColor;
// 页面背景颜色
@property (nonatomic, strong) UIColor *scenePageBackgroundColor;
// 导航栏标题文字颜色
@property (nonatomic, strong) UIColor *navigationTitleTextColor;
// 导航栏标题font
@property (nonatomic, strong) UIFont *navigationTitleFont;
// 新闻资讯新闻分类文字颜色
@property (nonatomic, strong) UIColor *newsTitleColor;
// 新闻标题颜色
@property (nonatomic, strong) UIColor *newsContentTitleColor;


@end

NS_ASSUME_NONNULL_END
