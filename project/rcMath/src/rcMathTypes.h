/*
 *  project/rcMath/src/rcMathTypes.h
 *  2012年 4月23日 月曜日 20時52分50秒 JST
 */

#ifndef _RC_MATH_TYPES_H_
#define _RC_MATH_TYPES_H_

#include "rc_base.h"

namespace rc {
namespace math {

typedef f32 VECTOR2_TYPE;       // Vector2 の要素の型
typedef f32 VECTOR3_TYPE;       // Vector3 の要素の型
typedef f32 VECTOR4_TYPE;       // Vector4 の要素の型


typedef f32 MATRIX4_TYPE;       // Matrix4の要素の型
const u32 MATRIX4_ROW_NUM    = 4;
const u32 MATRIX4_COLUMN_NUM = 4;
const u32 MATRIX4_ELEM_NUM   = MATRIX4_ROW_NUM * MATRIX4_COLUMN_NUM;

}
}

#endif//_RC_MATH_TYPES_H_

