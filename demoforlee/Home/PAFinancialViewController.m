//
//  PAFinancialViewController.m
//  PAChat
//
//  Created by leizhiping on 14-6-24.
//  Copyright (c) 2014年 FreeDo. All rights reserved.
//

#import "PAFinancialViewController.h"
#import "HEXCMyUIButton.h"
#import "MJRefresh.h"
#import "CSNotificationView.h"
#import "CycleScrollView.h"
#import "NSTimer+Addition.h"

#define kCycleScrollViewTag    2014071401
#define kContextViewFont  13
#define tableviewCellHeight  186
#define FM_SCREEN_HEIGHT ((float)[[UIScreen mainScreen] bounds].size.height)
#define FM_SCREEN_WIDTH ((float)[[UIScreen mainScreen] bounds].size.width)


@implementation FCTableViewCell
{
    UIImageView *_QimgView;
    UILabel *_titleLabel;
    UIButton *_playButton;
    UIImageView *_heardImgView;
    UILabel *_questCountLabel;
    UILabel *_contextLabel;
    UILabel *_tvstationLabel;    //首尔电视台
    UILabel *_redActiveteLabel; //红色活动标题
    UILabel *_attentionLabel; //多少人关注
}

@synthesize selectType = _selectType;

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    
    if (self) {
        
        self.backgroundColor = [UIColor clearColor];
        
        UIView *contextView = [[UIView alloc] initWithFrame:CGRectMake(0, 0 , FM_SCREEN_WIDTH,tableviewCellHeight)];
        contextView.backgroundColor = [UIColor whiteColor];
        contextView.layer.borderColor = [[UIColor grayColor] colorWithAlphaComponent:0.3].CGColor;
        

        _QimgView = [[UIImageView alloc] initWithFrame:CGRectMake(11, 9, 30, 15)];
        [contextView addSubview:_QimgView];
        
        
        
        _titleLabel = [[UILabel alloc] initWithFrame:CGRectMake(CGRectGetMaxX(_QimgView.frame) + 5, 5,FM_SCREEN_WIDTH-90, 25)];
        _titleLabel.font = [UIFont systemFontOfSize:15];
        _titleLabel.textColor = [[UIColor blackColor] colorWithAlphaComponent:0.9];
         [contextView addSubview:_titleLabel];

        _playButton =[UIButton  buttonWithType:UIButtonTypeRoundedRect];
        _playButton.frame=CGRectMake(CGRectGetMaxX(_titleLabel.frame)+ 5, 10, 16, 16);
        [_playButton setBackgroundImage:[UIImage imageNamed:@"voice.png"] forState:UIControlStateNormal];
         [_playButton setBackgroundImage:[UIImage imageNamed:@"voice.png"] forState:UIControlStateHighlighted];
        [contextView addSubview:_playButton];
        
        
        UIView *lineBackGround = [[UIView alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(_titleLabel.frame) + 5, FM_SCREEN_WIDTH, 1)];
        lineBackGround.backgroundColor = [[UIColor grayColor] colorWithAlphaComponent:0.3];
//      [contextView addSubview:lineBackGround];
        
       
        //个人头像
        _heardImgView = [[UIImageView alloc] initWithFrame:CGRectMake(10, CGRectGetMaxY(lineBackGround.frame) , 120, 130)];
        [contextView addSubview:_heardImgView];
        
        
        //开始时间和截止时间
        _contextLabel = [[UILabel alloc] initWithFrame:CGRectMake(CGRectGetMaxX(_heardImgView.frame) + 5, CGRectGetMaxY(lineBackGround.frame) + 5, 270, 20)];
        _contextLabel.font = [UIFont systemFontOfSize:kContextViewFont];
        _contextLabel.textColor = [[UIColor blackColor] colorWithAlphaComponent:0.7];
        _contextLabel.numberOfLines = 0;
        [contextView addSubview:_contextLabel];
        
        
        
       //首尔电视台
        _tvstationLabel=[[UILabel alloc] initWithFrame:CGRectMake(CGRectGetMaxX(_heardImgView.frame) + 5, CGRectGetMaxY(_contextLabel.frame) + 3, 270, 20)];
        _tvstationLabel.font = [UIFont systemFontOfSize:kContextViewFont];
        _tvstationLabel.textColor = [[UIColor blackColor] colorWithAlphaComponent:0.7];
        _tvstationLabel.numberOfLines = 0;
        _tvstationLabel.text =  @"首尔电视台";
        [contextView addSubview:_tvstationLabel];
        
        
        
         //红色活动标题
        _redActiveteLabel=[[UILabel alloc] initWithFrame:CGRectMake(CGRectGetMaxX(_heardImgView.frame) + 5, CGRectGetMaxY(_tvstationLabel.frame) + 3, 270, 20)];
        _redActiveteLabel.font = [UIFont systemFontOfSize:kContextViewFont];
        _redActiveteLabel.textColor = [[UIColor redColor] colorWithAlphaComponent:0.7];
        _redActiveteLabel.numberOfLines = 0;
         [contextView addSubview:_redActiveteLabel];
        
        UIImageView *img1=[[UIImageView alloc]initWithFrame:CGRectMake(CGRectGetMaxX(_heardImgView.frame) + 5, CGRectGetMaxY(_redActiveteLabel.frame) + 15, 14, 14)];
        img1.image=[UIImage imageNamed:@"group.png"];
        [contextView addSubview:img1];
        
        //多少人关注
        _attentionLabel=[[UILabel alloc] initWithFrame:CGRectMake(CGRectGetMaxX(img1.frame) + 5, CGRectGetMaxY(_redActiveteLabel.frame) + 15, 53, 20)];
        _attentionLabel.font = [UIFont systemFontOfSize:kContextViewFont];
        _attentionLabel.textColor = [[UIColor redColor] colorWithAlphaComponent:0.7];
        _attentionLabel.numberOfLines = 0;
        [contextView addSubview:_attentionLabel];
        
        
        UILabel *wordLabel=[[UILabel alloc]initWithFrame:CGRectMake(CGRectGetMaxX(_attentionLabel.frame) + 5, CGRectGetMaxY(_redActiveteLabel.frame) + 15, 270, 20)];
        wordLabel.text=@"人关注";
        wordLabel.font=[UIFont systemFontOfSize:kContextViewFont];
        [contextView addSubview:wordLabel];
        
        UIImageView *img2=[[UIImageView alloc]initWithFrame:CGRectMake(CGRectGetMaxX(_heardImgView.frame) + 5, CGRectGetMaxY(_attentionLabel.frame) + 5, 14, 14)];
        img2.image=[UIImage imageNamed:@"man.png"];
        [contextView addSubview:img2];
        
        //详细内容
        _questCountLabel = [[UILabel alloc] initWithFrame:CGRectMake(CGRectGetMaxX(img2.frame)+5, CGRectGetMaxY(_attentionLabel.frame) + 5, 270 , 15)];
        _questCountLabel.text = @"20";
        _questCountLabel.font = [UIFont systemFontOfSize:kContextViewFont];
        _questCountLabel.layer.masksToBounds = YES;
        _questCountLabel.textColor = [[UIColor blackColor] colorWithAlphaComponent:0.7];
        [contextView addSubview:_questCountLabel];
        
    
        [self addSubview:contextView];
        
        _selectType = FCTableViewCellSelectTypeNon;

    }
    
    return self;
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    UITouch *touch = [touches anyObject];
    CGPoint  point = [touch locationInView:self];
    

    CGRect titleFrame = CGRectMake(0, 0, CGRectGetMaxX(_titleLabel.frame), CGRectGetMinY(_heardImgView.frame) + 5);
    CGRect heardFrame = CGRectMake(0, CGRectGetMinY(_heardImgView.frame) + 5, CGRectGetMaxX(_heardImgView.frame) + 10, CGRectGetMaxY(_questCountLabel.frame) + 20);
    CGRect contextFrame = CGRectMake(CGRectGetMaxX(_heardImgView.frame) + 10 , CGRectGetMinY(_heardImgView.frame) + 5, _contextLabel.frame.size.width, heardFrame.size.height + 20);
    
    if (CGRectContainsPoint(titleFrame, point))
    {
        _selectType = FCTableViewCellSelectTypeTitle;
    }
    else if (CGRectContainsPoint(heardFrame, point))
    {
        _selectType = FCTableViewCellSelectTypeHeard;
    }
    else if (CGRectContainsPoint(contextFrame, point))
    {
        _selectType = FCTableViewCellSelectTypeContent;
    }
    else {
        _selectType = FCTableViewCellSelectTypeNon;
    }
    
    [super touchesEnded:touches withEvent:event];
    
    
}

