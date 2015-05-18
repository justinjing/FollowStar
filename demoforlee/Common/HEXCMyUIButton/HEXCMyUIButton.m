//
//  HEXCMyUIButton.m
//  ReAssistiveTouch
//
//  Created by clq on 13-8-12.
//  Copyright (c) 2013年 hexc.QQ: 727021292 All rights reserved.
//

#import "HEXCMyUIButton.h"

@implementation HEXCMyUIButton
@synthesize MoveEnable;
@synthesize MoveEnabled;


#define kIOS7OffHeight (kIOSVersions>=7.0 ? 64 : 0)
#define kIOSVersions [[[UIDevice currentDevice] systemVersion] floatValue] //获得iOS版本
- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
    }
    return self;
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event{
    MoveEnabled = NO;
    [super touchesBegan:touches withEvent:event];
    if (!MoveEnable) {
        return;
    }
    UITouch *touch = [touches anyObject];
    beginpoint = [touch locationInView:self];
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event{
    
    MoveEnabled = YES;//单击事件可用

    if (!MoveEnable)
    {
        return;
    }
    UITouch *touch = [touches anyObject];
    CGPoint currentPosition = [touch locationInView:self];

    float offsetX = currentPosition.x - beginpoint.x;
    float offsetY = currentPosition.y - beginpoint.y;

    self.center = CGPointMake(self.center.x + offsetX, self.center.y + offsetY);

    if (self.center.x > (self.superview.frame.size.width-self.frame.size.width/2))
    {
        CGFloat x = self.superview.frame.size.width-self.frame.size.width/2;
        self.center = CGPointMake(x, self.center.y + offsetY);
    }
    else if (self.center.x < self.frame.size.width/2)
    {
        CGFloat x = self.frame.size.width/2;
        self.center = CGPointMake(x, self.center.y + offsetY);
    }
    
   if (self.center.y > (self.superview.frame.size.height-self.frame.size.height/2))
   {
       CGFloat x = self.center.x;
       CGFloat y = self.superview.frame.size.height-self.frame.size.height/2;
       self.center = CGPointMake(x, y);
   }
   else if (self.center.y <= self.frame.size.height/2)
   {
       CGFloat x = self.center.x;
       CGFloat y = self.frame.size.height/2;
       self.center = CGPointMake(x, y);
    }
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    if (!MoveEnable) {
        return;
    }
    if (self.center.y >= self.superview.frame.size.height - 120)
    {
        [UIView beginAnimations:@"move" context:nil];
        [UIView setAnimationDuration:0.5];
        [UIView setAnimationDelegate:self];
        [UIView setAnimationCurve:UIViewAnimationCurveEaseOut];
        self.frame=CGRectMake(self.center.x - 35,self.superview.frame.size.height - 92.0, 72.f,72.f);
        [UIView commitAnimations];
    }
    else if (self.center.y <= 150)
    {
        [UIView beginAnimations:@"move" context:nil];
        [UIView setAnimationDuration:0.5];
        [UIView setAnimationDelegate:self];
        [UIView setAnimationCurve:UIViewAnimationCurveEaseOut];
        self.frame=CGRectMake(self.center.x - 35,kIOS7OffHeight -3.0, 72.f,72.f);
        [UIView commitAnimations];
    }
    else if (self.center.x >= self.superview.frame.size.width/2)
    {
        [UIView beginAnimations:@"move" context:nil];
        [UIView setAnimationDuration:0.5];
        [UIView setAnimationDelegate:self];
        [UIView setAnimationCurve:UIViewAnimationCurveEaseOut];
        self.frame=CGRectMake(self.superview.frame.size.width - 70.0f,self.center.y-35, 72.f,72.f);
        [UIView commitAnimations];
    }
    else
    {

        [UIView beginAnimations:@"move" context:nil];
        [UIView setAnimationDuration:0.5];
        [UIView setAnimationCurve:UIViewAnimationCurveEaseOut];
        [UIView setAnimationDelegate:self];
        self.frame=CGRectMake(-3.0f,self.center.y-35.0, 72.f,72.f);
        [UIView commitAnimations];

    }
    
  
    [super touchesEnded: touches withEvent: event];

}


- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
    
}

@end
