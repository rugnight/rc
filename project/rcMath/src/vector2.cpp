/*
 *  vector2.cpp
 *  2012年 2月 8日 水曜日 01時55分02秒 JST
 */

#include "vector2.h"

namespace rc {
namespace math {

Vector2::Vector2()
{
    Vector2(0.0f, 0.0f);
}

Vector2::Vector2(f32 _n)
{
    Vector2(_n, _n);
}

Vector2::Vector2(f32 _x, f32 _y)
: x(_x), y(_y)
{
}

Vector2::~Vector2()
{
}

} //math
} //rc
