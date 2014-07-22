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
    
    KATBeaconConfiguration *beaconConfiguration = [[KATBeaconConfiguration alloc] init];
    beaconConfiguration.beaconToken = [[NSUUID alloc] initWithUUIDString:@"AAAAAAAA-AAAA-AAAA-AAAA-AAAAAAAAAAAA"];
    beaconConfiguration.apiToken = [[NSUUID alloc] initWithUUIDString:@"B3945743-D258-49D0-AFBF-1E409AE59501"];
    beaconConfiguration.handlerFilter = KATHandlerFilterData;
    beaconConfiguration.presentingView = nil;
    beaconConfiguration.allowCircularRegionMonitoring = YES;
    beaconConfiguration.allowAdvertisingIdentifierAccess = YES;
    beaconConfiguration.suppressBluetoothAccuracyAlert = YES;
    
    KATBeaconManager *beaconManager = [[KATBeaconManager alloc] initWithConfiguration:beaconConfiguration];
    
    [beaconManager startWithHandler:^(id result, BOOL cached, NSError *error)
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
}


@end
