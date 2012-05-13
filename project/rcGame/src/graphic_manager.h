/*
 *   file   rcGame/src/graphic_manager.h
 *   brief  
 *   date   2012年 5月10日 木曜日 15時14分44秒 JST
 */

#ifndef _RC_GRAPHIC_MANAGER_H_
#define _RC_GRAPHIC_MANAGER_H_

#include "graphic_device.h"

using rc::graphic::GraphicDevice;

namespace rc {
namespace game {


/* ---------------------------------------------------------------------- */
class GraphicManager
/* ---------------------------------------------------------------------- */
{
	private:
		GraphicManager();
	public:
		virtual ~GraphicManager();

		static GraphicManager& Instance()
		{
			static GraphicManager m_instance;
			return m_instance;
		}

		void init(GraphicDevice* p_device);
		void term();
		GraphicDevice* get_device();

	private:
		GraphicDevice *m_p_device;
};

} //rc 
} //game 


#endif//_RC_GRAPHIC_MANAGER_H_
