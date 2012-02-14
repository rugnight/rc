//============================================================================
// Name        : project/rcGraphic/src/rcGraphicTypes.h
// Author      :
//============================================================================

#ifndef _RC_GRAPHIC_TYPEDEF_H_INCLUDED_
#define _RC_GRAPHIC_TYPEDEF_H_INCLUDED_

namespace rc {
namespace graphic {

// テクスチャターゲット
typedef enum {
	RC_TEX_2D,
	RC_TEX_CUBE_MAP
} RC_TEX_TARGET;

// テクスチャパラメータ
typedef enum {
	RC_TEX_NEAREST,
	RC_TEX_LINEAR,
	RC_TEX_NEAREST_MIPMAP_NEAREST,
	RC_TEX_LINEAR_MIPMAP_NEAREST,
	RC_TEX_NEAREST_MIPMAP_LINEAR,
	RC_TEX_LINEAR_MIPMAP_LINEAR,
} RC_TEX_PARAM;

// テクスチャパラメータ値
typedef enum {
	RC_TEX_NEAREST,
	RC_TEX_LINEAR,
	RC_TEX_NEAREST_MIPMAP_NEAREST,
	RC_TEX_LINEAR_MIPMAP_NEAREST,
	RC_TEX_NEAREST_MIPMAP_LINEAR,
	RC_TEX_LINEAR_MIPMAP_LINEAR,
} RC_TEX_PARAM_VALUE;

// 描画モード
typedef enum {
	RC_DRAW_MODE_POINTS,
	RC_DRAW_MODE_LINE_STRIP,
	RC_DRAW_MODE_LINE_LOOP,
	RC_DRAW_MODE_LINES,
	RC_DRAW_MODE_TRIANGLE_STRIP,
	RC_DRAW_MODE_TRIANGLE_FAN,
	RC_DRAW_MODE_TRIANGLES,
	RC_DRAW_MODE_QUAD_STRIP,
	RC_DRAW_MODE_QUADS,
	RC_DRAW_MODE_POLYGON,
} RC_DRAW_MODE;

};	// graphic 
};	// rc 

#endif//_RC_GRAPHIC_TYPEDEF_H_INCLUDED_
