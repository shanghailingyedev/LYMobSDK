//
//  CJZFHttpRequest+Internal.h
//  CJZFNetworking
//
//  Created by 早范 on 2025/7/10.
//  
//

#import "CJZFHttpRequest.h"

@interface CJZFHttpRequest ()

@property (nonatomic, strong, readwrite) NSURLSessionTask *requestTask;
@property (nonatomic, strong, readwrite) id responseObject;
@property (nonatomic, strong, readwrite) NSError *error;

- (void)clearCompletionBlock;

@end
