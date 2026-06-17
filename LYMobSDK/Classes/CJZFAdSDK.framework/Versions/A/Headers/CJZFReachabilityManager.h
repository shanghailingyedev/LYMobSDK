//
//  CJZFReachabilityManager.h
//  CJZFUtilsKit-code
//
//  Created by 早范 on 2025/1/28.
//  
//

#import <Foundation/Foundation.h>
#import <CoreTelephony/CTCarrier.h>
#import "CJZFReachability.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFReachabilityManager : NSObject

@property (nonatomic, readonly) CJZFReachability *reachability;

/// Current status.
@property (nonatomic, readonly) CJZFReachabilityStatus status;

/// Current WWAN status.
@property (nonatomic, readonly) CJZFReachabilityWWANStatus wwanStatus NS_AVAILABLE_IOS(7_0);

/// 'mobileCountryCode' + mobileNetworkCode, look at 'CTCarrier' for more
@property (nonatomic, readonly) NSString *imsi;

/// network proxy
@property (nonatomic, readonly) BOOL networkProxy;

+ (instancetype _Nonnull)sharedManager;

@end

NS_ASSUME_NONNULL_END
