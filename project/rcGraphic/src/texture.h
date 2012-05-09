/*
 *   file   texture.h
 *   brief  
 *   date   2011/07/17
 */

#ifndef _RC_TEXTURE_H_
#define _RC_TEXTURE_H_

#include "rcGraphicBase.h"

namespace rc {
namespace graphic {


/* ----------------------------------------------- */
class Texture
/* ----------------------------------------------- */
{
    public:
        struct Desc {
            u32 width, height;
            Desc() : width(), height() {}
        };
    public:
        Texture()  {}
        virtual ~Texture() {}

        // 破棄
        virtual void destroy() = 0;

        // テクスチャ情報取得
        const Desc& get_desc() { return m_desc; }

        // テクスチャリソース取得
        virtual void* get_resource() = 0;

        // テクスチャ生成
        virtual void create_from_file(const char* path) = 0;
        virtual void create_from_font(const char *str, const char *font_name, u32 font_size) = 0;

    protected:
        Desc    m_desc;
};

#ifdef RC_USE_OPENGL
/* ----------------------------------------------- */
class TextureOpenGL: public Texture
/* ----------------------------------------------- */
{
public:
    TextureOpenGL();
    virtual ~TextureOpenGL();

    // 破棄
    virtual void destroy();

    // テクスチャリソース取得
    virtual void* get_resource();

    // テクスチャ生成
    virtual void create_from_file(const char* path);
    virtual void create_from_font(const char *str, const char *font_name, u32 font_size);

private:
    GLuint m_tex_name;
};
#endif//RC_USE_OPENGL

}
}

#endif // _RC_TEXTURE_H_
