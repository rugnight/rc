/*
 *   file   rcGame/src/graphic_manager.cpp
 *   brief  
 *   date   2012年 5月10日 木曜日 15時14分44秒 JST
 */

#include "graphic_manager.h"

using namespace rc::graphic;

namespace rc {
namespace game {

/* -------------------------------------------------- */
//	class GraphicManager
/* -------------------------------------------------- */
GraphicManager::GraphicManager()
: m_p_device(NULL)
{
}

GraphicManager::~GraphicManager()
{
	term();
}

void GraphicManager::init(GraphicDevice* p_device)
{
	m_p_device = p_device;
}

void GraphicManager::term()
{
	SAFE_DELETE(m_p_device);
}

GraphicDevice* GraphicManager::get_device()
{
	return m_p_device;
}

} //rc 
} //game 
