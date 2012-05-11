/*
 *  vector3.h
 *  2012年 2月 16日 木曜日 23:00:13    
 */

#ifndef _RC_VECTOR4_H_
#define _RC_VECTOR4_H_

#include "rcMathBase.h"

namespace rc {
namespace math {

class Vector4
{
    public:
        static const Vector4 ZERO;  // ゼロ
        static const Vector4 UNIT;  // 単位
    public:
        // -------------------------
        // constructor
        Vector4();
        Vector4(VECTOR4_TYPE _n);
        Vector4(VECTOR4_TYPE _x, VECTOR4_TYPE _y, VECTOR4_TYPE _z, VECTOR4_TYPE _w);
        Vector4(const Vector4 &src);

        // -------------------------
        // destructor
        ~Vector4();

    // -------------------------
    // 演算子オーバーロード
    public:
        // -------------------------
        // =
        Vector4& operator= (const Vector4& rhs)
        {
            this->x = rhs.x; this->y = rhs.y; this->z = rhs.z; this->w = rhs.w;
            return *this;
        }

        // -------------------------
        // +
        Vector4 operator+ (const Vector4& rhs)
        {
            Vector4 ret;
            Vector4::add(&ret, *this, rhs);
            return ret;
        }

        // -------------------------
        // -
        Vector4 operator- (const Vector4& rhs)
        {
            Vector4 ret;
            Vector4::sub(&ret, *this, rhs);
            return ret;
        }

        // -------------------------
        // *
        Vector4 operator* (const VECTOR4_TYPE& rhs)
        {
            Vector4 ret;
            Vector4::scale(&ret, *this, rhs);
            return ret;
        }

        // -------------------------
        // *=
        Vector4 operator*= (const VECTOR4_TYPE& rhs)
        {
            Vector4::scale(this, *this, rhs);
            return *this;
        }

        // +Vector4
        Vector4 operator+() { return *this; }
        // -Vector4
        Vector4 operator-() { return Vector4(-x, -y, -z, -w); } 

    // -------------------------
    // static function
    public:
        // ベクトル同士の和
        static void add(Vector4 *dst, const Vector4 &src0, const Vector4 &src1);
        // ベクトル同士の差
        static void sub(Vector4 *dst, const Vector4 &src0, const Vector4 &src1);

        // ベクトルの定数倍
        static void scale(Vector4 *dst, const Vector4 &src0, const VECTOR4_TYPE &src1);

    public:
        union { 
            struct {
                VECTOR4_TYPE x;
                VECTOR4_TYPE y;
                VECTOR4_TYPE z;
                VECTOR4_TYPE w;
            };
            VECTOR4_TYPE v[4];
        };
};


} //math
} //rc

#endif//_RC_VECTOR4_H_
