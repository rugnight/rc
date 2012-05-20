//
//  RcTypes.h
//  ios_test
//
//  Created by 東 義隆 on 12/01/10.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef _RC_TYPES_H
#define _RC_TYPES_H

typedef char           s8;
typedef short          s16;
typedef int            s32;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef float          f32;
typedef double         f64;


/* -------------------------------------------------- */
//  入力関連
/* -------------------------------------------------- */
typedef enum input_state {
    RELEASE,
    RELEASE_EDGE,
    PUSH_EDGE,
    PUSH,
} INPUT_STATE;

/* -------------------------------------------------- */
//  型情報
/* -------------------------------------------------- */
typedef struct rect {
    s32 x, y;
    u32 w, h;
} RECT;

#endif
