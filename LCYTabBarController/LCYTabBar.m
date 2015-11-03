//
//  LCYTabBar.m
//  reim-ios
//
//  Created by lichangyuan on 15/10/29.
//  Copyright (c) 2015年 lijingjie. All rights reserved.
//

#import "LCYTabBar.h"
#import "LCYTabBarItem.h"

@interface LCYTabBar ()

@property (nonatomic) CGFloat itemWidth;
@property (nonatomic) UIView *backgroundView;

@end

@implementation LCYTabBar

- (id)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        [self commonInitialization];
    }
    return self;
}

- (id)initWithCoder:(NSCoder *)aDecoder {
    self = [super initWithCoder:aDecoder];
    if (self) {
        [self commonInitialization];
    }
    return self;
}

- (id)init {
    return [self initWithFrame:CGRectZero];
}

- (void)commonInitialization {
    _backgroundView = [[UIView alloc] init];
    [self addSubview:_backgroundView];
    
    [self setTranslucent:NO];
}

- (void)layoutSubviews {
    CGSize frameSize = self.frame.size;
    CGFloat minimumContentHeight = [self minimumContentHeight];
    
    [[self backgroundView] setFrame:CGRectMake(0, frameSize.height - minimumContentHeight, frameSize.width, frameSize.height)];
    
    [self setItemWidth:roundf((frameSize.width - [self contentEdgeInsets].left - [self contentEdgeInsets].right) / [[self items] count])];
    
    NSInteger index = 0;
    
    //item布局
    
    for (LCYTabBarItem *item in [self items]) {
        CGFloat itemHeight = [item itemHeight];
        
        if (!itemHeight) {
            itemHeight = frameSize.height;
        }
        
        [item setFrame:CGRectMake(self.contentEdgeInsets.left + index * self.itemWidth, (frameSize.height - itemHeight) / 2, self.itemWidth, itemHeight)];

        [item setNeedsDisplay];
        
        index++;
    }
}

- (void)setItemWidth:(CGFloat)itemWidth {
    if (itemWidth > 0) {
        _itemWidth = itemWidth;
    }
}

- (void)setItems:(NSArray *)items {
    for (LCYTabBarItem *item in _items) {
        [item removeFromSuperview];
    }
    
    _items = [items copy];
    for (LCYTabBarItem *item in _items) {
        [item addTarget:self action:@selector(tabBarItemWasSelected:) forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:item];
    }
}

- (void)setHeight:(CGFloat)height {
    [self setFrame:CGRectMake(CGRectGetMinX(self.frame), CGRectGetMinY(self.frame), CGRectGetWidth(self.frame), height)];
}

- (CGFloat)minimumContentHeight {
    CGFloat minimumTabBarContentHeight = CGRectGetHeight(self.frame);
    
    for (LCYTabBarItem *item in [self items]) {
        CGFloat itemHeight = CGRectGetHeight(item.frame);
        if (itemHeight && (itemHeight < minimumTabBarContentHeight)) {
            minimumTabBarContentHeight = itemHeight;
        }
    }
    return minimumTabBarContentHeight;
}

#pragma mark - Item selection

- (void)tabBarItemWasSelected:(id)sender {
    if ([self.delegate respondsToSelector:@selector(tabBar:shouldSelectItemAtIndex:)]) {
        NSInteger index = [self.items indexOfObject:sender];
        if (![self.delegate tabBar:self shouldSelectItemAtIndex:index]) {
            return;
        }
    }
    
    [self setSelectedItem:sender];
    
    if ([self.delegate respondsToSelector:@selector(tabBar:didSelectItemAtIndex:)]) {
        NSInteger index = [self.items indexOfObject:sender];
        [self.delegate tabBar:self didSelectItemAtIndex:index];
    }
}

- (void)setSelectedItem:(LCYTabBarItem *)selectedItem {
    if (_selectedItem == selectedItem) {
        return;
    }
    [_selectedItem setSelected:NO];
    
    _selectedItem = selectedItem;
    [_selectedItem setSelected:YES];
}

#pragma mark - 半透明设置

- (void)setTranslucent:(BOOL)translucent {
    _translucent = translucent;
    
    CGFloat alpha = (translucent ? 0.9 : 0.1);
    
    [_backgroundView setBackgroundColor:[UIColor colorWithRed:245/255.0 green:245/255.0 blue:245/255.0 alpha:alpha]];
}

@end
