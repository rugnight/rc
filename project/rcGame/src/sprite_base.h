/*
 *   file   rcGame/src/sprite_base.h
 *   brief  
 *   date   2012年 5月11日 金曜日 23時59分57秒 JST
 */

#ifndef _RC_SPRITE_BASE_H_
#define _RC_SPRITE_BASE_H_

#include "rcGameBase.h"
#include "transform.h"

namespace rc {
namespace game {

/* ------------------------------ */
class SpriteBase
/* ------------------------------ */
{
	public:
		SpriteBase();
		virtual ~SpriteBase();

		// テクスチャ設定
		void set_texture(Texture *p_tex);
		Texture* get_texture() { return m_p_tex; }

		// 描画
		void draw();

		// 姿勢情報
		void set_pos(f32 x, f32 y)           { get_transform().set_pos(x, y, 0.0f); }
		void set_pos(const Vector3& pos)     { get_transform().set_pos(pos); }
		void set_rot(f32 x, f32 y)           { get_transform().set_rot(x, y, 0.0f); }
		void set_rot(const Vector3& rot)     { get_transform().set_rot(rot); }
		void set_scale(f32 x, f32 y)         { get_transform().set_scale(x, y, 1.0f); }
		void set_scale(const Vector3& scale) { get_transform().set_scale(scale); }
		Vector3 get_pos()          { return get_transform().get_pos(); }
		Vector3 get_rot()          { return get_transform().get_rot(); }
		Vector3 get_scale()        { return get_transform().get_scale(); }

		Transform& get_transform() { return m_transform; }

		// 回転中心の設定
		void set_center(f32 x, f32 y);
		

	private:
		Texture		*m_p_tex;
		Transform	m_transform;

		bool		m_is_centering;
		Matrix4		m_center_mat;
		Matrix4		m_center_mat_inv;
};

} //rc 
} //game 

#endif//_RC_SPRITE_BASE_H_
