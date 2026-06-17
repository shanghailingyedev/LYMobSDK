//
//  CJZFAdapterInitializeRequestContext.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/13.
//

#import <Foundation/Foundation.h>
#import "CJZFAdSDKConfigModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterInitializeRequestContext : NSObject

@property (nonatomic, copy) NSString *appid;

@property (nonatomic, copy) NSString *appkey;

@property (nonatomic, copy) NSString *platform;

@property (nonatomic, strong) CJZFChannelInfo *channelInfo;

@property (nonatomic, copy) NSString *requestDomain;

@property (nonatomic, copy) NSString *mainRequestDomain;

@end

NS_ASSUME_NONNULL_END
