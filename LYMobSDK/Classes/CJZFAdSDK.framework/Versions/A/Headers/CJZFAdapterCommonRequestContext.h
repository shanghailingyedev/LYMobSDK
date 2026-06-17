//
//  CJZFAdapterCommonRequestContext.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/12.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterCommonRequestContext : NSObject

/// CJZF的appid
@property (nonatomic, copy) NSString *CJZFAppId;
/// 第三方平台的appid
@property (nonatomic, copy) NSString *platformAppid;
/// 第三方平台的Appkey
@property (nonatomic, copy) NSString *platformAppkey;
/// 第三方平台的posId
@property (nonatomic, copy) NSString *platformPosid;
/// 广告类型
@property (nonatomic, copy ,readonly) NSString *adType;
/// CJZF的Posid
@property (nonatomic, copy) NSString *CJZFPosid;
/// CJZF的Posid名称
@property (nonatomic, copy) NSString *CJZFPosName;
// CJZF的cityID
@property (nonatomic, copy) NSString *cityId;
/// 当前控制器
@property (nonatomic, weak) UIViewController *viewController;

@property (nonatomic, assign) BOOL customLoadingPage;

@property (nonatomic, copy) NSString *cacheId;

@property (nonatomic, copy) NSString *platformType;

@end

NS_ASSUME_NONNULL_END
