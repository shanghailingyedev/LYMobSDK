//
//  CJZFAdapterCommonDefine.h
//  CJZFAdSDK
//
//  Created by 早范 on 2025/3/12.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN


typedef NSString * CJZFAdapterAdType NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXPORT CJZFAdapterAdType _Nonnull const CJZFAdapterAdTypeOther;

FOUNDATION_EXPORT CJZFAdapterAdType _Nonnull const CJZFAdapterAdTypeSplash;

FOUNDATION_EXPORT CJZFAdapterAdType _Nonnull const CJZFAdapterAdTypeBanner;

FOUNDATION_EXPORT CJZFAdapterAdType _Nonnull const CJZFAdapterAdTypeGame;

FOUNDATION_EXPORT CJZFAdapterAdType _Nonnull const CJZFAdapterAdTypeNative;

FOUNDATION_EXPORT CJZFAdapterAdType _Nonnull const CJZFAdapterAdTypeNativeExpress;

FOUNDATION_EXPORT CJZFAdapterAdType _Nonnull const CJZFAdapterAdTypeRewardvod;

FOUNDATION_EXPORT CJZFAdapterAdType _Nonnull const CJZFAdapterAdTypeInterstitial;

FOUNDATION_EXPORT CJZFAdapterAdType _Nonnull const CJZFAdapterAdTypeFullScreenVod;

FOUNDATION_EXPORT CJZFAdapterAdType _Nonnull const CJZFAdapterAdTypeDrawvod;


typedef NSString * CJZFAdapterPlatform NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXPORT CJZFAdapterPlatform _Nonnull const CJZFAdapterPlatformOther;

FOUNDATION_EXPORT CJZFAdapterPlatform _Nonnull const CJZFAdapterPlatformGDT;

FOUNDATION_EXPORT CJZFAdapterPlatform _Nonnull const CJZFAdapterPlatformBU;

FOUNDATION_EXPORT CJZFAdapterPlatform _Nonnull const CJZFAdapterPlatformBaidu;

FOUNDATION_EXPORT CJZFAdapterPlatform _Nonnull const CJZFAdapterPlatformBWT;

FOUNDATION_EXPORT CJZFAdapterPlatform _Nonnull const CJZFAdapterPlatformChannel;

FOUNDATION_EXPORT CJZFAdapterPlatform _Nonnull const CJZFAdapterPlatformZhike;

FOUNDATION_EXPORT CJZFAdapterPlatform _Nonnull const CJZFAdapterPlatformRc;

FOUNDATION_EXPORT CJZFAdapterPlatform _Nonnull const CJZFAdapterPlatformMobTech;

FOUNDATION_EXPORT CJZFAdapterPlatform _Nonnull const CJZFAdapterPlatformAdMob;

FOUNDATION_EXPORT CJZFAdapterPlatform _Nonnull const CJZFAdapterPlatformDuoMeng;

typedef NSString * CJZFAdapterReportStatus NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXPORT CJZFAdapterReportStatus _Nonnull const CJZFAdapterReportStatusRequest;

FOUNDATION_EXPORT CJZFAdapterReportStatus _Nonnull const CJZFAdapterReportStatusSuccess;

FOUNDATION_EXPORT CJZFAdapterReportStatus _Nonnull const CJZFAdapterReportStatusDisplay;

FOUNDATION_EXPORT CJZFAdapterReportStatus _Nonnull const CJZFAdapterReportStatusClick;

FOUNDATION_EXPORT CJZFAdapterReportStatus _Nonnull const CJZFAdapterReportStatusClose;

FOUNDATION_EXPORT CJZFAdapterReportStatus _Nonnull const CJZFAdapterReportStatusFailed;

FOUNDATION_EXPORT CJZFAdapterReportStatus _Nonnull const CJZFAdapterReportStatusRewarded;

FOUNDATION_EXPORT CJZFAdapterReportStatus _Nonnull const CJZFAdapterReportStatusQuarter;

FOUNDATION_EXPORT CJZFAdapterReportStatus _Nonnull const CJZFAdapterReportStatusHalf;

FOUNDATION_EXPORT CJZFAdapterReportStatus _Nonnull const CJZFAdapterReportStatusThreeQuarter;

FOUNDATION_EXPORT CJZFAdapterReportStatus _Nonnull const CJZFAdapterReportStatusFinish;

FOUNDATION_EXPORT CJZFAdapterReportStatus _Nonnull const CJZFAdapterReportStatusStart;

FOUNDATION_EXPORT CJZFAdapterReportStatus _Nonnull const CJZFAdapterReportStatusSkip;

FOUNDATION_EXPORT CJZFAdapterReportStatus _Nonnull const CJZFAdapterReportStatusRecover;

FOUNDATION_EXPORT CJZFAdapterReportStatus _Nonnull const CJZFAdapterReportStatusPause;

FOUNDATION_EXPORT CJZFAdapterReportStatus _Nonnull const CJZFAdapterReportStatusMuted;

typedef NSString * CJZFAdapterNativeExpressType NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXPORT CJZFAdapterNativeExpressType _Nonnull const CJZFAdapterNativeExpressTypeLeft;

FOUNDATION_EXPORT CJZFAdapterNativeExpressType _Nonnull const CJZFAdapterNativeExpressTypeImage;

FOUNDATION_EXPORT CJZFAdapterNativeExpressType _Nonnull const CJZFAdapterNativeExpressTypeVerticalImage;

typedef NSString * CJZFAdSDKNativeAdMobAssetType NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXPORT CJZFAdSDKNativeAdMobAssetType _Nonnull const CJZFAdSDKNativeAdMobAssetTypeHeadline;

FOUNDATION_EXPORT CJZFAdSDKNativeAdMobAssetType _Nonnull const CJZFAdSDKNativeAdMobAssetTypeIcon;

FOUNDATION_EXPORT CJZFAdSDKNativeAdMobAssetType _Nonnull const CJZFAdSDKNativeAdMobAssetTypeBody;

FOUNDATION_EXPORT CJZFAdSDKNativeAdMobAssetType _Nonnull const CJZFAdSDKNativeAdMobAssetTypeImage;

FOUNDATION_EXPORT CJZFAdSDKNativeAdMobAssetType _Nonnull const CJZFAdSDKNativeAdMobAssetTypeAdvertiser;

FOUNDATION_EXPORT CJZFAdSDKNativeAdMobAssetType _Nonnull const CJZFAdSDKNativeAdMobAssetTypeAdChoicesView;

@interface CJZFAdapterCommonDefine : NSObject

/**
 SDK Version
 */
+ (NSString *)getSDKVersion;

+ (UIImage *)closeImage;

+ (UIImage *)serviceCloseImage;

+ (UIImage *)bwtLogoImage;

+ (UIImage *)channelLogoImage;

+ (NSData *)imageData;

+ (UIImage *)videoMutedImage;

+ (UIImage *)videoNoMutedImage;

+ (NSData *)shakeImageData;

+ (NSData *)openImageData;

+ (UIImage *)openImage;

@end

NS_ASSUME_NONNULL_END
