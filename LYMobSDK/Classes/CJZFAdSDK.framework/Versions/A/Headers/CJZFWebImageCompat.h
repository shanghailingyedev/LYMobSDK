//
//  CJZFWebImageCompat.h
//  CJZFAdSDK-Kit
//
//  Created by 早范 on 2025/9/10.
//

#ifndef CJZFWebImageCompat_h
#define CJZFWebImageCompat_h

#define CJZF_MAC 0

#define CJZF_UIKIT 1

#define CJZF_IOS 1

#define CJZF_TV 0

#define CJZF_WATCH 0

// Supports Xcode 14 to suppress warning
#define CJZF_VISION 0

#ifndef NS_ENUM
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#endif

#ifndef NS_OPTIONS
#define NS_OPTIONS(_type, _name) enum _name : _type _name; enum _name : _type
#endif

#endif /* CJZFWebImageCompat_h */
