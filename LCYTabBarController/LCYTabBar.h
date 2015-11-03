//
//  LCYTabBar.h
//  reim-ios
//
//  Created by lichangyuan on 15/10/29.
//  Copyright (c) 2015年 lijingjie. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LCYTabBarItem, LCYTabBar;

@protocol LCYTabBarDelegate <NSObject>

/**
 * 询问delegate指定的item是否可以被选中
 */
- (BOOL)tabBar:(LCYTabBar *)tabBar shouldSelectItemAtIndex:(NSInteger)index;

/**
 * 告诉delegate指定的item已经被选中
 */
- (void)tabBar:(LCYTabBar *)tabBar didSelectItemAtIndex:(NSInteger)index;

@end

@interface LCYTabBar : UIView

/**
 * tab bar的delegate对象
 */
@property (nonatomic, weak) id <LCYTabBarDelegate> delegate;

/**
 * tab bar上显示的item
 */
@property (nonatomic, copy) NSArray *items;

/**
 * tab bar上当前选中的item
 */
@property (nonatomic, weak) LCYTabBarItem *selectedItem;

/**
 * backgroundView显示在item后面，如果想增加额外的视图，就将其作为backgroundView的子视图
 */
@property (nonatomic, readonly) UIView *backgroundView;

/**
 * contentEdgeInsets可以调整item位于tab bar的中间
 */
@property UIEdgeInsets contentEdgeInsets;

/**
 * 设置tab bar的高度
 */
- (void)setHeight:(CGFloat)height;

/**
 * 返回tab bar上的item的最小高度
 */
- (CGFloat)minimumContentHeight;

/**
 * 设置tab bar是否半透明，默认是 NO
 */
@property (nonatomic, getter=isTranslucent) BOOL translucent;

@end
