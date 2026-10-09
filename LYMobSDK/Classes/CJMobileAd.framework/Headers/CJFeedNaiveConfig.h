//
//  CJFeedVideoConfig.h
//  CJMobileAd
//
//  Created by shanghailingye on 2024/4/11.
//  Copyright © 2024 Jun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CJFeedNaiveConfig : NSObject

#pragma mark 播放器设置(通用)

/// 视频素材必须字段
@property (nonatomic, assign) CGRect videoFrame;
/// 设置播放器圆角
@property (nonatomic, assign) CGFloat cornerRadius;
/// 设置播放器边框颜色
@property (nonatomic, strong) UIColor *borderColor;
/// 设置播放器边框宽度
@property (nonatomic, assign) CGFloat borderWidth;
/// 是否静音
@property (nonatomic, assign) BOOL ismute;

#pragma mark 通用设置

/// 响应点击事件view数组
@property (nonatomic, strong) NSArray *clickableViews;
/// 上游logo位置
@property (nonatomic, assign) CGPoint logoPistion;
/// 不透明度(0～1.0)
@property (nonatomic, assign) CGFloat logoAlpha;

@end

NS_ASSUME_NONNULL_END
