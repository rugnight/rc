//============================================================================
// Name        : project/rcGraphic/src/rcGraphicTypes.h
// Author      :
//============================================================================

#ifndef _RC_GRAPHIC_TYPEDEF_H_INCLUDED_
#define _RC_GRAPHIC_TYPEDEF_H_INCLUDED_

#include "rc_types.h"

namespace rc {
namespace graphic {

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
	DRAW_MODE_POINTS,
	DRAW_MODE_LINE_STRIP,
	DRAW_MODE_LINE_LOOP,
	DRAW_MODE_LINES,
	DRAW_MODE_TRIANGLE_STRIP,
	DRAW_MODE_TRIANGLE_FAN,
	DRAW_MODE_TRIANGLES,
	DRAW_MODE_QUAD_STRIP,
	DRAW_MODE_QUADS,
	DRAW_MODE_POLYGON,
} DRAW_MODE;

// ブレンドモード
typedef enum blend_mode {
    BLEND_MODE_ZERO,
    BLEND_MODE_ONE,
    BLEND_MODE_SRC_COLOR,
    BLEND_MODE_ONE_MINUS_SRC_COLOR,
    BLEND_MODE_DST_COLOR,
    BLEND_MODE_ONE_MINUS_DST_COLOR,
    BLEND_MODE_SRC_ALPHA,
    BLEND_MODE_ONE_MINUS_SRC_ALPHA,
    BLEND_MODE_DST_ALPHA,
    BLEND_MODE_ONE_MINUS_DST_ALPHA,
    BLEND_MODE_SRC_ALPHA_SATURATE,
} BLEND_MODE;

// レンダリングバッファ
typedef enum render_buffer {
    COLOR_BUFFER_BIT,	// カラー バッファ
    DEPTH_BUFFER_BIT,	// デプス バッファ
    ACCUM_BUFFER_BIT,	// アキュムレーション バッファ
    STENCIL_BUFFER_BIT, // ステンシル バッファ	
} RENDER_BUFFER;

}// graphic 
}// rc 

#endif//_RC_GRAPHIC_TYPEDEF_H_INCLUDED_
