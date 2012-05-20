/*
 *  file    rc_base.h
 *  date    2011/11/27
 *  author  Azuma_Yoshitaka
 */

#ifndef _RC_BASE_BASE_H_
#define _RC_BASE_BASE_H_

// --------------------------
// ビルド環境の選択
// --------------------------
#define RC_USE_XCODE_COCOA_FRAMEWORK
#define RC_USE_SDL

#ifdef RC_USE_XCODE_COCOA_FRAMEWORK
#endif//RC_USE_XCODE_COCOA_FRAMEWORK

#ifdef RC_USE_SDL
#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#include <SDL_ttf/SDL_ttf.h>
#endif//RC_USE_SDL

#include <assert.h>

#include <string>
#include <map>
#include <list>

// --------------------------
// 型の定義
#include "rc_types.h"
#include "keyboard_type.h"

// --------------------------
// 基本機能マクロ
#define SAFE_DELETE(p)        if ( p != NULL ) { delete p; p=NULL; }
#define SAFE_DELETE_ARRAY(p)  if ( p != NULL ) { delete[] p; p = NULL; }
//#define SAFE_RELEASE(p)       { if (p) != NULL ) { (p)->release(); (p) = NULL; } }
#define COUNTOF( array )      ( sizeof( array )/sizeof( array[0] ) )

#define DEBUG_ASSERT(e) assert(e)






#endif//_RC_BASE_BASE_H_INCLUDED_
