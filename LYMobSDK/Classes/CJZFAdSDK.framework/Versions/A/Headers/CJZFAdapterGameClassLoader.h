//
//  CJZFAdapterGameClassLoader.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2025/8/26.
//

#import "CJZFAdapterCommonClassLoader.h"
#import "CJZFAdapterGameRequestProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterGameClassLoader :  CJZFAdapterCommonClassLoader<Class<CJZFAdapterGameRequestProtocol>>

@end

NS_ASSUME_NONNULL_END
