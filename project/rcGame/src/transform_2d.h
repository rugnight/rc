/*
 *   file   rcGame/src/transform_2d.h
 *   brief  
 *   date   2012年 5月10日 木曜日 14時55分06秒 JST
 */

#ifndef _RC_TRANSFORM_2D_H_
#define _RC_TRANSFORM_2D_H_

#include "rcGameBase.h"
#include "transform.h"

namespace rc {
namespace game {

/* ---------------------------------------- */
class Transform2D : public Transform
/* ---------------------------------------- */
{
public:
    Transform2D();
    virtual ~Transform2D();

    virtual void update();

    void set_center(f32 x, f32 y);
    Vector3 get_center() { return m_centering; }

private:
    bool    m_is_centering;
    Vector3 m_centering;
};

} // namespace rc 
} // namespace game 

#endif//_RC_TRANSFORM_2D_H_
