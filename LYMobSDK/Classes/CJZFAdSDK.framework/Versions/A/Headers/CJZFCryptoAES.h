//
//  CJZFCryptoAES.h
//
//  Created by 早范 on 2025/3/19.
//

#import <Foundation/Foundation.h>

#pragma mark - GET string
/**
AES ECB模式加密
*/
NSString * KCJZFAESECBEncryptString(NSString *content, NSString *key);
/**
AES ECB模式解密
*/
NSString * KCJZFAESECBDecryptString(NSString *content, NSString *key);

#pragma mark - GET data

/**
 AES ECB模式加密
 */
NSData * KCJZFAESECBEncryptData(NSData *contentData, NSData *keyData);
/**
 AES ECB模式解密
*/
NSData * KCJZFAESECBDecryptData(NSData *contentData, NSData *keyData);

#pragma mark - AES CBC 加解密

NSString * KCJZFAESCBCEncryptData(NSString *content, NSString *key, NSString *iv);

NSString * KCJZFAESCBCDecryptData(NSString *content, NSString *key, NSString *iv);
