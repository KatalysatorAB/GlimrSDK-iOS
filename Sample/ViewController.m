//
//  ViewController.m
//  Sample
//
//  Created by Sven Roeder on 02/11/13.
//  Copyright (c) 2013 Katalysator AB. All rights reserved.
//

#import "ViewController.h"
#import <KatalysatorSDK/KatalysatorSDK.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    KATBeaconConfiguration *beaconConfiguration = [[KATBeaconConfiguration alloc] init];
    beaconConfiguration.beaconToken = [[NSUUID alloc] initWithUUIDString:@"KAT_BEACON_ID"];
    beaconConfiguration.apiToken = [[NSUUID alloc] initWithUUIDString:@"KAT_API_TOKEN"];
    beaconConfiguration.handlerFilter = KATHandlerFilterData;
    beaconConfiguration.presentingView = nil;
    
    KATBeaconManager *beaconManager = [[KATBeaconManager alloc] initWithConfiguration:beaconConfiguration];
    [beaconManager startWithHandler:^(id result, NSError *error) {
        NSLog(@"RESULT %@", result);
    }];
    
    [beaconManager debugWithHandler:^(id result) {
        NSLog(@"DEBUG %@", result);
    }];
}


@end
