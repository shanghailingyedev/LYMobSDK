//
//  CJZFAdTool.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/6/13.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT BOOL CJZF_DictIsEmpty(NSDictionary * _Nullable dict);

FOUNDATION_EXPORT BOOL CJZF_ArrayIsEmpty(NSArray * _Nullable array);

FOUNDATION_EXPORT NSArray* CJZF_DictAllKeys(NSDictionary * _Nullable dict);

@interface CJZFAdTool : NSObject

+ (void)openSchemeURL:(NSURL *)schemeURL completionHandler:(void (^)(BOOL opened))completionHandler;

+ (NSString *)randomString:(NSInteger)number;

+ (NSString *)mcid;

+ (UIWindow *)getWindow:(UIView *)view;

+ (CGPoint)getTouchPoint:(CGSize)adSize;

+ (CGPoint)getScreenPoint:(CGPoint)point view:(UIView *)view;

+ (UIImage *)getCloseImage;

+ (UIImage *)getReturnImage;

@end

NS_ASSUME_NONNULL_END
