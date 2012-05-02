//============================================================================
// Name        : rc/graphics/graphic_device.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "graphic_device.h"
#include "bitmap.h"

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
// テクスチャ
// --------------------------------------------------
Texture GraphicDeviceOpenGL::create_texture_from_file(const char *file_path)
{
    // 指定ファイルのビットマップ化
    rc::graphic::TextureOpenGL ret;
    rc::graphic::Bitmap bitmap;
    bitmap.create_from_file(file_path);

    ///// テクスチャの作成
    
    GLuint tex;
    // [4/5] テクスチャの名前を作る
    glEnable(GL_TEXTURE_RECTANGLE_EXT);
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_RECTANGLE_EXT, tex);
    
    // [5/5] ビットマップを割り当てる
    glPixelStorei(GL_UNPACK_ROW_LENGTH, (GLint)bitmap.get_width());
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    // 各行のピクセルデータの境界の種類
    // 1: バイト単位
    // 2: 偶数バイト単位
    // 4: WORD（2バイト）単位
    // 8: DWORD（4バイト）単位
    
    glTexImage2D(GL_TEXTURE_RECTANGLE_EXT,
                 0,             // MIPMAPのレベル
                 GL_RGBA,   // テクスチャで使う
                 // カラーコンポーネント数
                 (GLsizei)bitmap.get_width(),
                 (GLsizei)bitmap.get_height(),
                 0,         // ボーダー
                 GL_BGRA,   // ビットマップの色の並び順
                 GL_UNSIGNED_INT_8_8_8_8,
                 bitmap.get_bytes()
                 );
    return ret;
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
#endif//RC_USE_OPENGL


} // namespace graphic
} // namespace rc
