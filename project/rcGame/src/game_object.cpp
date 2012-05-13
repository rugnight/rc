/*
 *  file    rc/project/rcGame/src/game_object.cpp
 *  date    2012年 5月12日 土曜日 23時33分26秒 JST
 *  brief
 */

#include "game_object.h"
#include "sprite_image.h"
#include "game_component.h"

//using namespace rc::game;

namespace rc {
namespace game {

/* -------------------------------------------------- */
//  class GameObject
/* -------------------------------------------------- */
GameObject::GameObject()
{
    memset(m_pa_component, NULL, GC_NUM);
}

GameObject::~GameObject()
{
}

bool GameObject::add(GameComponent *p_component)
{
    m_pa_component[p_component->get_type()] = p_component;
}

bool GameObject::remove(GameComponent *p_component)
{
    m_pa_component[p_component->get_type()] = NULL;
}

bool GameObject::is_hold(GAME_COMPONENT_TYPE type)
{
    return (NULL != m_pa_component[type]);
}

GameComponent* GameObject::get_component(GAME_COMPONENT_TYPE type)
{
    DEBUG_ASSERT(m_pa_component[type]);
    return m_pa_component[type];
}

} // namespace rc
} // namespace game
