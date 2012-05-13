/*
 *   file   rcGame/src/texture_manager.cpp
 *   brief  
 *   date   2012年 5月10日 木曜日 15時14分44秒 JST
 */

#include "graphic_manager.h"
#include "texture_manager.h"

using namespace rc::graphic;

namespace rc {
namespace game {

/* -------------------------------------------------- */
//	class TextureManager
/* -------------------------------------------------- */
TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

void TextureManager::destroy()
{
#if 0
	TEX_MAP_IT it = m_map.begin();
	while ( it != m_map.end() ) {
		SAFE_DELETE( (*it).second.p_tex );
		m_map.erace(it);
	}
#endif
}

Texture* TextureManager::create(const char *file_path)
{
	TEX_MAP_IT it = m_map.find(file_path);

	Texture *p_tex = NULL;
	if ( it != m_map.end() ) {
		(*it).second.ref++;
		p_tex = (*it).second.p_tex;
	}
	else {
		// ないので作る
		p_tex = new TextureOpenGL();
		p_tex->create_from_file(file_path);

		Desc desc;
		desc.ref = 1;
		desc.p_tex = p_tex;
		m_map.insert(TEX_PAIR(file_path, desc));
	}

	return p_tex;
}

Texture* TextureManager::create(const char *string, const char *font_name, u32 font_size)
{
	TEX_MAP_IT it = m_map.find(string);

	Texture *p_tex = NULL;
	if ( it != m_map.end() ) {
		(*it).second.ref++;
		p_tex = (*it).second.p_tex;
	}
	else {
		// ないので作る
		p_tex = new TextureOpenGL();
		p_tex->create_from_font(string, font_name, font_size);

		Desc desc;
		desc.ref = 1;
		desc.p_tex = p_tex;
		m_map.insert(TEX_PAIR(string, desc));
	}

	return p_tex;
}

void TextureManager::release(Texture* p_tex)
{
	Texture::Desc desc = p_tex->get_desc();

	TEX_MAP_IT it = m_map.find(desc.info.c_str());

	if ( it != m_map.end() ) {
		(*it).second.ref--;
		if ( (*it).second.ref <= 0 ) {
			SAFE_DELETE( (*it).second.p_tex );
			m_map.erase(it);
		}
	}
	else {
		
	}
}

} // namespace rc
} // namespace game
