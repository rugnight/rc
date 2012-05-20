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
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    
    // ビットマップを割り当てる
    glPixelStorei(GL_UNPACK_ROW_LENGTH, width);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    // 各行のピクセルデータの境界の種類
    // 1: バイト単位
    // 2: 偶数バイト単位
    // 4: WORD（2バイト）単位
    // 8: DWORD（4バイト）単位
    
    //printf("texsize :%d\n", tex_size);
    
    glTexImage2D(GL_TEXTURE_2D,
        0,                         // MIPMAPのレベル
        4,                   // テクスチャで使う カラーコンポーネント数
        width,
        height,
        0,                         // ボーダー
        GL_RGBA,                   // ビットマップの色の並び順
        GL_UNSIGNED_BYTE,
        p_bmp->get_bytes()
        );
    return tex;
}

static GLuint create_from_surface(ISurface *p_surface)
{
    const GLuint width  = (GLint)p_surface->get_width();
    const GLuint height = (GLint)p_surface->get_height();

    ///// テクスチャの作成
    GLuint tex = GL_INVALID_VALUE;
    // テクスチャの名前を作る
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    
    // ビットマップを割り当てる
    glPixelStorei(GL_UNPACK_ROW_LENGTH, width);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
    // 各行のピクセルデータの境界の種類
    // 1: バイト単位
    // 2: 偶数バイト単位
    // 4: WORD（2バイト）単位
    // 8: DWORD（4バイト）単位
    
    glTexImage2D(GL_TEXTURE_2D,
        0,                         // MIPMAPのレベル
        GL_RGBA,                   // テクスチャで使う カラーコンポーネント数
        width,
        height,
        0,                         // ボーダー
        GL_BGRA,                   // ビットマップの色の並び順
		GL_UNSIGNED_BYTE,
		p_surface->get_pixels()
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
#if 0
    Bitmap bitmap;
    bitmap.create_from_file(path);
    GLuint tex    = create_from_bitmap(&bitmap);
#else
	SurfaceSDL surface, surface_rgb;
	surface.create_from_file(path);
	bool success = surface_rgb.create_empty(toPow2(surface.get_width()), toPow2(surface.get_height()), 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
    
    if ( !success ) {
        printf("failed create surface\n");
    }
    
	surface_rgb.blit((ISurface*)(&surface), NULL, NULL);
    if ( !success ) {
        printf("failed blit surface\n");
    }
    
    
    GLuint tex = create_from_surface((ISurface*)(&surface));
#endif
    m_tex_name    = tex;
    m_desc.width  = surface_rgb.get_width();
    m_desc.height = surface_rgb.get_height();

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
