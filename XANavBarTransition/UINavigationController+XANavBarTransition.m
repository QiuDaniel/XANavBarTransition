//
//  UINavigationController+XANavBarTransition.m
//  XANavBarTransitionDemo
//
//  Created by XangAm on 2017/8/1.
//  Copyright © 2017年 Lan. All rights reserved.
//

#import "UINavigationController+XANavBarTransition.h"
#import "UIViewController+XANavBarTransition.h"
#import "XATransitionManager.h"
#import <objc/message.h>

@implementation UINavigationController (XANavBarTransition)


#pragma mark - Transition
- (void)xa_configTransitionInfoWithType:(XATransitionType)transitionType
                           delegate:(id <XATransitionDelegate>)transitionDelegate{
    [XATransitionManager.sharedManager configTransitionWithNc:self
                                               transitionType:transitionType
                                           transitionDelegate:transitionDelegate ];
}

- (void)xa_unInitTransitionInfo{
    [XATransitionManager.sharedManager unInitTransitionWithNc:self];
}

#pragma mark - Alpha
- (void)xa_changeNavBarAlpha:(CGFloat)navBarAlpha{
    NSLog(@"xa:navBarAlpha:%lf",navBarAlpha);
    
    NSMutableArray *barSubviews = [NSMutableArray array];
    //将导航栏的子控件添加到数组当中,取首个子控件设置透明度(防止导航栏上存在非导航栏自带的控件)
    for (UIView * view in self.navigationBar.subviews) {
        if(![view isMemberOfClass:[UIView class]]){
            [barSubviews addObject:view];
        }
    }
    Ivar  backgroundOpacityVar =  class_getInstanceVariable([UINavigationBar class], "__backgroundOpacity");
    if(backgroundOpacityVar){
         [self.navigationBar setValue:@(navBarAlpha) forKey:@"__backgroundOpacity"];
    }
    UIView *barBackgroundView  = [barSubviews firstObject];
    barBackgroundView.alpha    = navBarAlpha;
}

#pragma mark - Getter/Setter
- (BOOL)xa_isTransitioning{
    return [objc_getAssociatedObject(self, _cmd)boolValue];
}

- (void)setXa_Transitioning:(BOOL)xa_Transitioning{
    objc_setAssociatedObject(self, @selector(xa_isTransitioning), @(xa_Transitioning), OBJC_ASSOCIATION_RETAIN);
}

- (BOOL)xa_isPopEnable{
    return [objc_getAssociatedObject(self, _cmd)boolValue];
}

- (void)setXa_popEnable:(BOOL)xa_popEnable{
     objc_setAssociatedObject(self, @selector(xa_isPopEnable), @(xa_popEnable), OBJC_ASSOCIATION_RETAIN);
}

@end
