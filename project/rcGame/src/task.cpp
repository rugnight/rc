/*
 *  file    rc/project/rcGame/src/task.cpp
 *  date    2012年 5月12日 土曜日 23時33分26秒 JST
 *  brief
 */

#include "task.h"
#include "game_component.h"
#include "game_object.h"
#include "sprite.h"

namespace rc {
namespace game {

/* -------------------------------------------------- */
//  class Task
/* -------------------------------------------------- */
Task::Task(GAME_COMPONENT_TYPE type)
    : m_type(type)
{
}

Task::~Task()
{
}

void Task::add(GameObject* p_object)
{
#if 0
    if ( p_object->is_hold(m_type) ) {
        m_list.push_back(p_object->get_component(m_type));
    }
#else
	if ( !p_object ) {
		DEBUG_ASSERT(p_object);
		return;
	}
	m_list.push_back(p_object);
#endif
}

void Task::remove(GameObject* p_object)
{
#if 0
    LIST_IT it = std::find( m_list.begin(), m_list.end(), p_object->get_component(GC_SPRITE));
    if ( it == m_list.end() ) {
        return;
    }
    m_list.erase(it);
#else
    LIST_IT it = std::find( m_list.begin(), m_list.end(), p_object);
    if ( it == m_list.end() ) {
        return;
    }
    m_list.erase(it);
#endif
}

/* -------------------------------------------------- */
//	class TaskUpdate : public Task
/* -------------------------------------------------- */
TaskUpdate::TaskUpdate()
    : Task(GC_UPDATE)
{
}

TaskUpdate::~TaskUpdate()
{
}

void TaskUpdate::update()
{
    for ( LIST_IT it = m_list.begin(); it != m_list.end(); ++it ) 
	{
#if 0
		GameComponentUpdate *p_component = static_cast<GameComponentUpdate*>((*it));
		GameObject* p_obj = p_component->get_game_object();
#else
		GameObject* p_obj = (*it);
        if ( !p_obj->is_hold(GC_UPDATE) ) {
			continue;
		}
#endif
		p_obj->update();
	}
}

/* -------------------------------------------------- */
//  class TaskSprite
/* -------------------------------------------------- */
TaskSprite::TaskSprite()
    : Task(GC_SPRITE)
{
}

TaskSprite::~TaskSprite()
{
}

void TaskSprite::update()
{
    for ( LIST_IT it = m_list.begin(); it != m_list.end(); ++it ) 
    {
		GameObject* p_obj = (*it);
        const u32 num = p_obj->get_component_num(GC_SPRITE);
        if ( num <= 0 ) {
            continue;
        }

        GameObject::COMPONENT_IT component_it = p_obj->get_component_iterator(GC_SPRITE);
        for ( int i = 0; i < num; ++i ) {
            GameComponentSprite *p_component = static_cast<GameComponentSprite*>((*component_it ).second);
            Sprite* p_sprite = p_component->get_sprite();
            Texture* p_tex = p_sprite->get_texture();

            if ( !p_tex ) {
                continue;
            }

            const float x = p_sprite->get_wh().x;//p_tex->get_desc().width;
            const float y = p_sprite->get_wh().y;//p_tex->get_desc().height;

            const float w = x * p_sprite->get_uv().x;//p_tex->get_desc().width;
            const float h = y * p_sprite->get_uv().y;//p_tex->get_desc().height;

            const u32 color = p_sprite->get_color();
            
            VERTEX_T2F_C4UB_V3F vertices[] = {
                { 0.0f , 0.0f , color, 0.0 , 0.0 , 0.0 }, 
                { w    , 0.0f , color, x   , 0.0 , 0.0 }, 
                { w    , h    , color, x   , y   , 0.0 }, 
                
                { 0.0f , 0.0f , color, 0.0 , 0.0 , 0.0 }, 
                { w    , h    , color, x   , y   , 0.0 }, 
                { 0.0f , h    , color, 0.0 , y   , 0.0 },         
            }; 

            GraphicDevice *p_device = GraphicManager::Instance().get_device();

            p_device->set_transform_matrix(p_sprite->get_transform().get_matrix());
            p_device->set_texture(p_tex);
            p_device->set_vertex_array(VERTEX_TYPE_T2F_C4UB_V3F, vertices);
            p_device->draw_vertex_array(DRAW_MODE_TRIANGLES, 6);

            ++component_it;
        }
    }
}

} // namespace rc
} // namespace game
