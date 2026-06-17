//
//  CJZFAdapterCacheCallBack.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/27.
//

#ifndef CJZFAdapterCacheCallBack_h
#define CJZFAdapterCacheCallBack_h

@class CJZFAdapterCacheAdapter;

@protocol CJZFAdapterCacheCallBack <NSObject>

- (void)cacheAdSuccess:(CJZFAdapterCacheAdapter *)adapter;

- (void)cacheAdFailed:(CJZFAdapterCacheAdapter *)adapter error:(NSError *)error;

@end


#endif /* CJZFAdapterCacheCallBack_h */
