//
//  JTCalendarAppearance.h
//  JTCalendar
//
//  Created by Jonathan Tribouharet
//

#import <UIKit/UIKit.h>

@interface JTCalendarAppearance : NSObject

typedef NS_ENUM(NSInteger, JTCalendarWeekDayFormat) {
    JTCalendarWeekDayFormatSingle,
    JTCalendarWeekDayFormatShort,
    JTCalendarWeekDayFormatFull
};

@property (assign, nonatomic) BOOL isWeekMode;

// Month
@property (strong, nonatomic) UIColor *menuMonthTextColor;
@property (strong, nonatomic) UIFont *menuMonthTextFont;

@property (assign, nonatomic) CGFloat ratioContentMenu;

// Weekday
@property (assign, nonatomic) JTCalendarWeekDayFormat weekDayFormat;
@property (strong, nonatomic) UIColor *weekDayTextColor;
@property (strong, nonatomic) UIFont *weekDayTextFont;

// Day
@property (strong, nonatomic) UIColor *dayCircleColorSelected;
@property (strong, nonatomic) UIColor *dayCircleColorSelectedOtherMonth;
@property (strong, nonatomic) UIColor *dayCircleColorToday;
@property (strong, nonatomic) UIColor *dayCircleColorTodayOtherMonth;

@property (strong, nonatomic) UIColor *dayDotColor;
@property (strong, nonatomic) UIColor *dayDotColorSelected;
@property (strong, nonatomic) UIColor *dayDotColorOtherMonth;
@property (strong, nonatomic) UIColor *dayDotColorSelectedOtherMonth;
@property (strong, nonatomic) UIColor *dayDotColorToday;
@property (strong, nonatomic) UIColor *dayDotColorTodayOtherMonth;

@property (strong, nonatomic) UIColor *dayTextColor;
@property (strong, nonatomic) UIColor *dayTextColorSelected;
@property (strong, nonatomic) UIColor *dayTextColorOtherMonth;
@property (strong, nonatomic) UIColor *dayTextColorSelectedOtherMonth;
@property (strong, nonatomic) UIColor *dayTextColorToday;
@property (strong, nonatomic) UIColor *dayTextColorTodayOtherMonth;

@property (strong, nonatomic) UIFont *dayTextFont;

@property (assign, nonatomic) CGFloat dayCircleRatio;
@property (assign, nonatomic) CGFloat dayDotRatio;

- (NSCalendar *)calendar;

- (void)setDayDotColorForAll:(UIColor *)dotColor;
- (void)setDayTextColorForAll:(UIColor *)textColor;

@end

// 版权属于原作者
// http://code4app.com (cn) http://code4app.net (en)
// 发布代码于最专业的源码分享网站: Code4App.com 

// 版权属于原作者
// http://code4app.com (cn) http://code4app.net (en)
// 发布代码于最专业的源码分享网站: Code4App.com 

// 版权属于原作者
// http://code4app.com (cn) http://code4app.net (en)
// 发布代码于最专业的源码分享网站: Code4App.com 
