//
//  CJZFAdSDK+Private.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/13.
//

#import "CJZFAdSDK.h"
#if __has_include(<CJZFAdSDK-Adapter/CJZFAdSDKAdapter.h>)
#import <CJZFAdSDK-Adapter/CJZFAdSDKAdapter.h>
#else
#import "CJZFAdSDKAdapter.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdSDK()

// SDK配置信息
@property (nonatomic, strong, nullable) CJZFAdSDKConfigModel *sdkConfigModel;
// SDK的启动Id
//@property (nonatomic, copy) NSString *appId;
// userID
@property (nonatomic, strong) NSMutableDictionary<CJZFAdapterPlatform, CJZFChannelInfo *> *channelInfoMap;
// SDK是否初始化成功
@property (nonatomic, assign) BOOL initSuccess;
// SDK是否初始化完成
@property (nonatomic, assign) BOOL initComplete;
// SDK是否正在初始化
@property (nonatomic, assign) BOOL isNowInit;
// 测试模式
@property (nonatomic, assign) BOOL isDebug;
// 不需要广告
@property (nonatomic, assign) BOOL isNoAd;
// 请求域名列表
@property (nonatomic, strong) NSMutableDictionary<NSString *, NSString *> *domainDict;
// webview原始UA
@property (nonatomic, copy) NSString *originalUA;

@property (nonatomic, copy) NSString *mobTechAppKey;

@property (nonatomic, copy) NSString *mobTechAppSecret;

@property (nonatomic, copy) NSString *appId;

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
