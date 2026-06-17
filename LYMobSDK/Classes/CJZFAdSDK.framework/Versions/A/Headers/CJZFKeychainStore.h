//
//  CJZFKeychainStore.h
//  CJZFUtilsKit-code
//
//  Created by 早范 on 2025/1/28.
//  
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol CJZFKeychainStoreProtocol <NSObject>

/** @fn initWithService:
 @brief Initialize a @c FIRAuthStorage instance.
 @param service The name of the storage service to use.
 @return An initialized @c FIRAuthStorage instance for the specified service.
 */
- (id<CJZFKeychainStoreProtocol>)initWithService:(NSString *)service;

/** @fn dataForKey:error:
 @brief Gets the data for @c key in the storage. The key is set for the attribute
 @c kSecAttrAccount of a generic password query.
 @param key The key to use.
 @param error The address to store any error that occurs during the process, if not NULL.
 If the operation was successful, its content is set to @c nil .
 @return The data stored in the storage for @c key, if any.
 */
- (nullable NSData *)dataForKey:(NSString *)key error:(NSError **)error;

/** @fn setData:forKey:error:
 @brief Sets the data for @c key in the storage. The key is set for the attribute
 @c kSecAttrAccount of a generic password query.
 @param data The data to store.
 @param key The key to use.
 @param error The address to store any error that occurs during the process, if not NULL.
 @return Whether the operation succeeded or not.
 */
- (BOOL)setData:(NSData *)data
         forKey:(NSString *)key
          error:(NSError **)error;

/** @fn removeDataForKey:error:
 @brief Removes the data for @c key in the storage. The key is set for the attribute
 @c kSecAttrAccount of a generic password query.
 @param key The key to use.
 @param error The address to store any error that occurs during the process, if not NULL.
 @return Whether the operation succeeded or not.
 */
- (BOOL)removeDataForKey:(NSString *)key error:(NSError **)error;

@end

@interface CJZFKeychainStore : NSObject <CJZFKeychainStoreProtocol>

@end

NS_ASSUME_NONNULL_END
