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
typedef void(^KATAudienceHandler)(NSDictionary *audiences, NSError *error);


@interface KATAudienceManager : NSObject


/**
 * Init KATAudienceManager with delegate and apiToken
 *
 * @param apiToken auth token for ad authorization
 *
 * @return void
 * @since v1.4.0
 */
- (id)initWithApiToken:(NSUUID *)apiToken;


/**
 * Loads associated tags for a link between device and a custom audience
 *
 * @param completion the callback for the audience dictionary or error
 *
 * @return void
 * @since v1.2.6
 */
- (void)audiencesWithCompletion:(KATAudienceHandler)completion;


/**
 * Loads associated tags for a link between device and a custom audience
 *
 * @param completion the callback for the audience dictionary or error
 *
 * @return void
 * @since v1.5.4
 */
- (void)audiencesAndGeotagsWithCompletion:(KATAudienceHandler)completion;


/**
 * Allows adding additional data to a profile for creating audiences
 *
 * @param dict dictionary with additional information
 *
 * @return void
 * @since v1.4.0
 */
- (void)collect:(NSDictionary *)dict;


/**
 * Allows url tracking
 *
 * @param url
 *
 * @return void
 * @since v1.7.6
 */
+ (void)trackURL:(NSURL *)url;


/**
 * Performs a glimr conclude check
 *
 * @param concludes app checking
 * @param media media checking
 * @param urls url article recording
 *
 * @return void
 * @since v1.7.6
 */
- (void)conclude:(NSArray *)concludes media:(NSNumber *)media urls:(NSNumber *)urls;


@end
