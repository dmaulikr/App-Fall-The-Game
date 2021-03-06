/*
 This file is part of Appirater.
 
 Copyright (c) 2010, Arash Payan
 All rights reserved.
 
 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:
 
 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
 */
/*
 * Appirater.h
 * appirater
 *
 * Created by Arash Payan on 9/5/09.
 * http://arashpayan.com
 * Copyright 2010 Arash Payan. All rights reserved.
 */

#import <Foundation/Foundation.h>

extern NSString *const kAppiraterLaunchDate;
extern NSString *const kAppiraterLaunchCount;
extern NSString *const kAppiraterCurrentVersion;
extern NSString *const kAppiraterRatedCurrentVersion;
extern NSString *const kAppiraterDeclinedToRate;
extern NSString *const kAppiraterAppID;

/*
 Your app's name.
 */
#define APPIRATER_APP_NAME				self.appName

/*
 The localized template message for displaying the rating request
 */
#define APPIRATER_LOCALIZED_MESSAGE		NSLocalizedString(@"If you enjoy using %@, would you mind taking a moment to rate it? Thanks for your support!", @"rating message")

/*
 This is the message your users will see once they've passed the day+launches
 threshold.
 */
#define APPIRATER_MESSAGE				[NSString stringWithFormat:APPIRATER_LOCALIZED_MESSAGE, APPIRATER_APP_NAME]

/*
 The localized template title of the message alert
 */

#define APPIRATER_LOCALIZED_TITLE		NSLocalizedString(@"Rate %@", @"rating title for dialog")

/*
 This is the title of the message alert that users will see.
 */
#define APPIRATER_MESSAGE_TITLE			[NSString stringWithFormat:APPIRATER_LOCALIZED_TITLE, APPIRATER_APP_NAME]

/*
 The text of the button that rejects reviewing the app.
 */
#define APPIRATER_CANCEL_BUTTON			NSLocalizedString(@"No, Thanks", @"rating no button text")

/*
 The localized confirm button text
 */

#define APPIRATER_LOCALIZED_RATE_BUTTON NSLocalizedString(@"Yes, Rate %@", @"rating yes button text")

/*
 Text of button that will send user to app review page.
 */
#define APPIRATER_RATE_BUTTON			[NSString stringWithFormat:APPIRATER_LOCALIZED_RATE_BUTTON, APPIRATER_APP_NAME]

/*
 Text for button to remind the user to review later.
 */
#define APPIRATER_RATE_LATER			NSLocalizedString(@"Remind me later", @"rating reminder button text")

/*
 Users will need to have the same version of your app installed for this many
 days before they will be prompted to rate it.
 */
#define DAYS_UNTIL_PROMPT				4		// double

/*
 Users will need to launch the same version of the app this many times before
 they will be prompted to rate it.
 */
#define LAUNCHES_UNTIL_PROMPT			7		// integer

/*
 'YES' will show the Appirater alert everytime. Useful for testing how your message
 looks and making sure the link to your app's review page works.
 */
#ifdef DEBUG
	#define APPIRATER_DEBUG				NO
#else
	#define APPIRATER_DEBUG				NO
#endif

@interface Appirater : NSObject <UIAlertViewDelegate> {

}

//appID is Apple ID from iTunes Connect, eg: 330453998
+ (void)appLaunchedWithID:(NSInteger)appID;
+ (void)applicationWillEnterForeground;
+ (void)openAppStoreReviewPage;

@end
