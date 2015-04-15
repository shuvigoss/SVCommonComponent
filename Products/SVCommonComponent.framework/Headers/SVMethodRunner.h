//
//  SVMethodRunner.h
//  SVCommonComponent
//
//  Created by shuvigoss on 15-4-2.
//  Copyright (c) 2015年 com.shuvigoss. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SVMethodRunner : NSObject

/**
 *  dynamic execute object's methods(user define methods) by prefix
 *  warnning : methods need no args...
 *
 *  @param object be executed object
 *  @param prefix execute prefix, NOTE:if prefix is nil or [prefix length] == 0 ,all the method will be executed
 */
+ (void)executeMethods:(id)object withPrefix:(NSString *)prefix;

@end
