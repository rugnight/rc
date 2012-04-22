/*
 *  file    rcGraphicBase.h
 *  date    2011/12/25
 *  author  Azuma_Yoshitaka
 */

#ifndef _RC_GRAPHIC_BASE_H_
#define _RC_GRAPHIC_BASE_H_

#include "rc_base.h"

// --------------------------
// グラフィックデバイスの選択
// --------------------------
#define RC_USE_OPENGL
//#define RC_USE_SDL
//#define RC_USE_IOS

// --------------------------
// OpenGL
// --------------------------
#ifdef RC_USE_OPENGL
// 依存物の読み込み
#include <gl3.h>
// 型の定義
//typedef GLuint u32;
#endif //RC_USE_OPENGL

// --------------------------
//  iOS
// --------------------------
#ifdef RC_USE_IOS
#import <UIKit/UIKit.h>
//#import <GLKit/GLKit.h>
#endif //RC_USE_IOS

// --------------------------
// SDL
// --------------------------
#ifdef RC_USE_SDL
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#endif//RC_USE_SDL

// --------------------------
// rc types
// --------------------------

#endif//_RC_GRAPHIC_BASE_H_
