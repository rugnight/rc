/*
 *   file   rcGame/src/sprite_image.cpp
 *   brief  
 *   date   2012年 5月10日 木曜日 14時55分06秒 JST
 */

#include "sprite_image.h"

using namespace rc::math;
using namespace rc::graphic;

namespace {
	// 特に指定がなければこのマネージャを使う
	static rc::game::TextureManager default_texture_man;
};

namespace rc {
namespace game {

/* ------------------------------ */
//	class SpriteImage 
/* ------------------------------ */
SpriteImage::SpriteImage()
	: m_p_tex_man(&default_texture_man)
{
}

SpriteImage::~SpriteImage()
{
	destroy();
}

void SpriteImage::destroy()
{
	if ( Sprite::get_texture() ) {
		m_p_tex_man->release( Sprite::get_texture() );
		Sprite::set_texture(NULL);
	}
}

void SpriteImage::create(const char *file_path)
{
	destroy();
	Sprite::set_texture( m_p_tex_man->create(file_path) );
}

} //rc 
} //game 
