//
//  SVSegmentedView.h
//  SVCommonComponent
//
//  Created by shuvigoss on 15-4-14.
//  Copyright (c) 2015年 com.shuvigoss. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SVSegmentedView : UIView

@property(nonatomic, readonly) UIScrollView *scrollView;

@property(nonatomic, strong) NSArray *titles;


/**
 *  |--text----text--|  '--' is the margin 
 */
@property(nonatomic, assign) CGFloat minTitleMargin;

/**
 *  default font name is STHeitiSC-Light、font size is 16.f
 */
@property(nonatomic, strong) UIFont *defaultFont;
/**
 *  default font color is grayColor
 */
@property(nonatomic, strong) UIColor *defaultFontColor;
/**
 *  default selected font size  is 18.f
 */
@property(nonatomic, assign) CGFloat selectedFontSize;
/**
 *  default selected font color is redColor
 */
@property(nonatomic, strong) UIColor *selectedFontColor;

@end
