//============================================================================
// Name        : rc/graphics/graphic_device.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "graphic_device.h"
#include "texture.h"


namespace rc { 
namespace graphic {

#ifdef RC_USE_OPENGL

/* ---------------------------------------------------------------------- */
// namespace
/* ---------------------------------------------------------------------- */
using rc::graphic::Texture;
using rc::graphic::TextureOpenGL;

/* ---------------------------------------------------------------------- */
// static functions
/* ---------------------------------------------------------------------- */

// --------------------------------------------------
// OpenGLのブレンドモードへ変換
// --------------------------------------------------
static GLenum trans_blend_mode_to_gl(BLEND_MODE blend_mode)
{
    GLenum gl_enum;
    switch ( blend_mode ) 
    {
        case BLEND_MODE_ZERO:
            gl_enum = GL_ZERO;
            break;
        case BLEND_MODE_ONE:
            gl_enum = GL_ONE;
            break;
        case BLEND_MODE_SRC_COLOR:
            gl_enum = GL_SRC_COLOR;
            break;
        case BLEND_MODE_ONE_MINUS_SRC_COLOR:
            gl_enum = GL_ONE_MINUS_SRC_COLOR;
            break;
        case BLEND_MODE_DST_COLOR:
            gl_enum = GL_DST_COLOR;
            break;
        case BLEND_MODE_ONE_MINUS_DST_COLOR:
            gl_enum = GL_ONE_MINUS_DST_COLOR;
            break;
        case BLEND_MODE_SRC_ALPHA:
            gl_enum = GL_SRC_ALPHA;
            break;
        case BLEND_MODE_ONE_MINUS_SRC_ALPHA:
            gl_enum = GL_ONE_MINUS_SRC_ALPHA;
            break;
        case BLEND_MODE_DST_ALPHA:
            gl_enum = GL_DST_ALPHA;
            break;
        case BLEND_MODE_ONE_MINUS_DST_ALPHA:
            gl_enum = GL_ONE_MINUS_DST_ALPHA;
            break;
        case BLEND_MODE_SRC_ALPHA_SATURATE:
            gl_enum = GL_SRC_ALPHA_SATURATE;
            break;
        default:
            break;
    }
    return gl_enum;
}
    
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
    GraphicDevice::set_vertex_type(type);
}

// --------------------------------------------------
// モデルビュー設定
// --------------------------------------------------
void GraphicDeviceOpenGL::set_transform_matrix(const Matrix4 &mat)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(mat.v);
}

// --------------------------------------------------
// カメラの設定(Projection)
// --------------------------------------------------
void GraphicDeviceOpenGL::set_projection_orthograhy(f32 width, f32 height, f32 z_near, f32 z_far)
{
    glMatrixMode(GL_PROJECTION);                    // 射影変換行列設定
    glOrtho(0, width, height, 0, z_near, z_far);    // 正射影変換設定
}

// --------------------------------------------------
// テクスチャの設定
// --------------------------------------------------
void GraphicDeviceOpenGL::set_texture(Texture *p_tex)
{
    if ( NULL == p_tex ) 
    {
        glDisable(GL_TEXTURE_RECTANGLE_EXT);
        return;
    }

    GLuint* resource = static_cast<GLuint*>(p_tex->get_resource());
    GLuint tex_name = (*resource);
    
    glEnable(GL_TEXTURE_RECTANGLE_EXT);
    glBindTexture(GL_TEXTURE_RECTANGLE_EXT, tex_name);
}

// --------------------------------------------------
// 描画
// --------------------------------------------------
void GraphicDeviceOpenGL::draw_vertex_array(DRAW_MODE mode, u32 vertex_num, void *vertex_array)
{  
    GLenum gl_vertex_type = GL_NONE;
    switch (get_vertex_type()) 
    {
        case VERTEX_TYPE_2D:
            gl_vertex_type = GL_V2F;
            break;

        case VERTEX_TYPE_2D_COLOR:
            gl_vertex_type = GL_C4UB_V2F;
            break;

        case VERTEX_TYPE_T2F_V3F:
            gl_vertex_type = GL_T2F_V3F;
            break;

        case VERTEX_TYPE_T2F_C4UB_V3F:
            gl_vertex_type = GL_T2F_C4UB_V3F;
            break;

        default:
            break;
    };

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
            break;
    };

    glInterleavedArrays(gl_vertex_type , 0, vertex_array);
    glDrawArrays(gl_mode, 0, vertex_num); 

#if 0
    VERTEX_2D_COLOR *vtx = static_cast<VERTEX_2D_COLOR*>(vertex_array);
    glBegin(gl_mode);
    for (unsigned i = 0; i < vertex_num; i++) 
    {
        glVertex2f( vtx[i].x, vtx[i].y);
        glColor4ub( vtx[i].r, vtx[i].g, vtx[i].b, vtx[i].a);    
    }
    glEnd();
#endif
}

// --------------------------------------------------
// 描画領域のクリア
// --------------------------------------------------
void GraphicDeviceOpenGL::set_clear_color(float a, float r, float g, float b)
{
    glClearColor(a, r, g, b);
}

void GraphicDeviceOpenGL::clear(RENDER_BUFFER render_buffer)
{
    GLbitfield bit_field = 0;
    switch ( render_buffer ) 
    {
        case COLOR_BUFFER_BIT:
            bit_field = GL_COLOR_BUFFER_BIT;
            break;
        case DEPTH_BUFFER_BIT:
            bit_field = GL_DEPTH_BUFFER_BIT;
            break;
        case ACCUM_BUFFER_BIT:
            bit_field = GL_ACCUM_BUFFER_BIT;
            break;
        case STENCIL_BUFFER_BIT:
            bit_field = GL_STENCIL_BUFFER_BIT;
            break;
        default:
            break;
    }
    glClear(bit_field);
}

// --------------------------------------------------
// アルファブレンドの設定
// --------------------------------------------------
void GraphicDeviceOpenGL::set_blend_enable(bool flg)
{
    if ( flg ) 
        glEnable(GL_BLEND);
    else 
        glDisable(GL_BLEND);
}


void GraphicDeviceOpenGL::set_blend_mode(BLEND_MODE src, BLEND_MODE dst)
{
    glBlendFunc(trans_blend_mode_to_gl(src), trans_blend_mode_to_gl(dst));
}

#endif//RC_USE_OPENGL


} // namespace graphic
} // namespace rc
