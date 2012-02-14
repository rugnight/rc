//============================================================================
// Name        : rc/graphics/shader/vertex_shader.h
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef _RC_VERTEX_SHADER_H_
#define _RC_VERTEX_SHADER_H_

#include "rcGraphicBase.h"

/* ---------------------------------------- */
namespace rc {
/* ---------------------------------------- */

/* ---------------------------------------- */
class IVertexShader
/* ---------------------------------------- */
{
	public:
		virtual bool create(const char* filename) = 0;
		virtual bool destroy() = 0;
		virtual u32 getShader() = 0;
};

/* ---------------------------------------- */
class VertexShaderBase
/* ---------------------------------------- */
{
	public:
        VertexShaderBase();
        virtual ~VertexShaderBase();

		virtual u32 getShader() { return m_shader; }
    protected:
		u32 m_shader;
};

/* ---------------------------------------- */
class GLVertexShader : public VertexShaderBase
/* ---------------------------------------- */
{
	public:
		GLVertexShader();
		virtual ~GLVertexShader();

		virtual bool create(const char* filename);
		virtual bool destroy();
	private:
};

/* ---------------------------------------- */
class VertexShader : public GLVertexShader
/* ---------------------------------------- */
{
	public:
	private:
};


}; // namespace rc
#endif //_RC_VERTEX_SHADER_H_
