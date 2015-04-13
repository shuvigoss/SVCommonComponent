//
//  SVMethodRunner.m
//  SVCommonComponent
//
//  Created by shuvigoss on 15-4-2.
//  Copyright (c) 2015年 com.shuvigoss. All rights reserved.
//

#import "SVMethodRunner.h"
#import "SVLog.h"
#import "SVUtils.h"
@import ObjectiveC;
static void (*t_method_invoke)(id, Method, ...) = (void(*)(id, Method, ...))method_invoke;

@implementation SVMethodRunner

+ (void)executeMethods:(id)object withPrefix:(NSString *)prefix{
  unsigned int mc = 0;
  Method * mlist = class_copyMethodList(object_getClass(object), &mc);
  SV_DEBUG(@"total :%d methods", mc);
  for(int i = 0; i < mc; i++){
    NSString *methodName = [NSString stringWithUTF8String:sel_getName(method_getName(mlist[i]))];
    SV_DEBUG(@"method name #%d: %@", i, methodName);
    if (SV_ISEMPTY_STRING(prefix)) {
      SV_DEBUG(@"empty prefix ... execute method:%@", methodName);
      t_method_invoke(object, mlist[i], nil);
      continue;
    }
    if ([methodName hasPrefix:prefix]) {
      SV_DEBUG(@"%@ accord prefix:%@ execute...", methodName, prefix);
      t_method_invoke(object, mlist[i], nil);
    }else{
      SV_DEBUG(@"%@ not accord prefix:%@ skip...", methodName, prefix);
    }
  }
  
}

@end
