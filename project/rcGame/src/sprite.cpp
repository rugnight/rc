/*
 *   file   rcGame/src/sprite.cpp
 *   brief  
 *   date   2012年 5月12日 土曜日 00時09分08秒 JST
 */

#include "sprite_image.h"
#include "graphic_manager.h"

namespace {
	// 特に指定がなければこのマネージャを使う
	static rc::game::TextureManager default_texture_man;
};

namespace rc {
namespace game {

/* ------------------------------ */
//	class Sprite
/* ------------------------------ */
Sprite::Sprite()
	: m_p_tex(NULL)
	, m_color(0xffffffff)
	, m_p_tex_man(&default_texture_man)
{
    m_uv = Vector3::UNIT;
    m_wh = Vector3(100.0f, 100.0f, 0.0f);
    m_center = Vector3::ZERO;
}

Sprite::~Sprite()
{
	release_texture();
}

void Sprite::set_texture(Texture *p_tex)
{
	m_p_tex = p_tex;
    if ( !m_p_tex ) {
        return;
    }

    set_wh( m_p_tex->get_desc().width, m_p_tex->get_desc().height);
    set_center(m_center.x, m_center.y);
}

void Sprite::release_texture()
{
	if ( m_p_tex ) {
		m_p_tex_man->release( m_p_tex );
		m_p_tex = NULL;
	}
}

// 色の設定
void Sprite::set_color(u8 a, u8 r, u8 g, u8 b)
{
    m_color = (a << 24) | (b << 16) | (g << 8) | (r << 0);
}

void Sprite::set_center(f32 x, f32 y)
{
	if ( !m_p_tex ) {
		return;
	}
    m_center.x = x;
    m_center.y = y;
    m_transform.set_center( (m_wh.x * m_center.x), (m_wh.y * m_center.y) );
}

} //rc 
} //game 
