/*
 *  file    project/rcBase/src/SDL/windowSDL.h
 *  date    2012年 5月19日 土曜日 13時08分55秒 JST
 *  author  Azuma_Yoshitaka
 */

#ifndef _RC_WINDOW_SDL_H_
#define _RC_WINDOW_SDL_H_

#include "../rc_base.h"

#ifdef RC_USE_SDL

/* -------------------------------------------------- */
class WindowSDL
/* -------------------------------------------------- */
{
public:
    WindowSDL();
    virtual ~WindowSDL();

    virtual bool create(const char* window_name, int width, int height);
    virtual void destroy();
private:

};

#endif//RC_USE_SDL

#endif//_RC_WINDOW_SDL_H_
