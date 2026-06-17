//
//  CJZFAdapterCacheRequestProtocol.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/26.
//

#ifndef CJZFAdapterCacheRequestProtocol_h
#define CJZFAdapterCacheRequestProtocol_h

@class CJZFAdapterCacheAdapter;

@protocol CJZFAdapterCacheRequestProtocol <NSObject>

- (void)requestAdData:(CJZFAdapterCacheAdapter *)adapter;

- (BOOL)needCacheAdData:(CJZFAdapterCacheAdapter *)adapter;

@end

#endif /* CJZFAdapterCacheRequestProtocol_h */
