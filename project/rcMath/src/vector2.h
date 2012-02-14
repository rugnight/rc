/*
 *  vector2.h
 *  2012年 2月 8日 水曜日 01時55分02秒 JST
 */

#ifndef _RC_VECTOR2_H_
#define _RC_VECTOR2_H_

#include "rcBase.h"

namespace rc {
namespace math {

class Vector2 {
    public:
        Vector2();
        Vector2(f32 _n);
        Vector2(f32 _x, f32 _y);
        ~Vector2();


    // 演算子オーバーロード
    public:
        // =
        Vector2& operator= (const Vector2& rhs)
        {
            this->x = rhs.x; this->y = rhs.y;
            return *this;
        }
        // +Vector2
        Vector2 operator+()
        {
            return *this;
        }
        // -Vector2
        Vector2 operator-()
        {
            return Vector2(-x, -y);
        }


    public:
        f32 x, y;
};

// ベクトル同士の和
void vec2_add(Vector2 &dst, const Vector2 &src0, const Vector2 &src1);
// ベクトル同士の差
void vec2_sub(Vector2 &dst, const Vector2 &src0, const Vector2 &src1);
// ベクトル同士の積
void vec2_mul(Vector2 &dst, const Vector2 &src0, const Vector2 &src1);
// ベクトル同士の除
void vec2_div(Vector2 &dst, const Vector2 &src0, const Vector2 &src1);

} //math
} //rc

#endif//_RC_VECTOR2_H_
