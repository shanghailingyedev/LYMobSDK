//
//  CJZFUtilsKit-code
//
//  Created by 早范 on 2025/1/28.
//  
//

#import <UIKit/UIKit.h>
#import <CoreTelephony/CTCarrier.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIDevice (CJZF)

/// 系统版本号 (e.g. 8.1)
+ (double)CJZF_systemVersion;

/// 是否是iPad
@property (nonatomic, readonly) BOOL CJZF_isPad;

/// 是否是模拟器
@property (nonatomic, readonly) BOOL CJZF_isSimulator;

@property (nonatomic, readonly) BOOL CJZF_isJailbroken;

/// idfa, iOS10后关闭广告追踪后, 返回为:00000000-0000-0000-0000-000000000000
- (nullable NSString *)CJZF_idfa;

/// idfv
- (nullable NSString *)CJZF_idfv;

- (long)getSystemUpTime;

- (NSString *)battery;

- (int)batteryStatus;

- (int)batteryLevels;

- (float)getTotalDiskSpace;

- (int)getTotalMemory;

+ (int)CJZF_getCPUCores;

+ (NSUInteger)CJZF_getCpuFrequency;
/**
 获取设备型号

 @return e.g. iPhone 2G (A1203)
 */
+ (nullable NSString *)CJZF_getCurrentDeviceModel;

/**
 获取设备型号

 @return e.g. iPhone11,2
 */
+ (NSString *)CJZF_getCurrentRawModel;

/**
 获取设备型号

 @return e.g. iPhone 2G
 */
+ (nullable NSString *)CJZF_getCurrentDeviceShortModel;

/**
 获取屏幕密度

 @return e.g. 326
 */
+ (NSInteger)CJZF_getCurrentDevicePPI;

+ (NSString *)networkStatus;

/// 获取运营商类型
+ (NSInteger)getOperatorsType;

+ (NSString *)mobileCountryCode;

+ (NSString *)mobileNetworkCode;

+ (NSString *)deviceImsi;

/// 判断是否开启了代理
+ (BOOL)checkProxySetting;

+ (NSString *)getBoot;

+ (NSString *)getUpdate;

+ (BOOL)isLandscape;

+ (NSString *)CJZF_getFileTime;

// CD

+ (NSString *)CJZF_bootTimeInSec;
+ (NSString *)CJZF_countryCode;
+ (NSString *)CJZF_language;
// hardware_model
+ (NSString *)CJZF_getHWModel;
+ (NSString* )CJZF_carrierInfo;
+ (CTCarrier *)CJZF_ctcarrierInfo;
+ (NSString *)CJZF_disk;
+ (NSString *) CJZF_memory;
// update_time_nsec iOS 参考代码（输出为纳秒）
+ (NSString *)CJZF_getSysU;
+ (NSInteger)CJZF_getSysUTime;
+ (NSString *)CJZF_timeZone;
+ (NSString *)CJZF_machine;
+ (NSString *)carrierInfo;
+ (NSString *)CJZF_mntId;
+ (NSString *)CJZF_fileInitTime;
+ (NSInteger)CJZF_deviceInitTime;

+ (NSString *)CJZF_EnpoId;
@end

#ifndef kCJZFSystemVersion
#define kCJZFSystemVersion [UIDevice CJZF_systemVersion]
#endif

#ifndef kCJZFiOS7Later
#define kCJZFiOS7Later (kCJZFSystemVersion >= 7)
#endif

#ifndef kCJZFiOS8Later
#define kCJZFiOS8Later (kCJZFSystemVersion >= 8)
#endif

#ifndef kCJZFiOS9Later
#define kCJZFiOS9Later (kCJZFSystemVersion >= 9)
#endif

#ifndef kCJZFiOS10Later
#define kCJZFiOS10Later (kCJZFSystemVersion >= 10)
#endif

#ifndef kCJZFiOS11Later
#define kCJZFiOS11Later (kCJZFSystemVersion >= 11)
#endif

NS_ASSUME_NONNULL_END
