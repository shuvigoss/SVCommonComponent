//
//  UIViewController+Loading.h
//  SVCommonComponent
//
//  Created by shuvigoss on 15-4-2.
//  Copyright (c) 2015年 com.shuvigoss. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  all loading view must implement this protocol
 */
@protocol UIViewControllerLoadingView <NSObject>
@required
- (void)startLoadingViewAnimation;
- (void)stopLoadingViewAnimation;
@end

@interface UIViewController (Loading)
@property(nonatomic, strong) UIView *loadingView;

- (void)startLoading;
- (void)stopLoading;
@end

@interface UIViewController (PlaceHolder)

@property (nonatomic, strong) UIView *placeHolderView;

- (void)showPlaceHolder;
- (void)hidePlaceHolder;
@end


