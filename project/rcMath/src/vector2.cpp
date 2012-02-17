/*
 *  vector2.cpp
 *  2012年 2月 8日 水曜日 01時55分02秒 JST
 */

#include "vector2.h"

namespace rc {
namespace math {


// --------------------------------------------------
// constructor
// --------------------------------------------------
Vector2::Vector2()
{
    Vector2(0.0f, 0.0f);
}

Vector2::Vector2(VECTOR2_TYPE _n)
{
    Vector2(_n, _n);
}

Vector2::Vector2(VECTOR2_TYPE _x, VECTOR2_TYPE _y)
: x(_x), y(_y)
{
}

Vector2::Vector2(const Vector2 &src)
{
    Vector2(src.x, src.y);
}

// --------------------------------------------------
// destructor
// --------------------------------------------------
Vector2::~Vector2()
{
}

// --------------------------------------------------
// static function
// --------------------------------------------------
    
// ベクトル同士の和
void Vector2::add(Vector2 *dst, const Vector2 &src0, const Vector2 &src1)
{
    dst->x = src0.x + src1.x;
    dst->y = src0.y + src1.y;
}

// ベクトル同士の差
void Vector2::sub(Vector2 *dst, const Vector2 &src0, const Vector2 &src1)
{
    dst->x = src0.x - src1.x;
    dst->y = src0.y - src1.y;
}

// ベクトル同士の内積
void Vector2::dot(VECTOR2_TYPE *dst, const Vector2 &src0, const Vector2 &src1)
{
    *dst = src0.x * src1.x + src0.y * src1.y;
}

// ベクトル同士の外積
void Vector2::cross(VECTOR2_TYPE *dst, const Vector2 &src0, const Vector2 &src1)
{
    // これは2次元の場合
    *dst = src0.x * src1.y - src1.x * src0.y;
}

// ベクトルの定数倍
void Vector2::scale(Vector2 *dst, const Vector2 &src0, const VECTOR2_TYPE &src1)
{
    dst->x = src0.x * src1;
    dst->y = src0.y * src1;
}

}; //math
}; //rc
