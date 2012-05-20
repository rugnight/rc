/*
 *  file    project/rcBase/src/SDL/surface_sdl.h
 *  date    2012年 5月19日 土曜日 15時58分48秒 JST
 *  brief
 */

#ifndef _RC_SURFACE_SDL_H_
#define _RC_SURFACE_SDL_H_

#include "../rc_base.h"

/* -------------------------------------------------- */
class ISurface
/* -------------------------------------------------- */
{
public:
	virtual bool create_from_file(const char* file_path) = 0;
	virtual bool create_empty(u32 width, u32 height, u32 depth, u32 r_mask, u32 g_mask, u32 b_mask, u32 a_mask) = 0;

	virtual void destroy() = 0;

	virtual bool blit(ISurface *src, RECT *src_rect, RECT *dst_rect) = 0;

	virtual void* get_pixels() = 0;
	virtual u32 get_width() = 0;
	virtual u32 get_height() = 0;
};

/* -------------------------------------------------- */
class SurfaceSDL : public ISurface
/* -------------------------------------------------- */
{
public:
	SurfaceSDL();
	virtual ~SurfaceSDL();

	virtual bool create_from_file(const char* file_path);
	virtual bool create_empty(u32 width, u32 height, u32 depth, u32 r_mask, u32 g_mask, u32 b_mask, u32 a_mask);

	virtual void destroy();

	virtual bool blit(ISurface *src, RECT *src_rect, RECT *dst_rect);

	virtual void* get_pixels();
	virtual u32 get_width();
	virtual u32 get_height();

	SDL_Surface* get_surface_sdl() { return m_p_surface; }

private:
	SDL_Surface *m_p_surface;
};


#endif//_RC_SURFACE_SDL_H_
