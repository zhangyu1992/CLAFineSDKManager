// CCHTTPRequestOperationManager.h
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


#import <SystemConfiguration/SystemConfiguration.h>
#import <Availability.h>

#if __IPHONE_OS_VERSION_MIN_REQUIRED
#import <MobileCoreServices/MobileCoreServices.h>
#else
#import <CoreServices/CoreServices.h>
#endif

#import "CCHTTPRequestOperation.h"
#import "CCURLResponseSerialization.h"
#import "CCURLRequestSerialization.h"
#import "CCSecurityPolicy.h"
#import "CCNetworkReachabilityManager.h"

#ifndef NS_DESIGNATED_INITIALIZER
#if __has_attribute(objc_designated_initializer)
#define NS_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
#else
#define NS_DESIGNATED_INITIALIZER
#endif
#endif

NS_ASSUME_NONNULL_BEGIN

/**
 `CCHTTPRequestOperationManager` encapsulates the common patterns of communicating with a web application over HTTP, including request creation, response serialization, network reachability monitoring, and security, as well as request operation management.

 ## Subclassing Notes

 Developers targeting iOS 7 or Mac OS X 10.9 or later that deal extensively with a web service are encouraged to subclass `CCHTTPSessionManager`, providing a class method that returns a shared singleton object on which authentication and other configuration can be shared across the application.

 For developers targeting iOS 6 or Mac OS X 10.8 or earlier, `CCHTTPRequestOperationManager` may be used to similar effect.

 ## Methods to Override

 To change the behavior of all request operation construction for an `CCHTTPRequestOperationManager` subclass, override `HTTPRequestOperationWithRequest:success:failure`.

 ## Serialization

 Requests created by an HTTP client will contain default headers and encode parameters according to the `requestSerializer` property, which is an object conforming to `<CCURLRequestSerialization>`.

 Responses received from the server are automatically validated and serialized by the `responseSerializers` property, which is an object conforming to `<CCURLResponseSerialization>`

 ## URL Construction Using Relative Paths

 For HTTP convenience methods, the request serializer constructs URLs from the path relative to the `-baseURL`, using `NSURL +URLWithString:relativeToURL:`, when provided. If `baseURL` is `nil`, `path` needs to resolve to a valid `NSURL` object using `NSURL +URLWithString:`.

 Below are a few examples of how `baseURL` and relative paths interact:

    NSURL *baseURL = [NSURL URLWithString:@"http://example.com/v1/"];
    [NSURL URLWithString:@"foo" relativeToURL:baseURL];                  // http://example.com/v1/foo
    [NSURL URLWithString:@"foo?bar=baz" relativeToURL:baseURL];          // http://example.com/v1/foo?bar=baz
    [NSURL URLWithString:@"/foo" relativeToURL:baseURL];                 // http://example.com/foo
    [NSURL URLWithString:@"foo/" relativeToURL:baseURL];                 // http://example.com/v1/foo
    [NSURL URLWithString:@"/foo/" relativeToURL:baseURL];                // http://example.com/foo/
    [NSURL URLWithString:@"http://example2.com/" relativeToURL:baseURL]; // http://example2.com/

 Also important to note is that a trailing slash will be added to any `baseURL` without one. This would otherwise cause unexpected behavior when constructing URLs using paths without a leading slash.

 ## Network Reachability Monitoring

 Network reachability status and change monitoring is available through the `reachabilityManager` property. Applications may choose to monitor network reachability conditions in order to prevent or suspend any outbound requests. See `CCNetworkReachabilityManager` for more details.

 ## NSSecureCoding & NSCopying Caveats

 `CCHTTPRequestOperationManager` conforms to the `NSSecureCoding` and `NSCopying` protocols, allowing operations to be archived to disk, and copied in memory, respectively. There are a few minor caveats to keep in mind, however:

 - Archives and copies of HTTP clients will be initialized with an empty operation queue.
 - NSSecureCoding cannot serialize / deserialize block properties, so an archive of an HTTP client will not include any reachability callback block that may be set.
 */
@interface CCHTTPRequestOperationManager : NSObject <NSSecureCoding, NSCopying>

/**
 The URL used to monitor reachability, and construct requests from relative paths in methods like `requestWithMethod:URLString:parameters:`, and the `GET` / `POST` / et al. convenience methods.
 */
@property (readonly, nonatomic, strong, nullable) NSURL *baseURL;

/**
 Requests created with `requestWithMethod:URLString:parameters:` & `multipartFormRequestWithMethod:URLString:parameters:constructingBodyWithBlock:` are constructed with a set of default headers using a parameter serialization specified by this property. By default, this is set to an instance of `CCHTTPRequestSerializer`, which serializes query string parameters for `GET`, `HEAD`, and `DELETE` requests, or otherwise URL-form-encodes HTTP message bodies.

 @warning `requestSerializer` must not be `nil`.
 */
@property (nonatomic, strong) CCHTTPRequestSerializer <CCURLRequestSerialization> * requestSerializer;

