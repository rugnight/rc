/*
 *   file   texture.cpp
 *   brief  
 *   date   2011/07/17
 */

#include "texture.h"
#include "util_math.h"
#include "bitmap.h"

namespace rc {
namespace graphic {

#ifdef RC_USE_OPENGL
/* ----------------------------------------------- */
//  class TextureOpenGL: public Texture
/* ----------------------------------------------- */
TextureOpenGL::TextureOpenGL()
    : m_tex_name(GL_INVALID_VALUE)
{
}

TextureOpenGL::~TextureOpenGL()
{
}

// テクスチャリソース取得
void* TextureOpenGL::get_resource()
{
    return &m_tex_name;
}

void TextureOpenGL::create_from_file(const char* path)
{
    // 指定ファイルのビットマップ化
    rc::graphic::TextureOpenGL ret;
    rc::graphic::Bitmap bitmap;
    //bitmap.create_from_file(path);
    bitmap.create_from_font("黒川エレン");

    ///// テクスチャの作成
    GLuint tex = GL_INVALID_VALUE;
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
        0,                                     // MIPMAPのレベル
        GL_RGBA,                               // テクスチャで使う カラーコンポーネント数
        (GLsizei)bitmap.get_width(),
        (GLsizei)bitmap.get_height(),
        0,                                     // ボーダー
        GL_BGRA,                               // ビットマップの色の並び順
        GL_UNSIGNED_INT_8_8_8_8,
        bitmap.get_bytes()
        );

    m_tex_name    = tex;
    m_desc.width  = bitmap.get_width();
    m_desc.height = bitmap.get_height();
}

#endif//RC_USE_OPENGL



}
}
