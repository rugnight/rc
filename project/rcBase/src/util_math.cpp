/*
 *  file    rc/util/util_math.cpp
 *  brief   
 *  date    2011/07/17
 */
#include "util_math.h"

namespace rc {

// x以上の最小の2の冪乗を返す
int toPow2(int x)
{
    int y = 1;
    while (y < x)
        y <<= 1;
    return y;
}

}; //namespace rc
