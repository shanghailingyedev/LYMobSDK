//
//  NativeViewController.m
//  CJModileAdDemo
//
//  Created by CJ on 2022/3/7.
//

#import "NativeViewController.h"
#import <CJMobileAd/CJMobileAd.h>
#import "CJMobilePublic.h"
#import <Masonry/Masonry.h>

@interface NativeViewController ()<CJNativeAdDelegate, UITableViewDelegate, UITableViewDataSource, UIScrollViewDelegate>

@property (nonatomic, strong) CJNativeAd *nativeAd;

@property (nonatomic, strong) UITableView *tableView;

@property (nonatomic, strong) UIView *nativeView;

@property (nonatomic, strong) NSMutableArray <UIView *>*nativeAdViews;

@end

@implementation NativeViewController

@synthesize customView = _customView;

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setupUI];
    [self loadAdData];
}

- (void)dealloc
{
    NSLog(@"事件:%s", __FUNCTION__);
}

- (void)setupUI {
    self.title = @"Native";
    [self.view addSubview:self.customView];
    [self.view addSubview:self.tableView];
    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.equalTo(self.view);
        make.bottom.equalTo(self.view).offset(-64);
    }];
    self.customView.frame = CGRectMake(0, 100, 200, 200);
    self.customView.center = self.view.center;
//    self.tableView.frame = self.view.bounds;
}

- (void)loadAdData {
    self.nativeAd = [[CJNativeAd alloc] initWithSlotId:nativeId size:CGSizeMake(jScreenW, 0) rootViewController:self];
    self.nativeAd.delegate = self;
    [self.nativeAd loadAdData:3];
    for (int i = 0; i < 19; i++) {
        [self.nativeAdViews addObject:[NSString stringWithFormat:@"模拟数据 %d", i]];
    }
}

- (void)handleEvent:(NSInteger)eve {
    if (eve == 0) {
        [self loadAdData];
        return;
    }
    self.tableView.hidden = false;
    [self.tableView reloadData];
}

- (CustomShowView *)customView {
    if (!_customView) {
        _customView = [[CustomShowView alloc] init];
        __weak NativeViewController *weakSelf = self;
        _customView.event = ^(NSInteger eve) {
            [weakSelf handleEvent:eve];
        };
    }
    return _customView;
}

- (NSMutableArray<UIView *> *)nativeAdViews {
    if (!_nativeAdViews) {
        _nativeAdViews = [NSMutableArray new];
    }
    return _nativeAdViews;
}


- (UITableView *)tableView {
    if (!_tableView) {
        _tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStylePlain];
        _tableView.delegate = self;
        _tableView.dataSource = self;
//        _tableView.frame = CGRectMake(0, 64, jScreenW, jScreenH-64);
//        _tableView.hidden = true;
        _tableView.backgroundColor = [UIColor whiteColor];
        _tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        [_tableView registerClass:UITableViewCell.class forCellReuseIdentifier:@"TextCell"];
        [_tableView registerClass:UITableViewCell.class forCellReuseIdentifier:@"AdCell"];
    }
    return _tableView;
}


#pragma mark delegate datasource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.nativeAdViews.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    id item = self.nativeAdViews[indexPath.row];
    if ([item isKindOfClass:[UIView class]]) {
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"AdCell" forIndexPath:indexPath];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        UIView *adView = (UIView *)item;
        
        for (UIView *v in cell.contentView.subviews) {
            [v removeFromSuperview];
        }
        
        if (adView.superview) {
            [adView removeFromSuperview];
        }
        
        CGRect frame = adView.frame;
        frame.origin = CGPointZero;
        frame.size.width = UIScreen.mainScreen.bounds.size.width;
        adView.frame = frame;
        cell.backgroundColor = [UIColor whiteColor];
        
        [cell.contentView addSubview:adView];
        return cell;
    } else {
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"TextCell" forIndexPath:indexPath];
        cell.textLabel.text = [NSString stringWithFormat:@"%@", item];
        return cell;
    }
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    id item = self.nativeAdViews[indexPath.row];
    if ([item isKindOfClass:[UIView class]]) {
//        return jScreenW*3/4;
        UIView *adView = (UIView *)item;
        return adView.frame.size.height > 0 ? adView.frame.size.height : 0.01;
    }
    return 60;
}


#pragma mark CJNativeAdDelegate
- (void)nativeExpressAdDidLoad:(id)nativeExpressAd views:(NSArray *)nativeExpressViews {
    NSLog(@"事件:%s", __FUNCTION__);
    UIView *nativeView = nativeExpressViews.firstObject;
    NSLog(@"adview size:%@",[NSValue valueWithCGSize:nativeView.frame.size]);
    CGRect frame = nativeView.frame;
    frame.origin.y = 88;
    nativeView.frame = frame;
    self.nativeView = [nativeExpressViews firstObject];
    [self.nativeAdViews insertObject:self.nativeView atIndex:4];
    NSLog(@"nativeAdViews.count ---%ld", self.nativeAdViews.count);
    NSLog(@"plat-----------%@", [self.nativeAd getAdType]);
    NSLog(@"cpm-----------%ld", [self.nativeAd getECpm]);
    [self.tableView reloadData];
}

- (void)nativeExpressAdOnShow:(id)nativeExpressView {
    NSLog(@"事件:%s", __FUNCTION__);
}

- (void)nativeExpressAdLoadFailed:(id)nativeExpressAd error:(NSError *)error {
    NSLog(@"事件:%s", __FUNCTION__);
    [self.customView canShowStatus:false errorMsg:error.description];
}

- (void)nativeExpressAdOnClicked:(id)nativeExpressView {
    NSLog(@"事件:%s", __FUNCTION__);
}

- (void)nativeExpressAdOnClosed:(id)nativeExpressView {
    NSLog(@"事件:%s", __FUNCTION__);
    if ([nativeExpressView isKindOfClass:[CJNativeAd class]]) {
        CJNativeAd *nativeAd = (CJNativeAd *)nativeExpressView;
//        [nativeAd.adView removeFromSuperview];
//        nativeAd = nil;
    }
}

@end
