// CCHTTPRequestOperation.h
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


#import "CCURLConnectionOperation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 `CCHTTPRequestOperation` is a subclass of `CCURLConnectionOperation` for requests using the HTTP or HTTPS protocols. It encapsulates the concept of acceptable status codes and content types, which determine the success or failure of a request.
 */
@interface CCHTTPRequestOperation : CCURLConnectionOperation

///------------------------------------------------
/// @name Getting HTTP URL Connection Information
///------------------------------------------------

/**
 The last HTTP response received by the operation's connection.
 */
@property (readonly, nonatomic, strong, nullable) NSHTTPURLResponse *response;

/**
 Responses sent from the server in data tasks created with `dataTaskWithRequest:success:failure:` and run using the `GET` / `POST` / et al. convenience methods are automatically validated and serialized by the response serializer. By default, this property is set to an CCHTTPResponse serializer, which uses the raw data as its response object. The serializer validates the status code to be in the `2XX` range, denoting success. If the response serializer generates an error in `-responseObjectForResponse:data:error:`, the `failure` callback of the session task or request operation will be executed; otherwise, the `success` callback will be executed.

 @warning `responseSerializer` must not be `nil`. Setting a response serializer will clear out any cached value
 */
@property (nonatomic, strong) CCHTTPResponseSerializer <CCURLResponseSerialization> * responseSerializer;

/**
 An object constructed by the `responseSerializer` from the response and response data. Returns `nil` unless the operation `isFinished`, has a `response`, and has `responseData` with non-zero content length. If an error occurs during serialization, `nil` will be returned, and the `error` property will be populated with the serialization error.
 */
@property (readonly, nonatomic, strong, nullable) id responseObject;

///-----------------------------------------------------------
/// @name Setting Completion Block Success / Failure Callbacks
///-----------------------------------------------------------

/**
 Sets the `completionBlock` property with a block that executes either the specified success or failure block, depending on the state of the request on completion. If `error` returns a value, which can be caused by an unacceptable status code or content type, then `failure` is executed. Otherwise, `success` is executed.

 This method should be overridden in subclasses in order to specify the response object passed into the success block.

 @param success The block to be executed on the completion of a successful request. This block has no return value and takes two arguments: the receiver operation and the object constructed from the response data of the request.
 @param failure The block to be executed on the completion of an unsuccessful request. This block has no return value and takes two arguments: the receiver operation and the error that occurred during the request.
 */
- (void)setCompletionBlockWithSuccess:(nullable void (^)(CCHTTPRequestOperation *operation, id responseObject))success
                              failure:(nullable void (^)(CCHTTPRequestOperation *operation, NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
