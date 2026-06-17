//
//  CJZFIdentityProvider.h
//  CJZFUtilsKit-code
//
//  Created by 早范 on 2025/1/28.
//  
//

#import <Foundation/Foundation.h>

@interface CJZFIdentityProvider : NSObject

/**
 SDK封装的设备唯一标识符, idfv+keychain, 换个包名可能会变化
 */
+ (NSString *)identifier;

@end
