//
//  LY_Macro.h
//  LYAdSDK
//
//  Created by coderqi on 2025/11/13.
//

#ifndef LY_Macro_h
#define LY_Macro_h

/// 广告类型
typedef NS_OPTIONS(NSUInteger, LYAdType) {
    /// 信息流
    LYAdTypeNative          = 1,
    /// 开屏
    LYAdTypeSplash          = 2,
    /// banner
    LYAdTypeBanner          = 3,
    /// 插屏
    LYAdTypeInterstitial    = 4,
    /// 激励
    LYAdTypeRewardVideo    = 5,
    /// 信息流自渲染
    LYAdTypeFeedCustom      = 6,
};

/// 广告渲染类型
typedef NS_OPTIONS(NSInteger, LYAdRenderType) {
    /// 默认值
    LYAdRenderTypeDefault = -9999,
    /// sdk模版渲染
    LYAdRenderTypeTemplate = 1,
    /// 媒体自渲染
    LYAdRenderTypeCustom   = 2,
};

/// 广告数据请求回调
typedef void(^LYAdDataCallBackHandler)(NSArray * _Nullable array, NSError * _Nullable error);

/**
 * 视频播放器状态枚举
 */
typedef NS_ENUM(NSInteger, LYVideoPlayerState) {
    LYVideoPlayerStateUnknown = 0,  // 未知状态
    LYVideoPlayerStateBuffering,    // 正在缓冲
    LYVideoPlayerStatePlaying,      // 正在播放
    LYVideoPlayerStatePaused,       // 已暂停
    LYVideoPlayerStateStopped,      // 已停止
    LYVideoPlayerStateCompleted,    // 播放完成
    LYVideoPlayerStateFailed        // 播放失败
};

/**
 * 视频播放状态回调
 * @param state 当前视频播放状态
 * @param error 如果出现错误，包含错误信息
 */
typedef void(^LYVideoPlayerStateCallback)(LYVideoPlayerState state, NSError * _Nullable error);

/**
 * 视频播放进度回调
 * @param currentTime 当前播放时间（秒）
 * @param duration 视频总时长（秒）
 */
typedef void(^LYVideoPlayerProgressCallback)(NSTimeInterval currentTime, NSTimeInterval duration);

/// 广告打开类
typedef NS_OPTIONS(NSUInteger, LYAdOpenType) {
    /// push
    LYAdOpenTypePush    = 1,
    /// Present
    LYAdOpenTypePresent = 2,
};

/// 交互类型
typedef NS_ENUM(NSInteger, LYAdInteractionType) {
    LYAdInteractionTypeUnknown,        //unknown type
    LYAdInteractionTypeApp,            //open download page in-app
    LYAdInteractionTypeWeb,            //open webpage in-app
    LYAdInteractionTypeDeepLink,       //open deeplink
    LYAdInteractionTypeAppStore,       //open appstore
    LYAdInteractionTypeSafari,         //open safari
    LYAdInteractionTypeError           //can`t open landing page
};

/**以下为C2S bidding上报参数key**/
//竞胜方价格 单位：分
#define kLYAdMediaWinPrice   @"win_price"
//最大竞败方出价 单位：分
#define kLYAdMediaLossPrice  @"sec_price"
//竞败原因 0 未知 100价格低失败 200 超时失败
#define kLYAdMediaLossReason @"loss_reason"

/**以下为广告返回的拓展参数的key**/
// requestId
#define kLYAdRequestID @"request_id"

#endif /* LY_Macro_h */
