/*
 *   file   rcGame/src/sprite_base.cpp
 *   brief  
 *   date   2012年 5月12日 土曜日 00時09分08秒 JST
 */

#include "sprite_base.h"
#include "graphic_manager.h"

using namespace rc::math;
using namespace rc::graphic;

namespace rc {
namespace game {

/* ------------------------------ */
//	class SpriteBase
/* ------------------------------ */
SpriteBase::SpriteBase()
	: m_p_tex(NULL)
	, m_color(0xffffffff)
	, m_is_centering(false)
{
}

SpriteBase::~SpriteBase()
{
}

void SpriteBase::set_texture(Texture *p_tex)
{
	m_p_tex = p_tex;
}

void SpriteBase::draw()
{
	if ( !m_p_tex ) {
		return;
	}

	Texture* tex = m_p_tex;

    const float w = tex->get_desc().width;
    const float h = tex->get_desc().height;
    
    static VERTEX_T2F_C4UB_V3F vertices[] = {
        { 0.0f , 0.0f , m_color, 0.0 , 0.0 , 0.0 }, 
        { w    , 0.0f , m_color, w   , 0.0 , 0.0 }, 
        { w    , h    , m_color, w   , h   , 0.0 }, 
        
        { 0.0f , 0.0f , m_color, 0.0 , 0.0 , 0.0 }, 
        { w    , h    , m_color, w   , h   , 0.0 }, 
        { 0.0f , h    , m_color, 0.0 , h   , 0.0 },         
    }; 

    GraphicDevice *p_device = GraphicManager::Instance().get_device();

	// 回転の中心を設定してあるかどうか
	if ( m_is_centering ) {
		// センタリングする
		p_device->set_transform_matrix(m_center_mat * m_transform.get_matrix() * m_center_mat_inv);
	}
	else {
		// デフォルト 中心(0.0f,0.0f)
		p_device->set_transform_matrix(m_transform.get_matrix());
	}

    p_device->set_texture(tex);
    p_device->set_vertex_array(VERTEX_TYPE_T2F_C4UB_V3F, vertices);
    p_device->draw_vertex_array(DRAW_MODE_TRIANGLES, 6);
}

// 色の設定
void SpriteBase::set_color(u8 a, u8 r, u8 g, u8 b)
{
    m_color = (a << 24) | (b << 16) | (g << 8) | (r << 0);
}

void SpriteBase::set_center(f32 x, f32 y)
{
	Texture* tex = m_p_tex;
    const float w = tex->get_desc().width;
    const float h = tex->get_desc().height;

	f32 center_x = -(w * x);
	f32 center_y = -(h * y);

	m_center_mat		= Matrix4::UNIT;
	m_center_mat.m30	= center_x;
	m_center_mat.m31	= center_y;
	Matrix4::inverse( &m_center_mat_inv, m_center_mat);
	m_is_centering = true;
}


} //rc 
} //game 
