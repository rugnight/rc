/*
 *  vector2.h
 *  2012年 2月 8日 水曜日 01時55分02秒 JST
 */

#ifndef _RC_VECTOR2_H_
#define _RC_VECTOR2_H_

#include "rcBase.h"

typedef f32 VECTOR2_TYPE;       // Vector2 の要素の型

namespace rc {
namespace math {

class Vector2 {
    public:
        // -------------------------
        // constructor
        Vector2();
        Vector2(VECTOR2_TYPE _n);
        Vector2(VECTOR2_TYPE _x, VECTOR2_TYPE _y);
        Vector2(const Vector2 &src);

        // -------------------------
        // destructor
        ~Vector2();

    // -------------------------
    // 演算子オーバーロード
    public:
        // -------------------------
        // =
        Vector2& operator= (const Vector2& rhs)
        {
            this->x = rhs.x; this->y = rhs.y;
            return *this;
        }

        // -------------------------
        // +
        Vector2 operator+ (const Vector2& rhs)
        {
            Vector2 ret;
            Vector2::add(&ret, *this, rhs);
            return ret;
        }

        // -------------------------
        // -
        Vector2 operator- (const Vector2& rhs)
        {
            Vector2 ret;
            Vector2::sub(&ret, *this, rhs);
            return ret;
        }

        // -------------------------
        // *
        Vector2 operator* (const VECTOR2_TYPE& rhs)
        {
            Vector2 ret;
            Vector2::scale(&ret, *this, rhs);
            return ret;
        }

        // -------------------------
        // *=
        Vector2 operator*= (const VECTOR2_TYPE& rhs)
        {
            Vector2::scale(this, *this, rhs);
            return *this;
        }

        // +Vector2
        Vector2 operator+() { return *this; }
        // -Vector2
        Vector2 operator-() { return Vector2(-x, -y); } 

    // -------------------------
    // static function
    public:
        // ベクトル同士の和
        static void add(Vector2 *dst, const Vector2 &src0, const Vector2 &src1);
        // ベクトル同士の差
        static void sub(Vector2 *dst, const Vector2 &src0, const Vector2 &src1);
        // ベクトル同士の内積
        static void dot(VECTOR2_TYPE *dst, const Vector2 &src0, const Vector2 &src1);
        // ベクトル同士の外積
        static void cross(VECTOR2_TYPE *dst, const Vector2 &src0, const Vector2 &src1);

        // ベクトルの定数倍
        static void scale(Vector2 *dst, const Vector2 &src0, const VECTOR2_TYPE &src1);

    public:
        union { 
            struct {
                VECTOR2_TYPE x;
                VECTOR2_TYPE y;
            };
            VECTOR2_TYPE v[2];
        };
};


} //math
} //rc

#endif//_RC_VECTOR2_H_