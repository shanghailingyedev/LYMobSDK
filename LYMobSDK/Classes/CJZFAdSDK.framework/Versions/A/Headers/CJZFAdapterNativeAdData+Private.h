//
//  CJZFAdapterNativeAdData+Private.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/5/4.
//

#import "CJZFAdapterNativeAdData.h"

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterNativeAdData ()

- (id)new NS_UNAVAILABLE;
- (id)init NS_UNAVAILABLE;

- (instancetype)initWithTitle:(NSString *)title
                      content:(NSString *)content
          imageUrlStringArray:(NSArray<NSString *> *)imageUrlStringArray
                    iconImage:(nullable UIImage *)iconImage
                 iconImageUrl:(nullable NSString *)iconImageUrl
          shouldShowMediaView:(BOOL)shouldShowMediaView
                    countDown:(NSInteger)countDown;

@end

NS_ASSUME_NONNULL_END
