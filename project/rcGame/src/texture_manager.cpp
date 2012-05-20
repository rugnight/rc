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
	TEX_MAP_IT it = m_map.begin();
	while ( it != m_map.end() ) {
		SAFE_DELETE( (*it).second.p_tex );
		m_map.erase(it);
	}
}

Texture* TextureManager::create(ISurface *p_surface, const char *key)
{
	Texture *p_tex = this->get_texture(key);
	// あったので返す
	if ( p_tex ) {
		return p_tex;
	}

	// ないので作る
	p_tex = new TextureOpenGL();
	bool success = p_tex->create_from_surface(p_surface);
	if ( !success ) {
		printf("failed create texture\n");
		return NULL;
	}

	this->add_texture(p_tex, key);
	return p_tex;
}


Texture* TextureManager::create(const char *file_path)
{
	Texture *p_tex = this->get_texture(file_path);
	// あったので返す
	if ( p_tex ) {
		return p_tex;
	}

	// ないので作る
	p_tex = new TextureOpenGL();
	p_tex->create_from_file(file_path);

	this->add_texture(p_tex, file_path);
	return p_tex;
}

Texture* TextureManager::create(const char *string, const char *font_name, u32 font_size)
{
	Texture *p_tex = this->get_texture(string);
	// あったので返す
	if ( p_tex ) {
		return p_tex;
	}

	// ないので作る
	p_tex = new TextureOpenGL();
	p_tex->create_from_font(string, font_name, font_size);

	this->add_texture(p_tex, string);
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

void TextureManager::add_texture(Texture *p_tex, const char *key)
{
	Desc desc;
	desc.ref = 1;
	desc.p_tex = p_tex;
	m_map.insert(TEX_PAIR(key, desc));
}

Texture* TextureManager::get_texture(const char *key)
{
	TEX_MAP_IT it = m_map.find(key);

	Texture *p_tex = NULL;
	if ( it != m_map.end() ) {
		(*it).second.ref++;
		p_tex = (*it).second.p_tex;
	}

	return p_tex;
}

} // namespace rc
} // namespace game
