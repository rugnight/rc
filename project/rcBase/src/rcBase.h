/*
 *  file    rcBase.h
 *  date    2011/11/27
 *  author  Azuma_Yoshitaka
 */

#ifndef _RC_BASE_H_
#define _RC_BASE_H_

// --------------------------
// 型の定義
#include "rcTypes.h"

// --------------------------
// 基本機能マクロ
#define SAFE_DELETE(p)        if ( p != NULL ) { delete p; p=NULL; }
#define SAFE_DELETE_ARRAY(p)  if ( p != NULL ) { delete[] p; p = NULL; }
#define COUNTOF( array )      ( sizeof( array )/sizeof( array[0] ) )

#endif//_RC_BASE_H_INCLUDED_
