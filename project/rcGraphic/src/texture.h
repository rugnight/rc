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

        void create_from_file(const char* path);

        // テクスチャ情報取得
        const Desc& get_desc() { return m_desc; }

        // テクスチャリソース取得
        // 各グラフィックデバイス毎に実装
        virtual void* get_resource() = 0;

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

    virtual void* get_resource() { return NULL; }

private:
};
#endif//RC_USE_OPENGL

}
}

#endif // _RC_TEXTURE_H_
