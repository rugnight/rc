/*
 *	file	rc/project/rcGame/src/game_component.cpp
 *	date	2012年 5月13日 日曜日 02時25分08秒 JST
 *	brief
 */

#include "game_component.h"

namespace rc {
namespace game {

/* -------------------------------------------------- */
//  class GameComponent
/* -------------------------------------------------- */
GameComponent::GameComponent(GAME_COMPONENT_TYPE type)
    : m_type(type)
{
}

GameComponent::~GameComponent()
{
}

/* -------------------------------------------------- */
//	class GameComponentUpdate : public GameComponent
/* -------------------------------------------------- */
GameComponentUpdate::GameComponentUpdate()
	: GameComponent(GC_UPDATE)
	, m_p_object(NULL)
{
}

GameComponentUpdate::~GameComponentUpdate()
{
}

void GameComponentUpdate::set_game_object(GameObject *p_object)
{
	m_p_object = p_object;
}

GameObject* GameComponentUpdate::get_game_object()
{
	DEBUG_ASSERT(m_p_object);
	return m_p_object;
}

/* -------------------------------------------------- */
//  class GameComponentSprite : public GameComponent
/* -------------------------------------------------- */
GameComponentSprite::GameComponentSprite()
    : GameComponent(GC_SPRITE)
    , m_p_sprite(NULL)
{
}

GameComponentSprite::~GameComponentSprite()
{
}


void GameComponentSprite::set_sprite(Sprite *p_sprite)
{
    m_p_sprite = p_sprite;
}

Sprite* GameComponentSprite::get_sprite()
{
    DEBUG_ASSERT(m_p_sprite);
    return m_p_sprite;
}


} // namespace rc
} // namespace game
