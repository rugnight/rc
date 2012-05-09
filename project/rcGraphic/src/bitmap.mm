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
}

bool Bitmap::create_from_font(const char *str, const char *font_name, u32 font_size)
{
    destroy();

    // フォント名を cocoa で扱う文字列に変換
	NSString *font_name_ns = [NSString 
        stringWithCString   : font_name
        encoding            : NSUTF8StringEncoding];

	// 文章を cocoa で扱う文字列に変換
	NSString *string = [NSString 
        stringWithCString   : str 
        encoding            : NSUTF8StringEncoding];
	u32 strSize = [string length];

	// フォント設定
	NSFont *font = [NSFont fontWithName:font_name_ns size:font_size];
	NSDictionary *attrsDictionary = [NSDictionary 
        dictionaryWithObjectsAndKeys: font, 
                                      NSFontAttributeName,
                                      [NSColor whiteColor], 
                                      NSForegroundColorAttributeName,
                                      [NSColor clearColor], 
                                      NSBackgroundColorAttributeName,
                                      nil ];
 
	// 書式付きの文字列を作成
	NSAttributedString *attrString;
	attrString = [[NSAttributedString alloc] 
        initWithString:string attributes:attrsDictionary];

    // 描画用のイメージを生成
    u32 img_width  = [attrString size].width;//TEX_WIDTH * strSize;
    u32 img_height = [attrString size].height;//TEX_HEIGHT;
    NSImage* img = [[NSImage alloc] 
        initWithSize    : NSMakeSize(img_width, img_height)];
 
	// 書式付きの文字列をイメージに書き込む
    f32 add_width = 0;
    [img setBackgroundColor:[NSColor clearColor]];
    [img lockFocus];
	for( u32 i = 0; i < strSize; i++ ){
        NSAttributedString *singleChar = [attrString 
            attributedSubstringFromRange    : NSMakeRange(i,1)];

        NSSize size = [singleChar size];

        f32 center_x = add_width + 0;//(size.width)/2;
        f32 center_y = 0;//(TEX_HEIGHT-size.height)/2;
        add_width    = add_width + size.width;

        NSPoint point = NSMakePoint( center_x, center_y );
		// 描画
		[singleChar drawAtPoint:point];
	}
    [img unlockFocus];

    // イメージからビットマップを作成
    NSBitmapImageRep *image_rep = [[NSBitmapImageRep alloc] initWithData:[img TIFFRepresentation]];
 
    // 自クラスのメンバに格納
    u32 bmp_size = [image_rep bytesPerPlane];
    m_p_data = new u8[bmp_size];
    memcpy(m_p_data, [image_rep bitmapData], bmp_size); 
    m_width  = img_width;
    m_height = img_height;
    
    return true;
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
