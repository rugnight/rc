//============================================================================
// Name        : rc/graphics/graphic_device.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "graphic_device.h"

namespace rc { 

#if 0
/* ---------------------------------------------------------------------- */
//  class GLGraphicDevice
/* ---------------------------------------------------------------------- */
GLGraphicDevice::GLGraphicDevice()
{
}

GLGraphicDevice::~GLGraphicDevice()
{
}

// Texture
void GLGraphicDevice::activeTexture(int tex_target)
{
    glActiveTexture(tex_target);
}

void GLGraphicDevice::bindTexture(int tex_target, ITexture* p_tex)
{
    glBindTexture(tex_target, p_tex->getID());
}

void GLGraphicDevice::texParameteri(int tex_target, int tex_param, int tex_param_value)
{
    glTexParameteri(tex_target, tex_param, tex_param_value);
}

// Vertex
void GLGraphicDevice::enableVertexAttribArray(int attribute_no)
{
    glEnableVertexAttribArray(attribute_no);
}

void GLGraphicDevice::disableVertexAttribArray(int attribute_no)
{
    glDisableVertexAttribArray(attribute_no);
}

void GLGraphicDevice::vertexAttribPointer(int attribute_no, int attribute_elem_num, int data_type, bool b_normalized, int stride, const void* p_data)
{
    glVertexAttribPointer(attribute_no, attribute_elem_num, data_type, b_normalized, stride, p_data);
}

// Shader
void GLGraphicDevice::shaderUse(u32 id)
{
    glUseProgram(id);
}

// Draw
void GLGraphicDevice::drawArrays(int draw_mode, int begin, int count)
{
	glDrawArrays(draw_mode, begin, count);
}
#endif

}; // namespace rc
