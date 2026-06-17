//
//  CJZFAdapterCommonClassLoader.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/12.
//

#import <Foundation/Foundation.h>
#import "CJZFAdapterCommonDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterCommonClassLoader<T> : NSObject

+ (void)registPlatformClass:(T)klass forSdkName:(CJZFAdapterPlatform)sdkName;

+ (T)platformClassForSdkName:(CJZFAdapterPlatform)sdkName;

@end

NS_ASSUME_NONNULL_END
