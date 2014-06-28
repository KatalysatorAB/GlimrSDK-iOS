//
//  KATSurveyManager.h
//  KatalysatorSample
//
//  Created by Sven Roeder on 26/06/14.
//  Copyright (c) 2014 Katalysator AB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KATBeaconConfiguration.h"

@interface KATSurveyManager : NSObject


/**
 * Track answers to a survey. Simply post the array with the questions and
 * filled answer key
 *
 * @param answers
 * @param config the api configuration
 *
 * @return void
 * @since v1.1.4
 */
+ (void)submitSurvey:(NSArray *)answers configuration:(KATBeaconConfiguration *)configuration;


@end
