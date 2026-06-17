//
//  CJZFWebView.h
//  WebViewTest
//
//  Created by 早范 on 2025/7/25.
//  
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "CJZFWeakScriptMessageDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class CJZFWebView;

@protocol CJZFWebViewDelegate <NSObject>

@optional

- (BOOL)webView:(CJZFWebView *)webView shouldStartLoadWithRequest:(nonnull NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;

- (void)webviewDidStartLoad:(CJZFWebView *)webView;

- (void)webViewDidFinishLoad:(CJZFWebView *)webView;

- (void)webView:(CJZFWebView *)webView didFailLoadWithError:(nonnull NSError *)error;

@end

typedef void (^CJZFWebViewJavascriptEvaluationCompletionHandler)(id result, NSError *error);
typedef void (^CJZFWebViewScriptMessageHandler)(WKUserContentController *controller, WKScriptMessage *message);

@interface CJZFWebView : UIView

@property (nonatomic, weak) id<CJZFWebViewDelegate> delegate;

@property (nonatomic, readonly, getter=isLoading) BOOL loading;

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= MP_IOS_9_0
@property (nonatomic) BOOL allowsLinkPreview;
@property (nonatomic, readonly) BOOL allowsPictureInPictureMediaPlayback;
#endif


- (void)loadHTMLString:(NSString *)string baseURL:(nullable NSURL *)baseURL;

- (void)loadRequest:(NSURLRequest *)request;
- (void)stopLoading;
- (void)reload;

@property (nonatomic) BOOL scalesPageToFit;
// default is 'NO'
@property (nonatomic) BOOL forbiddenUserSelect;
@property (nonatomic, readonly) UIScrollView *scrollView;
// only available in WKWebView
@property (nonatomic, readonly) WKWebViewConfiguration *wkConfiguration;

- (void)evaluateJavaScript:(NSString *)javaScriptString completionHandler:(_Nullable CJZFWebViewJavascriptEvaluationCompletionHandler)completionHandler;
- (void)addScriptMessageHandlerForName:(NSString *_Nonnull)name handler:(CJZFWebViewScriptMessageHandler)handler;

@property (nonatomic, readonly) BOOL allowsInlineMediaPlayback;
@property (nonatomic, readonly) BOOL mediaPlaybackRequiresUserAction;
@property (nonatomic, readonly) BOOL mediaplaybackallowsAirplay;

@end

NS_ASSUME_NONNULL_END
