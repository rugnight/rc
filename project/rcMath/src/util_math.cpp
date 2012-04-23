/*
 * util_math.cpp
 * 2012年 2月18日 土曜日 16時56分29秒 JST
 */

#include "util_math.h"

namespace rc {
namespace math { 

// x以上の最小の2の冪乗を返す
int toPow2(int x)
{
    int y = 1;
    while (y < x)
        y <<= 1;
    return y;
}

} //namespace math
} //namespace rc
