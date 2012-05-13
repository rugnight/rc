/*
 *   file   rcGame/src/sprite.cpp
 *   brief  
 *   date   2012年 5月12日 土曜日 00時09分08秒 JST
 */

#include "sprite_image.h"
#include "graphic_manager.h"

namespace rc {
namespace game {

/* ------------------------------ */
//	class Sprite
/* ------------------------------ */
Sprite::Sprite()
	: m_p_tex(NULL)
	, m_color(0xffffffff)
{
    m_center = Vector3::ZERO;
}

Sprite::~Sprite()
{
}

void Sprite::set_texture(Texture *p_tex)
{
	m_p_tex = p_tex;
    set_center(m_center.x, m_center.y);
}

void Sprite::draw()
{
	if ( !m_p_tex ) {
		return;
	}

	Texture* tex = m_p_tex;

    const float w = tex->get_desc().width;
    const float h = tex->get_desc().height;

    const float x = w;//tex->get_desc().width  * get_scale().x;
    const float y = h;//tex->get_desc().height * get_scale().y;

    VERTEX_T2F_C4UB_V3F vertices[] = {
        { 0.0f , 0.0f , m_color, 0.0 , 0.0 , 0.0 }, 
        { w    , 0.0f , m_color, x   , 0.0 , 0.0 }, 
        { w    , h    , m_color, x   , y   , 0.0 }, 
        
        { 0.0f , 0.0f , m_color, 0.0 , 0.0 , 0.0 }, 
        { w    , h    , m_color, x   , y   , 0.0 }, 
        { 0.0f , h    , m_color, 0.0 , y   , 0.0 },         
    }; 

    GraphicDevice *p_device = GraphicManager::Instance().get_device();
    p_device->set_transform_matrix(m_transform.get_matrix());

    p_device->set_texture(tex);
    p_device->set_vertex_array(VERTEX_TYPE_T2F_C4UB_V3F, vertices);
    p_device->draw_vertex_array(DRAW_MODE_TRIANGLES, 6);
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
    m_transform.set_center( (m_p_tex->get_desc().width  * m_center.x),
                            (m_p_tex->get_desc().height * m_center.y) );
}

} //rc 
} //game 
