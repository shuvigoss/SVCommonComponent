//
//  SVDevice.h
//  SVCommonComponent
//
//  Created by shuvigoss on 15-4-1.
//  Copyright (c) 2015年 com.shuvigoss. All rights reserved.
//
//设备相关的宏

#ifndef SVCommonComponent_SVDevice_h
#define SVCommonComponent_SVDevice_h

#pragma mark 版本
#define SVDEVICE_SYSTEMVERSION        [[UIDevice currentDevice] systemVersion]
#define SVDEVICE_SYSTEMVERSION_FLOAT  [[[UIDevice currentDevice] systemVersion] floatValue]

#pragma mark 屏幕
#define SVDEVICE_SCREEN_WIDTH         [[UIScreen mainScreen] bounds].size.width
#define SVDEVICE_SCREEN_HEIGHT        [[UIScreen mainScreen] bounds].size.height

#pragma mark 设备iphone ipod ipad
#define SVDEVICE_DEVICE_TYPE          [[UIDevice currentDevice] model]
#define SVDEVICE_IS_SIMULATOR         TARGET_IPHONE_SIMULATOR
#define SVDEVICE_IS_IPHONE            [[[UIDevice currentDevice] model] isEqualToString: @"iPhone"]
#define SVDEVICE_IS_IPOD              [[[UIDevice currentDevice] model] isEqualToString: @"iPod touch"]
#define SVDEVICE_IS_IPAD              [[[UIDevice currentDevice] model] isEqualToString: @"iPad"]


#endif
