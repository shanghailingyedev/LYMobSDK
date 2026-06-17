//
//  CJZFNetworkingError.h
//  CJZFNetworking
//
//  Created by 早范 on 2025/7/10.
//  
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSError * CJZFNetworkErrorWithUserInfo(NSErrorDomain domain, NSInteger code, NSDictionary *userInfo);

FOUNDATION_EXPORT NSError * CJZFNetworkErrorWithLocalizedDesc(NSErrorDomain domain, NSInteger code, NSString *localizedDescription);

FOUNDATION_EXPORT NSError * CJZFNetworkErrorWithUnderlyingError(NSError *error, NSError *underlyingError);

FOUNDATION_EXPORT BOOL CJZFNetworkErrorOrUnderlyingErrorHasCodeInDomain(NSError *error, NSInteger code, NSString *domain);
