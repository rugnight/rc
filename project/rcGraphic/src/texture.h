/*
 *   file   texture.h
 *   brief  
 *   date   2011/07/17
 */

#ifndef _RC_TEXTURE_H_
#define _RC_TEXTURE_H_

#include "rcGraphicBase.h"

#include <string>
#include <map>

namespace rc {

/* ----------------------------------------------- */
class ITexture
/* ----------------------------------------------- */
{
    public:
        virtual bool load(const char* file_path) = 0;
        virtual bool destroy() = 0;

        virtual int getWidth()  = 0;
        virtual int getHeight() = 0;

        virtual const char* getFilePath() = 0;

        virtual unsigned int getID() = 0;
};

/* ----------------------------------------------- */
class TextureBase : public ITexture
/* ----------------------------------------------- */
{
public: 
    TextureBase();
    virtual ~TextureBase();

    virtual int getWidth() { return m_width; }
    virtual int getHeight(){ return m_height; }
    virtual const char* getFilePath() { return m_file_path.c_str(); }

    //virtual unsigned int getID() = 0;

protected:
    int    m_width;
    int    m_height;
    std::string m_file_path;
};

/* ----------------------------------------------- */
class GLTexture : public TextureBase
/* ----------------------------------------------- */
{
public:
    GLTexture();
    virtual ~GLTexture();

    virtual bool load(const char* file_path);
    virtual bool destroy();

    virtual unsigned int getID() { return m_id; }

private:
    void resetMember();

private:
    u32 m_id;
};

/* ----------------------------------------------- */
class Texture : public GLTexture
/* ----------------------------------------------- */
{
public:
    Texture();
    virtual ~Texture();
private:
};

#if 0
/* ----------------------------------------------- */
class Texture
/* ----------------------------------------------- */
{
public:
    struct Desc {
        u32 width, height, bit, pitch, buffer_size, format;
    };
public:
    Texture();
    virtual ~Texture();
    
    const Desc& get_desc() { return m_desc; }
protected:
    Desc m_desc;
};
#endif


};

#endif // _RC_TEXTURE_H_
