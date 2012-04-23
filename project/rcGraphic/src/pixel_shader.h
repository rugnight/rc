//============================================================================
// Name        : rc/graphics/shader/pixel_shader.h
// Author      :
// Version     :
//============================================================================

#ifndef _RC_PIXEL_SHADER_H_
#define _RC_PIXEL_SHADER_H_

#include "rcGraphicBase.h"

namespace rc {

/* ---------------------------------------- */
class IPixelShader
/* ---------------------------------------- */
{
	public:
		virtual bool create(const char* filename) = 0;
		virtual bool destroy() = 0;
};

/* ---------------------------------------- */
class PixelShaderBase
/* ---------------------------------------- */
{
	public:
        PixelShaderBase();
        virtual ~PixelShaderBase();


		virtual bool create(const char* filename) = 0;
		virtual bool destroy() = 0;

		virtual u32 getShader() { return m_shader; }
	protected:
		u32 m_shader;
};

/* ---------------------------------------- */
class GLPixelShader : public PixelShaderBase 
/* ---------------------------------------- */
{
	public:
		GLPixelShader();
		virtual ~GLPixelShader();

		virtual bool create(const char* filename);
		virtual bool destroy();
    private:

};

/* ---------------------------------------- */
class PixelShader : public GLPixelShader
/* ---------------------------------------- */
{
	public:
	private:
};


} // namespace rc

#endif //_RC_PIXEL_SHADER_H_
