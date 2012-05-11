/*
 *   file   rcGame/src/sprite.h
 *   brief  
 *   date   2012年 5月10日 木曜日 14時55分06秒 JST
 */

#ifndef _RC_SPRITE_H_
#define _RC_SPRITE_H_

#include "rcGameBase.h"
#include "sprite_base.h"

namespace rc {
namespace game {

/* ------------------------------ */
class Sprite : public SpriteBase
/* ------------------------------ */
{
	public:
		Sprite();
		virtual ~Sprite();

		// ファイルパスから作成
		void create(const char *file_path);
		void destroy();

	private:
		TextureManager *m_p_tex_man;
};

} //rc 
} //game 

#endif//_RC_SPRITE_H_
