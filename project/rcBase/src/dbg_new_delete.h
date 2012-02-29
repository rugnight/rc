/*
    file    dbg_new_delete.h
    date    2012/02/29 
    author  Azuma_Yoshitaka
*/

#ifndef _RC_DBG_NEW_DELETE_H_ 
#define _RC_DBG_NEW_DELETE_H_ 

/*
    [�g������]
        �\�[�X�̏㗬��include���Anew���}�N����`����K�v������

        #ifdef _DEBUG
        #include "dbg_new_delete.h"
        #define new new(__FILE__, __LINE__)
        #else
        #endif// _DEBUG
 */

#ifdef _DEBUG
#include <cstdlib>

// ==================================================
// function
// ==================================================
void* operator new(size_t size, char* file, int line);

void* operator new[](size_t size, char* file, int line);

void operator delete(void* p);

void operator delete[](void* p);

void leak_check_dump(const char* str);

#pragma warning(disable:4291)   // delete�̈����̐��� new�ƍ���Ȃ��Ɠ{����

#endif	// _DEBUG

#endif//_RC_DBG_NEW_DELETE_H_ 