- (void)minimumHeight:(UILabel *)label
{
    float minimumHeight = 0.0;
    
    if ([[UIDevice currentDevice].systemVersion floatValue] >= 7.0) {
#if __IPHONE_7_0
        NSDictionary *attributes = [NSDictionary dictionaryWithObjectsAndKeys:label.font,NSFontAttributeName,nil];
        CGRect contentSize = [label.text boundingRectWithSize:CGSizeMake(label.frame.size.width, MAXFLOAT)
                                                      options:NSStringDrawingUsesLineFragmentOrigin
                                                   attributes:attributes
                                                      context:nil];
        minimumHeight = contentSize.size.height;
#endif
    }
    else
    {
        CGSize contentSize = [label.text sizeWithFont:label.font constrainedToSize:CGSizeMake(label.frame.size.width , MAXFLOAT) lineBreakMode:NSLineBreakByTruncatingTail];
        
        minimumHeight = contentSize.height;
    }
    
    CGRect tFrame = label.frame;
    
    if (75.0 > minimumHeight) {
        tFrame.size.height = minimumHeight;
        label.frame = tFrame;
    }
    else {
        tFrame.size.height = 75.0;
        label.frame = tFrame;
    }
}

- (void)setContentModel:(ConversationsModel *)model
{
    if(model.isOnline)
    {
        _QimgView.image = [UIImage imageNamed:@"xianshang.png"];
    }
    else
    {
       _QimgView.image = [UIImage imageNamed:@"xianxia.png"];
    
    }
    _titleLabel.text = model.maintitleContent;
    _heardImgView.image=[UIImage imageNamed:model.albumurl];
    _questCountLabel.text = model.smalltitleContent;
    _contextLabel.text = model.deadlineContent;
    _redActiveteLabel.text = model.keywords;
    _attentionLabel.text = model.attentionCount;
//    [self minimumHeight:_contextLabel];
}

