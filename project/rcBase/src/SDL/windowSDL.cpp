/*
 *  file    project/rcBase/src/SDL/windowSDL.h
 *  date    2012年 5月19日 土曜日 13時08分55秒 JST
 *  author  Azuma_Yoshitaka
 */

#include "windowSDL.h"

WindowSDL::WindowSDL()
{
}

WindowSDL::~WindowSDL()
{
}

bool WindowSDL::create(const char* window_name, int width, int height)
{
    /* 現在のビデオ設定についての情報 */
    const SDL_VideoInfo* info = NULL;
    /* ウィンドウの色深度の(ビット数表記) */
    int bpp = 0;
    /* SDL_SetVideoMode に渡すフラグ */
    int flags = 0;

    /* まず、SDL ビデオサブシステムを初期化 */
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        /* 失敗したので終了 */
        fprintf( stderr, "ビデオの初期化に失敗しました: %s\n", SDL_GetError( ) );
        return false;
    }

    /* いくつかのビデオ情報を取得しよう */
    info = SDL_GetVideoInfo( );

    if( !info ) {
        /* おそらくこれは絶対に起きないはず */
        fprintf( stderr, "ビデオの問い合わせに失敗しました: %s\n",
             SDL_GetError( ) );
        return false;
    }

    /*
     * 横幅/高さを 640/480 にセット。
     * (もちろん普通のアプリケーションにおいて
     * ユーザーにこれを決定してもらうだろう)
     * 画面から要求していたピクセル深度を取得。
     * X11 では、VidMode は解像度を変えることができないため、
     * これはおそらく過度安全だろう。
     * Win32 では、ChangeDisplaySettings によって
     * ピクセル深度を変えることができる。
     */
    bpp = info->vfmt->BitsPerPixel;

    /*
     * ここで、OpenGL ウィンドウのために要求されたウィンドウ属性を設定したい。
     * RGB 各チャンネルに *少なくとも* 5 ビット欲しい。
     * また、少なくとも 16 ビットのデプスバッファも欲しい。
     *
     * 最後にする事はダブルバッファウィンドウの要求である。
     * '1' でダルバッファが有効になり、
     * '0' で無効になる。
     *
     * SDL_SetVideoMode へのフラグにおいて
     * SDL_DOUBLEBUF を使わない事に注意。
     * それは GL アトリビュートに影響せず、
     * 標準の 2D blit 転送の設定だけに影響する。
     */
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    /*
     * SDL がフルスクリーンビデオモードにおいて
     * OpenGL ウィンドウを提供してくれるよう要求したい。
     *
     * 練習:
     * ウィンドウ状態で開始するオプションを作り、
     * glViewPort でリサイズイベントを適切に処理せよ。
     */
    flags = SDL_OPENGL;// | SDL_FULLSCREEN;

    /*
     * ビデオモードを設定。
     */
    if( SDL_SetVideoMode( width, height, bpp, flags ) == 0 ) {
        /* 
         * これはさまざまな理由で起き得る。
         * DISPLAY が設定されていない、
         * 指定された解像度が利用可能でない、など。
         */
        fprintf( stderr, "ビデオモードのセットに失敗しました: %s\n", SDL_GetError( ) );
        return false;
    }
    return true;
}

void WindowSDL::destroy()
{
}
