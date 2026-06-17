//
//  CJZFAdapterInitializeClassLoader.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/13.
//

#import <Foundation/Foundation.h>
#import "CJZFAdapterCommonDefine.h"
#import "CJZFAdapterInitializeProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterInitializeClassLoader : NSObject

+ (NSArray<CJZFAdapterPlatform> *)allPlatforms;

+ (void)registPlatformClass:(Class<CJZFAdapterInitializeProtocol>)klass forSdkName:(CJZFAdapterPlatform)sdkName;

+ (Class<CJZFAdapterInitializeProtocol>)platformClassForSdkName:(CJZFAdapterPlatform)sdkName;

@end

NS_ASSUME_NONNULL_END
