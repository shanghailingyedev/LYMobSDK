// UIKit+CJZFNewNetworking.h

#import <TargetConditionals.h>

#ifndef _UIKIT_CJZFNewNETWORKING_
    #define _UIKIT_CJZFNewNETWORKING_

#if TARGET_OS_IOS || TARGET_OS_TV
    #import "CJZFNewAutoPurgingImageCache.h"
    #import "CJZFNewImageDownloader.h"
    #import "UIActivityIndicatorView+CJZFNewNetworking.h"
    #import "UIButton+CJZFNewNetworking.h"
    #import "UIImageView+CJZFNewNetworking.h"
    #import "UIProgressView+CJZFNewNetworking.h"
#endif

#if TARGET_OS_IOS
    #import "CJZFNewNetworkActivityIndicatorManager.h"
    #import "UIRefreshControl+CJZFNewNetworking.h"
    #import "WKWebView+CJZFNewNetworking.h"
#endif

#endif /* _UIKIT_CJZFNewNETWORKING_ */
