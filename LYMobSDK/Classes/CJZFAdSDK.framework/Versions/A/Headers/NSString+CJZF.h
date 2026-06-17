//
//  CJZFUtilsKit-code
//
//  Created by 早范 on 2025/1/28.
//  
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (CJZF)

#pragma mark - Utils

/**
 生成一个新的udid
 */
+ (nullable NSString *)CJZF_stringWithUUID;

/**
 用UTF-8编码成NSData类型
 */
- (nullable NSData *)CJZF_dataValue;

#pragma mark - Encode and decode

/**
 Base64编码
 */
- (nullable NSString *)CJZF_base64EncodedString;

/**
 Base64解码
 
 @param base64EncodedString The encoded string
 */
+ (nullable NSString *)CJZF_stringWithBase64EncodedString:(NSString *)base64EncodedString;

/**
 Json解析
 如果失败,返回 nil
 
 e.g. NSString: @"{"name":"a","count":2}"  => NSDictionary: @[@"name":@"a",@"count":@2]
 */
- (nullable id)CJZF_jsonValueDecodedWithError:(NSError **)error;

/**
 URL编码, utf-8
 */
- (NSString *)CJZF_stringByURLEncode;

/**
 URL解码, utf-8
 */
- (NSString *)CJZF_stringByURLDecode;

#pragma mark - Hash

/**
 MD5字符串
 */
- (nullable NSString *)CJZF_md5String;

@end

NS_ASSUME_NONNULL_END
