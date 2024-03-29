/*
 *  vector3.cpp
 *  2012年 2月 16日 木曜日 23:00:13    
 */

#include "vector4.h"

namespace rc {
namespace math {

// --------------------------------------------------
// static var member
// --------------------------------------------------
const Vector4 Vector4::ZERO(0.0f, 0.0f, 0.0f, 0.0f);
const Vector4 Vector4::UNIT(1.0f, 1.0f, 1.0f, 1.0f);

// --------------------------------------------------
// constructor
// --------------------------------------------------
Vector4::Vector4()
: x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{
}

Vector4::Vector4(VECTOR4_TYPE _n)
: x(_n), y(_n), z(_n), w(_n)
{
}

Vector4::Vector4(VECTOR4_TYPE _x, VECTOR4_TYPE _y, VECTOR4_TYPE _z, VECTOR4_TYPE _w)
: x(_x), y(_y), z(_z), w(_w)
{
}

Vector4::Vector4(const Vector4 &src)
: x(src.x), y(src.y), z(src.z), w(src.w)
{
}

// --------------------------------------------------
// destructor
// --------------------------------------------------
Vector4::~Vector4()
{
}

// --------------------------------------------------
// static function
// --------------------------------------------------
    
// ベクトル同士の和
void Vector4::add(Vector4 *dst, const Vector4 &src0, const Vector4 &src1)
{
    dst->x = src0.x + src1.x;
    dst->y = src0.y + src1.y;
    dst->z = src0.z + src1.z;
    dst->w = src0.w + src1.w;
}

// ベクトル同士の差
void Vector4::sub(Vector4 *dst, const Vector4 &src0, const Vector4 &src1)
{
    dst->x = src0.x - src1.x;
    dst->y = src0.y - src1.y;
    dst->z = src0.z - src1.z;
    dst->w = src0.w - src1.w;
}

// ベクトルの定数倍
void Vector4::scale(Vector4 *dst, const Vector4 &src0, const VECTOR4_TYPE &src1)
{
    dst->x = src0.x * src1;
    dst->y = src0.y * src1;
    dst->z = src0.z * src1;
    dst->w = src0.w * src1;
}

} //math
} //rc
