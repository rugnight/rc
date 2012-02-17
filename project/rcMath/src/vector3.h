/*
 *  vector3.h
 *  2012年 2月 16日 木曜日 23:00:13    
 */

#ifndef _RC_VECTOR3_H_
#define _RC_VECTOR3_H_

#include "rcBase.h"

typedef f32 VECTOR3_TYPE;

namespace rc {
namespace math {

class Vector3
{
    public:
        // -------------------------
        // constructor
        Vector3();
        Vector3(VECTOR3_TYPE _n);
        Vector3(VECTOR3_TYPE _x, VECTOR3_TYPE _y, VECTOR3_TYPE _z);
        Vector3(const Vector3 &src);

        // -------------------------
        // destructor
        ~Vector3();

    // -------------------------
    // 演算子オーバーロード
    public:
        // -------------------------
        // =
        Vector3& operator= (const Vector3& rhs)
        {
            this->x = rhs.x; this->y = rhs.y; this->z = rhs.z;
            return *this;
        }

        // -------------------------
        // +
        Vector3 operator+ (const Vector3& rhs)
        {
            Vector3 ret;
            Vector3::add(&ret, *this, rhs);
            return ret;
        }

        // -------------------------
        // -
        Vector3 operator- (const Vector3& rhs)
        {
            Vector3 ret;
            Vector3::sub(&ret, *this, rhs);
            return ret;
        }

        // -------------------------
        // *
        Vector3 operator* (const VECTOR3_TYPE& rhs)
        {
            Vector3 ret;
            Vector3::scale(&ret, *this, rhs);
            return ret;
        }

        // -------------------------
        // *=
        Vector3 operator*= (const VECTOR3_TYPE& rhs)
        {
            Vector3::scale(this, *this, rhs);
            return *this;
        }

        // +Vector3
        Vector3 operator+() { return *this; }
        // -Vector3
        Vector3 operator-() { return Vector3(-x, -y, -z); } 

    // -------------------------
    // static function
    public:
        // ベクトル同士の和
        static void add(Vector3 *dst, const Vector3 &src0, const Vector3 &src1);
        // ベクトル同士の差
        static void sub(Vector3 *dst, const Vector3 &src0, const Vector3 &src1);
        // ベクトル同士の内積
        static void dot(VECTOR3_TYPE *dst, const Vector3 &src0, const Vector3 &src1);
        // ベクトル同士の外積
        static void cross(Vector3 *dst, const Vector3 &src0, const Vector3 &src1);

        // ベクトルの定数倍
        static void scale(Vector3 *dst, const Vector3 &src0, const VECTOR3_TYPE &src1);

    public:
        union { 
            struct {
                VECTOR3_TYPE x;
                VECTOR3_TYPE y;
                VECTOR3_TYPE z;
            };
            VECTOR3_TYPE v[3];
        };
};


}; //math
}; //rc

#endif//_RC_VECTOR3_H_
