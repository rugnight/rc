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
	public:
		Transform();
		virtual ~Transform();

        // 位置
		void set_pos(f32 x, f32 y, f32 z);
		void set_pos(const Vector3 &pos);
		Vector3 get_pos() { return m_pos; }

        // 回転
		void set_rot(f32 x, f32 y, f32 z);
		void set_rot(const Vector3 &rot);
		Vector3 get_rot() { return m_rot; }

        // 拡縮
		void set_scale(f32 x, f32 y, f32 z);
		void set_scale(const Vector3 &scale);
		Vector3 get_scale() { return m_scale; }

        // 行列の参照
		virtual const Matrix4& get_matrix();

        // 行列の更新
		virtual void update();

	private:
		bool	m_dirty;

		Vector3 m_pos;
		Vector3 m_rot;
		Vector3 m_scale;

    protected:
		Matrix4	m_transform;
};


} // namespace rc 
} // namespace game 

#endif//_RC_TRANSFORM_H_
