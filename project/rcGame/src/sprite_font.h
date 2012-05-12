/*
 *   file   rcGame/src/sprite_font.h
 *   date   2012年 5月12日 土曜日 00時43分19秒 JST
 *   brief  
 */

#ifndef _RC_SPRITE_FONT_H_
#define _RC_SPRITE_FONT_H_

#include "rcGameBase.h"
#include "sprite.h"

namespace rc {
namespace game {

/* -------------------------------------------------- */
class SpriteFont : public Sprite
/* -------------------------------------------------- */
{
	public:
		SpriteFont();
		virtual ~SpriteFont();

		void create(const char* string, const char* font_name, u32 font_size);
		void destroy();

	private:
		std::string m_text;
		std::string m_font_neme;
		u32			m_font_size;

		TextureManager *m_p_tex_man;
};

} //rc 
} //game 

#endif//_RC_SPRITE_FONT_H_
