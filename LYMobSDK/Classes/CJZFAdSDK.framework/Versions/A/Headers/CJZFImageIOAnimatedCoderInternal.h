/*
* This file is part of the CJZFWebImage package.
* (c) Olivier Poitrey <>
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <ImageIO/ImageIO.h>
#import "CJZFImageIOAnimatedCoder.h"

// AVFileTypeHEIC/AVFileTypeHEIF is defined in AVFoundation via iOS 11, we use this without import AVFoundation
#define kCJZFUTTypeGIFHEIC  ((__bridge CFStringRef)@"public.heic")
#define kCJZFUTTypeGIFHEIF  ((__bridge CFStringRef)@"public.heif")
// HEIC Sequence (Animated Image)
#define kCJZFUTTypeGIFHEICS ((__bridge CFStringRef)@"public.heics")
// kCJZFUTTypeGIFWebP seems not defined in public UTI framework, Apple use the hardcode string, we define them :)
#define kCJZFUTTypeGIFWebP  ((__bridge CFStringRef)@"org.webmproject.webp")

#define kCJZFUTTypeGIFImage ((__bridge CFStringRef)@"public.image")
#define kCJZFUTTypeGIFJPEG  ((__bridge CFStringRef)@"public.jpeg")
#define kCJZFUTTypeGIFPNG   ((__bridge CFStringRef)@"public.png")
#define kCJZFUTTypeGIFTIFF  ((__bridge CFStringRef)@"public.tiff")
#define kCJZFUTTypeGIFSVG   ((__bridge CFStringRef)@"public.svg-image")
#define kCJZFUTTypeGIFGIF   ((__bridge CFStringRef)@"com.compuserve.gif")
#define kCJZFUTTypeGIFPDF   ((__bridge CFStringRef)@"com.adobe.pdf")
#define kCJZFUTTypeGIFBMP   ((__bridge CFStringRef)@"com.microsoft.bmp")
#define kCJZFUTTypeGIFRAW   ((__bridge CFStringRef)@"public.camera-raw-image")

@interface CJZFImageIOAnimatedCoder ()

+ (NSTimeInterval)frameDurationAtIndex:(NSUInteger)index source:(nonnull CGImageSourceRef)source;
+ (NSUInteger)imageLoopCountWithSource:(nonnull CGImageSourceRef)source;
+ (nullable UIImage *)createFrameAtIndex:(NSUInteger)index source:(nonnull CGImageSourceRef)source scale:(CGFloat)scale preserveAspectRatio:(BOOL)preserveAspectRatio thumbnailSize:(CGSize)thumbnailSize lazyDecode:(BOOL)lazyDecode animatedImage:(BOOL)animatedImage;
+ (BOOL)canEncodeToFormat:(CJZFImageFormat)format;
+ (BOOL)canDecodeFromFormat:(CJZFImageFormat)format;

@end
