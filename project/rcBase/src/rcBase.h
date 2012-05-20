/*
 *  file    project/rcBase/src/rcBase.h
 *  date    2012年 5月19日 土曜日 15時58分48秒 JST
 *  brief
 */

#ifndef _RC_BASE_H_
#define _RC_BASE_H_

#include "rc_base.h"

#ifdef RC_USE_SDL
#include "keyboard_sdl.h"
#include "surface_sdl.h"
#endif//RC_USE_SDL

#ifdef RC_USE_XCODE_COCOA_FRAMEWORK
#include "cocoa_util.h"
#endif//RC_USE_XCODE_COCOA_FRAMEWORK

#endif//_RC_BASE_H_
