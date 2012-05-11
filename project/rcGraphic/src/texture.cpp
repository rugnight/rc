/*
 *   file   texture.cpp
 *   brief  
 *   date   2011/07/17
 */

#include "texture.h"
#include "util_math.h"
#include "bitmap.h"

using namespace rc::graphic;

namespace rc {
namespace graphic {

#ifdef RC_USE_OPENGL
/* ----------------------------------------------- */
//  static function
/* ----------------------------------------------- */
static GLuint create_from_bitmap(Bitmap *p_bmp)
{
    const GLuint width = (GLint)p_bmp->get_width();
    const GLuint height = (GLint)p_bmp->get_height();

    ///// テクスチャの作成
    GLuint tex = GL_INVALID_VALUE;
    // テクスチャの名前を作る
    glEnable(GL_TEXTURE_RECTANGLE_EXT);
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_RECTANGLE_EXT, tex);
    
    // ビットマップを割り当てる
    glPixelStorei(GL_UNPACK_ROW_LENGTH, width);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    // 各行のピクセルデータの境界の種類
    // 1: バイト単位
    // 2: 偶数バイト単位
    // 4: WORD（2バイト）単位
    // 8: DWORD（4バイト）単位
    
    glTexImage2D(GL_TEXTURE_RECTANGLE_EXT,
        0,                         // MIPMAPのレベル
        GL_RGBA,                   // テクスチャで使う カラーコンポーネント数
        width,
        height,
        0,                         // ボーダー
        GL_BGRA,                   // ビットマップの色の並び順
        GL_UNSIGNED_INT_8_8_8_8,
        p_bmp->get_bytes()
        );
    return tex;
}


/* ----------------------------------------------- */
//  class TextureOpenGL: public Texture
/* ----------------------------------------------- */
TextureOpenGL::TextureOpenGL()
    : m_tex_name(GL_INVALID_VALUE)
{
}

TextureOpenGL::~TextureOpenGL()
{
    destroy();
}

// 破棄
void TextureOpenGL::destroy()
{
    if ( GL_INVALID_VALUE != m_tex_name ) {
        glDeleteTextures(1, &m_tex_name);
    }
}

// テクスチャリソース取得
void* TextureOpenGL::get_resource()
{
    return &m_tex_name;
}

void TextureOpenGL::create_from_file(const char* path)
{
    destroy();

    // 指定ファイルのビットマップ化
    Bitmap bitmap;
    bitmap.create_from_file(path);

    GLuint tex    = create_from_bitmap(&bitmap);
    m_tex_name    = tex;
    m_desc.width  = bitmap.get_width();
    m_desc.height = bitmap.get_height();
    m_desc.info   = path;
}

void TextureOpenGL::create_from_font(const char *str, const char *font_name, u32 font_size)
{
    destroy();

    // フォントのビットマップ化
    Bitmap bitmap;
    bitmap.create_from_font(str, font_name, font_size);

    GLuint tex    = create_from_bitmap(&bitmap);
    m_tex_name    = tex;
    m_desc.width  = bitmap.get_width();
    m_desc.height = bitmap.get_height();
    m_desc.info   = str;
}

#endif//RC_USE_OPENGL

}
}
