/*
 *   file   rcGame/src/sprite_image.cpp
 *   brief  
 *   date   2012年 5月10日 木曜日 14時55分06秒 JST
 */

#include "sprite_image.h"

using namespace rc::math;
using namespace rc::graphic;

namespace rc {
namespace game {

/* ------------------------------ */
//	class SpriteImage 
/* ------------------------------ */
SpriteImage::SpriteImage()
{
}

SpriteImage::~SpriteImage()
{
}

void SpriteImage::create(const char *file_path)
{
	Sprite::release_texture();

	// サーフェイスを作成
	SurfaceSDL surface;
	bool success = surface.create_from_file(file_path);
	if ( !success ) {
		printf("failed create sprite image\n");
		return ;
	}

	// テクスチャを作成してセット
	Texture *p_tex = m_p_tex_man->create(static_cast<ISurface*>(&surface), file_path);
	Sprite::set_texture( p_tex );
    
    const f32 sprite_w = surface.get_width();
    const f32 sprite_h = surface.get_height();
	this->set_wh(sprite_w, sprite_h);

	const f32 u = sprite_w / static_cast<float>(p_tex->get_desc().width);
	const f32 v = sprite_h / static_cast<float>(p_tex->get_desc().height);
	this->set_uv(u, v);
}

} //rc 
} //game 
