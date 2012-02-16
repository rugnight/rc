/*
 *  vector3.cpp
 *  2012年 2月 16日 木曜日 23:00:13    
 */

#include "vector3.h"

namespace rc {
namespace math {

// --------------------------------------------------
// constructor
// --------------------------------------------------
Vector3::Vector3()
{
    Vector3(0.0f, 0.0f, 0.0f);
}

Vector3::Vector3(VECTOR3_TYPE _n)
{
    Vector3(_n, _n, _n);
}

Vector3::Vector3(VECTOR3_TYPE _x, VECTOR3_TYPE _y, VECTOR3_TYPE _z)
: x(_x), y(_y), z(_z)
{
}

Vector3::Vector3(const Vector3 &src)
{
    Vector3(src.x, src.y, src.z);
}

// --------------------------------------------------
// destructor
// --------------------------------------------------
Vector3::~Vector3()
{
}

// --------------------------------------------------
// static function
// --------------------------------------------------
    
// ベクトル同士の和
void Vector3::add(Vector3 *dst, const Vector3 &src0, const Vector3 &src1)
{
    dst->x = src0.x + src1.x;
    dst->y = src0.y + src1.y;
    dst->z = src0.z + src1.z;
}

// ベクトル同士の差
void Vector3::sub(Vector3 *dst, const Vector3 &src0, const Vector3 &src1)
{
    dst->x = src0.x - src1.x;
    dst->y = src0.y - src1.y;
    dst->z = src0.z - src1.z;
}

// ベクトル同士の内積
void Vector3::dot(VECTOR3_TYPE *dst, const Vector3 &src0, const Vector3 &src1)
{
    *dst = src0.x * src1.x + src0.y * src1.y src0.z * src1.z;
}

// ベクトル同士の外積
void Vector3::cross(VECTOR3_TYPE *dst, const Vector3 &src0, const Vector3 &src1)
{
    // これは2次元の場合
    dst->x = src0.y*src1.z-z1*src1.y;
    dst->y = z1*x2-x1*src1.z;
    dst->z = x1*src1.y-src0.y*x2;
}

// ベクトルの定数倍
void Vector3::scale(Vector3 *dst, const Vector3 &src0, const VECTOR3_TYPE &src1)
{
    dst->x = src0.x * src1;
    dst->y = src0.y * src1;
    dst->z = src0.z * src1;
}

} //math
} //rc
