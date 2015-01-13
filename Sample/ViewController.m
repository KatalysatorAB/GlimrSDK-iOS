//
//  ViewController.m
//  Sample
//
//  Created by Sven Roeder on 02/11/13.
//  Copyright (c) 2013 Katalysator AB. All rights reserved.
//

#import "ViewController.h"
#import <KatalysatorSDK/KatalysatorSDK.h>


@implementation ViewController


- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    // REGION TRACKING
    KATConfiguration *config = [[KATConfiguration alloc] init];
    config.apiToken = [[NSUUID alloc] initWithUUIDString:@"B3945743-D258-49D0-AFBF-1E409AE59501"];
    config.handlerFilter = KATHandlerFilterData;
    config.allowCircularRegionMonitoring = YES;
    config.allowAdvertisingIdentifierAccess = YES;
    config.suppressBluetoothAccuracyAlert = YES;
    
    KATBeaconManager *beaconManager = [[KATBeaconManager alloc] initWithConfiguration:config];
    
    [beaconManager startWithHandler:^(id result, BOOL cached, NSDate *date, NSError *error)
    {
        NSLog(@"RESULT %@", result);
    }];
    
    [beaconManager triggerWithHandler:^(NSDictionary *requestDict)
    {
        NSLog(@"TRIGGER %@", requestDict);
    }];
    
    [beaconManager debugWithHandler:^(id result)
    {
        NSLog(@"DEBUG %@", result);
    }];
    
    // AUDIENCE
    KATAudienceManager *audienceManager = [[KATAudienceManager alloc] initWithApiToken:config.apiToken];
    [audienceManager collect:@{@"userId" : @"sven@glimr.io"}];
    [audienceManager audiencesWithCompletion:^(NSDictionary *audiences, NSError *error)
     {
         NSLog(@"AUDIENCES %@", audiences);
     }];
}


@end
