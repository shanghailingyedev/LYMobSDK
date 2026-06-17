//
//  CJZFUtilsKit-code
//
//  Created by 早范 on 2025/1/28.
//  
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSKeyedUnarchiver (CJZF)

+ (nullable id)CJZF_unarchiveObjectWithData:(NSData *)data exception:(NSException *_Nullable *_Nullable)exception;

+ (nullable id)CJZF_unarchiveObjectWithFile:(NSString *)path exception:(NSException *_Nullable *_Nullable)exception;

@end

NS_ASSUME_NONNULL_END
