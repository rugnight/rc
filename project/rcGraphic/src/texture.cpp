/*
 *   file   texture.cpp
 *   brief  
 *   date   2011/07/17
 */

#include "texture.h"
#include "util_math.h"

namespace rc {
namespace graphic {

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


}
}
