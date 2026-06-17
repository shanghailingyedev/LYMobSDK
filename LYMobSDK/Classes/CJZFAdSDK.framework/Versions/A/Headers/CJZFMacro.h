//
//  CJZFMacro.h
//
//  Created by 早范 on 2025/7/13.
//  
//

#ifndef CJZFMacro_h
#define CJZFMacro_h

#define CJZF_SUPPRESS_PERFORM_SELECTOR_LEAK_WARNING(code) \
    _Pragma("clang diagnostic push") \
    _Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
    code; \
    _Pragma("clang diagnostic pop")

#ifndef CJZF_dispatch_main_async_safe
#define CJZF_dispatch_main_async_safe(block)    \
    if (strcmp(dispatch_queue_get_label(DISPATCH_CURRENT_QUEUE_LABEL), dispatch_queue_get_label(dispatch_get_main_queue())) == 0) { \
        block();    \
    } else {    \
        dispatch_async(dispatch_get_main_queue(), block);   \
    }
#endif


#define kCJZFStringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || str == nil || ![str isKindOfClass:[NSString class]] || [str length] < 1 ? YES : NO)
#define kCJZFArrayIsEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || ![array isKindOfClass:[NSArray class]] || array.count == 0)
#define kCJZFDictIsEmpty(dict) (dict == nil || [dict isKindOfClass:[NSNull class]] || ![dict isKindOfClass:[NSDictionary class]] || dict.allKeys.count == 0)
#define kCJZFObjectIsEmpty(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))

// 机型UI适配宏
#define kCJZFIPhoneX (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone && (kCJZFScreenWidth == 375.0 && kCJZFScreenHeight == 812.0))
#define kCJZFIphoneXS (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone && (kCJZFScreenWidth == 375.0 && kCJZFScreenHeight == 812.0))
#define kCJZFIphoneXR (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone && (kCJZFScreenWidth == 414.0 && kCJZFScreenHeight == 896.0) && (kScreenScale == 2))
#define kCJZFIphoneXS_MAX (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone && (kCJZFScreenWidth == 414.0 && kCJZFScreenHeight == 896.0) && (kScreenScale == 3))
#define kCJZFCurveScreen (CGSizeEqualToSize(CGSizeMake(375.f, 812.f), [UIScreen mainScreen].bounds.size) \
|| CGSizeEqualToSize(CGSizeMake(812.f, 375.f), [UIScreen mainScreen].bounds.size) \
|| CGSizeEqualToSize(CGSizeMake(414.f, 896.f), [UIScreen mainScreen].bounds.size) \
|| CGSizeEqualToSize(CGSizeMake(896.f, 414.f), [UIScreen mainScreen].bounds.size) \
|| CGSizeEqualToSize(CGSizeMake(844.f, 390.f), [UIScreen mainScreen].bounds.size) \
|| CGSizeEqualToSize(CGSizeMake(812.f, 375.f), [UIScreen mainScreen].bounds.size) \
|| CGSizeEqualToSize(CGSizeMake(844.f, 390.f), [UIScreen mainScreen].bounds.size) \
|| CGSizeEqualToSize(CGSizeMake(926.f, 428.f), [UIScreen mainScreen].bounds.size) \
|| CGSizeEqualToSize(CGSizeMake(375.f, 812.f), [UIScreen mainScreen].bounds.size) \
|| CGSizeEqualToSize(CGSizeMake(390.f, 844.f), [UIScreen mainScreen].bounds.size) \
|| CGSizeEqualToSize(CGSizeMake(428.f, 926.f), [UIScreen mainScreen].bounds.size)) // 刘海屏幕

#define kCJZFStatusBarHeight (kCJZFCurveScreen ? 44 : 20)
#define kCJZFNavBarHeight ([UIDevice currentDevice].CJZF_isPad ? 50 : 44)
#define kCJZFTopBarHeight (kCJZFStatusBarHeight + kCJZFNavBarHeight)
#define kCJZFTabBarHeight (kCJZFCurveScreen ? 83 : 49)
#define kCJZFBottomSafeHeight (kCJZFStatusBarHeight>20?34:0)

#endif /* CJZFMacro_h */
