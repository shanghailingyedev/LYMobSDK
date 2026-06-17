//
//  CJZFAdapterNativeExpressClassLoader.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/4/9.
//

#import "CJZFAdapterCommonClassLoader.h"
#import "CJZFAdapterNativeExpressRequestProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterNativeExpressClassLoader : CJZFAdapterCommonClassLoader<Class<CJZFAdapterNativeExpressRequestProtocol>>

@end

NS_ASSUME_NONNULL_END
