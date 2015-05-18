//
//  CycleScrollView.h
//  PagedScrollView
//
//  Created by Hsn on 14-1-23.
//  Copyright (c) 2014年 Apple Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CycleScrollViewDelegate <NSObject>
/*
 * 点击某一张图片
 */
- (void)tapActionView:(NSInteger)index;
/*
 * 左移一张图片
 */
- (void)cycNextScroll:(NSInteger)index;
/*
 * 右移一张图片
 */
- (void)cycPreviousScroll:(NSInteger)index;
@end


@interface CycleScrollView : UIView


@property (nonatomic , readonly) UIScrollView *scrollView;
/**
 *  初始化
 *
 *  @param frame             frame
 *  @param animationDuration 自动滚动的间隔时长。如果<=0，不自动滚动。
 *  @param views             所有要轮播的视图
 *  @param viewCount         多少个view
 *
 *  @return instance
 */
- (id)initWithFrame:(CGRect)frame animationDuration:(NSTimeInterval)animationDuration views:(NSArray *)views viewCount:(NSInteger)viewCount;

@property (nonatomic , strong) NSTimer *animationTimer;

@property (nonatomic , assign) NSTimeInterval animationDuration;

@property (nonatomic , assign) id<CycleScrollViewDelegate> delegate;

@end