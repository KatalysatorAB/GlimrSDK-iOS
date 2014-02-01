//
//  KATBeaconConfiguration.h
//  KatalysatorSDK
//
//  Created by Sven Roeder on 10/18/13.
//  Copyright (c) 2013 Katalysator AB. All rights reserved.
//


/**
 * KATHandlerFilter allows bit mask callback filtering
 *
 */
typedef NS_OPTIONS(NSUInteger, KATHandlerFilter) {
    KATHandlerFilterAll     = 1 << 0,
    KATHandlerFilterData    = 1 << 1,
    KATHandlerFilterAlert   = 1 << 2,
    KATHandlerFilterView    = 1 << 3,
};


@interface KATBeaconConfiguration : NSObject


/**
 * UUID for the region / beacon that needs to be monitored
 *
 */
@property (strong, nonatomic) NSUUID *beaconToken;


/**
 * UUID to authenticate against the katalysatorlab cloud api
 *
 */
@property (strong, nonatomic) NSUUID *apiToken;


/**
 * Optionally you can supply a presenting view which will be feeded with the results
 *
 */
@property (strong, nonatomic) UIView *presentingView;


/**
 * KATHandlerFilter allows bit mask callback filtering
 *
 */
@property (nonatomic) KATHandlerFilter handlerFilter;


@end
