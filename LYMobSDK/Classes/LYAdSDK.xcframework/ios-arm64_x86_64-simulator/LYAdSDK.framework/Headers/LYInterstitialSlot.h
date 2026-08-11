//
//  LYInterstitialSlot.h
//  LYAdSDK
//
//  Created by coderqi on 2025/12/2.
//

#import <LYAdSDK/LYSlot.h>

NS_ASSUME_NONNULL_BEGIN

@interface LYInterstitialSlot : LYSlot

/// 是否点击后关闭插屏，默认不关闭
@property (nonatomic, assign) BOOL closeBehindClicked;

/// ------------------------------------模版配置------------------------------------
/// 模版背景颜色， 默认白色
@property (nonatomic, strong) UIColor *bacColor;

/// click按钮字体，默认systemFont:20
@property (nonatomic, strong) UIFont *clickBtnTextFont;

/// click按钮背景颜色， 默认浅灰
@property (nonatomic, strong) UIColor *clickBtnBacColor;

/// click按钮字体颜色， 默认白色
@property (nonatomic, strong) UIColor *clickBtnTextColor;

@end

NS_ASSUME_NONNULL_END
