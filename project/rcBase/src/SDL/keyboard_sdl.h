/*
 *  file    project/rcBase/src/SDL/keyboard_sdl.h
 *  date    2012年 5月19日 土曜日 15時58分48秒 JST
 *  brief
 */

#ifndef _RC_KEYBOARD_SDL_H_
#define _RC_KEYBOARD_SDL_H_

#include "../keyboard.h"

/* -------------------------------------------------- */
class KeyboardSDL : public Keyboard
/* -------------------------------------------------- */
{
public:
	KeyboardSDL();
	virtual ~KeyboardSDL();

    virtual void init();
    virtual void update();
};

#endif//_RC_KEYBOARD_SDL_H_
