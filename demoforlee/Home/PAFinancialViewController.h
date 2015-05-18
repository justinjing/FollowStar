//
//  PAFinancialViewController.h
//  PAChat
//
//  Created by leizhiping on 14-6-24.
//  Copyright (c) 2014年 FreeDo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "JTCalendar.h"
#import "ConversationsModel.h"

typedef enum _FCCellSelectType
{
    FCTableViewCellSelectTypeNon,
    FCTableViewCellSelectTypeHeard,
    FCTableViewCellSelectTypeTitle,
    FCTableViewCellSelectTypeContent
}FCTableViewCellSelectType;

@interface FCTableViewCell : UITableViewCell

@property (nonatomic,assign) FCTableViewCellSelectType selectType;

- (void)setContentModel:(ConversationsModel *)model;

@end



@interface PAFinancialViewController : UIViewController<JTCalendarDataSource>
@property(nonatomic,strong)UIButton *rightButton;
@property(nonatomic,strong)UIButton *leftButton;


@property (strong, nonatomic) IBOutlet JTCalendarMenuView *calendarMenuView;
@property (strong, nonatomic) IBOutlet JTCalendarContentView *calendarContentView;

@property (strong, nonatomic) IBOutlet NSLayoutConstraint *calendarContentViewHeight;

@property (strong, nonatomic) JTCalendar *calendar;
@property (strong, nonatomic) IBOutlet UIView *headerView;

@end
