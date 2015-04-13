//
//  SVStatusBarNotification.m
//  SVCommonComponent
//
//  Created by shuvigoss on 15-4-8.
//  Copyright (c) 2015年 com.shuvigoss. All rights reserved.
//

#define statusBarNotificationInstance [SVStatusBarNotification shareInstance]


#import "SVStatusBarNotification.h"

static NSString *const defaultStyleKey = @"statusBarNotificationDefaultKey";
@interface SVStatusBarNotification()

@property(nonatomic, strong) NSMutableDictionary *allConfig;
@property(nonatomic, assign, readonly) BOOL isLock;
@property(nonatomic, strong) UIWindow *overlayWindow;
@property(nonatomic, strong) SVStatusBarView *barView;
@property(nonatomic, strong) NSTimer *dismissTimer;
@end

@implementation SVStatusBarNotification

+ (instancetype)shareInstance{
  static dispatch_once_t once;
  static SVStatusBarNotification *statusBarNotification = nil;
  dispatch_once(&once, ^{
    statusBarNotification = [[self alloc] init];
  });
  return statusBarNotification;
}

- (instancetype)init {
  if (self = [super init]) {
    _allConfig = [NSMutableDictionary dictionary];
    [self createDefaultStyle];
    [self createOverlayWindow];
    [self createBarView];
    _isLock = NO;
  }
  return self;
}

- (void)createDefaultStyle{
  SVStatusConfig *config = [[SVStatusConfig alloc] init];
  UILabel *label = [[UILabel alloc] init];
  label.textColor = [UIColor colorWithWhite:0.95 alpha:1.0];
  label.font = [UIFont systemFontOfSize:12];
  config.textLabel = label;
  UIColor *color = [UIColor colorWithRed:0.050 green:0.078 blue:0.120 alpha:0.900];
  config.backgroundColor = color;
  [_allConfig setObject:config forKey:defaultStyleKey];
}

- (void)createOverlayWindow{
  _overlayWindow = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
  _overlayWindow.backgroundColor = [UIColor clearColor];
  _overlayWindow.rootViewController = [[SVStatusWindowController alloc] init];
  _overlayWindow.rootViewController.view.backgroundColor = [UIColor clearColor];
  _overlayWindow.userInteractionEnabled = NO;
  _overlayWindow.windowLevel = UIWindowLevelStatusBar;
}

- (void)createBarView{
  _barView = [[SVStatusBarView alloc] init];
  _barView.backgroundColor = [UIColor clearColor];
  _barView.alpha = 0;
  [_overlayWindow.rootViewController.view addSubview:_barView];
}

+ (void)lockConfig{
  [statusBarNotificationInstance lockConfig:YES];
}

+ (void)addConfig:(SVStatusConfig *)config withName:(NSString *)name{
  if (statusBarNotificationInstance.isLock) { NSLog(@"statusBarNotification config be lock...");}
  NSAssert(config != nil, @"statusBarNotification config can not be nil...");
  NSAssert(name != nil || name.length != 0, @"statusBarNotification config name can not be nil...");
  
  if ([statusBarNotificationInstance.allConfig objectForKey:name]) { NSLog(@"statusBarNotification old config(%@) will be replace...", name); }
  [statusBarNotificationInstance.allConfig setObject:config forKey:name];
}

+ (void)unlockConfig{
  [statusBarNotificationInstance lockConfig:NO];
}

- (void)lockConfig:(BOOL)bln{
  @synchronized(self){
    if (_isLock == bln) { return; }
    _isLock = bln;
  }
}

+ (void)showNotification:(NSString *)message{
  [SVStatusBarNotification showNotification:message withConfigName:defaultStyleKey];
}

+ (void)showNotification:(NSString *)message withConfigName:(NSString *)name{
  NSAssert(message != nil || message.length != 0, @"statusBarNotification message can not be nil...");
  NSAssert(name != nil || name.length != 0, @"statusBarNotification config name can not be nil...");
  
  
  SVStatusConfig *config = [statusBarNotificationInstance.allConfig objectForKey:name];
  if (!config) { config = [statusBarNotificationInstance.allConfig objectForKey:defaultStyleKey]; }
  [statusBarNotificationInstance.overlayWindow setHidden:NO];
  [statusBarNotificationInstance updateBarViewFrame:[[UIApplication sharedApplication] statusBarFrame]];
  [statusBarNotificationInstance updateBarViewStyle:config];
  statusBarNotificationInstance.barView.textLabel.text = message;
  [statusBarNotificationInstance showBarView:YES];
}


- (void)updateBarViewFrame:(CGRect)rect{
  CGFloat width = MAX(rect.size.width, rect.size.height);
  CGFloat height = MIN(rect.size.width, rect.size.height);
  // on ios7 fix position, if statusBar has double height
  CGFloat yPos = 0;
  if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0 && height > 20.0) {
    yPos = -height/2.0;
  }
  _barView.frame = CGRectMake(0, yPos, width, height);
}

- (void)updateBarViewStyle:(SVStatusConfig *)config{
  _barView.textLabel = config.textLabel;
  _barView.backgroundColor = config.backgroundColor;
}

- (void)showBarView:(BOOL)animated{
  if (animated) {
    [UIView animateWithDuration:0.4 animations:^{
        _barView.alpha = 1;
    } completion:^(BOOL finished) {}];
  }else{
    _barView.alpha = 1;
  }
}

+ (void)dismissNow{
  [statusBarNotificationInstance dismiss:0 animated:YES];
}
+ (void)dismissAfter:(NSTimeInterval)timeInterval{
  [statusBarNotificationInstance dismiss:timeInterval animated:YES];
}

- (void)dismiss:(NSTimeInterval)timeInterval animated:(BOOL)animated{
  if (animated) {
    [self.dismissTimer invalidate];
    self.dismissTimer = [[NSTimer alloc] initWithFireDate:[NSDate dateWithTimeIntervalSinceNow:timeInterval]
                                                 interval:0 target:self selector:@selector(dismiss:) userInfo:nil repeats:NO];
    [[NSRunLoop currentRunLoop] addTimer:self.dismissTimer forMode:NSRunLoopCommonModes];
  }else{
    _barView.alpha = 0;
  }
}

- (void)dismiss:(NSTimer *)timer{
  [self.dismissTimer invalidate];
  self.dismissTimer = nil;
  [UIView animateWithDuration:0.4 animations:^{
    _barView.alpha = 0;
  } completion:^(BOOL finished) {}];
}

@end

@implementation SVStatusBarView

- (void)setTextLabel:(UILabel *)textLabel{
  if (_textLabel) {
    [_textLabel removeFromSuperview];
  }
  _textLabel = textLabel;
  _textLabel.textAlignment = NSTextAlignmentCenter;
  [self addSubview:_textLabel];
}

- (void)layoutSubviews{
  [super layoutSubviews];
  _textLabel.frame = self.bounds;
  CGPoint center = CGPointMake(self.frame.size.width / 2, self.frame.size.height / 2);
  _textLabel.center = center;
}

@end

@implementation SVStatusConfig



@end

@implementation SVStatusWindowController

@end