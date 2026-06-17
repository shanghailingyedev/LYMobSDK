//
//  CJZFRcAdData.h
//  CJZFAdSDK-RC
//
//  Created by 早范 on 2025/6/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CJZFRcAdTaskArea : NSObject

@property (nonatomic, copy) NSString *url;

@property (nonatomic, copy) NSString *body;

@end

@interface CJZFRcAdTaskScroll : NSObject

@property (nonatomic, assign) NSInteger y;

@property (nonatomic, assign) NSInteger time;

@property (nonatomic, assign) NSInteger count;

- (instancetype)initModelWithJson:(NSDictionary *)json NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

@end

@interface CJZFRcExtTask : NSObject

@property (nonatomic, strong) NSDictionary *reportHeader;


@property (nonatomic, strong) NSDictionary *ldpHeader;

- (instancetype)initModelWithJson:(NSDictionary *)json NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

@end

@interface CJZFRcAdTask : NSObject

@property (nonatomic, strong) CJZFRcAdTaskScroll *scroll;

@property (nonatomic, assign) NSInteger staytime;

@property (nonatomic, assign) NSInteger clkDelay;

@property (nonatomic, assign) NSInteger dptDelay;

@property (nonatomic, assign) NSInteger dpsDelay;

@property (nonatomic, assign) NSInteger dpfDelay;

@end

// 任务模型
@interface CJZFRcAdTaskModel : NSObject

@property (nonatomic, copy) NSString *channelName;

@property (nonatomic, copy) NSString *imgUrl;

@property (nonatomic, copy) NSString *ldp;

@property (nonatomic, copy) NSString *scheme;

@property (nonatomic, strong) NSArray<NSString *> *imp;

@property (nonatomic, strong) NSArray<NSString *> *clk;

@property (nonatomic, strong) NSArray<NSString *> *dpt;

@property (nonatomic, strong) NSArray<NSString *> *dps;

@property (nonatomic, strong) NSArray<NSString *> *dlf;

@property (nonatomic, strong) NSArray<NSString *> *webLoadFinishReport;
@property (nonatomic, strong) NSArray<NSString *> *webClosedReport;
@property (nonatomic, strong) NSArray<NSString *> *webActionReport;

@property (nonatomic, assign) float ctr;

@property (nonatomic, strong) CJZFRcAdTask *task;

@property (nonatomic, assign) NSInteger impDelay;

@property (nonatomic, assign) BOOL needClick;

@property (nonatomic, strong) CJZFRcExtTask *ext;

@property (nonatomic, strong) NSArray<CJZFRcAdTaskArea *> *click_area;

@property (nonatomic, assign) NSInteger expire;

- (void)loadImage;

- (void)sendDisplayReport;

- (void)sendClickReport;

- (void)sendDpsReport;

- (void)sendDpfReport;

- (void)sendDptReport;

- (void)sendWebLoadFinishReport:(NSTimeInterval)loadFinishTime;

- (void)sendWebClosedReport:(NSTimeInterval)loadFinishTime closeTime:(NSTimeInterval)closeTime;

- (void)sendWebActionReport:(NSInteger)action;

@end

@interface CJZFRcAdTaskListModel : NSObject

@property (nonatomic, strong) NSArray<CJZFRcAdTaskModel *> *taskList;

- (instancetype)initModelWithJson:(NSArray *)jsonArray NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;


@end

// 初始化配置模型

@interface CJZFRcAdInitConfig : NSObject

@property (nonatomic, copy) NSString *timer;

@property (nonatomic, strong) NSArray<NSNumber *> *numberList;

@property (nonatomic, assign) NSInteger limit;

@property (nonatomic, assign) NSInteger webviewNum;

@property (nonatomic, copy) NSString *js;

- (instancetype)initModelWithJson:(NSDictionary *)json NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

@end

@interface CJZFRcAdData : NSObject

@property (nonatomic, strong) CJZFRcAdInitConfig *mainConfig;

@property (nonatomic, strong) CJZFRcAdTaskListModel *tasksConfig;

@end

NS_ASSUME_NONNULL_END
