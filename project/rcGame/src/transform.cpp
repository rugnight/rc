/*
 *   file   rcGame/src/transform.cpp
 *   brief  
 *   date   2012年 5月10日 木曜日 14時55分06秒 JST
 */

#include "transform.h"

using namespace rc::math;

namespace rc {
namespace game {

/* ---------------------------------------- */
//	class Transform
/* ---------------------------------------- */
Transform::Transform()
: m_dirty(false)
, m_pos(Vector3::ZERO)
, m_rot(Vector3::ZERO)
, m_scale(Vector3::UNIT)
, m_transform(Matrix4::UNIT)
{
}

Transform::~Transform()
{
}

void Transform::set_pos(f32 x, f32 y, f32 z)
{
	m_dirty = true;
	m_pos.x = x; m_pos.y = y; m_pos.z = z;
}

void Transform::set_pos(const Vector3 &pos)
{
	m_dirty = true;
	m_pos = pos;
}

void Transform::set_rot(f32 x, f32 y, f32 z)
{
	m_dirty = true;
	m_rot.x = x; m_rot.y = y; m_rot.z = z;
}

void Transform::set_rot(const Vector3 &rot)
{
	m_dirty = true;
	m_rot = rot;
}

void Transform::set_scale(f32 x, f32 y, f32 z)
{
	m_dirty = true;
	m_scale.x = x; m_scale.y = y; m_scale.z = z;
}

void Transform::set_scale(const Vector3 &scale)
{
	m_dirty = true;
	m_scale = scale;
}

void Transform::update()
{
	if ( !m_dirty )
		return;

	Matrix4 translate = Matrix4::UNIT;
	translate.m30 = m_pos.x;
	translate.m31 = m_pos.y;
	translate.m32 = m_pos.z;

	Matrix4 rotate = Matrix4::UNIT;
#if 0
	rotate.m00 = cos(m_rot.x) * cos(m_rot.y);
	rotate.m01 = cos(m_rot.x) * sin(m_rot.y) * sin(m_rot.z) - sin(m_rot.x) * cos(m_rot.z);
	rotate.m02 = cos(m_rot.x) * sin(m_rot.y) * cos(m_rot.z) + sin(m_rot.x) * sin(m_rot.z);

	rotate.m11 = sin(m_rot.x) * cos(m_rot.y);
	rotate.m12 = sin(m_rot.x) * sin(m_rot.y) * sin(m_rot.z) + cos(m_rot.x) * cos(m_rot.z);
	rotate.m13 = sin(m_rot.x) * sin(m_rot.y) * cos(m_rot.z) - cos(m_rot.x) * sin(m_rot.z);

	rotate.m21 = -sin(m_rot.y);
	rotate.m22 = cos(m_rot.y) * sin(m_rot.z);
	rotate.m23 = cos(m_rot.y) * cos(m_rot.z);

#else
	rotate.m00 = cos(m_rot.y) * cos(m_rot.x) * cos(m_rot.z) - sin(m_rot.y) * sin(m_rot.z);
	rotate.m01 = -cos(m_rot.y) * cos(m_rot.x) * sin(m_rot.z) - sin(m_rot.y) * cos(m_rot.z);
	rotate.m02 = cos(m_rot.y) * sin(m_rot.x);

	rotate.m10 = sin(m_rot.y) * cos(m_rot.x) * cos(m_rot.z) + cos(m_rot.y) * sin(m_rot.z);
	rotate.m11 = -sin(m_rot.y) * cos(m_rot.x) * sin(m_rot.z) + cos(m_rot.y) * cos(m_rot.z);
	rotate.m12 = sin(m_rot.y) * sin(m_rot.x);

	rotate.m20 = -sin(m_rot.x) * cos(m_rot.z);
	rotate.m21 = sin(m_rot.x) * sin(m_rot.z);
	rotate.m22 = cos(m_rot.x);
#endif
	

	Matrix4 scale = Matrix4::UNIT;
	scale.m00 = m_scale.x;
	scale.m11 = m_scale.y;
	scale.m22 = m_scale.z;

	m_transform = scale * rotate * translate;
}

const Matrix4& Transform::get_matrix()
{
	update();
	return m_transform;
}

} // namespace rc 
} // namespace game 

