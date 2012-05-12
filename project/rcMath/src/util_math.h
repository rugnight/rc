/*
 * util_math.h
 * 2012年 2月18日 土曜日 16時56分29秒 JST
 */

#ifndef _RC_UTIL_MATH_H_
#define _RC_UTIL_MATH_H_

#include "rcMathBase.h"

namespace rc {
namespace math { 

// x以上の最小の2の冪乗を返す
int toPow2(int x);

bool is_float_zero(f32 value);
bool is_float_equal(f32 value0, f32 value1);

} //namespace math
} //namespace rc

#endif //_RC_UTIL_MATH_H_
