//
//  CJZFChannelAlertView.h
//  CJZFAdSDK-Channel
//
//  Created by 早范 on 2025/9/8.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface CJZFChannelAlertView : NSObject

@property (nonatomic, copy) void (^clickConfirm)(CGPoint point, CGPoint sPoint);

- (void)showAlert:(UIViewController *)viewController point:(CGPoint)point sPoint:(CGPoint)sPoint;

@end

NS_ASSUME_NONNULL_END
