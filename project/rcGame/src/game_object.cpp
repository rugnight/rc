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
    //memset(m_pa_component, NULL, GC_NUM);
}

GameObject::~GameObject()
{
}

bool GameObject::add(GameComponent *p_component)
{
    //m_pa_component[p_component->get_type()] = p_component;

    COMPONENT_PAIR pair(p_component->get_type(), p_component);
    m_map.insert(pair);
    return true;
}

bool GameObject::remove(GameComponent *p_component)
{
    //m_pa_component[p_component->get_type()] = NULL;

    const u32 num = m_map.count(p_component->get_type());
    if ( num == 0 ) {
        return false;
    }

    COMPONENT_IT it = m_map.find(p_component->get_type());
    for ( int i = 0; i < num; ++i ) {
        if ( (*it).second == p_component ) {
            m_map.erase(it);
            return true;
        }
        it++;
    }
    return false;
}

bool GameObject::is_hold(GAME_COMPONENT_TYPE type)
{
    //return (NULL != m_pa_component[type]);

    const u32 num = m_map.count(type);
    if ( num == 0 ) {
        return false;
    }
    return true;
}

GameComponent* GameObject::get_component(GAME_COMPONENT_TYPE type)
{
    //DEBUG_ASSERT(m_pa_component[type]);
    //return m_pa_component[type];

    DEBUG_ASSERT(is_hold(type));
    COMPONENT_IT it = m_map.find(type);
    return (*it).second;
}

u32 GameObject::get_component_num(GAME_COMPONENT_TYPE type)
{
    return m_map.count(type);
}

GameObject::COMPONENT_IT GameObject::get_component_iterator(GAME_COMPONENT_TYPE type)
{
    DEBUG_ASSERT(0 < get_component_num(type));
    return m_map.find(type);
}

} // namespace rc
} // namespace game
