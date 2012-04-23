//============================================================================
// Name        : rc/graphics/shader/shader.h
// Author      :
// Version     :
//============================================================================

#ifndef _RC_SHADER_H_
#define _RC_SHADER_H_

#if 1

#include "rcGraphicBase.h"

#include "vertex_shader.h"
#include "pixel_shader.h"

namespace rc {

/* ---------------------------------------- */
class IShader
/* ---------------------------------------- */
{
    public:
        virtual bool linkProgram() = 0;
        virtual void bindAttribute(int id, const char* name) = 0;

        virtual void setUniform1f(const char* name, float value0) = 0;
        virtual void setUniform2f(const char* name, float value0, float value1) = 0;

        virtual void use() = 0;
};

/* ---------------------------------------- */
class GLShader : public IShader
/* ---------------------------------------- */
{
    public:
        GLShader();
        virtual ~GLShader();

        virtual bool create(GLVertexShader* p_vs = NULL, GLPixelShader* p_ps = NULL);
        virtual void bindAttribute(int id, const char* name);
        virtual bool linkProgram();

        virtual void setUniform1f(const char* name, float value0);
        virtual void setUniform2f(const char* name, float value0, float value1);

        virtual void use();

    private:
        u32 m_shader;
};


/* ---------------------------------------- */
class Shader : public GLShader
/* ---------------------------------------- */
{
    public:
};


} // namespace rc

#endif 

#endif //_RC_SHADER_H_
