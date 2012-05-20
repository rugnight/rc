/*
 *  file    project/rcBase/src/keyboard.cpp
 *  date    2012年 5月19日 土曜日 15時43分50秒 JST
 *
 */

#include "keyboard.h"

/* -------------------------------------------------- */
//	class Keyboard
/* -------------------------------------------------- */
Keyboard::Keyboard()
	: m_index(0)
{
	init();
}

Keyboard::~Keyboard()
{
}


void Keyboard::init()
{
    m_index = 0;
	for ( int i = 0; i < 2; ++i ) {
		for ( int j = 0; j < RC_KEY_BUFFER_SIZE; ++j ) {
			m_keys[j][i] = 0;
		}
	}
}

void Keyboard::update()
{
	m_index = m_index^1;
}

bool Keyboard::get_key_state(RC_KEY key, INPUT_STATE state)
{
	if ( m_keys[m_index][key] ) {
		if ( m_keys[m_index][key] == m_keys[m_index^1][key] ) {
			return (state == PUSH);
		}
		else {
			return (state == PUSH_EDGE);
		}
	} 
	else {
		if ( m_keys[m_index][key] == m_keys[m_index^1][key] ) {
			return (state == RELEASE);
		}
		else {
			return (state == RELEASE_EDGE);
		}
	}
}

