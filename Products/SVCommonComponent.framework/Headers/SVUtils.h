//
//  SVUtils.h
//  SVCommonComponent
//
//  Created by shuvigoss on 15-4-1.
//  Copyright (c) 2015年 com.shuvigoss. All rights reserved.
//
#ifndef SVCommonComponent_SVUtils_h
#define SVCommonComponent_SVUtils_h

#pragma mark 空判断
static inline BOOL SV_ISEMPTY_STRING(id objc){
  if (!objc) {
    return YES;
  }
  return [objc isKindOfClass:[NSString class]] ? [objc length] == 0 : NO;
}

static inline BOOL SV_ISEMPTY_ARRAY(id objc){
  if (!objc) {
    return YES;
  }
  return [objc isKindOfClass:[NSArray class]] ? [objc count] == 0 : NO;
}

static inline BOOL SV_ISEMPTY_DICTIONARY(id objc){
  if (!objc) {
    return YES;
  }
  return [objc isKindOfClass:[NSDictionary class]] ? [objc count] == 0 : NO;
}

static inline BOOL SV_ISEMPTY(id objc){
  if (!objc) {
    return YES;
  }
  if ([objc isKindOfClass:[NSString class]]) {
    return SV_ISEMPTY_STRING(objc);
  }else if([objc isKindOfClass:[NSArray class]]){
    return SV_ISEMPTY_ARRAY(objc);
  }else if([objc isKindOfClass:[NSDictionary class]]){
    return SV_ISEMPTY_DICTIONARY(objc);
  }
  return NO;
}

#pragma mark UIColor Utils
#define SV_COLOR_ALPHA(r, g, b, a)            [UIColor colorWithRed:r/255.f green:g/255.f blue:b/255.f alpha:a]
#define SV_COLOR(r, g, b)                     SV_COLOR_ALPHA(r, g, b, 1)
#define SV_COLOR_SAME(i)                      SV_COLOR_ALPHA(i, i, i, 1)
#define SV_COLOR_CLEAR                        [UIColor clearColor]


#pragma mark UIView Utils
#define SV_UPDATE_FRAME_X(newX)						do{CGRect __tmpFrame = self.frame; __tmpFrame.origin.x = (newX); self.frame = __tmpFrame;}while(0)
#define SV_UPDATE_FRAME_Y(newY)						do{CGRect __tmpFrame = self.frame; __tmpFrame.origin.y = (newY); self.frame = __tmpFrame;}while(0)
#define SV_UPDATE_FRAME_WIDTH(newWidth)				do{CGRect __tmpFrame = self.frame; __tmpFrame.size.width = (newWidth); self.frame = __tmpFrame;}while(0)
#define SV_UPDATE_FRAME_HEIGHT(newHeight)				do{CGRect __tmpFrame = self.frame; __tmpFrame.size.height = (newHeight); self.frame = __tmpFrame;}while(0)
#define SV_UPDATE_FRAME_SIZE(newSize)                  do{CGRect __tmpFrame = self.frame; __tmpFrame.size = (newSize); self.frame = __tmpFrame;}while(0)
#define SV_UPDATE_FRAME_ORIGIN(newOrigin)				do{CGRect __tmpFrame = self.frame; __tmpFrame.origin = (newOrigin); self.frame = __tmpFrame;}while(0)

// UPDATE a view frame
#define SV_UPDATE_VIEW_FRAME_X(aView, newX)			do{CGRect __tmpFrame = aView.frame; __tmpFrame.origin.x = (newX); aView.frame = __tmpFrame;}while(0)
#define SV_UPDATE_VIEW_FRAME_Y(aView, newY)			do{CGRect __tmpFrame = aView.frame; __tmpFrame.origin.y = (newY); aView.frame = __tmpFrame;}while(0)
#define SV_UPDATE_VIEW_FRAME_WIDTH(aView, newWidth)	do{CGRect __tmpFrame = aView.frame; __tmpFrame.size.width = (newWidth); aView.frame = __tmpFrame;}while(0)
#define SV_UPDATE_VIEW_FRAME_HEIGHT(aView, newHeight)	do{CGRect __tmpFrame = aView.frame; __tmpFrame.size.height = (newHeight); aView.frame = __tmpFrame;}while(0)
#define SV_UPDATE_VIEW_FRAME_SIZE(aView,newSize)       do{CGRect __tmpFrame = aView.frame; __tmpFrame.size = (newSize); aView.frame = __tmpFrame;}while(0)
#define SV_UPDATE_VIEW_FRAME_ORIGIN(aView,newOrigin)   do{CGRect __tmpFrame = aView.frame; __tmpFrame.origin = (newOrigin); aView.frame = __tmpFrame;}while(0)

// UPDATE current center
#define SV_UPDATE_CENTER_X(newX)						do{CGPoint __tmpCenter = self.center; __tmpCenter.x = (newX); self.center = __tmpCenter;}while(0)
#define SV_UPDATE_CENTER_Y(newY)						do{CGPoint __tmpCenter = self.center; __tmpCenter.y = (newY); self.center = __tmpCenter;}while(0)

// UPDATE a view center
#define SV_UPDATE_VIEW_CENTER_X(aView, newX)			do{CGPoint __tmpCenter = aView.center; __tmpCenter.x = (newX); aView.center = __tmpCenter;}while(0)
#define SV_UPDATE_VIEW_CENTER_Y(aView, newY)			do{CGPoint __tmpCenter = aView.center; __tmpCenter.y = (newY); aView.center = __tmpCenter;}while(0)

#define SV_VIEW_WIDTH(view) view.frame.size.width
#define SV_VIEW_HEIGHT(view) view.frame.size.height
#define SV_VIEW_X(view) view.frame.origin.x
#define SV_VIEW_Y(view) view.frame.origin.y
#define SV_VIEW_LEFT(view) view.frame.origin.x
#define SV_VIEW_TOP(view) view.frame.origin.y
#define SV_VIEW_BOTTOM(view) (view.frame.origin.y + view.frame.size.height)
#define SV_VIEW_RIGHT(view) (view.frame.origin.x + view.frame.size.width)

#pragma mark UIFont Utils
static NSString *sv_global_font_name = nil;
#define SV_FONT(s) sv_global_font_name ? [UIFont fontWithName:sv_global_font_name size:s] :   [UIFont systemFontOfSize:s]


#pragma mark print
#define NSLogRect(rect) NSLog(@"%s x:%.4f, y:%.4f, w:%.4f, h:%.4f", #rect, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height)
#define NSLogSize(size) NSLog(@"%s w:%.4f, h:%.4f", #size, size.width, size.height)
#define NSLogPoint(point) NSLog(@"%s x:%.4f, y:%.4f", #point, point.x, point.y)
#endif
