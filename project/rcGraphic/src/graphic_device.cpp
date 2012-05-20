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
    Matrix4 mat = Matrix4::UNIT;
    mat.m00 = 2.0f/width;
    mat.m11 = -2.0f/height;
    mat.m30 = -1.0f;//width/2.0f;
    mat.m31 = 1.0f;
    glLoadMatrixf(mat.v);
    //glOrtho(0, width, height, 0, z_near, z_far);    // 正射影変換設定
}

// --------------------------------------------------
// テクスチャの設定
// --------------------------------------------------
void GraphicDeviceOpenGL::set_texture(Texture *p_tex)
{
    if ( NULL == p_tex ) 
    {
        glDisable(GL_TEXTURE_2D);
        return;
    }

    GLuint* resource = static_cast<GLuint*>(p_tex->get_resource());
    GLuint tex_name = (*resource);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex_name);
}

// --------------------------------------------------
// 描画設定
// --------------------------------------------------
void GraphicDeviceOpenGL::set_vertex_array(VERTEX_TYPE type, void *vertex_array)
{
    glInterleavedArrays(type, 0, vertex_array);
}

// --------------------------------------------------
// 描画
// --------------------------------------------------
void GraphicDeviceOpenGL::draw_vertex_array(DRAW_MODE mode, u32 vertex_num)
{  
    glDrawArrays(mode, 0, vertex_num); 
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
    glClear(render_buffer);
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
    glBlendFunc(src, dst);
}

#endif//RC_USE_OPENGL


} // namespace graphic
} // namespace rc
