/*
 *   file   rcGame/src/sprite_image.cpp
 *   brief  
 *   date   2012年 5月10日 木曜日 14時55分06秒 JST
 */

#include "sprite_image.h"

using namespace rc::math;
using namespace rc::graphic;

namespace rc {
namespace game {

/* ------------------------------ */
//	class SpriteImage 
/* ------------------------------ */
SpriteImage::SpriteImage()
{
}

SpriteImage::~SpriteImage()
{
}

void SpriteImage::create(const char *file_path)
{
	Sprite::release_texture();
	Sprite::set_texture( m_p_tex_man->create(file_path) );
}

} //rc 
} //game 
