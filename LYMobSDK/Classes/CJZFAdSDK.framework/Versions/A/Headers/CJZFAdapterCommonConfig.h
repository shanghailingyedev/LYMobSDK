//
//  CJZFAdapterCommonConfig.h
//  CJZFAdSDK
//
//  Created by 早范 on 2026/3/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterCommonConfig : NSObject

+ (instancetype)sharedInstance;

// 设置二次弹窗提示文案
- (void)setPopUpDesc:(NSString *)popUpDesc;

- (NSString *)getPopUpDesc;

// 设置开屏点击热区文案
- (void)setClickContentDesc:(NSString *)clickContentDesc;

- (NSString *)getClickContentDesc;

// 设置插屏打开应用文案
- (void)setInterOpenDesc:(NSString *)interOpenDesc;

- (NSString *)getInterOpenDesc;

// 设置落地页的UIModalPresentationStyle，默认为UIModalPresentationOverFullScreen
- (void)setLDPModalPresentationStyle:(UIModalPresentationStyle)style;
- (UIModalPresentationStyle)getLDPModalPresentationStyle;

@end

NS_ASSUME_NONNULL_END
