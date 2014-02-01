//
//  KATBeaconManager.h
//  Example
//
//  Created by Sven Roeder on 10/17/13.
//  Copyright (c) 2013 Katalysator AB. All rights reserved.
//

#import "KATBeaconConfiguration.h"


/**
 * KATAdvertHandler defines the callback for beacon actions
 *
 */
typedef void(^KATAdvertHandler)(id result, NSError *error);


/**
 * KATDebugHandler defines the callback for debug calls
 *
 */
typedef void(^KATDebugHandler)(id result);



@interface KATBeaconManager : NSObject


/**
 * A shared version of the KATBeaconManager
 *
 * @return an previous instantiated instance of the KATBeaconManager
 */
+ (instancetype)shared;


/**
 * Inits the KATBeaconManager
 *
 * @return instancetype a KATBeaconManager instance with profile settings
 */
- (instancetype)initWithConfiguration:(KATBeaconConfiguration *)configuration;


/**
 * Starts monitoring / ranging for beacons and does callbacks
 *
 * @param handler the callback function when a beacon action is fired
 *
 * @return void
 */
- (void)startWithHandler:(KATAdvertHandler)handler;


/**
 * The handler gets called at different locations to help debugging
 *
 * @param handler the callback for various debug calls
 *
 * @return void
 */
- (void)debugWithHandler:(KATDebugHandler)handler;


/**
 * Stops monitoring and ranging beacons
 *
 * @return void
 */
- (void)stop;


@end
