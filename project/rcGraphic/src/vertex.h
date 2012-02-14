//
// Name        : vertex.h
//
//
//

#ifndef _RC_VERTEX_H_INCLUDED_
#define _RC_VERTEX_H_INCLUDED_

#include "rcGraphicBase.h"

template<class Vertex>
class VertexBuffer
{
	public:
		VertexBuffer()
		: m_p_buffer(NULL)
		, m_num(0) 
		{
		}

		~VertexBuffer()
		{
			destroy();
		}

		void setVertex(Vertex* p_vertex_array, u32 num)
		{
			m_num = num;
			m_p_buffer = malloc(sizeof(Vertex) * num);
			memcpy_s(m_p_buffer, p_vertex_array, num);
		}

		Vertex* getVertex(u32 offset)
		{
			return (m_p_buffer + offset);
		}

		u32 getNum()
		{
			return m_num;
		}
	private:
		void destroy()
		{
			if ( m_p_buffer ) {
				free(m_p_buffer);
				m_p_buffer = NULL;
				m_num = 0;
			}
		}

	private:
		Vertex *m_p_buffer;
		u32		m_num;
};

#endif//_RC_VERTEX_H_INCLUDED_
