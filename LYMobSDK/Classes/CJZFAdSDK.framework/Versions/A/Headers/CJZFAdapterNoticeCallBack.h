//
//  CJZFAdapterNoticeCallBack.h
//  CJZFAdSDK-Adapter
//
//  Created by 早范 on 2026/5/15.
//

#ifndef CJZFAdapterNoticeCallBack_h
#define CJZFAdapterNoticeCallBack_h

#import "CJZFAdapterCommonCallBack.h"
@class CJZFAdapterNoticeAdapter;
NS_ASSUME_NONNULL_BEGIN

@protocol CJZFAdapterNoticeCallBack <CJZFAdapterCommonCallBack>

- (void)noticeAdViewDidLoadCallBack:(CJZFAdapterNoticeAdapter *)adapter;

- (void)noticeAdViewFailToLoadCallBack:(CJZFAdapterNoticeAdapter *)adapter error:(nullable NSError *)error;

- (void)noticeAdViewDidPresentCallBack:(CJZFAdapterNoticeAdapter *)adapter;

- (void)noticeAdViewFailToPresentCallBack:(CJZFAdapterNoticeAdapter *)adapter error:(nullable NSError *)error;

- (void)noticeAdViewClickedCallBack:(CJZFAdapterNoticeAdapter *)adapter loadingPageURL:(NSString *)loadingPageURL;

- (void)noticeAdViewExposureCallBack:(CJZFAdapterNoticeAdapter *)adapter;

- (void)noticeAdViewExposureReportCallBack:(CJZFAdapterNoticeAdapter *)adapter;

- (void)noticeAdViewClickedReportCallBack:(CJZFAdapterNoticeAdapter *)adapter;

- (void)noticeAdViewCloseCallBack:(CJZFAdapterNoticeAdapter *)adapter;

- (void)noticeAdViewCloseLandingPageCallBack:(CJZFAdapterNoticeAdapter *)adapter;

@end
NS_ASSUME_NONNULL_END

#endif /* CJZFAdapterNoticeCallBack_h */
