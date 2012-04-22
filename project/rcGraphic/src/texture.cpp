/*
 *   file   texture.cpp
 *   brief  
 *   date   2011/07/17
 */

#include "texture.h"
#include "util_math.h"

namespace rc {

#ifdef RC_USE_OPENGL
/* ----------------------------------------------- */
//  class TextureOpenGL: public Texture
/* ----------------------------------------------- */
TextureOpenGL::TextureOpenGL()
{
}

TextureOpenGL::~TextureOpenGL()
{
}
#endif//RC_USE_OPENGL

#if 0
/*
 *  GLTexture
 */
GLTexture::GLTexture() 
: m_id(-1)
{
}

GLTexture::~GLTexture()
{
    this->destroy();
}

bool GLTexture::load(const char* file_path)
{
    this->destroy();

#ifdef USE_SDL
    // 画像を読み込む
    SDL_Surface* surface1 = IMG_Load(file_path);
    if (!surface1) {
        fprintf(stderr, "%sを読み込めませんでした: %s\n", file_path, SDL_GetError());
        return false;
    }

    // フォーマットをRGBAに変換する
    SDL_Surface* surface2 = SDL_CreateRGBSurface(SDL_SWSURFACE,
            toPow2(surface1->w), toPow2(surface1->h), 32,
            0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
    if (!surface2) {
        fprintf(stderr, "変換用サーフィスを確保できませんでした: %s\n", SDL_GetError());
        SDL_FreeSurface(surface1);
        return false;
    }
    SDL_BlitSurface(surface1, NULL, surface2, NULL);

    // 範囲指定しても、拡大はされないみたい
    //SDL_Rect rect;
    //rect.x = 0; rect.y = 0;
    //rect.w = surface1->w; rect.h = surface1->h;
    //SDL_BlitSurface(surface1, &rect, surface2, NULL);

    // テクスチャを作る
    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, surface2->w, surface2->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface2->pixels);

    // テクスチャ情報を保管
    m_file_path = file_path;
    m_width  = surface2->w;
    m_height = surface2->h;

    // 後片付け
    SDL_FreeSurface(surface2);
    SDL_FreeSurface(surface1);
#endif//USE_SDL

    return true;
}

bool GLTexture::destroy()
{
    if ( 0 <= m_id ) {
        // テクスチャを削除する
        glDeleteTextures(1, &m_id);
        this->resetMember();
        return 1;
    }
    return 0;
}

void GLTexture::resetMember()
{
    m_id = -1;
    m_width = 0;
    m_height = 0;
    m_file_path = "";
}
#endif

};
