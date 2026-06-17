//
//  CJZFAdSDKConfigModel.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/12.
//

#import <Foundation/Foundation.h>
#import "CJZFAdapterCommonDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFChannelInfo : NSObject

@property (nonatomic, copy) CJZFAdapterPlatform platformType;
@property (nonatomic, copy) NSString *baseUrl;
@property (nonatomic, copy) NSString *key;
@property (nonatomic, copy) NSString *userID;

@end

@interface CJZFAdSDKReportModel : NSObject

@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *appid;
@property (nonatomic, copy) NSString *platformType;

- (instancetype)initModelWithJson:(NSDictionary *)json NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

@end


@interface CJZFAdSDKPosModel : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *appid;
@property (nonatomic, copy) NSString *posid;
@property (nonatomic, copy) NSString *platformAppid;
@property (nonatomic, copy) NSString *platformPosid;
@property (nonatomic, copy) NSString *platformType;
@property (nonatomic, copy) NSString *adType;
@property (nonatomic, strong) NSArray<NSString *> *reportURLArray;
//@property (nonatomic, copy) NSString *reportURL;
@property (nonatomic, copy) NSString *expand;
@property (nonatomic, assign) NSInteger price;
@property (nonatomic, assign) NSInteger countdown;
@property (nonatomic, copy) NSString *baseURL;
@property (nonatomic,  assign) CGFloat bidding_ratio;


- (instancetype)initModelWithJson:(NSDictionary *)json NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;
 
@end

@interface CJZFAdSDKPlatformModel : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *appid;
@property (nonatomic, copy) NSString *platformAppid;
@property (nonatomic, copy) NSString *platformAppkey;
@property (nonatomic, assign) NSInteger sort;
@property (nonatomic, copy) NSString *platformType;
@property (nonatomic, copy) NSString *baseURL;
//@property (nonatomic, copy) NSString *reportURL;
@property (nonatomic, strong) NSArray<NSString *> *reportURLArray;
@property (nonatomic, copy) NSString *expand;
@property (nonatomic, strong, nullable) CJZFAdSDKPlatformModel *nextPlatform;
// posid:CJZFAdSDKPosModel
@property (nonatomic, strong, nullable) NSMutableDictionary<NSString*, CJZFAdSDKPosModel *> *posModelMap;


- (instancetype)initModelWithJson:(NSDictionary *)json NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

- (CJZFAdSDKPosModel *)getPosModel:(NSString *)posid;

@end

@interface CJZFAdSDKConfigAppModel : NSObject

@property (nonatomic, copy) NSString *appId;
// 链表，当前为顺位第一的平台，动态变化平台顺序不适用该结构
@property (nonatomic, strong, nullable) CJZFAdSDKPlatformModel *firstPlatform;

@property (nonatomic, assign) BOOL emptyPosIdList;

@property (nonatomic, copy) NSString *appKey;

@property (nonatomic, copy) NSString *appSecret;

@property (nonatomic, strong) NSDictionary<CJZFAdapterPlatform, CJZFChannelInfo *> *channelInfoMap;

@property (nonatomic, strong) NSArray<NSString *> *posIdList;

- (instancetype)initModelWithJson:(NSDictionary *)json NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

- (CJZFAdSDKPlatformModel *)getPlatformModel:(NSString *)platformType;

@end

@interface CJZFAdSDKConfigModel : NSObject

@property (nonatomic, strong) NSMutableDictionary<NSString *, CJZFAdSDKConfigAppModel *> *configModelMap;

- (BOOL)posidConfigIsEmpty;

- (CJZFAdSDKConfigAppModel *)getAppModelByPosid:(NSString *)posid;

- (NSString *)getAppIdByPosid:(NSString *)posid;

- (void)addInitCionfigModelByJson:(NSDictionary *)json;

- (void)addInitConfigModelByModel:(CJZFAdSDKConfigAppModel *)appModel;

- (CJZFChannelInfo *)getRCChannelInfoModelByAppid:(NSString *)appid;

- (CJZFChannelInfo *)getChannelInfoModelByPlatform:(CJZFAdapterPlatform)platform appid:(NSString *)appid;

- (CJZFAdSDKPlatformModel *)getPlatformModelByPlatform:(CJZFAdapterPlatform)platform appid:(NSString *)appid;

@end


NS_ASSUME_NONNULL_END
