//
//  SVStatusBarNotification.h
//  SVCommonComponent
//
//  Created by shuvigoss on 15-4-8.
//  Copyright (c) 2015年 com.shuvigoss. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
@class SVStatusBarView, SVStatusConfig;

@interface SVStatusBarNotification : NSObject

+ (void)lockConfig;
+ (void)addConfig:(SVStatusConfig *)config withName:(NSString *)name;
+ (void)unlockConfig;

+ (void)showNotification:(NSString *)message;
+ (void)showNotification:(NSString *)message withConfigName:(NSString *)name;

+ (void)dismissNow;
+ (void)dismissAfter:(NSTimeInterval)timeInterval;
@end


@interface SVStatusBarView : UIView
@property(nonatomic, strong) UILabel *textLabel;
@end

@interface SVStatusConfig : NSObject

@property(nonatomic, strong) UILabel *textLabel;
@property(nonatomic, strong) UIColor *backgroundColor;

@end

@interface SVStatusWindowController : UIViewController

@end