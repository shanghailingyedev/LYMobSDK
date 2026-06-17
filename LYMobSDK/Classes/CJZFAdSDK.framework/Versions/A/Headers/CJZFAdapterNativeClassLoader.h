//
//  CJZFAdapterNativeClassLoader.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/5/4.
//

#import "CJZFAdapterCommonClassLoader.h"
#import "CJZFAdapterNativeRequestProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterNativeClassLoader : CJZFAdapterCommonClassLoader<Class<CJZFAdapterNativeRequestProtocol>>

@end

NS_ASSUME_NONNULL_END
