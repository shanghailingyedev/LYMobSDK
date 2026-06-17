//
//  CJZFAdapterErrorDefine.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/13.
//

#import <Foundation/Foundation.h>
#import "CJZFAdapterCommonDefine.h"

typedef NSInteger CJZFAdapterErrorCode NS_EXTENSIBLE_STRING_ENUM;
extern const CJZFAdapterErrorCode CJZF_SDK_INIT_ERROR;

extern const CJZFAdapterErrorCode CJZF_SDK_POSID_CONFIG_ERROR;

extern const CJZFAdapterErrorCode CJZF_SDK_IMAGE_EMPTY;

extern const CJZFAdapterErrorCode CJZF_SDK_INIT_NOCOMP;

extern const CJZFAdapterErrorCode CJZF_SDK_POSID_NOPLATFORM;

extern const CJZFAdapterErrorCode CJZF_SDK_CLICK_NODISPLAY;

extern const CJZFAdapterErrorCode CJZF_SDK_IMAGE_LOADFAIL;
//splash广告获取超时
extern const CJZFAdapterErrorCode CJZF_SDK_SPLASH_TIMEOUT;
// 横屏不加载开屏广告
extern const CJZFAdapterErrorCode CJZF_SDK_SPLASH_HORIZONTAL;
// banner广告获取超时
extern const CJZFAdapterErrorCode CJZF_SDK_BANNER_TIMEOUT;
// appId为空
extern const CJZFAdapterErrorCode CJZF_SDK_INIT_APPIDEMPTY;
// 包名和appId不对应
extern const CJZFAdapterErrorCode CJZF_SDK_INIT_BUNDLE;
// 请求配置为空
extern const CJZFAdapterErrorCode CJZF_SDK_INIT_CONFIGEMPTY;
// 未获取到加载广告的平台，可能一下原因 1、第一次启动未获取到配置信息；2、运营未配置广告
extern const CJZFAdapterErrorCode CJZF_SDK_INIT_PLATFORMEMPTY;
// 未导入需要加载的广告类型对应的类
extern const CJZFAdapterErrorCode CJZF_SDK_INIT_CLASSEMPTY;
// posid和广告位类型不匹配
extern const CJZFAdapterErrorCode CJZF_SDK_POSID_ERROR;
// banner加载失败
extern const CJZFAdapterErrorCode CJZF_SDK_BANNER_ERROR;
// 插屏加载失败
extern const CJZFAdapterErrorCode CJZF_SDK_INTERSTITIAL_ERROR;

#define CJZFAdapterErrorDomain @"com.CJZFAd.error"

FOUNDATION_EXPORT NSError *CJZFAdapterError(NSErrorDomain domain, NSInteger code, NSString *localizedDescription);

FOUNDATION_EXPORT NSError *CJZFAdapterErrorDefaultDomain(NSInteger code, NSString *localizedDescription);

@interface CJZFAdapterErrorDefine : NSObject

@end
