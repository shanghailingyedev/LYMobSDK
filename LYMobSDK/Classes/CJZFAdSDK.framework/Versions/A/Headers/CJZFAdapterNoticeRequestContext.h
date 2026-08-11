//
//  CJZFAdapterNoticeRequestContext.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2026/5/15.
//

#import "CJZFAdapterCommonRequestContext.h"
#import "CJZFAdapterCommonDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterNoticeRequestContext : CJZFAdapterCommonRequestContext

@property (nonatomic, strong) NSDictionary *scenes;

@property (nonatomic, assign) CJZFAdSDKNoticeAdStyleType styleType;

@end

NS_ASSUME_NONNULL_END
