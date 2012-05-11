/*
 *   file   rcGame/src/transform.h
 *   brief  
 *   date   2012年 5月10日 木曜日 14時55分06秒 JST
 */

#ifndef _RC_TRANSFORM_H_
#define _RC_TRANSFORM_H_

#include "rcGameBase.h"

namespace rc {
namespace game {

/* ---------------------------------------- */
class Transform
/* ---------------------------------------- */
{
	private:
		typedef rc::math::Vector3 Vector3;
		typedef rc::math::Matrix4 Matrix4;

	public:
		Transform();
		virtual ~Transform();

		void set_pos(f32 x, f32 y, f32 z);
		void set_pos(const Vector3 &pos);
		Vector3 get_pos() { return m_pos; }

		void set_rot(f32 x, f32 y, f32 z);
		void set_rot(const Vector3 &rot);
		Vector3 get_rot() { return m_rot; }

		void set_scale(f32 x, f32 y, f32 z);
		void set_scale(const Vector3 &scale);
		Vector3 get_scale() { return m_scale; }

		void update();
		const Matrix4& get_matrix();

	private:
		bool	m_dirty;

		Vector3 m_pos;
		Vector3 m_rot;
		Vector3 m_scale;

		Matrix4	m_transform;
};


} // namespace rc 
} // namespace game 




#endif//_RC_TRANSFORM_H_
