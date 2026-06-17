//
//  CJZFCGUtilities.h
//  CJZFUtilsKit-code
//
//  Created by 早范 on 2025/1/28.
//  
//

#import <UIKit/UIKit.h>

CGFloat CJZFScreenScale(void);

CGSize CJZFScreenSize(void);

/// 状态栏高度
FOUNDATION_EXTERN CGFloat CJZFStatusBarHeight(void);

// main screen's scale
#ifndef kCJZFScreenScale
#define kCJZFScreenScale CJZFScreenScale()
#endif

// main screen's size (portrait)
#ifndef kCJZFScreenSize
#define kCJZFScreenSize CJZFScreenSize()
#endif

// main screen's width (portrait)
#ifndef kCJZFScreenWidth
#define kCJZFScreenWidth CJZFScreenSize().width
#endif

// main screen's height (portrait)
#ifndef kCJZFScreenHeight
#define kCJZFScreenHeight CJZFScreenSize().height
#endif

#ifndef kStatusBarHeight
#define kStatusBarHeight CJZFStatusBarHeight()
#endif

