//
//  CJZFTimer.h
//  CJZFCore
//
//  Created by 早范 on 2025/7/12.
//  
//

#import <Foundation/Foundation.h>

@interface CJZFTimer : NSObject

/// default is 'NSDefaultRunLoopMode'
@property (nonatomic, copy) NSRunLoopMode runLoopMode;

+ (NSTimeInterval)currentTimeInterval;

+ (CJZFTimer *)timerWithTimeInterval:(NSTimeInterval)ti
                              target:(id)aTarget
                            selector:(SEL)aSelector
                             repeats:(BOOL)yesOrNo;

@property (readonly, assign) NSTimeInterval timeInterval;
@property (readonly, getter=isValid) BOOL valid;
@property (readonly, getter=isScheduled) BOOL scheduled;

- (void)invalidate;
- (BOOL)scheduleImmediately:(BOOL)immediately;
- (BOOL)pause;
- (BOOL)resume;

@end
