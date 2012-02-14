//============================================================================
// Name        : rc/graphics/shader/shader.cpp
// Author      :
// Version     :
//============================================================================

#include "shader.h"

#include <stdio.h>
#include <stdlib.h>

namespace rc {

/* ---------------------------------------- */
//  class GLShader : public IShader
/* ---------------------------------------- */
GLShader::GLShader()
{
}
GLShader::~GLShader()
{
}

bool GLShader::create(GLVertexShader* p_vs, GLPixelShader* p_ps)
{
    m_shader = glCreateProgram();
    /* それぞれのシェーダーをアタッチする */
    glAttachShader(m_shader, p_vs->getShader());
    glAttachShader(m_shader, p_ps->getShader());
    return true;
}
void GLShader::bindAttribute(int id, const char* name)
{
    glBindAttribLocation(m_shader, id, name);
}

void GLShader::setUniform1f(const char* name, float value0)
{
    GLuint idx = glGetUniformLocation(m_shader, name);
    glUniform1f(idx, value0);
}

void GLShader::setUniform2f(const char* name, float value0, float value1)
{
    GLuint idx = glGetUniformLocation(m_shader, name);
    glUniform2f(idx, value0, value1);
}

bool GLShader::linkProgram()
{
    int IsLinked;
    int maxLength;
    char *shaderProgramInfoLog;
    glLinkProgram(m_shader);
    glGetProgramiv(m_shader, GL_LINK_STATUS, (int *)&IsLinked);
    if(IsLinked == false)
    {
       glGetProgramiv(m_shader, GL_INFO_LOG_LENGTH, &maxLength);
       /* The maxLength includes the NULL character */
       shaderProgramInfoLog = (char *)malloc(maxLength);

       /* Notice that glGetProgramInfoLog, not glGetShaderInfoLog. */
       glGetProgramInfoLog(m_shader, maxLength, &maxLength, shaderProgramInfoLog);
       free(shaderProgramInfoLog);
       return false;
    }
   return true;
}

void GLShader::use()
{
    glUseProgram(m_shader);
}


}; // namespace rc

