//
//  CJSceneManager.h
//  CJMobileAd
//
//  Created by shanghailingye on 2022/12/2.
//  Copyright © 2022 Jun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CJMobileAd/CJSceneRequest.h>

NS_ASSUME_NONNULL_BEGIN

@interface CJSceneManager : NSObject

// 加载并展示场景模块
+ (void)loadAndShowModuleWithSceneRequest:(CJSceneRequest *)request;

/// uni H5控制器获取
/// - Parameter url: 网页地址
+ (UIViewController *)setupH5AppMainController:(NSString *)url;

@end

NS_ASSUME_NONNULL_END
