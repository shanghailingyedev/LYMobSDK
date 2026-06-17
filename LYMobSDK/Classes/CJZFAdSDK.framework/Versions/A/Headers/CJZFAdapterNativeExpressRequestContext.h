//
//  CJZFAdapterNativeExpressRequestContext.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/4/9.
//

#import "CJZFAdapterCommonRequestContext.h"
#import "CJZFAdapterCommonDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterNativeExpressRequestContext : CJZFAdapterCommonRequestContext

@property (nonatomic, assign) BOOL muted;

@property (nonatomic, assign) CGSize adSize;

@property (nonatomic, assign) NSInteger loadCount;

@property (nonatomic, assign) BOOL autoPlay;

@property (nonatomic, copy) CJZFAdapterNativeExpressType expressType;

@property (nonatomic, strong) NSDictionary *scenes;

@end

NS_ASSUME_NONNULL_END
