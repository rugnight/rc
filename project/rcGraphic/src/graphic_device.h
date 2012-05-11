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

using rc::graphic::Texture;
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
        // モデルビュー設定
        // --------------------------------------------------
        virtual void set_transform_matrix(const Matrix4 &mat) = 0;

        // --------------------------------------------------
        // カメラの設定(Projection)
        // --------------------------------------------------
        virtual void set_projection_orthograhy(f32 width, f32 height, f32 z_near, f32 z_far) = 0;

        // --------------------------------------------------
        // テクスチャの設定
        // --------------------------------------------------
        virtual void set_texture(Texture *p_tex) = 0;

        // --------------------------------------------------
        // 描画設定
        // --------------------------------------------------
        virtual void set_vertex_array(VERTEX_TYPE type, void *vertex_array) = 0;

        // --------------------------------------------------
        // 描画
        // --------------------------------------------------
        virtual void draw_vertex_array(DRAW_MODE mode, u32 vertex_num) = 0;

        // --------------------------------------------------
        // 描画領域のクリア
        // --------------------------------------------------
        virtual void set_clear_color(float a, float r, float g, float b) = 0;
        virtual void clear(RENDER_BUFFER render_buffer) = 0;

        // --------------------------------------------------
        // アルファブレンドの設定
        // --------------------------------------------------
        virtual void set_blend_enable(bool flg) = 0;
        virtual void set_blend_mode(BLEND_MODE src, BLEND_MODE dst) = 0;

    private:
        VERTEX_TYPE m_vertex_type;
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
        // モデルビュー設定
        // --------------------------------------------------
        virtual void set_transform_matrix(const Matrix4 &mat);

        // --------------------------------------------------
        // カメラの設定(Projection)
        // --------------------------------------------------
        virtual void set_projection_orthograhy(f32 width, f32 height, f32 z_near, f32 z_far);

        // --------------------------------------------------
        // テクスチャの設定
        // --------------------------------------------------
        virtual void set_texture(Texture *p_tex);

        // --------------------------------------------------
        // 描画設定
        // --------------------------------------------------
        virtual void set_vertex_array(VERTEX_TYPE type, void *vertex_array);

        // --------------------------------------------------
        // 描画
        // --------------------------------------------------
        virtual void draw_vertex_array(DRAW_MODE mode, u32 vertex_num);

        // --------------------------------------------------
        // 描画領域のクリア
        // --------------------------------------------------
        virtual void set_clear_color(float a, float r, float g, float b);
        virtual void clear(RENDER_BUFFER render_buffer);

        // --------------------------------------------------
        // アルファブレンドの設定
        // --------------------------------------------------
        virtual void set_blend_enable(bool flg);
        virtual void set_blend_mode(BLEND_MODE src, BLEND_MODE dst);

    private:
};
#endif//RC_USE_OPENGL

} // graphic
} // namespace rc

#endif // _RC_GRAPHIC_DEVICE_H_
