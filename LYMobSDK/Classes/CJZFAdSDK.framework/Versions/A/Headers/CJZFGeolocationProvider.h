//
//  CJZFGeolocationProvider.h
//
//  Created by 早范 on 2025/7/13.
//  
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface CJZFGeolocationProvider : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, readonly) CLLocation *lastKnownLocation;

@property (nonatomic, assign) BOOL locationUpdatesEnabled;
// 坐标系统,1:GPS， 2:GCJ-02(高德使用)， 3:BD-09(百度使用)
@property (nonatomic, assign) NSInteger coordinate_type;
// 定位精准度，IOS操 作系统必传 0: 定位不准确,1: 定位精准，可以获取到小数 点4位及以上
@property (nonatomic, assign) NSInteger laccu;
// 获取定位的时间戳 (秒)
@property (nonatomic, assign) NSInteger timestamp;

@end
