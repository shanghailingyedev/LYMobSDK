//
//  CJZFLogging.h
//
//  Created by 早范 on 2025/7/12.
//  
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, CJZFLogLevel) {
    /// No logs
    CJZFLogLevelOff     = 0,
    /// Error logs only. 0...00001
    CJZFLogLevelError   = (1 << 0),
    /// Error and warning logs, 0...00010
    CJZFLogLevelWarning = (1 << 1),
    /// Error, warning, track logs, 0...00011
    CJZFLogLevelTrack   = 3,
    /// Error, warning and info logs, 0...00100
    CJZFLogLevelInfo    = (1 << 2),
    /// Error, warning, info and debug logs, 0...01000
    CJZFLogLevelDebug   = (1 << 3),
    /// Error, warning, info, debug and verbose logs, 0...10000
    CJZFLogLevelVerbose = (1 << 4),
    /// All logs. 1...11111
    CJZFLogLevelAll     = NSUIntegerMax
};

/// default is 'CJZFLogLevelInfo' if not set
CJZFLogLevel CJZFLogGetLevel(void);
void CJZFLogSetLevel(CJZFLogLevel level);

void _CJZFLogError(NSString *format, ...);
void _CJZFLogWarn(NSString *format, ...);
void _CJZFLogTrack(NSString *format, ...);
void _CJZFLogInfo(NSString *format, ...);
void _CJZFLogDebug(NSString *format, ...);
void _CJZFLogVerbose(NSString *format, ...);

#ifdef DEBUG
    #define CJZFLogError(...)   _CJZFLogError(__VA_ARGS__)
    #define CJZFLogWarn(...)    _CJZFLogWarn(__VA_ARGS__)
    #define CJZFLogTrack(...)    _CJZFLogTrack(__VA_ARGS__)
    #define CJZFLogInfo(...)    _CJZFLogInfo(__VA_ARGS__)
    #define CJZFLogDebug(...)   _CJZFLogDebug(__VA_ARGS__)
    #define CJZFLogVerbose(...) _CJZFLogVerbose(__VA_ARGS__)
#else
    #define CJZFLogError(...)   _CJZFLogError(__VA_ARGS__)
    #define CJZFLogWarn(...)    _CJZFLogWarn(__VA_ARGS__)
    #define CJZFLogTrack(...)    _CJZFLogTrack(__VA_ARGS__)
    #define CJZFLogInfo(...)    _CJZFLogInfo(__VA_ARGS__)
    #define CJZFLogDebug(...)   _CJZFLogDebug(__VA_ARGS__)
    #define CJZFLogVerbose(...) {}
#endif






