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

bool is_float_zero(f32 value)
{
    return is_float_equal(0.0f, value);
}

bool is_float_equal(f32 value0, f32 value1)
{
    return ( fabs(value0-value1) < __FLT_EPSILON__);
}

} //namespace math
} //namespace rc
