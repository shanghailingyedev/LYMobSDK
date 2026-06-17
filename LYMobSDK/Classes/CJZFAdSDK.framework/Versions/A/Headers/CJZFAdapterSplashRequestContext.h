//
//  CJZFAdapterSplashRequestContext.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2025/9/21.
//

#import "CJZFAdapterCommonRequestContext.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterSplashRequestContext : CJZFAdapterCommonRequestContext

@property (nonatomic, weak, nullable) UIWindow *window;

@property (nonatomic, strong, nullable) UIView *bottomView;

@property (nonatomic, strong) NSDictionary *scenes;

@property (nonatomic, strong) UIImage *backgroundImage;

@property (nonatomic, assign) NSInteger showTime;

@property (nonatomic, assign) BOOL rightTop;

@end

NS_ASSUME_NONNULL_END
