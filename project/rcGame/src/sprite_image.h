/*
 *   file   rcGame/src/sprite_image.h
 *   brief  
 *   date   2012年 5月10日 木曜日 14時55分06秒 JST
 */

#ifndef _RC_SPRITE_IMAGE_H_
#define _RC_SPRITE_IMAGE_H_

#include "rcGameBase.h"
#include "sprite.h"

namespace rc {
namespace game {

/* ------------------------------ */
class SpriteImage : public Sprite
/* ------------------------------ */
{
	public:
		SpriteImage();
		virtual ~SpriteImage();

		// ファイルパスから作成
		void create(const char *file_path);
};

} //rc 
} //game 

#endif//_RC_SPRITE_IMAGE_H_
