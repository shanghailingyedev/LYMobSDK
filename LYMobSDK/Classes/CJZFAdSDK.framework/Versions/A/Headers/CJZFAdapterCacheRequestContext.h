//
//  CJZFAdapterCacheRequestContext.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterCacheRequestContext : NSObject

@property (nonatomic, copy) NSString *posId;

@property (nonatomic, copy) NSString *cityId;

@property (nonatomic, copy) NSString *appid;

@property (nonatomic, strong) NSDictionary *scenes;

@property (nonatomic, assign) NSInteger loadCount;
// 广告类型, 1:开屏广告， 2:信息流广告， 3:banner广告 ，4:插屏广告
@property (nonatomic, assign) NSInteger ad_type;

@property (nonatomic, copy) NSString *cacheId;

@property (nonatomic, copy) NSString *platformType;

@end

NS_ASSUME_NONNULL_END
