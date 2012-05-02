/*
 *  rcGraphic/src/rcGraphicVertexTypes.h
 *
 */

#ifndef _RC_GRAPHIC_VERTEX_TYPE_H_
#define _RC_GRAPHIC_VERTEX_TYPE_H_

#include "rc_types.h"

namespace rc {
namespace graphic {

// 定義済みの頂点型
typedef enum vertex_type {
    VERTEX_TYPE_2D,
    VERTEX_TYPE_2D_COLOR,

    VERTEX_TYPE_T2F_V3F,
}VERTEX_TYPE;

// VERTEX_TYPE_2D,
typedef struct vertex_2d{
    union {
        f32 v[2];
        struct { f32 x, y; };
    };
} VERTEX_2D;

// VERTEX_TYPE_2D_COLOR,
typedef struct vertex_2d_color {
    union {
        u32 color;
        struct { u8 a, b, g, r; };
    };
    union {
        f32 v[2];
        struct { f32 x, y; };
    };
} VERTEX_2D_COLOR;

// VERTEX_T2F_V3F
typedef struct vertex_t2f_v3f {
    union {
        f32 uv[2];
        struct { f32 u, v; };
    };
    union {
        f32 va[3];
        struct { f32 x, y, z; };
    };
} VERTEX_T2F_V3F;

} //namespace rc
} //namespace graphic

#endif//_RC_GRAPHIC_VERTEX_TYPE_H_
