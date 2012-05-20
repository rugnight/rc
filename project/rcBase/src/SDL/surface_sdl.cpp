
/*
 *  file    project/rcBase/src/SDL/surface_sdl.cpp
 *  date    2012年 5月19日 土曜日 15時58分48秒 JST
 *  brief
 */

#include "surface_sdl.h"

/* -------------------------------------------------- */
//	class SurfaceSDL
/* -------------------------------------------------- */
SurfaceSDL::SurfaceSDL()
	: m_p_surface(NULL)
{
}

SurfaceSDL::~SurfaceSDL()
{
	destroy();
}

bool SurfaceSDL::create_from_file(const char* file_path)
{
	destroy();

    m_p_surface = IMG_Load(file_path);
    if (!m_p_surface ) {
        fprintf(stderr, "%sを読み込めませんでした\n", file_path);
        return false;
    }
	return true;
}

bool SurfaceSDL::create_empty(u32 width, u32 height, u32 depth, u32 r_mask, u32 g_mask, u32 b_mask, u32 a_mask)
{
	destroy();
    m_p_surface = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, 32, r_mask, g_mask, b_mask, a_mask);
    if (!m_p_surface) {
        fprintf(stderr, "変換用サーフィスを確保できませんでした: %s\n", SDL_GetError());
		return false;
    }
	return true;
}

void SurfaceSDL::destroy()
{
	if ( m_p_surface ) {
		SDL_FreeSurface(m_p_surface);
		m_p_surface = NULL;
	}
}

bool SurfaceSDL::blit(ISurface *src, RECT *src_rect, RECT *dst_rect)
{
    if ( !m_p_surface ) { 
        return false;
    }
	if ( !src ) {
		return false;
	}
    
	SDL_Rect rect1, rect2;
	SDL_Rect* p_rect1 = NULL;
	SDL_Rect* p_rect2 = NULL;

	if ( src_rect ) {
		rect1.x = src_rect->x;
		rect1.y = src_rect->y;
		rect1.w = src_rect->w;
		rect1.h = src_rect->h;
		p_rect1 = &rect1;
	}
	if ( dst_rect ) {
		rect2.x = dst_rect->x;
		rect2.y = dst_rect->y;
		rect2.w = dst_rect->w;
		rect2.h = dst_rect->h;
		p_rect2 = &rect2;
	}

	SurfaceSDL *p_src_sdl = dynamic_cast<SurfaceSDL*>(src);
	SurfaceSDL *p_dst_sdl = dynamic_cast<SurfaceSDL*>(this);
	const u32 ret = SDL_BlitSurface(p_src_sdl->get_surface_sdl(), p_rect1, p_dst_sdl->get_surface_sdl(), p_rect2);
	return (ret == 0);
}

void* SurfaceSDL::get_pixels()
{
	if ( !m_p_surface ) { return NULL; }
	return m_p_surface->pixels;
}

u32 SurfaceSDL::get_width()
{
	if ( !m_p_surface ) { return NULL; }
	return m_p_surface->w;
}

u32 SurfaceSDL::get_height()
{
	if ( !m_p_surface ) { return NULL; }
	return m_p_surface->h;
}