/**
 Responses sent from the server in data tasks created with `dataTaskWithRequest:success:failure:` and run using the `GET` / `POST` / et al. convenience methods are automatically validated and serialized by the response serializer. By default, this property is set to a JSON serializer, which serializes data from responses with a `application/json` MIME type, and falls back to the raw data object. The serializer validates the status code to be in the `2XX` range, denoting success. If the response serializer generates an error in `-responseObjectForResponse:data:error:`, the `failure` callback of the session task or request operation will be executed; otherwise, the `success` callback will be executed.

 @warning `responseSerializer` must not be `nil`.
 */
@property (nonatomic, strong) CCHTTPResponseSerializer <CCURLResponseSerialization> * responseSerializer;

/**
 The operation queue on which request operations are scheduled and run.
 */
@property (nonatomic, strong) NSOperationQueue *operationQueue;

///-------------------------------
/// @name Managing URL Credentials
///-------------------------------

/**
 Whether request operations should consult the credential storage for authenticating the connection. `YES` by default.

 @see CCURLConnectionOperation -shouldUseCredentialStorage
 */
@property (nonatomic, assign) BOOL shouldUseCredentialStorage;

/**
 The credential used by request operations for authentication challenges.

 @see CCURLConnectionOperation -credential
 */
@property (nonatomic, strong, nullable) NSURLCredential *credential;

///-------------------------------
/// @name Managing Security Policy
///-------------------------------

/**
 The security policy used by created request operations to evaluate server trust for secure connections. `CCHTTPRequestOperationManager` uses the `defaultPolicy` unless otherwise specified.
 */
@property (nonatomic, strong) CCSecurityPolicy *securityPolicy;

///------------------------------------
/// @name Managing Network Reachability
///------------------------------------

/**
 The network reachability manager. `CCHTTPRequestOperationManager` uses the `sharedManager` by default.
 */
@property (readwrite, nonatomic, strong) CCNetworkReachabilityManager *reachabilityManager;

///-------------------------------
/// @name Managing Callback Queues
///-------------------------------

/**
 The dispatch queue for the `completionBlock` of request operations. If `NULL` (default), the main queue is used.
 */
#if OS_OBJECT_USE_OBJC
@property (nonatomic, strong, nullable) dispatch_queue_t completionQueue;
#else
@property (nonatomic, assign, nullable) dispatch_queue_t completionQueue;
#endif

/**
 The dispatch group for the `completionBlock` of request operations. If `NULL` (default), a private dispatch group is used.
 */
#if OS_OBJECT_USE_OBJC
@property (nonatomic, strong, nullable) dispatch_group_t completionGroup;
#else
@property (nonatomic, assign, nullable) dispatch_group_t completionGroup;
#endif

///---------------------------------------------
/// @name Creating and Initializing HTTP Clients
///---------------------------------------------

/**
 Creates and returns an `CCHTTPRequestOperationManager` object.
 */
+ (instancetype)manager;

/**
 Initializes an `CCHTTPRequestOperationManager` object with the specified base URL.

 This is the designated initializer.

 @param url The base URL for the HTTP client.

 @return The newly-initialized HTTP client
 */
- (instancetype)initWithBaseURL:(nullable NSURL *)url NS_DESIGNATED_INITIALIZER;

///---------------------------------------
/// @name Managing HTTP Request Operations
///---------------------------------------

/**
 Creates an `CCHTTPRequestOperation`, and sets the response serializers to that of the HTTP client.

 @param request The request object to be loaded asynchronously during execution of the operation.
 @param success A block object to be executed when the request operation finishes successfully. This block has no return value and takes two arguments: the created request operation and the object created from the response data of request.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments:, the created request operation and the `NSError` object describing the network or parsing error that occurred.
 */
- (CCHTTPRequestOperation *)HTTPRequestOperationWithRequest:(NSURLRequest *)request
                                                    success:(nullable void (^)(CCHTTPRequestOperation *operation, id responseObject))success
                                                    failure:(nullable void (^)(CCHTTPRequestOperation *operation, NSError *error))failure;

///---------------------------
/// @name Making HTTP Requests
///---------------------------

/**
 Creates and runs an `CCHTTPRequestOperation` with a `GET` request.

 @param URLString The URL string used to create the request URL.
 @param parameters The parameters to be encoded according to the client request serializer.
 @param success A block object to be executed when the request operation finishes successfully. This block has no return value and takes two arguments: the request operation, and the response object created by the client response serializer.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a two arguments: the request operation and the error describing the network or parsing error that occurred.

 @see -HTTPRequestOperationWithRequest:success:failure:
 */
- (nullable CCHTTPRequestOperation *)GET:(NSString *)URLString
                     parameters:(nullable id)parameters
                        success:(nullable void (^)(CCHTTPRequestOperation *operation, id responseObject))success
                        failure:(nullable void (^)(CCHTTPRequestOperation * __nullable operation, NSError *error))failure;