@end

NSString *const MJTableViewCellIdentifier = @"Cell";

@interface PAFinancialViewController () <UITableViewDelegate,UITableViewDataSource,CycleScrollViewDelegate>

@property (nonatomic,strong) UITableView *tableView;
@property (nonatomic,strong) NSMutableArray *listData;
@property (nonatomic,strong) HEXCMyUIButton *myButton;
@property (nonatomic,copy) NSString *keywords;
@property (nonatomic,strong) UIView *headerScrollView;

@end

@implementation PAFinancialViewController
@synthesize  tableView = _tableView;
@synthesize listData = _listData;
@synthesize myButton = _myButton;
@synthesize keywords = _keywords;
@synthesize headerScrollView = _headerScrollView;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)dealloc
{
    
    CycleScrollView *CSView = (CycleScrollView *)[self.headerScrollView viewWithTag:kCycleScrollViewTag];
    CSView.delegate = nil;
    self.headerScrollView = nil;
    self.keywords = nil;
    self.tableView.delegate = nil;
    self.tableView.dataSource = nil;
}

- (UIBarButtonItem *)createRightBarButtonItem:(NSString *)title target:(id)obj selector:(SEL)selector ImageName:(NSString*)imageName
{
    UIImage *image = [UIImage imageNamed:imageName];
    _rightButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [self.rightButton setImage:image forState:UIControlStateNormal];
    [self.rightButton setTitle:title forState:UIControlStateNormal];
    //FIX ME:!!!不是所有的右上按钮都是更多！
    self.rightButton.titleLabel.font = [UIFont systemFontOfSize:16];
    //    [self.rightButton setTitleColor:[UIColor colorWithHex:0xff8c3f] forState:UIControlStateNormal];
    [self.rightButton setTitleColor:[UIColor lightGrayColor] forState:UIControlStateHighlighted];
    [self.rightButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [self.rightButton setTitleColor:[UIColor colorWithWhite:1 alpha:0.6] forState:UIControlStateDisabled];
    [self.rightButton addTarget:obj action:@selector(didChangeModeTouch) forControlEvents:UIControlEventTouchUpInside];
    [self.rightButton sizeToFit];
    [self.rightButton setAccessibilityLabel:title];
    //iOS7之前的版本需要手动设置和屏幕边缘的间距
    if (kIOSVersions < 7.0) {
        self.rightButton.frame = CGRectInset(self.rightButton.frame, -10, 0);
    }
    
    UIBarButtonItem *item = [[UIBarButtonItem alloc] initWithCustomView:self.rightButton];
    return item;
}

- (UIBarButtonItem *)createLeftBarButtonItem:(NSString *)title target:(id)obj selector:(SEL)selector ImageName:(NSString*)imageName
{
    UIImage *image = [UIImage imageNamed:imageName];
    self.leftButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [self.leftButton setImage:image forState:UIControlStateNormal];
    self.leftButton.frame = CGRectMake(0, 0,44, 44);
    self.leftButton.titleLabel.font = [UIFont systemFontOfSize:18];
    self.leftButton.titleLabel.textAlignment = NSTextAlignmentLeft;
    self.leftButton.titleLabel.adjustsFontSizeToFitWidth = YES;
    [self.leftButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [self.leftButton setTitleColor:[UIColor lightGrayColor] forState:UIControlStateHighlighted];
      [self.leftButton setTitleColor:[UIColor colorWithRed:130.0/255 green:56.0/255 blue:23.0/255 alpha:1] forState:UIControlStateHighlighted];
    [self.leftButton setTitleColor:[UIColor colorWithWhite:1 alpha:0.6] forState:UIControlStateDisabled];
    [self.leftButton addTarget:obj action:selector forControlEvents:UIControlEventTouchUpInside];
    [self.leftButton sizeToFit];
    
    //iOS7之前的版本需要手动设置和屏幕边缘的间距
    if (kIOSVersions < 7.0) {
        self.leftButton.imageEdgeInsets = UIEdgeInsetsMake(0, 0, 0, 0);
    }else{
        self.leftButton.imageEdgeInsets = UIEdgeInsetsMake(0, -10, 0, 0);
        self.leftButton.titleEdgeInsets = UIEdgeInsetsMake(0, -10, 0, 0);
    }
    
    UIBarButtonItem *item = [[UIBarButtonItem alloc] initWithCustomView:self.leftButton];
    return item;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.title = @"明星活动";
    
    self.navigationItem.leftBarButtonItem =  [self createLeftBarButtonItem:@"" target:self selector:nil ImageName:@"left_icon1.png"];
    self.navigationItem.rightBarButtonItem =  [self createRightBarButtonItem:@"" target:self selector:nil ImageName:@"right_icon2.png"];
    
    //初始化数据
    NSString* path=[[NSBundle mainBundle] pathForResource:@"datasource" ofType:@"plist"];
    NSArray *arr =[NSArray arrayWithContentsOfFile:path];
    NSMutableArray *temp=[[NSMutableArray alloc]initWithCapacity:10];
    
    for (int i=0; i<[arr count]; i++)
    {
        ConversationsModel *con=[[ConversationsModel alloc] init];
        con.albumurl = [[arr objectAtIndex:i] objectForKey:@"albumurl"];
        con.maintitleContent = [[arr objectAtIndex:i] objectForKey:@"maintitleContent"];
        con.deadlineContent = [[arr objectAtIndex:i] objectForKey:@"deadlineContent"];
        con.keywords = [[arr objectAtIndex:i] objectForKey:@"keywords"];
        con.smalltitleContent = [[arr objectAtIndex:i] objectForKey:@"smalltitleContent"];
        con.TVStation = [[arr objectAtIndex:i] objectForKey:@"TVStation"];
        con.attentionCount = [[arr objectAtIndex:i] objectForKey:@"attentionCount"];
        con.isOnline = [[[arr objectAtIndex:i] objectForKey:@"isOnline"] boolValue];
        [temp addObject:con];
    }
    self.listData = temp ;//@[[[ConversationsModel alloc] init]];
    
    
    self.tableView = [[UITableView alloc] initWithFrame:[self.view bounds] style:UITableViewStylePlain];
    _tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width,kScreenHeight-64) style:UITableViewStylePlain];
    _tableView.backgroundColor = kBackgroudColor;
    _tableView.separatorStyle = UITableViewCellSeparatorStyleSingleLine;
    _tableView.delegate = self;
    _tableView.dataSource = self;
    
    [self setupRefresh];

    self.headerScrollView  = [self CreateHeaderView];
    
    _tableView.tableHeaderView = _headerScrollView;
    
    [self.view addSubview:_tableView];

//    [self addCustomElements];  //添加“＋”button

}

