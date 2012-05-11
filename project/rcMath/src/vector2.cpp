/*
 *  vector2.cpp
 *  2012年 2月 8日 水曜日 01時55分02秒 JST
 */

#include "vector2.h"

namespace rc {
namespace math {

// --------------------------------------------------
// static var member
// --------------------------------------------------
const Vector2 Vector2::ZERO(0.0f, 0.0f);
const Vector2 Vector2::UNIT(1.0f, 1.0f);

// --------------------------------------------------
// constructor
// --------------------------------------------------
Vector2::Vector2()
	: x(0.0f), y(0.0f)
{
}

Vector2::Vector2(VECTOR2_TYPE _n)
	: x(_n), y(_n)
{
}

Vector2::Vector2(VECTOR2_TYPE _x, VECTOR2_TYPE _y)
	: x(_x), y(_y)
{
}

Vector2::Vector2(const Vector2 &src)
	: x(src.x), y(src.y)
{
}

Vector2::Vector2(const Vector3 &src)
	: x(src.x), y(src.y)
{
}

Vector2::Vector2(const Vector4 &src)
	: x(src.x), y(src.y)
{
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

} //math
} //rc
