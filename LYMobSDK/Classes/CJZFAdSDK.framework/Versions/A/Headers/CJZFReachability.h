//
//  CJZFReachability.h
//  CJZFUtilsKit-code
//
//  Created by 早范 on 2025/1/28.
//  
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <netinet/in.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, CJZFReachabilityStatus) {
    CJZFReachabilityStatusNone = 0, ///< Not Reachable
    CJZFReachabilityStatusWWAN = 1, ///< Reachable via WWAN (2G/3G/4G)
    CJZFReachabilityStatusWiFi = 2  ///< Reachable via WiFi
};

typedef NS_ENUM(NSUInteger, CJZFReachabilityWWANStatus) {
    CJZFReachabilityWWANStatusNone, ///< Not Reachable vis WWAN
    CJZFReachabilityWWANStatus2G,   ///< Reachable via 2G (GPRS/EDGE)       10~100Kbps
    CJZFReachabilityWWANStatus3G,   ///< Reachable via 3G (WCDMA/HSDPA/...) 1~10Mbps
    CJZFReachabilityWWANStatus4G    ///< Reachable via 4G (eHRPD/LTE)       100Mbps
};

@interface CJZFReachability : NSObject

@property (nonatomic, readonly) SCNetworkReachabilityFlags flags;                           ///< Current flags.
@property (nonatomic, readonly) CTTelephonyNetworkInfo *networkInfo; ///< current network info
@property (nonatomic, readonly) CJZFReachabilityStatus status;                                ///< Current status.
@property (nonatomic, readonly) CJZFReachabilityWWANStatus wwanStatus NS_AVAILABLE_IOS(7_0);  ///< Current WWAN status.
@property (nonatomic, readonly, getter=isReachable) BOOL reachable;  ///< Current reachable status.

/// Notify block which will be called on main thread when network changed.
@property (nullable, nonatomic, copy) void (^notifyBlock)(CJZFReachability *reachability);

/// Create an object to check the reachability of the default route.
+ (instancetype)reachability;

/// Create an object to check the reachability of the local WI-FI.
+ (instancetype)reachabilityForLocalWifi DEPRECATED_MSG_ATTRIBUTE("unnecessary and potentially harmful");

/// Create an object to check the reachability of a given host name.
+ (nullable instancetype)reachabilityWithHostname:(NSString *)hostname;

/// Create an object to check the reachability of a given IP address
/// @param hostAddress You may pass `struct sockaddr_in` for IPv4 address or `struct sockaddr_in6` for IPv6 address.
+ (nullable instancetype)reachabilityWithAddress:(const struct sockaddr *)hostAddress;

@end

NS_ASSUME_NONNULL_END
