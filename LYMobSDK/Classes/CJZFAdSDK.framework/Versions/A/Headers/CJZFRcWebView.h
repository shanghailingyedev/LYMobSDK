//
//  CJZFRcWebView.h
//  CJZFAdSDK-RC
//
//  Created by 早范 on 2025/6/13.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class CJZFWebView;

@class CJZFRcAdTaskModel;

@interface CJZFRcWebView : UIView

@property (nonatomic, strong) CJZFWebView *webView;
/// 当前运行渠道
@property (nonatomic, readonly, copy) NSString *channel;
/// 是否在加载中
@property (nonatomic, readonly, assign) BOOL isLoading;

@property (nonatomic, readonly, strong) NSDate *lastStartLoadDate;

- (void)loadTask:(CJZFRcAdTaskModel *)taskModel js:(NSString *)js;

- (void)cancelLoad;

@end

NS_ASSUME_NONNULL_END
