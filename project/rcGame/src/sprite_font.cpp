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
    TTF_Font *p_font = TTF_OpenFont(font_name, font_size);
    if ( !p_font ) {
        printf("failed open font\n");
    }
    SDL_Color color;
    color.r = 255;
    color.g = 255;
    color.b = 255;

    SDL_Surface *surface = TTF_RenderUTF8_Solid(p_font, string, color);
	u32 font_w = surface->w;//TTF_GetFontOutline(p_font);
	u32 font_h = surface->h;//TTF_FontFaceIsFixedWidth(p_font);
	printf("font %d, %d\n", font_w, font_h);

	if ( !surface ) {
		printf("failed create surface\n");
	}
    TTF_CloseFont(p_font);

	// サーフェイスを作成
	SurfaceSDL _surface;
	_surface.set_surface_sdl(surface);

	// テクスチャを作成してセット
	Sprite::release_texture();
	Texture *p_tex = m_p_tex_man->create(static_cast<ISurface*>(&_surface), string);
	Sprite::set_texture(p_tex);

    const f32 sprite_w = surface->w;
    const f32 sprite_h = surface->h;
	this->set_wh(sprite_w, sprite_h);

	const f32 u = sprite_w / static_cast<float>(p_tex->get_desc().width);
	const f32 v = sprite_h / static_cast<float>(p_tex->get_desc().height);
	this->set_uv(u, v);
}

} //rc 
} //game 