/**
 Creates and runs an `CCHTTPRequestOperation` with a `HEAD` request.

 @param URLString The URL string used to create the request URL.
 @param parameters The parameters to be encoded according to the client request serializer.
 @param success A block object to be executed when the request operation finishes successfully. This block has no return value and takes a single arguments: the request operation.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a two arguments: the request operation and the error describing the network or parsing error that occurred.

 @see -HTTPRequestOperationWithRequest:success:failure:
 */
- (nullable CCHTTPRequestOperation *)HEAD:(NSString *)URLString
                      parameters:(nullable id)parameters
                         success:(nullable void (^)(CCHTTPRequestOperation *operation))success
                         failure:(nullable void (^)(CCHTTPRequestOperation * __nullable operation, NSError *error))failure;

/**
 Creates and runs an `CCHTTPRequestOperation` with a `POST` request.

 @param URLString The URL string used to create the request URL.
 @param parameters The parameters to be encoded according to the client request serializer.
 @param success A block object to be executed when the request operation finishes successfully. This block has no return value and takes two arguments: the request operation, and the response object created by the client response serializer.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a two arguments: the request operation and the error describing the network or parsing error that occurred.

 @see -HTTPRequestOperationWithRequest:success:failure:
 */
- (nullable CCHTTPRequestOperation *)POST:(NSString *)URLString
                      parameters:(nullable id)parameters
                         success:(nullable void (^)(CCHTTPRequestOperation *operation, id responseObject))success
                         failure:(nullable void (^)(CCHTTPRequestOperation * __nullable operation, NSError *error))failure;

/**
 Creates and runs an `CCHTTPRequestOperation` with a multipart `POST` request.

 @param URLString The URL string used to create the request URL.
 @param parameters The parameters to be encoded according to the client request serializer.
 @param block A block that takes a single argument and appends data to the HTTP body. The block argument is an object adopting the `CCMultipartFormData` protocol.
 @param success A block object to be executed when the request operation finishes successfully. This block has no return value and takes two arguments: the request operation, and the response object created by the client response serializer.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a two arguments: the request operation and the error describing the network or parsing error that occurred.

 @see -HTTPRequestOperationWithRequest:success:failure:
 */
- (nullable CCHTTPRequestOperation *)POST:(NSString *)URLString
                      parameters:(nullable id)parameters
       constructingBodyWithBlock:(nullable void (^)(id <CCMultipartFormData> formData))block
                         success:(nullable void (^)(CCHTTPRequestOperation *operation, id responseObject))success
                         failure:(nullable void (^)(CCHTTPRequestOperation * __nullable operation, NSError *error))failure;

/**
 Creates and runs an `CCHTTPRequestOperation` with a `PUT` request.

 @param URLString The URL string used to create the request URL.
 @param parameters The parameters to be encoded according to the client request serializer.
 @param success A block object to be executed when the request operation finishes successfully. This block has no return value and takes two arguments: the request operation, and the response object created by the client response serializer.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a two arguments: the request operation and the error describing the network or parsing error that occurred.

 @see -HTTPRequestOperationWithRequest:success:failure:
 */
- (nullable CCHTTPRequestOperation *)PUT:(NSString *)URLString
                     parameters:(nullable id)parameters
                        success:(nullable void (^)(CCHTTPRequestOperation *operation, id responseObject))success
                        failure:(nullable void (^)(CCHTTPRequestOperation * __nullable operation, NSError *error))failure;

/**
 Creates and runs an `CCHTTPRequestOperation` with a `PATCH` request.

 @param URLString The URL string used to create the request URL.
 @param parameters The parameters to be encoded according to the client request serializer.
 @param success A block object to be executed when the request operation finishes successfully. This block has no return value and takes two arguments: the request operation, and the response object created by the client response serializer.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a two arguments: the request operation and the error describing the network or parsing error that occurred.

 @see -HTTPRequestOperationWithRequest:success:failure:
 */
- (nullable CCHTTPRequestOperation *)PATCH:(NSString *)URLString
                       parameters:(nullable id)parameters
                          success:(nullable void (^)(CCHTTPRequestOperation *operation, id responseObject))success
                          failure:(nullable void (^)(CCHTTPRequestOperation * __nullable operation, NSError *error))failure;

/**
 Creates and runs an `CCHTTPRequestOperation` with a `DELETE` request.

 @param URLString The URL string used to create the request URL.
 @param parameters The parameters to be encoded according to the client request serializer.
 @param success A block object to be executed when the request operation finishes successfully. This block has no return value and takes two arguments: the request operation, and the response object created by the client response serializer.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a two arguments: the request operation and the error describing the network or parsing error that occurred.

 @see -HTTPRequestOperationWithRequest:success:failure:
 */
- (nullable CCHTTPRequestOperation *)DELETE:(NSString *)URLString
                        parameters:(nullable id)parameters
                           success:(nullable void (^)(CCHTTPRequestOperation *operation, id responseObject))success
                           failure:(nullable void (^)(CCHTTPRequestOperation * __nullable operation, NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
