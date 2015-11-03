//
//  LCYTabBarController.h
//  LCYTabBarController
//
//  Created by lichangyuan on 15/10/30.
//  Copyright (c) 2015年 lichangyuan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LCYTabBar.h"

@protocol LCYTabBarControllerDelegate;

@interface LCYTabBarController : UIViewController<LCYTabBarDelegate>

/**
 * tab bar controller的delegate对象
 */
@property (nonatomic, weak) id <LCYTabBarControllerDelegate> delegate;

/**
 * 通过与tab bar交互展示的根视图控制器的数组
 */
@property (nonatomic, copy) IBOutletCollection(UIViewController) NSArray *viewControllers;

/**
 * 与控制器对应的tab bar对象（只读）
 */
@property (nonatomic, readonly) LCYTabBar *tabBar;

/**
 * 与tab bar中当前被选中的item对应的视图控制器
 */
@property (nonatomic, weak) UIViewController *selectedViewController;

/**
 * tab bar中当前被选中的item对应的视图控制器的下标
 */
@property (nonatomic) NSUInteger selectedIndex;

/**
 * 决定tab bar是否隐藏的布尔值
 */
@property (nonatomic, getter=isTabBarHidden) BOOL tabBarHidden;

/**
 * 设置tab bar可见性
 */
- (void)setTabBarHidden:(BOOL)hidden animated:(BOOL)animated;

@end

@protocol LCYTabBarControllerDelegate <NSObject>

@optional

/**
 * 询问delegate对象指定的控制器是否可以被激活
 */
- (BOOL)tabBarController:(LCYTabBarController *)tabBarController shouldSelectViewController:(UIViewController *)viewController;

/**
 * 告诉delegate对象tab bar中一个item被选中
 */
- (BOOL)tabBarController:(LCYTabBarController *)tabBarController didSelectViewController:(UIViewController *)viewController;

@end

@interface UIViewController (LCYTabBarControllerItem)

/**
 * 代表被加入到tab bar controller的viewController的item
 */
@property (nonatomic, setter=lcy_setTabBarItem:) LCYTabBarItem *lcy_tabBarItem;

/**
 * view controller体系中最近的祖先就是一个tab bar controller（只读）
 */
@property (nonatomic, readonly) LCYTabBarController *lcy_tabBarController;

@end