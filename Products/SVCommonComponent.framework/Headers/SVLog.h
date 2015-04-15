//
//  SVLog.h
//  SVCommonComponent
//
//  Created by shuvigoss on 15-3-31.
//  Copyright (c) 2015年 com.shuvigoss. All rights reserved.
//
//日志相关的宏，下边的日志可以记录类、方法、以及多少行。比较好用
#ifndef SVCommonComponent_SVLog_h
#define SVCommonComponent_SVLog_h

#define NSLog(format, ...) SV_LOG((format), "log",  ##__VA_ARGS__)
#define SV_WARNING(format, ...) SV_LOG((format), "warning", ##__VA_ARGS__)
#define SV_DEBUG(format, ...) SV_LOG((format), "debug", ##__VA_ARGS__)
#define SV_ERROR(format, ...) SV_LOG((format), "error", ##__VA_ARGS__)

#define SV_LOG(format, type, ...) do { \
  fprintf(stderr, "---------%s start---------\n", type);                      \
  fprintf(stderr, "<%s : %d> %s\n",                                           \
  [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String],  \
  __LINE__, __func__);                                                        \
  (NSLog)((format), ##__VA_ARGS__);                                           \
  fprintf(stderr, "---------%s end---------\n\n", type);                      \
} while (0)\

#endif
