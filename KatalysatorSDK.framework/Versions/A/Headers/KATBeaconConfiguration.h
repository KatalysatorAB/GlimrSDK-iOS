//
//  KATBeaconConfiguration.h
//  KatalysatorSDK
//
//  Created by Sven Roeder on 10/18/13.
//  Copyright (c) 2013 Katalysator AB. All rights reserved.
//


/**
 * KATHandlerFilter allows bit mask callback filtering.
 * The actual type is configured on the Katalysator backend.
 * Contact Katalysator AB for more information on this.
 *
 */
typedef NS_OPTIONS(NSUInteger, KATHandlerFilter) {
    /** The KATAdvertHandler will return all kinds of data. This might be:
     * NSDictionary, UILocationNotification, UIView 
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
    KATHandlerFilterAlert   = 1 << 2,
    /** The KATAdvertHandler will return only return types or subclasses of UIView. 
     * @since v1.0
     */
    KATHandlerFilterView    = 1 << 3,
};


/**
 * KATDebugHandler defines the callback for debug calls.
 *
 * @since v1.0
 */
typedef void(^KATUpdateRegionsHandler)(NSArray *regions, NSError *error);


/**
 
 A KATBeaconConfiguration object provides the settings for monitoring/ranging of a certain beacon as well as authentication properties against the Katalysator backend.
 
 An instance of this class needs to be passed in when initializing the KATBeaconManager.
 
 */
@interface KATBeaconConfiguration : NSObject


////////////////////////////////////////////////////////////////////////////////
/// @name API token and beacon token
////////////////////////////////////////////////////////////////////////////////

/**
 * UUID for the region/beacon that should be monitored or ranged.
 * Contact Katalysator AB for more information on this.
 * @warning `beaconToken` can be `nil`. In that case regions can be managed on the backend
 *
 * @since v1.0
 */
@property (strong, nonatomic) NSUUID *beaconToken;


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
 * Optionally you can supply a presenting view which will be feeded with the results. 
 * This property has only effect in certain circumstances:
 * - The integrating app needs to be in foreground during the beacon trigger
 * - The handlerFilter must be set to KATHandlerFilterView
 * - The backend configuration needs to be configured to match these settings
 *
 * @since v1.0
 */
@property (strong, nonatomic) UIView *presentingView;


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
 * Get current list of regions to monitor managed on the backend.
 * To use this `beaconToken` must be nil.
 *
 * @param update forces the region list update
 * @param completion handler
 *
 * @since v1.1.6
 */
- (NSArray *)beaconRegionsForceUpdate:(BOOL)update completion:(KATUpdateRegionsHandler)completion;


@end
