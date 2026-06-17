//
//  CJZFAdapterNativeAdData.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/5/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CJZFAdapterNativeAdData : NSObject

/**
 标题
 */
@property (nonatomic, copy, nullable, readonly) NSString *title;

/**
 描述
 */
@property (nonatomic, copy, nullable, readonly) NSString *desc;

/**
 封面大图
 */
@property (nonatomic, copy, nullable, readonly) NSString *imageUrl;

/**
 图片列表
 */
@property (nonatomic, copy, nullable, readonly) NSArray<NSString *> *imageUrlAry;

/**
 icon图片
 */
@property (nonatomic, strong, nullable, readonly) NSString *iconImageUrl;

@property (nonatomic, assign) NSInteger countDown;

/**
 是否需要显示多媒体View（当素材为视频素材时，或者没有图片素材，需要调用获取广告视图方法）
 */
@property (nonatomic, assign, readonly) BOOL shouldShowMediaView;

@end

NS_ASSUME_NONNULL_END
