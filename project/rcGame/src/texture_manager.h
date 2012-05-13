/*
 *   file   rcGame/src/texture_manager.h
 *   brief  
 *   date   2012年 5月10日 木曜日 15時14分44秒 JST
 */

#ifndef _RC_TEXTURE_MANAGER_H_
#define _RC_TEXTURE_MANAGER_H_

#include "texture.h"

namespace rc {
namespace game {

/* -------------------------------------------------- */
class TextureManager
/* -------------------------------------------------- */
{
	public:
		struct Desc {
			u32	ref;
			rc::graphic::Texture *p_tex;
		};

		typedef rc::graphic::Texture		 Texture;
		typedef std::map<std::string, Desc>  TEX_MAP;
		typedef TEX_MAP::iterator			 TEX_MAP_IT;
		typedef std::pair<std::string, Desc> TEX_PAIR;

	private:
		void destroy();

	public:
		TextureManager();
		virtual ~TextureManager();

		Texture* create(const char *file_path);
		Texture* create(const char *string, const char *font_name, u32 font_size);

		void release(Texture* p_tex);

	private:
		TEX_MAP m_map;
};

} // namespace rc
} // namespace game

#endif//_RC_TEXTURE_MANAGER_H_
