//
//  CJZFWeakScriptMessageDelegate.h
//  CJZFCore
//
//  Created by 早范 on 2025/7/27.
//  
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

@interface CJZFWeakScriptMessageDelegate : NSObject <WKScriptMessageHandler>

@property (nonatomic, weak) id<WKScriptMessageHandler> scriptDelegate;

- (instancetype)initWithDelegate:(id<WKScriptMessageHandler>)scriptDelegate;

@end
