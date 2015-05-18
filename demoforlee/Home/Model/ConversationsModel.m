//
//  ConversationsModel.m
//  demoforlee
//
//  Created by justinjing on 15/5/18.
//  Copyright (c) 2015年 jinglijun. All rights reserved.
//

#import "ConversationsModel.h"

@implementation ConversationsModel
@synthesize albumurl = _albumurl;
@synthesize maintitleContent = _maintitleContent;
@synthesize deadlineContent = _deadlineContent;
@synthesize attentionCount = _attentionCount;
@synthesize keywords = _keywords;
@synthesize smalltitleContent = _smalltitleContent;
@synthesize TVStation = _TVStation;
@synthesize isOnline = _isOnline;

- (id)init{
    self = [super init];
    
    if (self) {
            self.albumurl = @"weather_snow.png";
            self.maintitleContent = @"正在加载中...";
            self.deadlineContent = @"欢迎您使用问理财，这是一个神奇的功能! 您有钱？放在口袋闲得欢？没事，找问理财，这里提供给您最好的理财方案。而且还是免费的哦！";
            self.keywords = @"20131014";
            self.smalltitleContent = @"afsdasf";
            self.TVStation = @"0";
            self.attentionCount = @"0";
            self.isOnline = NO;
    }
    
    return self;
}

+ (NSArray*) getAllFields
{
    return @[@"attentionCount",
             @"albumurl",
             @"maintitleContent",
             @"deadlineContent",
             @"keywords",
             @"smalltitleContent"];
}

-(void) setFieldValue:(NSString*) fieldName value:(NSObject*) value
{

}

- (id)getFromFieldValue:(NSString *)fieldName
{
    if ([fieldName  isEqualToString:@"attentionCount"]) {
        return self.attentionCount;
    }
    else if ([fieldName isEqualToString:@"albumurl"])
    {
        return self.albumurl;
    }

    else if ([fieldName isEqualToString:@"maintitleContent"])
    {
        return self.maintitleContent;
    }
    else if ([fieldName isEqualToString:@"deadlineContent"])
    {
        return self.deadlineContent;
    }
    else if ([fieldName isEqualToString:@"keywords"])
    {
        return self.keywords;
    }
    else if ([fieldName isEqualToString:@"smalltitleContent"])
    {
        return self.smalltitleContent;
    }
    else {
        NSLog(@"Error");
        return nil;
    }
}


@end
