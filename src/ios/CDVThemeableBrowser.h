/*
 Licensed to the Apache Software Foundation (ASF) under one
 or more contributor license agreements.  See the NOTICE file
 distributed with this work for additional information
 regarding copyright ownership.  The ASF licenses this file
 to you under the Apache License, Version 2.0 (the
 "License"); you may not use this file except in compliance
 with the License.  You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing,
 software distributed under the License is distributed on an
 "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied.  See the License for the
 specific language governing permissions and limitations
 under the License.
 */

#import <Cordova/CDVPlugin.h>
#import <Cordova/CDVInvokedUrlCommand.h>
#import <Cordova/CDVScreenOrientationDelegate.h>
#import "CDVInAppBrowser.h"



#ifdef __CORDOVA_4_0_0
    #import <Cordova/CDVUIWebViewDelegate.h>
#else
    #import <Cordova/CDVWebViewDelegate.h>
#endif

@interface CDVThemeableBrowserOptions : NSObject {}

@property (nonatomic) BOOL location;
@property (nonatomic) NSString* closebuttoncaption;
@property (nonatomic) NSString* toolbarposition;
@property (nonatomic) BOOL clearcache;
@property (nonatomic) BOOL clearsessioncache;

@property (nonatomic) NSString* presentationstyle;
@property (nonatomic) NSString* transitionstyle;

@property (nonatomic) BOOL zoom;
@property (nonatomic) BOOL mediaplaybackrequiresuseraction;
@property (nonatomic) BOOL allowinlinemediaplayback;
@property (nonatomic) BOOL keyboarddisplayrequiresuseraction;
@property (nonatomic) BOOL suppressesincrementalrendering;
@property (nonatomic) BOOL hidden;
@property (nonatomic) BOOL disallowoverscroll;

@property (nonatomic) NSDictionary* statusbar;
@property (nonatomic) NSDictionary* toolbar;
@property (nonatomic) NSDictionary* title;
@property (nonatomic) NSDictionary* backButton;
@property (nonatomic) NSDictionary* forwardButton;
@property (nonatomic) NSDictionary* closeButton;
@property (nonatomic) NSDictionary* menu;
@property (nonatomic) NSArray* customButtons;
@property (nonatomic) BOOL backButtonCanClose;
@property (nonatomic) BOOL disableAnimation;
@property (nonatomic) BOOL fullscreen;
@property (nonatomic) NSString *logoUrl;
@property (nonatomic) BOOL showPriceIt, openedFromPdp;
@property (nonatomic) int price_points;
@property (nonatomic) float percentage_saved;


@end

@class CDVThemeableBrowserViewController;

@interface CDVThemeableBrowser : CDVInAppBrowser {
    BOOL _injectedIframeBridge;
    int _taps;
}

@property (nonatomic, retain) CDVThemeableBrowserViewController* themeableBrowserViewController;
@property (nonatomic, copy) NSString* callbackId;
@property (nonatomic, copy) NSRegularExpression *callbackIdPattern;
@property (nonatomic) BOOL openedPdp;
@property (nonatomic) long userId;


- (CDVThemeableBrowserOptions*)parseOptions:(NSString*)options;
- (void)open:(CDVInvokedUrlCommand*)command;
- (void)close:(CDVInvokedUrlCommand*)command;
- (void)foundProduct:(CDVInvokedUrlCommand*)command;
-(void)openProduct;
- (void)priceIt;
- (void)injectScriptCode:(CDVInvokedUrlCommand*)command;
- (void)show:(CDVInvokedUrlCommand*)command;
- (void)show:(CDVInvokedUrlCommand*)command withAnimation:(BOOL)animated;
- (void)reload:(CDVInvokedUrlCommand*)command;
- (void)gotStatusCode:(CDVInvokedUrlCommand*)command;



@end

@interface CDVThemeableBrowserViewController : UIViewController <UIWebViewDelegate, CDVScreenOrientationDelegate, UIActionSheetDelegate>{
    @private
    NSString* _userAgent;
    NSString* _prevUserAgent;
    NSInteger _userAgentLockToken;
    UIStatusBarStyle _statusBarStyle;
    
#ifdef __CORDOVA_4_0_0
    CDVUIWebViewDelegate* _webViewDelegate;
#else
    CDVWebViewDelegate* _webViewDelegate;
#endif
    
}

@property (nonatomic, strong) IBOutlet UIWebView* webView;
@property (nonatomic, strong) IBOutlet UIButton* closeButton;
@property (nonatomic, strong) IBOutlet UILabel* addressLabel;
@property (nonatomic, strong) IBOutlet UILabel* titleLabel;
@property (nonatomic, strong) IBOutlet UIButton* titleButton;
@property (nonatomic, strong) IBOutlet UIButton* backButton;
@property (nonatomic, strong) IBOutlet UIButton* forwardButton;
@property (nonatomic, strong) IBOutlet UIButton* menuButton;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView* spinner;
@property (nonatomic, strong) IBOutlet UIView* toolbar;
@property (nonatomic, strong)UILabel* savingsLabel, *loadingLabel;
@property (nonatomic, strong)UIButton *priceItButton, *detailButton, *arrowButton;
@property (nonatomic, strong)UIProgressView *progressBar;
@property (nonatomic)float progress;
@property (nonatomic, strong)UIView *loadingView, *savingsView, *footerView;

@property (nonatomic, strong) NSArray* leftButtons;
@property (nonatomic, strong) NSArray* rightButtons;
@property (nonatomic) BOOL searching, inProduction, sucess, pricing;
@property (nonatomic, strong)NSString *currentUrl;
@property (nonatomic, strong)UIImageView *headerImageView;
@property (nonatomic)CDVThemeableBrowserOptions *browserOptions;



@property (nonatomic, weak) id <CDVScreenOrientationDelegate> orientationDelegate;
@property (nonatomic, weak) CDVThemeableBrowser* navigationDelegate;
@property (nonatomic) NSURL* currentURL;
@property (nonatomic) CGFloat titleOffset;


-(void)gotHeaderImage:(NSURL*)imageUrl;
-(void)showPriceIt:(BOOL)show;
- (void)close;
- (void)reload;
- (void)foundProductWithSavings:(float)savings andPoints:(int)points;
- (void)gotStatusCode:(int)code;
- (void)navigateTo:(NSURL*)url;
- (void)showLocationBar:(BOOL)show;
- (void)showToolBar:(BOOL)show : (NSString*) toolbarPosition;
- (void)setCloseButtonTitle:(NSString*)title;

- (id)initWithUserAgent:(NSString*)userAgent prevUserAgent:(NSString*)prevUserAgent browserOptions: (CDVThemeableBrowserOptions*) browserOptions navigationDelete:(CDVThemeableBrowser*) navigationDelegate statusBarStyle:(UIStatusBarStyle) statusBarStyle;

+ (UIColor *)colorFromRGBA:(NSString *)rgba;

@end

@interface CDVThemeableBrowserNavigationController : UINavigationController

@property (nonatomic, weak) id <CDVScreenOrientationDelegate> orientationDelegate;

@end

