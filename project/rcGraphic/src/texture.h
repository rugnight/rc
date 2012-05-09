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

        // テクスチャ情報取得
        const Desc& get_desc() { return m_desc; }

        // テクスチャリソース取得
        virtual void* get_resource() = 0;

        // テクスチャ生成
        virtual void create_from_file(const char* path) = 0;

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

    // テクスチャリソース取得
    virtual void* get_resource();

    // テクスチャ生成
    virtual void create_from_file(const char* path);
    //virtual void create_from_fonts(const char* path);

private:
    GLuint m_tex_name;
};
#endif//RC_USE_OPENGL

}
}

#endif // _RC_TEXTURE_H_
