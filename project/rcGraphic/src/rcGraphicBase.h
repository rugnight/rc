/*
 *  file    rcGraphicBase.h
 *  date    2011/12/25
 *  author  Azuma_Yoshitaka
 */

#ifndef _RC_GRAPHIC_BASE_H_
#define _RC_GRAPHIC_BASE_H_

#include "rcBase.h"
#include "rcMath.h"

// --------------------------
// ビルド環境の選択
// --------------------------
#define RC_USE_XCODE_OPENGL_FRAMEWORK

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
#ifdef RC_USE_XCODE_OPENGL_FRAMEWORK
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#else
#include <OpenGL.h>
#include <gl.h>
#endif
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
// rc types
// --------------------------
namespace rc {
namespace graphic {

/* -------------------------------------------------- */
#ifdef RC_USE_OPENGL
/* -------------------------------------------------- */
// テクスチャターゲット
typedef enum {
	TEX_2D,
	TEX_CUBE_MAP
} TEX_TARGET;

// テクスチャパラメータ
typedef enum {
	TEX_NEAREST,
	TEX_LINEAR,
	TEX_NEAREST_MIPMAP_NEAREST,
	TEX_LINEAR_MIPMAP_NEAREST,
	TEX_NEAREST_MIPMAP_LINEAR,
	TEX_LINEAR_MIPMAP_LINEAR,
} TEX_PARAM;

// 描画モード
typedef enum {
	DRAW_MODE_POINTS         = GL_POINTS,
	DRAW_MODE_LINE_STRIP     = GL_LINE_STRIP,
	DRAW_MODE_LINE_LOOP      = GL_LINE_LOOP,
	DRAW_MODE_LINES          = GL_LINES,
	DRAW_MODE_TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
	DRAW_MODE_TRIANGLE_FAN   = GL_TRIANGLE_FAN,
	DRAW_MODE_TRIANGLES      = GL_TRIANGLES,
	DRAW_MODE_QUAD_STRIP     = GL_QUAD_STRIP,
	DRAW_MODE_QUADS          = GL_QUADS,
	DRAW_MODE_POLYGON        = GL_POLYGON,
} DRAW_MODE;

// ブレンドモード
typedef enum blend_mode {
    BLEND_MODE_ZERO                = GL_ZERO,
    BLEND_MODE_ONE                 = GL_ONE,
    BLEND_MODE_SRC_COLOR           = GL_SRC_COLOR,
    BLEND_MODE_ONE_MINUS_SRC_COLOR = GL_ONE_MINUS_SRC_COLOR,
    BLEND_MODE_DST_COLOR           = GL_DST_COLOR,
    BLEND_MODE_ONE_MINUS_DST_COLOR = GL_ONE_MINUS_DST_COLOR,
    BLEND_MODE_SRC_ALPHA           = GL_SRC_ALPHA,
    BLEND_MODE_ONE_MINUS_SRC_ALPHA = GL_ONE_MINUS_SRC_ALPHA,
    BLEND_MODE_DST_ALPHA           = GL_DST_ALPHA,
    BLEND_MODE_ONE_MINUS_DST_ALPHA = GL_ONE_MINUS_DST_ALPHA,
    BLEND_MODE_SRC_ALPHA_SATURATE  = GL_SRC_ALPHA_SATURATE,
} BLEND_MODE;

// レンダリングバッファ
typedef enum render_buffer {
    COLOR_BUFFER_BIT   = GL_COLOR_BUFFER_BIT,   // カラー バッファ
    DEPTH_BUFFER_BIT   = GL_DEPTH_BUFFER_BIT,   // デプス バッファ
    ACCUM_BUFFER_BIT   = GL_ACCUM_BUFFER_BIT,   // アキュムレーション バッファ
    STENCIL_BUFFER_BIT = GL_STENCIL_BUFFER_BIT, // ステンシル バッファ
} RENDER_BUFFER;
/* -------------------------------------------------- */
#endif//RC_USE_OPENGL
/* -------------------------------------------------- */

}// graphic 
}// rc 

#include "rcGraphicVertexTypes.h"

#endif//_RC_GRAPHIC_BASE_H_