- (UIView *)CreateHeaderView
{

        self.calendar = [JTCalendar new];
    
        self.calendar.calendarAppearance.calendar.firstWeekday = 2; // Sunday == 1, Saturday == 7
        self.calendar.calendarAppearance.dayCircleRatio = 9. / 10.;
        self.calendar.calendarAppearance.ratioContentMenu = 1.;
    
        [self.calendar setMenuMonthsView:self.calendarMenuView];
        [self.calendar setContentView:self.calendarContentView];
        [self.calendar setDataSource:self];
    
       self.headerView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, FM_SCREEN_WIDTH, 350)];
       [self.headerView addSubview:_calendarMenuView];
       [self.headerView addSubview:_calendarContentView];
    
       return self.headerView;
}

#pragma mark  - 上下拉刷新状态
/**
 *  集成刷新控件
 */
- (void)setupRefresh
{
    [self.tableView addHeaderWithTarget:self action:@selector(headerRereshing)];
    //[self.tableView headerBeginRefreshing];
    [self.tableView addFooterWithTarget:self action:@selector(footerRereshing)];
}


- (void)headerRereshing
{
    [self performSelector:@selector(plaza) withObject:nil afterDelay:1];
}

- (void)footerRereshing
{
    [self plaza];
}



#pragma mark - 添加问题

