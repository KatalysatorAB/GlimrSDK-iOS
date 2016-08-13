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
    
    // START COLLECTING
    KATConfiguration *config = [[KATConfiguration alloc] init];
    config.apiToken = [[NSUUID alloc] initWithUUIDString:@"B3945743-D258-49D0-AFBF-1E409AE59501"];
    config.suppressBluetoothAccuracyAlert = YES;
    
    KATBeaconManager *beaconManager = [[KATBeaconManager alloc] initWithConfiguration:config];
    [beaconManager startCollecting];
    
    [beaconManager debugWithHandler:^(id result) {
         NSLog(@"DEBUG %@", result);
     }];
    
    // RECEIVE TAGS
    KATAudienceManager *audienceManager = [[KATAudienceManager alloc] initWithApiToken:config.apiToken];
    [audienceManager audiencesAndGeotagsWithCompletion:^(NSDictionary *audiences, NSError *error) {
         NSLog(@"AUDIENCES %@", audiences);
     }];
}


@end
