/*
 *   file   rcGame/src/sprite_font.cpp
 *   date   2012年 5月12日 土曜日 00時43分19秒 JST
 *   brief  
 */

#include "sprite_font.h"

namespace {
	// 特に指定がなければこのマネージャを使う
	static TextureManager default_texture_man;
};

namespace rc {
namespace game {

/* -------------------------------------------------- */
//	class SpriteFont : public SpriteBase
/* -------------------------------------------------- */
SpriteFont::SpriteFont()
	: m_p_tex_man(&default_texture_man)
	, m_font_size(0)
{
}

SpriteFont::~SpriteFont()
{
	destroy();
}

void SpriteFont::destroy()
{
	if ( SpriteBase::get_texture() ) {
		m_p_tex_man->release( SpriteBase::get_texture() );
		SpriteBase::set_texture(NULL);
	}
}

void SpriteFont::create(const char* string, const char* font_name, u32 font_size)
{
	destroy();
	SpriteBase::set_texture( m_p_tex_man->create(string, font_name, font_size) );
}

} //rc 
} //game 
