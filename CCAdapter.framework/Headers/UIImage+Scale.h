//
//  UIImage.h
//  Net263CCLiteDemo_IOS
//
//  Created by xugw0711 on 16-12-14.
//  Copyright (c) 2016年 xugw0711. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage(Scale)  

- (UIImage*)getSubImage:(CGRect)rect;

- (UIImage *)getSubImage:(CGRect)rect usedScale:(BOOL)usedScale;

- (UIImage *)getSubImage:(CGRect)rect deviceScale:(CGFloat)deviceScale;

- (UIImage*)scaleToSize:(CGSize)size;

- (UIImage *)reSizeImagetoSize:(CGSize)reSize;

- (UIImage *)clipImageInRect:(CGRect)rect;  //截图

@end
