//
//  CJZFAdapterNoticeRequestProtocol.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2026/5/15.
//

#ifndef CJZFAdapterNoticeRequestProtocol_h
#define CJZFAdapterNoticeRequestProtocol_h

#import "CJZFAdapterCommonRequestProtocol.h"
@class CJZFAdapterNoticeAdapter;

@protocol CJZFAdapterNoticeRequestProtocol <CJZFAdapterCommonRequestProtocol>

- (void)loadNoticeView:(CJZFAdapterNoticeAdapter *)adapter;

- (void)showNoticeViewInWinbdow:(UIWindow *)window screenBottom:(BOOL)screenBottom;

- (void)showNoticeViewInController:(UIViewController *)controller screenBottom:(BOOL)screenBottom;

@end

#endif /* CJZFAdapterNoticeRequestProtocol_h */