- (void)addCustomElements
{
    self.myButton = [HEXCMyUIButton buttonWithType:UIButtonTypeCustom];
    _myButton.MoveEnable = YES;
    _myButton.frame = CGRectMake(125, CGRectGetHeight(self.view.bounds)  - kNavigationBarHeight - kSeekTabBarHeight - 72.0, 72, 72);

    [_myButton setBackgroundImage:[UIImage imageNamed:@"ask.png"] forState:UIControlStateNormal];
    [_myButton setTag:10];
    
    [_myButton addTarget:self action:@selector(onCustomElements:) forControlEvents:UIControlEventTouchUpInside];
    
    
    [self.view addSubview:_myButton];
    [self.view bringSubviewToFront:_myButton];

}

/**
 *  提问按键
 *
 *  @param sender button
 */
- (void)onCustomElements:(id)sender
{
    
    HEXCMyUIButton *btn = (HEXCMyUIButton *)sender;
    if (!btn.MoveEnabled)
    {
        UIAlertView *alert=[[UIAlertView alloc]initWithTitle:@"你好" message:@"警告" delegate:self cancelButtonTitle:nil otherButtonTitles:@"确定", nil];
        [alert show];
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewWillAppear:(BOOL)animated
{
    _myButton.frame =  CGRectMake(125 ,CGRectGetHeight(self.view.bounds) - 92.0, 72.f,72.f);
}



#pragma mark - TableView

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return tableviewCellHeight;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.listData.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{

    ConversationsModel *model  = [self.listData objectAtIndex:indexPath.row];
    
    static NSString *cellIdentifier = @"financialfriendCell1";
    
    FCTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];
    
    if (cell == nil) {
        cell = [[FCTableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellIdentifier];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    }
    
    cell.tag = indexPath.row;
    
    [cell setContentModel:model];
    
    return cell;
}


- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    FCTableViewCell *cell = (FCTableViewCell *)[tableView cellForRowAtIndexPath:indexPath];
    DDLog(@"单击=====%ld",(long)indexPath.row);
    switch (cell.selectType) {
        case FCTableViewCellSelectTypeTitle:
        {
            NSLog(@"单击小title");
            break;
        }
        case FCTableViewCellSelectTypeHeard:
        {
            NSLog(@"单击头像");
        }
            break;
        case FCTableViewCellSelectTypeContent:
        {
          DDLog(@"单击内容==");
        }
            break;
        default:
            break;
    }
    [tableView  deselectRowAtIndexPath:indexPath animated:NO];
}


- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gestureRecognizer
{
    if ([self.navigationController.viewControllers count] > 1)
    {
        return YES;
    }
    else
    {
        return NO;
    }
}

#pragma mark - HTTP Request

- (void)plaza
{
    [self.tableView headerEndRefreshing];
    [self.tableView footerEndRefreshing];

}
- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    [self.calendar reloadData]; // Must be call in viewDidAppear
}

