//
//  ConversationsModel.h
//  demoforlee
//
//  Created by justinjing on 15/5/18.
//  Copyright (c) 2015年 jinglijun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IEntity.h"


@interface ConversationsModel : NSObject<IEntity>

@property (nonatomic,copy) NSString *albumurl;//封面头像链接
@property (nonatomic,copy) NSString *maintitleContent;//  首航title标题
@property (nonatomic,copy) NSString *deadlineContent;//  开始时间和截至时间
@property (nonatomic,copy) NSString *attentionCount; //关注数量
@property (nonatomic,copy) NSString *keywords;//  关键字
@property (nonatomic,copy) NSString *smalltitleContent;//  详细介绍
@property (nonatomic,copy) NSString *TVStation;// 首尔电视台
@property (nonatomic,copy) NSString *redActiveteLabel;// 红色关键字
@property (nonatomic,assign) BOOL isOnline; //线上线下



+(NSArray*) getAllFields;
-(void)setFieldValue:(NSString*)fieldName value:(NSObject*) value;
-(id)getFromFieldValue:(NSString *)fieldName;


@end
