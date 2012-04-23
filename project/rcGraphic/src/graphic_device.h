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

#if 1

using rc::math::Matrix4;

namespace rc { 
namespace graphic {

/* ---------------------------------------------------------------------- */
class GraphicDevice
/* ---------------------------------------------------------------------- */
{
    public:
        GraphicDevice() {}
        virtual ~GraphicDevice() {}

        // --------------------------------------------------
        // 頂点型の設定
        // --------------------------------------------------
        virtual void set_vertex_type(VERTEX_TYPE type) = 0;

        // --------------------------------------------------
        // モデルビュー設定
        // --------------------------------------------------
        //virtual void set_model_view(

        // --------------------------------------------------
        // カメラの設定(Projection)
        // --------------------------------------------------
        virtual void set_projection_orthograhy(f32 width, f32 height, f32 z_near, f32 z_far) = 0;

        // --------------------------------------------------
        // 描画
        // --------------------------------------------------
        virtual void draw(DRAW_MODE mode, u32 vertex_num, void *vertex_array) = 0;

    private:
};

#ifdef RC_USE_OPENGL
/* ---------------------------------------------------------------------- */
class GraphicDeviceOpenGL : public GraphicDevice
/* ---------------------------------------------------------------------- */
{
    public:
        GraphicDeviceOpenGL();
        virtual ~GraphicDeviceOpenGL();

        // --------------------------------------------------
        // 頂点型の設定
        // --------------------------------------------------
        virtual void set_vertex_type(VERTEX_TYPE type);

        // --------------------------------------------------
        // モデルビュー設定
        // --------------------------------------------------

        // --------------------------------------------------
        // カメラの設定(Projection)
        // --------------------------------------------------
        virtual void set_projection_orthograhy(f32 width, f32 height, f32 z_near, f32 z_far);

        // --------------------------------------------------
        // 描画
        // --------------------------------------------------
        virtual void draw(DRAW_MODE mode, u32 vertex_num, void *vertex_array);

    private:
};
#endif//RC_USE_OPENGL

#if 0
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

    // Draw
	virtual void drawArrays(int draw_mode, int begin, int count);

private:
};
#endif

} // graphic
} // namespace rc

#endif

#endif // _RC_GRAPHIC_DEVICE_H_
