//
//  XABaseTransition.h
//  XANavBarTransitionDemo
//
//  Created by xangam on 2018/5/21.
//  Copyright © 2018年 Lan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XABaseTransitionAnimation.h"
#import "XANavBarTransitionTool.h"
#import "UIViewController+XANavBarTransition.h"
@interface XABaseTransition : NSObject<UIGestureRecognizerDelegate>{
    @protected
    XABaseTransitionAnimation *_animation;
    UIPanGestureRecognizer *_pushInteractivePan;
    UIPanGestureRecognizer *_popInteractivePan;
}
@property (nonatomic, weak)   UIView *transitionView;
@property (nonatomic, weak)   UINavigationController *nc;
@property (nonatomic, weak)   id<XATransitionDelegate> transitionDelegate;
@property (nonatomic, strong) UIViewController *nextVC;
@property (nonatomic, assign) BOOL pushTransitionEnable;
@property (nonatomic, assign) BOOL popTransitionEnable;
@property (nonatomic, strong) UIPanGestureRecognizer *pushInteractivePan;
@property (nonatomic, strong) UIPanGestureRecognizer *popInteractivePan;
@property (nonatomic, strong) UIPercentDrivenInteractiveTransition *interactive;
@property (nonatomic, strong, readonly) XABaseTransitionAnimation *pushAnimation;
@property (nonatomic, strong, readonly) XABaseTransitionAnimation *popAnimation;
@property (nonatomic, assign, readonly) XATransitionMode transitionMode;

- (instancetype)initWithNavigationController:(UINavigationController *)nc
                            transitionAction:(XATransitionAction)action
                          transitionDelegate:(id<XATransitionDelegate>)delegate;

#pragma mark - Subclass Rewrite
- (void)setupWithNc:(UINavigationController *)nc
             action:(XATransitionAction)action
           delegate:(id<XATransitionDelegate>)delegate;

- (void)interactiveTransitioningEvent:(UIPanGestureRecognizer *)pan;

- (CGFloat)calcTransitioningX:(CGPoint)translationPoint;
@end

