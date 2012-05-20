/*
 *   file   rcGame/src/sprite_font.cpp
 *   date   2012年 5月12日 土曜日 00時43分19秒 JST
 *   brief  
 */

#include "sprite_font.h"

namespace rc {
namespace game {

/* -------------------------------------------------- */
//	class SpriteFont : public SpriteBase
/* -------------------------------------------------- */
SpriteFont::SpriteFont()
	: m_font_size(0)
{
}

SpriteFont::~SpriteFont()
{
}

void SpriteFont::create(const char* string, const char* font_name, u32 font_size)
{
	Sprite::release_texture();
	Sprite::set_texture( m_p_tex_man->create(string, font_name, font_size) );
}

} //rc 
} //game 
