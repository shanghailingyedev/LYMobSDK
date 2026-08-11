//
//  LYAdSDKManager.h
//  LYAdSDK
//
//  Created by coderqi on 2025/11/14.
//

#import <Foundation/Foundation.h>
@class UIImage;

NS_ASSUME_NONNULL_BEGIN

typedef void (^LYInitResultBlock)(BOOL isSucc, NSError * _Nullable error);

@interface LYAdSDKManager : NSObject

/**
 * SDK 初始化接口，请在 app 初始化时调用。
 * 可在任意线程调用；`resultBlock` 保证在主线程回调。
 * @param clientId - LY开发者后台创建的clientId
 * @param clientSecret - LY开发者后台创建的clientSecret
 * @param resultBlock - LY SDK初始化结果（主线程回调）
 */
+ (NSError *)initWithClientId:(NSString *)clientId andClientSecret:(NSString *)clientSecret andInitResult:(LYInitResultBlock)resultBlock;

/**
 * 获取 SDK 版本
 */
+ (NSString *)SDKVersion;

/**
 *  是否允许sdk 获取当前设备经纬度信息
 *  @param canGetLBSBySDK    默认NO，不允许
 */
+ (void)getDeviceLBSBySDK:(BOOL)canGetLBSBySDK;

/**
 *  是否在控制台打印Log
 *  @param isOpen    默认NO，不允许
 */
+ (void)setOpenLog:(BOOL)isOpen;

/**
 *  接入方透传经纬度信息
 *  @param lon  经度信息
 *  @param lat  纬度信息
 */
 + (void)updateLocalLBSLon:(nullable NSString *)lon
                       lat:(nullable NSString *)lat;

/**
 *  接入方透传设备ID
 *  若 deviceID 非空，SDK 直接使用该值作为设备ID，不再自行请求获取。
 *  @param deviceID 媒体获取的设备ID字符串；传 nil 或空串表示不透传，由 SDK 自行获取
 */
+ (void)setDeviceID:(nullable NSString *)deviceID;

/**
 *  是否打开个性化广告开关
 *  @param isOpen  是否打开
 */
+ (void)setPersonalInfo:(BOOL)isOpen;


/**
 * 设置 SDK 全局展示 Logo（广告展示前调用；未设置则各广告位 Logo 为空）。
 * @param logoImage 展示用 Logo 图片，传 nil 表示清空
 */
+ (void)setLogoImage:(UIImage * _Nullable)logoImage;

// SDKTOOLS_LOGO_SETTING_API
@end

NS_ASSUME_NONNULL_END
