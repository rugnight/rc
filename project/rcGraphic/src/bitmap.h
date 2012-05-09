/*
 *   file   rcGraphic/src/bitmap.h
 *   brief  
 *   date   2012年 4月29日 日曜日 12時33分24秒 JST
 */

#ifndef _RC_BITMAP_H_
#define _RC_BITMAP_H_

#include "rcGraphicBase.h"

namespace rc {
namespace graphic {

#ifdef RC_USE_XCODE_OPENGL_FRAMEWORK
class Bitmap
{
    public:
        Bitmap();
        virtual ~Bitmap();

        bool create_from_file(const char* file_path);
        bool create_from_font(const char *str, const char *font_name, u32 font_size);

        u8* get_bytes();
        float get_width() { return m_width; }
        float get_height() { return m_height; }

        void destroy();

    private:
        u8* m_p_data;

        float m_width;
        float m_height;
};
#else
class Bitmap
{
    public:
        Bitmap();
        virtual ~Bitmap();

        bool create_from_file(const char* file_path);

    private:
};
#endif//RC_USE_XCODE_OPENGL_FRAMEWORK

}
}


#endif//_RC_BITMAP_H_
