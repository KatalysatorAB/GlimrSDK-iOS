//
//  KATAdvertisementManager.h
//  KatalysatorSample
//
//  Created by Sven Roeder on 19/08/14.
//  Copyright (c) 2014 Katalysator AB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KATBeaconConfiguration.h"
#import "KATAdvertisementView.h"

/**
 * KATAudienceHandler defines the callback for getting audiences
 *
 * @since v1.2.6
 */
typedef void(^KATAudienceHandler)(NSDictionary *audiences, NSError *error);


@protocol KATAdvertisementDelegate <NSObject>

@optional
- (void)katBannerViewWillLoadAd:(KATAdvertisementView *)advertisementView;
- (void)katBannerViewDidLoadAd:(KATAdvertisementView *)advertisementView requiredSize:(CGSize)size;
- (BOOL)katBannerViewActionShouldTrigger:(KATAdvertisementView *)advertisementView url:(NSURL *)url;
- (void)katBannerViewActionWillTrigger:(KATAdvertisementView *)advertisementView url:(NSURL *)url;
- (void)katBannerView:(KATAdvertisementView *)advertisementView didFailToReceiveAdWithError:(NSError *)error;
@end


@interface KATAdvertisementManager : NSObject

@property (nonatomic, weak) id <KATAdvertisementDelegate> delegate;


/**
 * Init KATAdvertisementManager with delegate and apiToken
 *
 * @param delegate delegate for ad management
 * @param apiToken auth token for ad authorization
 *
 * @return void
 * @since v1.2.6
 */
- (id)initWithDelegate:(id<KATAdvertisementDelegate>)delegate apiToken:(NSUUID *)apiToken;


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
 * Allows adding additional data to a profile for creating audiences
 *
 * @param dict dictionary with additional information
 *
 * @return void
 * @since v1.2.6
 */
- (void)enrichProfileWithDictionary:(NSDictionary *)dict;


/**
 * Initilizes loading of ads
 *
 * @return void
 * @since v1.2.6
 */
- (void)loadAd;


@end
