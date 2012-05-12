/*
 *   file   rcGame/src/sprite.cpp
 *   brief  
 *   date   2012年 5月12日 土曜日 00時09分08秒 JST
 */

#include "sprite_image.h"
#include "graphic_manager.h"

using namespace rc::math;
using namespace rc::graphic;

namespace rc {
namespace game {

/* ------------------------------ */
//	class Sprite
/* ------------------------------ */
Sprite::Sprite()
	: m_p_tex(NULL)
	, m_color(0xffffffff)
	, m_is_centering(false)
{
}

Sprite::~Sprite()
{
}

void Sprite::set_texture(Texture *p_tex)
{
	m_p_tex = p_tex;
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
void Sprite::set_color(u8 a, u8 r, u8 g, u8 b)
{
    m_color = (a << 24) | (b << 16) | (g << 8) | (r << 0);
}

void Sprite::set_center(f32 x, f32 y)
{
	if ( !m_p_tex ) {
		return;
	}    
    
	Texture* tex = m_p_tex;
    const float w = tex->get_desc().width;
    const float h = tex->get_desc().height;

	f32 center_x = -(w * x);
	f32 center_y = -(h * y);

    // スケーリングがかかっていることも考慮するため
    // 変換前と変換後で移動量が変わる

    // トランスフォーム前はスケーリング前のテクスチャサイズで移動
	m_center_mat		= Matrix4::UNIT;
	m_center_mat.m30	= center_x;
	m_center_mat.m31	= center_y;

    // トランスフォーム後はスケーリング後のテクスチャサイズで移動
	m_center_mat_inv        = Matrix4::UNIT;
	m_center_mat_inv.m30    = -(center_x * get_scale().x);
	m_center_mat_inv.m31    = -(center_y * get_scale().y);

	m_is_centering = true;
}


} //rc 
} //game 
