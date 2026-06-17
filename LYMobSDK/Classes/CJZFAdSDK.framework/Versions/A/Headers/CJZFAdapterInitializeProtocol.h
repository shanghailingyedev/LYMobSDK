//
//  CJZFAdapterInitializeProtocol.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/13.
//

#ifndef CJZFAdapterInitializeProtocol_h
#define CJZFAdapterInitializeProtocol_h
#import "CJZFAdapterCommonDefine.h"
#import "CJZFAdapterInitializeRequestContext.h"

@protocol CJZFAdapterInitializeProtocol <NSObject>

@required
+ (void)initializePlatformSDKWithParams:(CJZFAdapterInitializeRequestContext *)params;

+ (NSString *)platformSDKVersion;

+ (CJZFAdapterPlatform)platformSDKName;

@end

#endif /* CJZFAdapterInitializeProtocol_h */
