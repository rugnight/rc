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
        void set_vertex_type(VERTEX_TYPE type) { m_vertex_type = type; }
        u32 get_vertex_type() { return m_vertex_type; }

        // --------------------------------------------------
        // モデルビュー設定
        // --------------------------------------------------
        virtual void set_transform_matrix(const Matrix4 &mat) = 0;

        // --------------------------------------------------
        // カメラの設定(Projection)
        // --------------------------------------------------
        virtual void set_projection_orthograhy(f32 width, f32 height, f32 z_near, f32 z_far) = 0;

        // --------------------------------------------------
        // テクスチャ
        // --------------------------------------------------
        virtual Texture create_texture_from_file(const char *file_path) = 0;

        // --------------------------------------------------
        // 描画
        // --------------------------------------------------
        virtual void draw_vertex_array(DRAW_MODE mode, u32 vertex_num, void *vertex_array) = 0;
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
        // 頂点型の設定
        // --------------------------------------------------
        virtual void set_vertex_type(VERTEX_TYPE type);

        // --------------------------------------------------
        // モデルビュー設定
        // --------------------------------------------------
        virtual void set_transform_matrix(const Matrix4 &mat);

        // --------------------------------------------------
        // カメラの設定(Projection)
        // --------------------------------------------------
        virtual void set_projection_orthograhy(f32 width, f32 height, f32 z_near, f32 z_far);

        // --------------------------------------------------
        // テクスチャ
        // --------------------------------------------------
        virtual Texture create_texture_from_file(const char *file_path);

        // --------------------------------------------------
        // 描画
        // --------------------------------------------------
        virtual void draw_vertex_array(DRAW_MODE mode, u32 vertex_num, void *vertex_array);

    private:
};
#endif//RC_USE_OPENGL

} // graphic
} // namespace rc

#endif

#endif // _RC_GRAPHIC_DEVICE_H_
