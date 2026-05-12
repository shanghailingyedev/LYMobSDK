//
//  JTAdSDKManager.h
//  JTAdSDK
//
//  Created by Frank on 2025/6/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 聚推SDK管理器
@interface LYJTAdSDKManager : NSObject

/// 获取管理器实例的唯一方法
+ (instancetype)manager;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (id)copy NS_UNAVAILABLE;
- (id)mutableCopy NS_UNAVAILABLE;

/// 启动聚推SDK方法
- (void)startAdSDK;

/// 当前SDK版本
- (NSString *)sdkVersion;

@end

NS_ASSUME_NONNULL_END
