//============================================================================
// Name        : rc/graphics/graphic_device.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "graphic_device.h"

namespace rc { 
namespace graphic {

#ifdef RC_USE_OPENGL

/* ---------------------------------------------------------------------- */
//  class GraphicDeviceOpenGL : public GraphicDevice
/* ---------------------------------------------------------------------- */
GraphicDeviceOpenGL::GraphicDeviceOpenGL()
{
}

GraphicDeviceOpenGL::~GraphicDeviceOpenGL()
{
}

// --------------------------------------------------
// 頂点型の設定
// --------------------------------------------------
void GraphicDeviceOpenGL::set_vertex_type(VERTEX_TYPE type)
{
}

// --------------------------------------------------
// モデルビュー設定
// --------------------------------------------------

// --------------------------------------------------
// カメラの設定(Projection)
// --------------------------------------------------
void GraphicDeviceOpenGL::set_projection_orthograhy(f32 width, f32 height, f32 z_near, f32 z_far)
{
}

#include <stdio.h>
// --------------------------------------------------
// 描画
// --------------------------------------------------
void GraphicDeviceOpenGL::draw(DRAW_MODE mode, u32 vertex_num, void *vertex_array)
{  
    GLenum gl_mode = GL_NONE;
    switch ( mode ) 
    {
        case DRAW_MODE_TRIANGLES:
            gl_mode = GL_TRIANGLES;
            break;

        case DRAW_MODE_TRIANGLE_STRIP:
            gl_mode = GL_TRIANGLE_STRIP;
            break;

        default:
            return;
            break;
    };
    glBegin(gl_mode);

    VERTEX_2D_COLOR *vtx = static_cast<VERTEX_2D_COLOR*>(vertex_array);
    for (unsigned i = 0; i < vertex_num; i++) 
    {
        printf("%f, %f\n", vtx[i].x, vtx[i].y);
        
        glVertex2f( vtx[i].x, vtx[i].y);
        glColor4ub( vtx[i].r, vtx[i].g, vtx[i].b, vtx[i].a);    
    }
    glEnd();
}
#endif//RC_USE_OPENGL




} // namespace graphic
} // namespace rc
