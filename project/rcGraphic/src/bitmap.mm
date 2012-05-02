/*
 *   file   rcGraphic/src/bitmap.mm
 *   brief  
 *   date   2012年 4月29日 日曜日 12時33分24秒 JST
 */


#include "bitmap.h"

#ifdef RC_USE_XCODE_OPENGL_FRAMEWORK
#import "Cocoa/Cocoa.h"

namespace rc {
namespace graphic {

Bitmap::Bitmap()
: m_p_data(NULL)
, m_width(0.0f)
, m_height(0.0f)
{
}

Bitmap::~Bitmap()
{
    destroy();
}

void Bitmap::destroy()
{
    SAFE_DELETE(m_p_data);
}

bool Bitmap::create_from_file(const char* file_path)
{
    destroy();

#if 1
    GLuint ret = GL_INVALID_VALUE;
    
    NSString* imageName = [NSString stringWithCString: file_path encoding:NSUTF8StringEncoding];
    
    ///// 画像の読み込み
    
    // [1/5] 画像の名前→画像のパス
    NSBundle* bundle = [NSBundle mainBundle];
    NSString* imagePath = [bundle pathForResource:imageName ofType:nil];
    
    // [2/5] 画像オブジェクトの作成  
    CFURLRef urlRef =
    CFURLCreateWithFileSystemPath( NULL, (__bridge CFStringRef)imagePath, kCFURLPOSIXPathStyle, false);
    CGImageSourceRef imageSourceRef = CGImageSourceCreateWithURL(urlRef, NULL);
    CGImageRef imageRef = CGImageSourceCreateImageAtIndex(imageSourceRef, 0, NULL);
    m_width = (float)CGImageGetWidth(imageRef);
    m_height = (float)CGImageGetHeight(imageRef);
    
    // [3/5] ビットマップ（RGBAの並び）への変換
    CGColorSpaceRef colorSpaceRef =CGColorSpaceCreateDeviceRGB();
    NSMutableData* data = [NSMutableData dataWithLength:4 * (int)m_width * (int)m_height];
    CGContextRef bitmapContextRef =
        CGBitmapContextCreate([data mutableBytes], (int)m_width, (int)m_height, 8, (int)m_width * 4, colorSpaceRef, kCGImageAlphaPremultipliedFirst);
    CGContextDrawImage(bitmapContextRef, CGRectMake(0, 0, (int)m_width, (int)m_height), imageRef);

    u32 size = [data length];
    m_p_data = new u8[size];
    memcpy(m_p_data, [data bytes], size);
    
    ///// クリーンアップ
    CGContextRelease(bitmapContextRef);
    CGColorSpaceRelease(colorSpaceRef);
    CGImageRelease(imageRef);
    CFRelease(imageSourceRef);
    CFRelease(urlRef);
    
    return ret;
#endif 
}

u8* Bitmap::get_bytes()
{
    if ( !m_p_data ) {
        return NULL;
    }

    return m_p_data;
}

}
}

#endif
