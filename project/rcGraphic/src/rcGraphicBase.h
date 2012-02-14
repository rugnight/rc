/*
 *  file    rcGraphicBase.h
 *  date    2011/12/25
 *  author  Azuma_Yoshitaka
 */

#ifndef _RC_GRAPHIC_BASE_H_
#define _RC_GRAPHIC_BASE_H_

#include "rcBase.h"
//#include "rcGraphicBase.h"

#define RC_USE_OPENGL

// --------------------------
// 依存物の読み込み
#ifdef RC_USE_OPENGL
#include <gl3.h>
#endif //RC_USE_OPENGL

// --------------------------
// 型の定義
#ifdef RC_USE_OPENGL
//typedef GLuint u32;
#endif //RC_USE_OPENGL

#endif//_RC_GRAPHIC_BASE_H_
