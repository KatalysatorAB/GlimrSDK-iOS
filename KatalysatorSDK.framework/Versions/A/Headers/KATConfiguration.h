//
//  KATConfiguration.h
//  KatalysatorSDK
//
//  Created by Sven Roeder on 10/18/13.
//  Copyright (c) 2013 Katalysator AB. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

/**
 * KATSSLPinningMode ssl pinning mode. Default is KATSSLPinningModeNone
 *
 */
typedef NS_OPTIONS(NSUInteger, KATSSLPinningMode) {
    KATSSLPinningModeNone    = 1 << 0,
    KATSSLPinningModeLeaf    = 1 << 1,
    KATSSLPinningModeChain   = 1 << 2
};


/**
 * KATDebugHandler defines the callback for debug calls.
 *
 * @since v1.0
 */
typedef void(^KATUpdateConfigHandler)(NSArray *regions, NSError *error);


/**
 
 A KATConfiguration object provides the settings for monitoring/ranging of a certain beacon as well as authentication properties against the Katalysator backend.
 
 An instance of this class needs to be passed in when initializing the KATBeaconManager.
 
 */
@interface KATConfiguration : NSObject


////////////////////////////////////////////////////////////////////////////////
/// @name API token
////////////////////////////////////////////////////////////////////////////////


/**
 * UUID to authenticate against the Katalysator cloud api.
 * Contact Katalysator AB for more information on this.
 * @warning `apiToken` must not be `nil`.
 *
 * @since v1.0
 */
@property (copy, nonatomic) NSUUID *apiToken;


////////////////////////////////////////////////////////////////////////////////
/// @name Callback options
////////////////////////////////////////////////////////////////////////////////


/**
 * Settings suppressBluetoothAccuracyAlert to YES will disable the alert that usually pops up
 * When using CoreLocation + Beacon and Bluetooth is turned off on the device.
 *
 * @since v1.0.8
 */
@property (nonatomic) BOOL suppressBluetoothAccuracyAlert;


/**
 * Settings askForLocationPermission will ask for location permission if not allowed already, default is YES
 *
 * @since v1.5.6
 */
@property (nonatomic) BOOL askForLocationPermission;


/**
 * Checks if a config update is required
 *
 * @since v1.6.8
 */
@property (nonatomic) BOOL needsConfigUpdate;


/**
 * Get the local config
 *
 * @since v1.6.8
 */
@property (nonatomic) NSArray *localConfig;


/**
 * Get current list of regions to monitor managed on the backend.
 * To use this `regionToken` must be nil.
 *
 * @param update forces the region list update
 * @param location for adjusting regions
 * @param completion handler
 *
 * @since v1.7.2
 */
- (void)configUpdate:(BOOL)force location:(CLLocation *)location completion:(KATUpdateConfigHandler)completion;


/**
 * Check if caching is disabled, use for development only
 *
 * @since v1.6.9
 */
+ (BOOL)disableCaching;


/**
 * Disables caching on the device, use for development only
 *
 * @since v1.6.9
 */
+ (void)setDisableCaching:(BOOL)value;


/**
 * Method to enable ssl pinning. Please be aware that this requires additional files inside the app bundle.
 * Depending on the mode public certificates for *.appspot.com are required.
 *
 *
 * @since v1.5.6
 */
+ (void)setPinningMode:(KATSSLPinningMode)pinningMode;


@end
