//
//  LCYTabBarItem.h
//  reim-ios
//
//  Created by lichangyuan on 15/10/28.
//  Copyright (c) 2015年 lijingjie. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LCYTabBarItem : UIControl

/**
 * itemHeight是可选参数，被设置后会替代tabBar的高度，不设置则使用tabBar的高度作为item的高度
 */
@property(atomic, readwrite, assign) CGFloat itemHeight;

#pragma mark - 标题设置

/**
 * tabBar item上显示的标题
 */
@property (nonatomic, copy) NSString *title;

/**
 * item标题所在的矩形的偏移
 */
@property (nonatomic) UIOffset titlePositionAdjustment;

/**
 * item未被选中时title的属性字典
 */
@property (copy) NSDictionary *unselectedTitleAttributes;

/**
 * item被选中时title的属性字典
 */
@property (copy) NSDictionary *selectedTitleAttributes;

#pragma mark - 图片设置

/**
 * item的图片所在的矩形的偏移
 */
@property (nonatomic) UIOffset imagePositionAdjustment;

/**
 * item被选中时的图片
 */
- (UIImage *)finishedSelectedImage;

/**
 * item未被选中时的图片
 */
- (UIImage *)finishedUnselectedImage;

/**
 * 设置item被选中和未被选中时的图片
 */
- (void)setFinishedSelectedImage:(UIImage *)selectedImage withFinishedUnselectedImage:(UIImage *)unselectedImage;

#pragma mark - 背景设置

/**
 * item被选中时的背景图片
 */
-(UIImage *)backgroundSelectedImage;

/**
 * item未被选中时的背景图片
 */
-(UIImage *)backgroundUnselectedImage;

/**
 * 设置item被选中和未被选中时的背景图片
 */
- (void)setBackgroundSelectedImage:(UIImage *)selectedImage withUnselectedImage:(UIImage *)unselectedImage;

#pragma mark - 标记设置

/**
 * item右上角标记显示的文本
 */
@property (nonatomic, copy)NSString *badgeValue;

/**
 * 标记的背景图片
 */
@property (strong) UIImage *badgeBackgroundImage;

/**
 * 标记的背景颜色
 */
@property (strong) UIColor *badgeBackgroundColor;

/**
 * 标记文本的颜色
 */
@property (strong) UIColor *badgeTextColor;

/**
 * item的右上角标记所在矩形的偏移
 */
@property (nonatomic) UIOffset badgePositionAdjustment;

/**
 * 标记文本的字体
 */
@property (nonatomic) UIFont *badgeTextFont;

@end
