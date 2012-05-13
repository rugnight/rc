/*
 *  file    rc/project/rcGame/src/task.h
 *  date    2012年 5月12日 土曜日 23時33分26秒 JST
 *  brief
 */

#ifndef _RC_TASK_H_
#define _RC_TASK_H_

#include "rcGameBase.h"

#include "game_object.h"
#include "game_component.h"

//class rc::game::GameObject;
//class rc::game::GameComponent;

namespace rc {
namespace game {

/* -------------------------------------------------- */
class Task
/* -------------------------------------------------- */
{
protected:
    typedef std::list<GameObject*> LIST; 
    typedef LIST::iterator         LIST_IT;

private:
    Task() {};

public:
    Task(GAME_COMPONENT_TYPE type);
    virtual ~Task();

    virtual void update() = 0;

    virtual void add(GameObject* p_object);
    virtual void remove(GameObject* p_object);

    GAME_COMPONENT_TYPE get_type() { return m_type; }

protected:
    GAME_COMPONENT_TYPE m_type;
    LIST m_list;
};

/* -------------------------------------------------- */
class TaskUpdate : public Task
/* -------------------------------------------------- */
{
public:
	TaskUpdate();
	virtual ~TaskUpdate();

	virtual void update();

private:

};

/* -------------------------------------------------- */
class TaskSprite : public Task
/* -------------------------------------------------- */
{
public:
    TaskSprite();
    virtual ~TaskSprite();

    virtual void update();
};


} // namespace rc
} // namespace game

#endif//_RC_TASK_H_
