/*
 *   file   rcGame/src/sprite.cpp
 *   brief  
 *   date   2012年 5月10日 木曜日 14時55分06秒 JST
 */

#include "sprite.h"

using namespace rc::math;
using namespace rc::graphic;

namespace {
	// 特に指定がなければこのマネージャを使う
	static TextureManager default_texture_man;
};

namespace rc {
namespace game {

/* ------------------------------ */
//	class Sprite 
/* ------------------------------ */
Sprite::Sprite()
	: m_p_tex_man(&default_texture_man)
{
}

Sprite::~Sprite()
{
	destroy();
}

void Sprite::destroy()
{
	if ( SpriteBase::get_texture() ) {
		m_p_tex_man->release( SpriteBase::get_texture() );
		SpriteBase::set_texture(NULL);
	}
}

void Sprite::create(const char *file_path)
{
	destroy();
	SpriteBase::set_texture( m_p_tex_man->create(file_path) );
}

} //rc 
} //game 
