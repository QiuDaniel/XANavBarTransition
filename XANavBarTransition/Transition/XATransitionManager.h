//
//  XATransitionManager.h
//  XANavBarTransitionDemo
//
//  Created by xangam on 2018/5/21.
//  Copyright © 2018年 Lan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XABaseTransition.h"
#import "XANavBarTransitionConst.h"
#import "UINavigationController+XANavBarTransition.h"

@interface XATransitionManager : NSObject
@property (nonatomic, strong, readonly) XABaseTransition *transition;
@property (nonatomic, assign, readonly) XATransitionType transitionType;
@property (nonatomic, weak,   readonly) UINavigationController  *nc;
@property (nonatomic, weak,   readonly) id<XATransitionDelegate> transitionDelegate;

+ (instancetype)sharedManager;

- (void)configTransitionWithNc:(UINavigationController *)nc
                transitionType:(XATransitionType)transitionType
            transitionDelegate:(id<XATransitionDelegate>)transitionDelegate;

- (void)unInitTransitionWithNc:(UINavigationController *)nc;
@end
