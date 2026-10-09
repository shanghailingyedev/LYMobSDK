//
//  CJFeedAdMaterial.h
//  CJMobileAd
//
//  Created by shanghailingye on 2024/4/9.
//  Copyright © 2024 Jun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class CJFeedAdImage;
@class CJFeedAdVideo;
typedef NS_ENUM(NSInteger, CJMaterialType) {
    CJMaterialTypeUnknow = 0,   // 未知素材
    CJMaterialTypeSingle = 1,   // 单图素材
    CJMaterialTypeAtlas  = 2,   // 多图素材
    CJMaterialTypeVideo  = 3,   // 视频素材
};

NS_ASSUME_NONNULL_BEGIN

@interface CJFeedAdMaterial : NSObject

/// 素材类型
@property (nonatomic, assign, readonly) CJMaterialType materialType;
/// 广告是否有效
@property (nonatomic, assign, readonly) BOOL isAdValid;
/// 广告标题
@property (nonatomic, copy, readonly)   NSString *title;
/// 广告描述
@property (nonatomic, copy, readonly)   NSString *desc;
/// 为图片资源时有值（单图类型为1）
@property (nonatomic, strong, readonly) NSArray<CJFeedAdImage *> *mediaUrlList;
/// 应用类广告App 图标Url
@property (nonatomic, strong, readonly) CJFeedAdImage *iconImage;
/// 视频资源
@property (nonatomic, strong, readonly) CJFeedAdVideo *videoResource;

@property (nonatomic, strong, readonly) UIView *videoView;

- (void)setupPlatMaterial:(id)material;

@end

#pragma mark 图片素材信息
@interface CJFeedAdImage : NSObject

/// 图片素材地址
@property (nonatomic, copy) NSString *imageURL;

/// 图片宽度
@property (nonatomic, assign) float width;

/// 图片高度
@property (nonatomic, assign) float height;

@end

#pragma mark 视频素材信息
@interface CJFeedAdVideo : NSObject

/// 可能为空，不建议使用自制播放器
@property (nonatomic, copy)   NSString *videoUrl;
/// 为空时，传入固定比例
@property (nonatomic, assign) CGFloat width;
/// 为空时，传入固定比例
@property (nonatomic, assign) CGFloat height;
/// 视频时长
@property (nonatomic, assign) CGFloat duration;

@end

NS_ASSUME_NONNULL_END
