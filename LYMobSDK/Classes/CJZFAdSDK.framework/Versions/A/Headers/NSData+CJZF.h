//
//  CJZFUtilsKit-code
//
//  Created by 早范 on 2025/1/28.
//  
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (CJZF)

#pragma mark - Encode and Decode

/**
 UTF8编码
 */
- (nullable NSString *)CJZF_utf8String;

/**
 Base64编码
 */
- (nullable NSString *)CJZF_base64EncodedString;

/**
 Base64解码
 
 @param base64EncodedString The encoded string.
 */
+ (nullable NSData *)CJZF_dataWithBase64EncodedString:(NSString *)base64EncodedString;

/**
 Json解析
 如果失败,返回 nil
 */
- (nullable id)CJZF_jsonValueDecodedWithError:(NSError **)error;

#pragma mark - Hash

/**
 MD5编码
 */
- (NSString *)CJZF_md5String;

#pragma mark - Inflate and deflate

/**
 从gzip数据解压
 */
- (nullable NSData *)CJZF_gzipInflate;

/**
 用默认压缩等级压缩成gizp数据
 */
- (nullable NSData *)CJZF_gzipDeflate;

/**
 从zlib数据解压
 */
- (nullable NSData *)CJZF_zlibInflate;

/**
 用默认压缩等级压缩成zlib数据
 */
- (nullable NSData *)CJZF_zlibDeflate;

/**
 AES CBC 128位加密模式
 */
- (nullable NSData *)AESCBC128EncryptWithKey:(NSString *)key gIv:(NSString *)Iv;
/**
AES CBC 128位解密模式
*/
- (nullable NSData *)AESCBC128DecryptWithKey:(NSString *)key gIv:(NSString *)Iv;
/**
AES CBC 256位加密模式
*/
- (nullable NSData *)AESCBC256EncryptWithKey:(NSString *)key gIv:(NSString *)Iv;
/**
AES CBC 256位解密模式
*/
- (nullable NSData *)AESCBC256DecryptWithKey:(NSString *)key gIv:(NSString *)Iv;

/**
AES CBC 256位解密模式
*/
- (nullable NSData *)AESCBC256OpenDecryptWithKey:(NSString *)key gIv:(NSString *)Iv;

@end

NS_ASSUME_NONNULL_END
