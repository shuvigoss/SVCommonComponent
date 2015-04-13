//
//  UIViewController+Loading.m
//  SVCommonComponent
//
//  Created by shuvigoss on 15-4-2.
//  Copyright (c) 2015年 com.shuvigoss. All rights reserved.
//

#import "UIViewController+PlaceHolder.h"
#import <objc/runtime.h>

static char UIViewControllerLoadingView;

@implementation UIViewController (Loading)

@dynamic loadingView;


- (void)startLoading{
  @synchronized(self){
    if (self.loadingView && [self.loadingView isDescendantOfView:self.view]) { return; }
    
    if (!self.loadingView) {
      self.loadingView = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
      self.loadingView.frame = self.view.bounds;
      self.loadingView.backgroundColor = [UIColor whiteColor];
    }
    [self.view addSubview:self.loadingView];
    
    if ([self.loadingView isKindOfClass:[UIActivityIndicatorView class]]) {
      [(UIActivityIndicatorView *)self.loadingView startAnimating];
    }else{
      if ([self.loadingView respondsToSelector:@selector(startLoadingViewAnimation)]) {
        [self.loadingView performSelector:@selector(startLoadingViewAnimation)];
      }
    }
  }
}

- (void)stopLoading{
  @synchronized(self){
    if (!self.loadingView || ![self.loadingView isDescendantOfView:self.view]) { return; }
    if ([self.loadingView isKindOfClass:[UIActivityIndicatorView class]]) {
      [(UIActivityIndicatorView *)self.loadingView stopAnimating];
    }else{
      if ([self.loadingView respondsToSelector:@selector(stopLoadingViewAnimation)]) {
        [self.loadingView performSelector:@selector(stopLoadingViewAnimation)];
      }
    }
    [self.loadingView removeFromSuperview];
  }
}

- (UIView *)loadingView{
  return objc_getAssociatedObject(self, &UIViewControllerLoadingView);
}

- (void)setLoadingView:(UIView *)loadingView{
  objc_setAssociatedObject(self, &UIViewControllerLoadingView, loadingView, OBJC_ASSOCIATION_RETAIN);
}

@end


static char UIViewControllerPlaceHolderView;

@implementation UIViewController (PlaceHolder)
@dynamic placeHolderView;


- (void)showPlaceHolder{
  @synchronized(self){
    if (self.placeHolderView && [self.placeHolderView isDescendantOfView:self.view]) { return; }
    [self.view addSubview:self.placeHolderView];
    self.placeHolderView.frame = self.view.bounds;
  }
}

- (void)hidePlaceHolder{
  @synchronized(self){
    if (!self.placeHolderView || ![self.placeHolderView isDescendantOfView:self.view]) { return; }
    [self.placeHolderView removeFromSuperview];
  }
}

- (void)setPlaceHolderView:(UIView *)placeHolderView{
  objc_setAssociatedObject(self, &UIViewControllerPlaceHolderView, placeHolderView, OBJC_ASSOCIATION_RETAIN);
}

- (UIView *)placeHolderView{
  return objc_getAssociatedObject(self, &UIViewControllerPlaceHolderView);
}
@end
