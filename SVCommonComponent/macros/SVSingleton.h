//
//  SVSingleton.h
//  SVCommonComponent
//
//  Created by shuvigoss on 15-4-1.
//  Copyright (c) 2015年 com.shuvigoss. All rights reserved.
//  将类变为单例
#import <UIKit/UIKit.h>
#ifndef SVCommonComponent_SVSingleton_h
#define SVCommonComponent_SVSingleton_h

#define SV_SINGLETON_HEADER +(instancetype)shareInstance
#define SV_SINGLETON(initSelectorName) \
+(instancetype)shareInstance{\
  static dispatch_once_t pred = 0; \
  __strong static id _sharedObject = nil; \
  dispatch_once(&pred, ^{ \
    _sharedObject = [[self alloc] init]; \
    if (initSelectorName && [_sharedObject respondsToSelector:initSelectorName]) {\
      [_sharedObject performSelector:initSelectorName]; \
    }\
  }); \
  return _sharedObject;\
}\


#define SV_SINGLETON_IMP SV_SINGLETON(@selector(commonInit))
#define SV_SINGLETON_DEFAULTINIT \
+(instancetype)shareInstance{\
  static dispatch_once_t pred = 0; \
  __strong static id _sharedObject = nil; \
  dispatch_once(&pred, ^{ \
    _sharedObject = [[self alloc] init]; \
  }); \
  return _sharedObject;\
}\


#endif

