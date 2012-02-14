//============================================================================
// Name        : rc/graphics/graphic_device.h
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef _RC_GRAPHIC_DEVICE_H_
#define _RC_GRAPHIC_DEVICE_H_

#include "rcGraphicBase.h"
#include "texture.h"

namespace rc { 

/* ---------------------------------------------------------------------- */
class IDevice
/* ---------------------------------------------------------------------- */
{
public:
    // Texture
    virtual void activeTexture(int tex_target) = 0;
    virtual void bindTexture(int tex_target, ITexture* p_tex) = 0;
    virtual void texParameteri(int tex_target, int tex_param, int tex_param_value) = 0;

    // Vertex
    virtual void enableVertexAttribArray(int attribute_no) = 0;
    virtual void vertexAttribPointer(int attribute_no, int attribute_elem_num, int data_type, bool b_normalized, int stride, const void* p_data) = 0;

    // Shader
    virtual void shaderUse(u32 id) = 0;

    // Draw
	virtual void drawArrays(int draw_mode, int begin, int count) = 0;
};

/* ---------------------------------------------------------------------- */
class GLGraphicDevice
/* ---------------------------------------------------------------------- */
{
private:
public:
    GLGraphicDevice();
    virtual ~GLGraphicDevice();

    // Texture
    virtual void activeTexture(int tex_target);
    virtual void bindTexture(int tex_target, ITexture* p_tex);
    virtual void texParameteri(int tex_target, int tex_param, int tex_param_value);

    // Vertex
    virtual void enableVertexAttribArray(int attribute_no);
    virtual void disableVertexAttribArray(int attribute_no);
    virtual void vertexAttribPointer(int attribute_no, int attribute_elem_num, int data_type, bool b_normalized, int stride, const void* p_data);


    // Shader
    virtual void shaderUse(u32 id);

;
    // Draw
	virtual void drawArrays(int draw_mode, int begin, int count);

private:
};

}; // namespace rc


#endif // _RC_GRAPHIC_DEVICE_H_
