//
//  CJZFAdapterCommonRequestProtocol.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2025/9/5.
//

#ifndef CJZFAdapterCommonRequestProtocol_h
#define CJZFAdapterCommonRequestProtocol_h

NS_ASSUME_NONNULL_BEGIN

@protocol CJZFAdapterCommonRequestProtocol <NSObject>

@optional

- (NSInteger)CJZF_getBidPrice;

- (NSString *)CJZF_getRequestId;

- (void)CJZF_sendWinNotice:(NSInteger)price;

- (void)CJZF_sendLossNoticePrice:(NSInteger)price;

@end
NS_ASSUME_NONNULL_END

#endif /* CJZFAdapterCommonRequestProtocol_h */
