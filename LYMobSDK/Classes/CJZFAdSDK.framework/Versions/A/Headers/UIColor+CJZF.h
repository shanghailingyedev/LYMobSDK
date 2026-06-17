//
//  CJZFAdImpressionTimer.h
//  Test
//
//  Created by 早范 on 2025/1/29.
//  Copyright © 2025 早范. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (CJZF)

/**
 十六进制数转颜色
 @param hexString 十六进制数
 */
+ (nullable UIColor *)cjzf_colorWithHexString:(NSString *)hexString;

/**
 十六进制数转颜色
 @param hexString 十六进制数
 @param alphaComponent 透明度 0~1
 */
+ (nullable UIColor *)cjzf_colorWithHexString:(NSString *)hexString alphaComponent:(CGFloat)alphaComponent;

/**
 当前颜色的十六进制值
 */
- (nullable NSString *)cjzf_hexadecimalString;

/*
 随机颜色
 */
+(nullable UIColor *)cjzf_randomColor;

@end

NS_ASSUME_NONNULL_END
