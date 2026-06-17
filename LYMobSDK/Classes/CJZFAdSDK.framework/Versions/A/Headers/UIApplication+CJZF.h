//
//  CJZFUtilsKit-code
//
//  Created by 早范 on 2025/1/29.
//  
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIApplication (CJZF)

- (NSString *)CJZF_ua;

- (NSError *)setApplicationUa:(NSString *)ua;

/// "Documents"在沙盒中文件夹路径
@property (nonatomic, readonly) NSURL *CJZF_documentsURL;
@property (nonatomic, readonly) NSString *CJZF_documentsPath;

/// "Caches"在沙盒中文件夹路径
@property (nonatomic, readonly) NSURL *CJZF_cachesURL;
@property (nonatomic, readonly) NSString *CJZF_cachesPath;

/// "Library"在沙盒中文件夹路径
@property (nonatomic, readonly) NSURL *CJZF_libraryURL;
@property (nonatomic, readonly) NSString *CJZF_libraryPath;

/// Application's Bundle Name (show in SpringBoard).
@property (nullable, nonatomic, readonly) NSString *CJZF_appBundleName;

/// Application's Bundle ID.  e.g. "com.XXX.MyApp"
@property (nullable, nonatomic, readonly) NSString *CJZF_appBundleID;

/// Application's Version.  e.g. "1.2.0"
@property (nullable, nonatomic, readonly) NSString *CJZF_appVersion;

/// Application's Build number. e.g. "123"
@property (nullable, nonatomic, readonly) NSString *CJZF_appBuildVersion;

/// app是否是盗版(不是从app store下载的)
@property (nonatomic, readonly) BOOL CJZF_isPirated;

/// app是否正在被调试
@property (nonatomic, readonly) BOOL CJZF_isBeingDebugged;


@end

NS_ASSUME_NONNULL_END
