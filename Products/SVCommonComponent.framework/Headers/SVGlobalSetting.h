//
//  SVGlobalSetting.h
//  SVCommonComponent
//
//  Created by shuvigoss on 15-4-2.
//  Copyright (c) 2015年 com.shuvigoss. All rights reserved.
//  全局设置

#ifndef SVCommonComponent_SVGlobalSetting_h
#define SVCommonComponent_SVGlobalSetting_h

//设置status 为透明 ios7+ 设置步骤：在info.plist View controller-based status bar appearance 设置为NO
#define SV_SETTING_STATUS_BAR_LIGHT             [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent]
#define SV_SETTING_STATUS_BAR_LIGHT_ANIMATION   [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent animated:YES]
#define SV_SETTING_STATUS_BAR_HIDE              [[UIApplication sharedApplication] setStatusBarHidden:YES]
#define SV_SETTING_STATUS_BAR_SHOW              [[UIApplication sharedApplication] setStatusBarHidden:NO]



#endif
