//
//  KATCouponManager.h
//  KatalysatorSample
//
//  Created by Sven Roeder on 26/06/14.
//  Copyright (c) 2014 Katalysator AB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KATBeaconConfiguration.h"


/**
 * KATCouponHandler defines the callback for generating a coupon.
 *
 * @since v1.1.4
 */
typedef void(^KATCouponHandler)(NSDictionary *coupon);


@interface KATCouponManager : NSObject


/**
 * Allows to generate a coupon.
 * This also depends on the beacon configuration on the backend.
 *
 * @param key coupon storekey
 * @param config the api configuration
 * @param completion the callback for generating a coupon
 *
 * @return void
 * @since v1.1.4
 */
+ (void)couponForId:(NSString *)key configuration:(KATBeaconConfiguration *)config completion:(KATCouponHandler)completion;


@end
