//
//  AppDelegate.m
//  demoforlee
//
//  Created by jinglijun on 14/10/30.
//  Copyright (c) 2014年 jinglijun. All rights reserved.
//

#import "AppDelegate.h"
#import "Harpy.h"
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
        [[UINavigationBar appearance] setBackgroundImage:[UIImage imageNamed:@"title_bar_ios7.png"] forBarMetrics:UIBarMetricsDefault];
    NSMutableDictionary *titleBarAttributes = [NSMutableDictionary dictionaryWithDictionary: [[UINavigationBar appearance] titleTextAttributes]];
    [titleBarAttributes setValue:[UIFont fontWithName:@"HelveticaNeue-Light" size:20] forKey:NSFontAttributeName];
    [titleBarAttributes setValue:[UIColor whiteColor] forKey:NSForegroundColorAttributeName];
    [[UINavigationBar appearance] setTitleTextAttributes:titleBarAttributes];
    
    [[Harpy sharedInstance] setAppID:@"233143123"];
    
    // Set the UIViewController that will present an instance of UIAlertController
    [[Harpy sharedInstance] setPresentingViewController:_window.rootViewController];
    
    // (Optional) The tintColor for the alertController
    [[Harpy sharedInstance] setAlertControllerTintColor:[UIColor redColor]];
    
    // (Optional) Set the App Name for your app
    [[Harpy sharedInstance] setAppName:@"demo"];
    
    /* (Optional) Set the Alert Type for your app
     By default, Harpy is configured to use HarpyAlertTypeOption */
    [[Harpy sharedInstance] setAlertType:HarpyAlertTypeOption];
    
    /* (Optional) If your application is not availabe in the U.S. App Store, you must specify the two-letter
     country code for the region in which your applicaiton is available. */
    [[Harpy sharedInstance] setCountryCode:@"zh"];
    
    /* (Optional) Overides system language to predefined language.
     Please use the HarpyLanguage constants defined inHarpy.h. */
    [[Harpy sharedInstance] setForceLanguageLocalization:HarpyLanguageChineseSimplified];
    
    // Perform check for new version of your app
    [[Harpy sharedInstance] checkVersion];
    return YES;
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    
    /*
     Perform daily check for new version of your app
     Useful if user returns to you app from background after extended period of time
     Place in applicationDidBecomeActive:
     
     Also, performs version check on first launch.
     */
    [[Harpy sharedInstance] checkVersionDaily];
    
    /*
     Perform weekly check for new version of your app
     Useful if you user returns to your app from background after extended period of time
     Place in applicationDidBecomeActive:
     
     Also, performs version check on first launch.
     */
    [[Harpy sharedInstance] checkVersionWeekly];

}



- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
