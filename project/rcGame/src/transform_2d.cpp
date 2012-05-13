/*
 *   file   rcGame/src/transform_2d.cpp
 *   brief  
 *   date   2012年 5月10日 木曜日 14時55分06秒 JST
 */

#include "transform_2d.h"

using namespace rc::math;

namespace rc {
namespace game {

/* ---------------------------------------- */
//  class Transform2D : public Transform
/* ---------------------------------------- */
Transform2D::Transform2D()
    : m_is_centering(false)
{
    m_centering = Vector3::ZERO;
}
Transform2D::~Transform2D()
{
}

void Transform2D::update()
{
    Transform::update();
    if ( !m_is_centering ) {
        return;
    }

    // スケーリングがかかっていることも考慮するため
    // 変換前と変換後で移動量が変わる

    // トランスフォーム前はスケーリング前のテクスチャサイズで移動
	Matrix4 center_mat = Matrix4::UNIT;
	center_mat.m30     = -m_centering.x;
	center_mat.m31     = -m_centering.y;

    // トランスフォーム後はスケーリング後のテクスチャサイズで移動
	Matrix4 center_mat_inv = Matrix4::UNIT;
	center_mat_inv.m30     = m_centering.x * get_scale().x;
	center_mat_inv.m31     = m_centering.y * get_scale().y;

    Matrix4 tmp = m_transform;
    m_transform = center_mat * tmp * center_mat_inv;
}

void Transform2D::set_center(f32 x, f32 y)
{
    m_centering.x = x;
    m_centering.y = y;
    if ( is_float_zero(x) && is_float_zero(y) ) {
        m_is_centering = false;
    }
    else {
        m_is_centering = true;
    }
}

} // namespace rc 
} // namespace game 
