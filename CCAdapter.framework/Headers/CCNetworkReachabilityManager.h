// CCNetworkReachabilityManager.h
// Copyright (c) 2011–2015 Alamofire Software Foundation (http://alamofire.org/)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


#import <objc/runtime.h>
#import <Availability.h>
#import <AvailabilityMacros.h>
#import <TargetConditionals.h>

#if (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE)
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#elif defined(TARGET_OS_MAC) && TARGET_OS_MAC
#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>
#import <AppKit/AppKit.h>
#endif

#if !TARGET_OS_WATCH
#import <SystemConfiguration/SystemConfiguration.h>

#ifndef NS_DESIGNATED_INITIALIZER
#if __has_attribute(objc_designated_initializer)
#define NS_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
#else
#define NS_DESIGNATED_INITIALIZER
#endif
#endif

typedef NS_ENUM(NSInteger, CCNetworkReachabilityStatus) {
    CCNetworkReachabilityStatusUnknown          = -1,
    CCNetworkReachabilityStatusNotReachable     = 0,
    CCNetworkReachabilityStatusReachableViaWWAN = 1,
    CCNetworkReachabilityStatusReachableViaWiFi = 2,
};

NS_ASSUME_NONNULL_BEGIN

/**
 `CCNetworkReachabilityManager` monitors the reachability of domains, and addresses for both WWAN and WiFi network interfaces.

 Reachability can be used to determine background information about why a network operation failed, or to trigger a network operation retrying when a connection is established. It should not be used to prevent a user from initiating a network request, as it's possible that an initial request may be required to establish reachability.

 See Apple's Reachability Sample Code (https://developer.apple.com/library/ios/samplecode/reachability/)

 @warning Instances of `CCNetworkReachabilityManager` must be started with `-startMonitoring` before reachability status can be determined.
 */
@interface CCNetworkReachabilityManager : NSObject

/**
 The current network reachability status.
 */
@property (readonly, nonatomic, assign) CCNetworkReachabilityStatus networkReachabilityStatus;

/**
 Whether or not the network is currently reachable.
 */
@property (readonly, nonatomic, assign, getter = isReachable) BOOL reachable;

/**
 Whether or not the network is currently reachable via WWAN.
 */
@property (readonly, nonatomic, assign, getter = isReachableViaWWAN) BOOL reachableViaWWAN;

/**
 Whether or not the network is currently reachable via WiFi.
 */
@property (readonly, nonatomic, assign, getter = isReachableViaWiFi) BOOL reachableViaWiFi;

///---------------------
/// @name Initialization
///---------------------

/**
 Returns the shared network reachability manager.
 */
+ (instancetype)sharedManager;

/**
 Creates and returns a network reachability manager for the specified domain.

 @param domain The domain used to evaluate network reachability.

 @return An initialized network reachability manager, actively monitoring the specified domain.
 */
+ (instancetype)managerForDomain:(NSString *)domain;

/**
 Creates and returns a network reachability manager for the socket address.

 @param address The socket address (`sockaddr_in`) used to evaluate network reachability.

 @return An initialized network reachability manager, actively monitoring the specified socket address.
 */
+ (instancetype)managerForAddress:(const void *)address;

/**
 Initializes an instance of a network reachability manager from the specified reachability object.

 @param reachability The reachability object to monitor.

 @return An initialized network reachability manager, actively monitoring the specified reachability.
 */
- (instancetype)initWithReachability:(SCNetworkReachabilityRef)reachability NS_DESIGNATED_INITIALIZER;

///--------------------------------------------------
/// @name Starting & Stopping Reachability Monitoring
///--------------------------------------------------

/**
 Starts monitoring for changes in network reachability status.
 */
- (void)startMonitoring;

/**
 Stops monitoring for changes in network reachability status.
 */
- (void)stopMonitoring;

///-------------------------------------------------
/// @name Getting Localized Reachability Description
///-------------------------------------------------

/**
 Returns a localized string representation of the current network reachability status.
 */
- (NSString *)localizedNetworkReachabilityStatusString;

///---------------------------------------------------
/// @name Setting Network Reachability Change Callback
///---------------------------------------------------

/**
 Sets a callback to be executed when the network availability of the `baseURL` host changes.

 @param block A block object to be executed when the network availability of the `baseURL` host changes.. This block has no return value and takes a single argument which represents the various reachability states from the device to the `baseURL`.
 */
- (void)setReachabilityStatusChangeBlock:(nullable void (^)(CCNetworkReachabilityStatus status))block;

@end

///----------------
/// @name Constants
///----------------

/**
 ## Network Reachability

 The following constants are provided by `CCNetworkReachabilityManager` as possible network reachability statuses.

 enum {
 CCNetworkReachabilityStatusUnknown,
 CCNetworkReachabilityStatusNotReachable,
 CCNetworkReachabilityStatusReachableViaWWAN,
 CCNetworkReachabilityStatusReachableViaWiFi,
 }

 `CCNetworkReachabilityStatusUnknown`
 The `baseURL` host reachability is not known.

 `CCNetworkReachabilityStatusNotReachable`
 The `baseURL` host cannot be reached.

 `CCNetworkReachabilityStatusReachableViaWWAN`
 The `baseURL` host can be reached via a cellular connection, such as EDGE or GPRS.

 `CCNetworkReachabilityStatusReachableViaWiFi`
 The `baseURL` host can be reached via a Wi-Fi connection.

 ### Keys for Notification UserInfo Dictionary

 Strings that are used as keys in a `userInfo` dictionary in a network reachability status change notification.

 `CCNetworkingReachabilityNotificationStatusItem`
 A key in the userInfo dictionary in a `CCNetworkingReachabilityDidChangeNotification` notification.
 The corresponding value is an `NSNumber` object representing the `CCNetworkReachabilityStatus` value for the current reachability status.
 */

///--------------------
/// @name Notifications
///--------------------

/**
 Posted when network reachability changes.
 This notification assigns no notification object. The `userInfo` dictionary contains an `NSNumber` object under the `CCNetworkingReachabilityNotificationStatusItem` key, representing the `CCNetworkReachabilityStatus` value for the current network reachability.

 @warning In order for network reachability to be monitored, include the `SystemConfiguration` framework in the active target's "Link Binary With Library" build phase, and add `#import <SystemConfiguration/SystemConfiguration.h>` to the header prefix of the project (`Prefix.pch`).
 */
FOUNDATION_EXPORT NSString * const CCNetworkingReachabilityDidChangeNotification;
FOUNDATION_EXPORT NSString * const CCNetworkingReachabilityNotificationStatusItem;

///--------------------
/// @name Functions
///--------------------

/**
 Returns a localized string representation of an `CCNetworkReachabilityStatus` value.
 */
FOUNDATION_EXPORT NSString * CCStringFromNetworkReachabilityStatus(CCNetworkReachabilityStatus status);

NS_ASSUME_NONNULL_END
#endif
