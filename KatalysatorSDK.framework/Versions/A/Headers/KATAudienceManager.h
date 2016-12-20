//
//  KATAudienceManager.h
//  KatalysatorSample
//
//  Created by Sven Roeder on 19/08/14.
//  Copyright (c) 2014 Katalysator AB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KATConfiguration.h"

/**
 * KATAudienceHandler defines the callback for getting audiences
 *
 * @since v1.2.6
 */
typedef void(^KATAudienceHandler)(NSDictionary * _Nullable audiences,  NSError * _Nullable error);


/**
 * KATTagResponseFormat gives the option to retrieve the response tags in a specific format
 *
 */
typedef NS_OPTIONS(NSUInteger, KATTagResponseFormat) {
    /** The KATTagResponseFormatFlat returns the tag in a flat array
     * @since v1.9.4
     */
    KATTagResponseFormatFlat = 1,
    /** The KATTagResponseFormatMap returns the tags in a dictionary format
     * @since v1.9.4
     */
    KATTagResponseFormatMap = 2,
};


@interface KATAudienceManager : NSObject


/**
 * Init KATAudienceManager with delegate and apiToken
 *
 * @param apiToken auth token for ad authorization
 *
 * @return void
 * @since v1.4.0
 */
- (id _Nullable)initWithApiToken:(NSUUID * _Nonnull)apiToken;


/**
 * Loads associated tags for a link between device and a custom audience
 *
 * @param completion the callback for the audience dictionary or error
 *
 * @return void
 * @since v1.2.6
 */
- (void)audiencesWithCompletion:(KATAudienceHandler _Nullable)completion;


/**
 * Loads associated tags for a link between device and a custom audience
 *
 * @param completion the callback for the audience dictionary or error
 *
 * @return void
 * @since v1.5.4
 */
- (void)audiencesAndGeotagsWithCompletion:(KATAudienceHandler _Nullable)completion;


/**
 * Get the latest local tags
 *
 * @return dictionary or array of tags containing list and mapped tags
 * @since v1.9.4
 */
- (id _Nullable)cachedTags:(KATTagResponseFormat)format;


/**
 * Allows adding additional data to a profile for creating audiences
 *
 * @param dict dictionary with additional information
 *
 * @return void
 * @since v1.4.0
 */
- (void)collect:(NSDictionary * _Nullable)dict;


/**
 * Allows url tracking
 *
 * @param url
 *
 * @return void
 * @since v1.7.6
 */
+ (void)trackURL:(NSURL * _Nonnull)url;


/**
 * Performs a glimr conclude check
 *
 * @param concludes app checking
 * @param urls url article recording
 *
 * @return void
 * @since v1.7.6
 */
- (void)conclude:(NSArray * _Nullable)concludes urls:(NSNumber * _Nullable)urls;


/**
 * Utility method to create a query string out of a Glimr tag dict
 *
 * @param tag dictionary
 *
 * @return string
 * @since v1.8.2
 */
+ (NSString * _Nullable)toQueryString:(NSDictionary * _Nonnull)kv;


/**
 * Utility method to check if headphones are conntected
 *
 * @return bool
 * @since v1.9.3
 */
+ (BOOL)hasHeadphonesConnected;


@end
