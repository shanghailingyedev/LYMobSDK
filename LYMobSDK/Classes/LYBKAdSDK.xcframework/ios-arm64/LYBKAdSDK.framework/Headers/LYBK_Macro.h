//
//  LYBK_Macro.h
//  LYBKAdSDK
//
//  Created by coderqi on 2025/11/13.
//

#ifndef LYBK_Macro_h
#define LYBK_Macro_h

/// 广告类型
typedef NS_OPTIONS(NSUInteger, LYBKAdType) {
    /// 信息流
    LYBKAdTypeNative          = 1,
    /// 开屏
    LYBKAdTypeSplash          = 2,
    /// banner
    LYBKAdTypeBanner          = 3,
    /// 插屏
    LYBKAdTypeInterstitial    = 4,
    /// 激励
    LYBKAdTypeRewardVideo    = 5,
    /// 信息流自渲染
    LYBKAdTypeFeedCustom      = 6,
};

/// 广告渲染类型
typedef NS_OPTIONS(NSInteger, LYBKAdRenderType) {
    /// 默认值
    LYBKAdRenderTypeDefault = -9999,
    /// sdk模版渲染
    LYBKAdRenderTypeTemplate = 1,
    /// 媒体自渲染
    LYBKAdRenderTypeCustom   = 2,
};

/// 广告数据请求回调
typedef void(^LYBKAdDataCallBackHandler)(NSArray * _Nullable array, NSError * _Nullable error);

/**
 * 视频播放器状态枚举
 */
typedef NS_ENUM(NSInteger, LYBKVideoPlayerState) {
    LYBKVideoPlayerStateUnknown = 0,  // 未知状态
    LYBKVideoPlayerStateBuffering,    // 正在缓冲
    LYBKVideoPlayerStatePlaying,      // 正在播放
    LYBKVideoPlayerStatePaused,       // 已暂停
    LYBKVideoPlayerStateStopped,      // 已停止
    LYBKVideoPlayerStateCompleted,    // 播放完成
    LYBKVideoPlayerStateFailed        // 播放失败
};

/**
 * 视频播放状态回调
 * @param state 当前视频播放状态
 * @param error 如果出现错误，包含错误信息
 */
typedef void(^LYBKVideoPlayerStateCallback)(LYBKVideoPlayerState state, NSError * _Nullable error);

/**
 * 视频播放进度回调
 * @param currentTime 当前播放时间（秒）
 * @param duration 视频总时长（秒）
 */
typedef void(^LYBKVideoPlayerProgressCallback)(NSTimeInterval currentTime, NSTimeInterval duration);

/// 广告打开类
typedef NS_OPTIONS(NSUInteger, LYBKAdOpenType) {
    /// push
    LYBKAdOpenTypePush    = 1,
    /// Present
    LYBKAdOpenTypePresent = 2,
};

/// 交互类型
typedef NS_ENUM(NSInteger, LYBKAdInteractionType) {
    LYBKAdInteractionTypeUnknown,        //unknown type
    LYBKAdInteractionTypeApp,            //open download page in-app
    LYBKAdInteractionTypeWeb,            //open webpage in-app
    LYBKAdInteractionTypeDeepLink,       //open deeplink
    LYBKAdInteractionTypeAppStore,       //open appstore
    LYBKAdInteractionTypeSafari,         //open safari
    LYBKAdInteractionTypeError           //can`t open landing page
};

/**以下为C2S bidding上报参数key**/
//竞胜方价格 单位：分
#define kLYBKAdMediaWinPrice   @"win_price"
//最大竞败方出价 单位：分
#define kLYBKAdMediaLossPrice  @"sec_price"
//竞败原因 0 未知 100价格低失败 200 超时失败
#define kLYBKAdMediaLossReason @"loss_reason"

/**以下为广告返回的拓展参数的key**/
// requestId
#define kLYBKAdRequestID @"request_id"

#endif /* LYBK_Macro_h */
