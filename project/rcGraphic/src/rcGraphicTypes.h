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

typedef enum vertex_type {
    VERTEX_TYPE_2D,
    VERTEX_TYPE_2D_COLOR,
}VERTEX_TYPE;

typedef class vertex_2d{
    public:
        union {
            f32 v[2];
            struct { f32 x, y; };
        };
} VERTEX_2D;

typedef class vertex_2d_color : public vertex_2d {
    public:
        union {
            u32 color;
            struct { u8 b, g, r, a; };
        };
} VERTEX_2D_COLOR;

};	// graphic 
};	// rc 

#endif//_RC_GRAPHIC_TYPEDEF_H_INCLUDED_
