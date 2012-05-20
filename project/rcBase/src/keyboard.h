/*
 *  file    project/rcBase/src/keyboard.h
 *  date    2012年 5月19日 土曜日 15時43分50秒 JST
 *
 */
#ifndef _RC_KEYBOARD_H_
#define _RC_KEYBOARD_H_

#include "rc_base.h"

#define RC_KEY_BUFFER_SIZE 512

/* -------------------------------------------------- */
class IKeyboard
/* -------------------------------------------------- */
{
public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual bool get_key_state(RC_KEY key, INPUT_STATE state) = 0;
};

/* -------------------------------------------------- */
class Keyboard : public IKeyboard
/* -------------------------------------------------- */
{
public:
    Keyboard();
    virtual ~Keyboard();

    virtual void init();
    virtual void update();
    virtual bool get_key_state(RC_KEY key, INPUT_STATE state);

protected:
	u8 m_index;
	u8 m_keys[2][RC_KEY_BUFFER_SIZE];
};

#endif//_RC_KEYBOARD_H_
