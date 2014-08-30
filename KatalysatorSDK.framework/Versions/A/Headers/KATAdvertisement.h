//
//  KATAdvertisement.h
//  KatalysatorSample
//
//  Created by Sven Roeder on 19/08/14.
//  Copyright (c) 2014 Katalysator AB. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KATAdvertisement : NSObject

@property (nonatomic, copy) NSNumber *type;
@property (nonatomic, copy) NSNumber *format;
@property (nonatomic, copy) NSDictionary *dimension;
@property (nonatomic, copy) NSArray *elements;
@property (nonatomic, copy) NSString *key;

@end
