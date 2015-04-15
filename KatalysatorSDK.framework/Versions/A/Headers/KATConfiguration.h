//
//  KATConfiguration.h
//  KatalysatorSDK
//
//  Created by Sven Roeder on 10/18/13.
//  Copyright (c) 2013 Katalysator AB. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

/**
 * KATHandlerFilter allows bit mask callback filtering.
 * The actual type is configured on the Katalysator backend.
 * Contact Katalysator AB for more information on this.
 *
 */
typedef NS_OPTIONS(NSUInteger, KATHandlerFilter) {
    /** The KATAdvertHandler will return all kinds of data. This might be:
     * NSDictionary, UILocationNotification
     * @since v1.0
     */
    KATHandlerFilterAll     = 1 << 0,
    /** The KATAdvertHandler will return only return key value results wrapped in a NSDictionary. 
     * @since v1.0
     */
    KATHandlerFilterData    = 1 << 1,
    /** The KATAdvertHandler will return only return alert types of UILocalNotifications. 
     * @since v1.0
     */
    KATHandlerFilterAlert   = 1 << 2
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
/// @name API token and beacon token
////////////////////////////////////////////////////////////////////////////////

/**
 * UUID for the region/beacon that should be monitored or ranged.
 * Contact Katalysator AB for more information on this.
 * @warning `regionToken` can be `nil`. In that case regions can be managed on the backend
 *
 * @since v1.0
 */
@property (strong, nonatomic) NSUUID *regionToken;


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
 * KATHandlerFilter allows bit mask callback filtering.
 * Since there are many options for different beacons and notification types and opportunities
 * it is possible to constrain the types of call backs the integrating app wants to receive data for.
 *
 * @since v1.0
 */
@property (nonatomic) KATHandlerFilter handlerFilter;


/**
 * Settings suppressBluetoothAccuracyAlert to YES will disable the alert that usually pops up
 * When using CoreLocation + Beacon and Bluetooth is turned off on the device.
 *
 * @since v1.0.8
 */
@property (nonatomic) BOOL suppressBluetoothAccuracyAlert;


/**
 * Settings allowCircularRegionMonitoring allows to monitor circular regions configured on the dashboard
 *
 * @since v1.1.7
 */
@property (nonatomic) BOOL allowCircularRegionMonitoring;


/**
 * Settings allowAdvertisingIdentifierAccess allows the sdk to include the IDFA in the request payload
 *
 * @since v1.1.8
 */
@property (nonatomic) BOOL allowAdvertisingIdentifierAccess;


/**
 * Settings askForNotificationPermission will ask for notifications permission if not allowed already
 *
 * @since v1.4.1
 */
@property (nonatomic) BOOL askForNotificationPermission;


/**
 * Settings askForLocationPermission will ask for location permission if not allowed already, default is YES
 *
 * @since v1.5.6
 */
@property (nonatomic) BOOL askForLocationPermission;


/**
 * Get current list of regions to monitor managed on the backend.
 * To use this `regionToken` must be nil.
 *
 * @param update forces the region list update
 * @param coordinate for adjusting regions
 * @param completion handler
 * @return local config
 *
 * @since v1.4.2
 */
- (NSArray *)configUpdate:(BOOL)force coordinate:(CLLocationCoordinate2D)coordinate completion:(KATUpdateConfigHandler)completion;


@end
