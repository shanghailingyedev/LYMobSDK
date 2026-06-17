//
//  CJZFAdapterCacheClassLoader.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/26.
//

#import "CJZFAdapterCommonClassLoader.h"
#import "CJZFAdapterCacheRequestProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterCacheClassLoader : CJZFAdapterCommonClassLoader<Class<CJZFAdapterCacheRequestProtocol>>

@end

NS_ASSUME_NONNULL_END
