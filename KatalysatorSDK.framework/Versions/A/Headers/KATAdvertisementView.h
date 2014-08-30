//
//  KATAdvertisementView.h
//  KatalysatorSample
//
//  Created by Sven Roeder on 19/08/14.
//  Copyright (c) 2014 Katalysator AB. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KATAdvertisement.h"

typedef void(^KATAdvertisementTriggerHandler)(NSURL *url);


@interface KATAdvertisementView : UIView

- (void)updateWithAdvertisement:(KATAdvertisement *)advertisement handler:(KATAdvertisementTriggerHandler)handler;

@end
