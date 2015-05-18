//
//  IEntity.h
//  LimitnessH
//
//  Created by 毅 叶 on 13-4-16.
//  Copyright (c) 2013年 Leaph. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol IEntity

@required

+ (NSArray*) getAllFields;

-(void) setFieldValue:(NSString*) fieldName value:(NSObject*) value;

- (id)getFromFieldValue:(NSString *)fieldName;

//@optional

@end


@protocol ICreateORUpdate

-(void)createTable;

- (void)createIndex;

- (BOOL)UpdateColumn;

- (Class)getClassModel;

@end
