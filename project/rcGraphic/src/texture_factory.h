/*
 *   file   rc/graphics/texture_factory.h
 *   brief  
 *   date   2011/10/11
 */

#ifndef _TEXTURE_FACTORY_H_
#define _TEXTURE_FACTORY_H_

namespace rc {
    class Texture;

/* -------------------------------------------------- */
class ITextureFactory
/* -------------------------------------------------- */
{
public:
    virtual Texture* createEmpty()                         = 0;
    virtual Texture* createOnMemory()                      = 0;
    virtual Texture* createFromFile(const char* file_path) = 0;

};

/* -------------------------------------------------- */
class TextureFactoryBase : public ITextureFactory
/* -------------------------------------------------- */
{
public:
    Texture* createEmpty()                         = 0;
    Texture* createOnMemory()                      = 0;
    Texture* createFromFile(const char* file_path) = 0;
};

/* -------------------------------------------------- */
class GLTextureFactory : public TextureFactoryBase
/* -------------------------------------------------- */
{
public:
    Texture* createEmpty();
    Texture* createOnMemory();
    Texture* createFromFile(const char* file_path);
private:
};

/* -------------------------------------------------- */
class TextureFactory : public GLTextureFactory
/* -------------------------------------------------- */
{
public:
private:
};


}  // namespace rc

#endif //_TEXTURE_FACTORY_H_
