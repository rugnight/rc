/*
 * matrix4.h 
 * 2012年 2月18日 土曜日 16時51分24秒 JST
 */

#ifndef _RC_MATRIX4_H_
#define _RC_MATRIX4_H_

#include "rcMath.h"
#include "vector4.h"

namespace rc {
namespace math { 

class Matrix4
{
    public:
        static const Matrix4 ZERO;  // ゼロ行列
        static const Matrix4 UNIT;  // 単位行列

    public:
        Matrix4();
        Matrix4(MATRIX4_TYPE _n);
        Matrix4(MATRIX4_TYPE _n00, MATRIX4_TYPE _n01, MATRIX4_TYPE _n02, MATRIX4_TYPE _n03,
                MATRIX4_TYPE _n10, MATRIX4_TYPE _n11, MATRIX4_TYPE _n12, MATRIX4_TYPE _n13,
                MATRIX4_TYPE _n20, MATRIX4_TYPE _n21, MATRIX4_TYPE _n22, MATRIX4_TYPE _n23,
                MATRIX4_TYPE _n30, MATRIX4_TYPE _n31, MATRIX4_TYPE _n32, MATRIX4_TYPE _n33);
        ~Matrix4();

    // -------------------------
    // 演算子オーバーロード
    public:
        // -------------------------
        // =
        Matrix4& operator= (const Matrix4& rhs)
        {
            Matrix4::copy(this, rhs);
            return *this;
        }

        // -------------------------
        // +
        Matrix4 operator+ (const Matrix4& rhs)
        {
            Matrix4 ret;
            Matrix4::add(&ret, *this, rhs);
            return ret;
        }

        // -------------------------
        // -
        Matrix4 operator- (const Matrix4& rhs)
        {
            Matrix4 ret;
            Matrix4::sub(&ret, *this, rhs);
            return ret;
        }

        // -------------------------
        // *
        Matrix4 operator* (const Matrix4& rhs)
        {
            Matrix4 ret;
            Matrix4::mul(&ret, *this, rhs);
            return ret;
        }

    public:
        static void add(Matrix4 *dst, const Matrix4 &src0, const Matrix4 &src1);
        static void sub(Matrix4 *dst, const Matrix4 &src0, const Matrix4 &src1);
        static void mul(Matrix4 *dst, const Matrix4 &src0, const Matrix4 &src1);

        static void inverse(Matrix4 *dst, const Matrix4 &src);

        static void copy(Matrix4 *dst, const Matrix4 &src);

    public:
        union 
        {
            struct {
                MATRIX4_TYPE m00, m01, m02, m03,
                             m10, m11, m12, m13,
                             m20, m21, m22, m23,
                             m30, m31, m32, m33;
            };
            //Vector4 row[4];
            MATRIX4_TYPE v[MATRIX4_ELEM_NUM];
            MATRIX4_TYPE vv[MATRIX4_ROW_NUM][MATRIX4_COLUMN_NUM];
        };
};


}; //namespace math
}; //namespace rc


#endif//_RC_MATRIX4_H_