#pragma mark - Buttons callback

- (void)didGoTodayTouch
{
    [self.calendar setCurrentDate:[NSDate date]];
}

- (void)didChangeModeTouch
{
    self.calendar.calendarAppearance.isWeekMode = !self.calendar.calendarAppearance.isWeekMode;
    
    [self transitionExample];
}

#pragma mark - JTCalendarDataSource

- (BOOL)calendarHaveEvent:(JTCalendar *)calendar date:(NSDate *)date
{
    return (rand() % 10) == 1;
}

- (void)calendarDidDateSelected:(JTCalendar *)calendar date:(NSDate *)date
{
    NSLog(@"Date: %@", date);
}

#pragma mark - Transition examples

- (void)transitionExample
{
    CGFloat newHeight = 300;
    if(self.calendar.calendarAppearance.isWeekMode)
    {
        newHeight = 75.;
    }
    
    
    [UIView animateWithDuration:.5
                     animations:^{
                         self.calendarContentViewHeight.constant = newHeight;
                         [self changeFrame:newHeight];
                         [self.view layoutIfNeeded];
                     }];
    
    [UIView animateWithDuration:.25
                     animations:^{
                         self.calendarContentView.layer.opacity = 0;
                     }
                     completion:^(BOOL finished) {
                         [self.calendar reloadAppearance];
                         
                         [UIView animateWithDuration:.25
                                          animations:^{
                                              self.calendarContentView.layer.opacity = 1;
                                          }];
                     }];

}

-(void)changeFrame:(CGFloat)height
{
    self.headerView.frame =CGRectMake(0, 0, FM_SCREEN_WIDTH, height + 50);
    self.tableView.tableHeaderView=self.headerView;
}


#pragma mark -CycleScrollView Delegate
/*
 * 点击某一张图片
 */
- (void)tapActionView:(NSInteger)index{

}
/*
 * 左移一张图片
 */
- (void)cycNextScroll:(NSInteger)index{

}
/*
 * 右移一张图片
 */
- (void)cycPreviousScroll:(NSInteger)index{

}
@end
