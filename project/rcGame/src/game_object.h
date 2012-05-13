/*
 *  file    rc/project/rcGame/src/game_object.h
 *  date    2012年 5月12日 土曜日 23時33分26秒 JST
 *  brief
 */

#ifndef _RC_GAME_OBJECT_H_
#define _RC_GAME_OBJECT_H_

#include "rcGameBase.h"

#include "game_component.h"

namespace rc {
namespace game {

/* -------------------------------------------------- */
class GameObject
/* -------------------------------------------------- */
{
public:
    GameObject();
    virtual ~GameObject();

    bool add(GameComponent *p_component);
    bool remove(GameComponent *p_component);

    bool is_hold(GAME_COMPONENT_TYPE type);
    GameComponent* get_component(GAME_COMPONENT_TYPE type);

    // ゲームコンポーネントの更新
    virtual void update() {}

private:
    GameComponent *m_pa_component[GC_NUM];
};

} // namespace rc
} // namespace game

#endif//_RC_GAME_OBJECT_H_
