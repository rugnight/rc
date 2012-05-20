/*
 *  file    project/rcBase/src/SDL/keyboard_sdl.cpp
 *  date    2012年 5月19日 土曜日 15時43分50秒 JST
 *
 */

#include "keyboard_sdl.h"

/* -------------------------------------------------- */
//	class KeyboardSDL : public IKeyboad
/* -------------------------------------------------- */
KeyboardSDL::KeyboardSDL()
{
	init();
}

KeyboardSDL::~KeyboardSDL()
{
}

void KeyboardSDL::init()
{
	//SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
	SDL_EnableKeyRepeat(0, 0);
	Keyboard::init();
}

void KeyboardSDL::update()
{
	Keyboard::update();

	SDL_PumpEvents();
	u8 *key_states = SDL_GetKeyState(NULL);
	memcpy(m_keys[m_index], key_states, SDLK_LAST);
}
