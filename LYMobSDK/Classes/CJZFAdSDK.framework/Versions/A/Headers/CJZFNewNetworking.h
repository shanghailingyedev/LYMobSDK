

#import <Foundation/Foundation.h>
#import <Availability.h>
#import <TargetConditionals.h>

#ifndef _CJZFNewNETWORKING_
    #define _CJZFNewNETWORKING_

    #import "CJZFNewURLRequestSerialization.h"
    #import "CJZFNewURLResponseSerialization.h"
    #import "CJZFNewSecurityPolicy.h"

#if !TARGET_OS_WATCH
    #import "CJZFNewNetworkReachabilityManager.h"
#endif

    #import "CJZFNewURLSessionManager.h"
    #import "CJZFNewHTTPSessionManager.h"

#endif /* _CJZFNewNETWORKING_ */
