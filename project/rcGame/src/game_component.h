/*
 *	file	rc/project/rcGame/src/game_component.h
 *	date	2012年 5月13日 日曜日 02時25分08秒 JST
 *	brief
 */

#ifndef _RC_GAME_COMPONENT_H_
#define _RC_GAME_COMPONENT_H_

#include "rcGameBase.h"

namespace rc {
namespace game {

/* -------------------------------------------------- */
typedef enum game_component_type {
/* -------------------------------------------------- */
	GC_UPDATE,
    GC_SPRITE,

    GC_NUM,
} GAME_COMPONENT_TYPE;


/* -------------------------------------------------- */
class GameComponent
/* -------------------------------------------------- */
{
private:
    GameComponent() {};    // type指定なしの生成は禁止
public:
    GameComponent(GAME_COMPONENT_TYPE type);
    virtual ~GameComponent();

    GAME_COMPONENT_TYPE get_type() { return m_type; }

private:
    GAME_COMPONENT_TYPE m_type;
};

/* -------------------------------------------------- */
class GameObject;
/* -------------------------------------------------- */
class GameComponentUpdate : public GameComponent
/* -------------------------------------------------- */
{
public:
	GameComponentUpdate();
	virtual ~GameComponentUpdate();

	virtual void set_game_object(GameObject *p_object);
	virtual GameObject* get_game_object();

private:
	GameObject *m_p_object;
};

/* -------------------------------------------------- */
class Sprite;
/* -------------------------------------------------- */
class GameComponentSprite : public GameComponent
/* -------------------------------------------------- */
{
public:
    GameComponentSprite();
    virtual ~GameComponentSprite();

    virtual void set_sprite(Sprite *p_sprite);
    virtual Sprite* get_sprite();

private:
    Sprite *m_p_sprite;
};

} // namespace rc
} // namespace game

#endif//_RC_GAME_COMPONENT_H_
