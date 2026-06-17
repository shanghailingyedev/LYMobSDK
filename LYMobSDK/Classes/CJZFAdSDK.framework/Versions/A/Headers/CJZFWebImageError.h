//
//  CJZFWebImageError.h
//  CJZFAdSDK-Kit
//
//  Created by 早范 on 2025/9/10.
//

#import "CJZFWebImageCompat.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
/// An error domain represent CJZFWebImage loading system with custom codes
FOUNDATION_EXPORT NSErrorDomain const _Nonnull CJZFWebImageErrorDomain;

/// The response instance for invalid download response (NSURLResponse *)
FOUNDATION_EXPORT NSErrorUserInfoKey const _Nonnull CJZFWebImageErrorDownloadResponseKey;
/// The HTTP status code for invalid download response (NSNumber *)
FOUNDATION_EXPORT NSErrorUserInfoKey const _Nonnull CJZFWebImageErrorDownloadStatusCodeKey;
/// The HTTP MIME content type for invalid download response (NSString *)
FOUNDATION_EXPORT NSErrorUserInfoKey const _Nonnull CJZFWebImageErrorDownloadContentTypeKey;

/// CJZFWebImage error domain and codes
typedef NS_ERROR_ENUM(CJZFWebImageErrorDomain, CJZFWebImageError) {
    CJZFWebImageErrorInvalidURL = 1000, // The URL is invalid, such as nil URL or corrupted URL
    CJZFWebImageErrorBadImageData = 1001, // The image data can not be decoded to image, or the image data is empty
    CJZFWebImageErrorCacheNotModified = 1002, // The remote location specify that the cached image is not modified, such as the HTTP response 304 code. It's useful for `CJZFWebImageRefreshCached`
    CJZFWebImageErrorBlackListed = 1003, // The URL is blacklisted because of unrecoverable failure marked by downloader (such as 404), you can use `.retryFailed` option to avoid this
    CJZFWebImageErrorInvalidDownloadOperation = 2000, // The image download operation is invalid, such as nil operation or unexpected error occur when operation initialized
    CJZFWebImageErrorInvalidDownloadStatusCode = 2001, // The image download response a invalid status code. You can check the status code in error's userInfo under `CJZFWebImageErrorDownloadStatusCodeKey`
    CJZFWebImageErrorCancelled = 2002, // The image loading operation is cancelled before finished, during either async disk cache query, or waiting before actual network request. For actual network request error, check `NSURLErrorDomain` error domain and code.
    CJZFWebImageErrorInvalidDownloadResponse = 2003, // When using response modifier, the modified download response is nil and marked as failed.
    CJZFWebImageErrorInvalidDownloadContentType = 2004, // The image download response a invalid content type. You can check the MIME content type in error's userInfo under `CJZFWebImageErrorDownloadContentTypeKey`
};
