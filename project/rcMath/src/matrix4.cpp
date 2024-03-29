/*
 * matrix4.cpp
 * 2012年 2月19日 日曜日 13時54分30秒 JST
 */

#include "matrix4.h"
#include "util_math.h"
#include <string.h>

namespace rc {
namespace math { 

// --------------------------------------------------
// local static function
// --------------------------------------------------
static MATRIX4_TYPE mul_row_column(const Matrix4 &src0, const u32 &row, const Matrix4 &src1, const u32 &col)
{
    DEBUG_ASSERT( 0 <= row && row < 4 );
    DEBUG_ASSERT( 0 <= col && col < 4 );
    const u32 r = row*4;
    return src0.v[r]   * src1.v[col]   
         + src0.v[r+1] * src1.v[col+4] 
         + src0.v[r+2] * src1.v[col+8] 
         + src0.v[r+3] * src1.v[col+12];
}

inline static f32 CalDetMat4x4(const MATRIX4_TYPE* m)
{
    return m[0]*m[5]*m[10]*m[15]+m[0]*m[6]*m[11]*m[13]+m[0]*m[7]*m[9]*m[14]
          +m[1]*m[4]*m[11]*m[14]+m[1]*m[6]*m[8]*m[15]+m[1]*m[7]*m[10]*m[12]
          +m[2]*m[4]*m[9]*m[15]+m[2]*m[5]*m[11]*m[12]+m[2]*m[7]*m[8]*m[13]
          +m[3]*m[4]*m[10]*m[13]+m[3]*m[5]*m[8]*m[14]+m[3]*m[6]*m[9]*m[12]
          -m[0]*m[5]*m[11]*m[14]-m[0]*m[6]*m[9]*m[15]-m[0]*m[7]*m[10]*m[13]
          -m[1]*m[4]*m[10]*m[15]-m[1]*m[6]*m[11]*m[12]-m[1]*m[7]*m[8]*m[14]
          -m[2]*m[4]*m[11]*m[13]-m[2]*m[5]*m[8]*m[15]-m[2]*m[7]*m[9]*m[12]
          -m[3]*m[4]*m[9]*m[14]-m[3]*m[5]*m[10]*m[12]-m[3]*m[6]*m[8]*m[13];
}

// --------------------------------------------------
// static var member
// --------------------------------------------------
const Matrix4 Matrix4::ZERO(0.0f);
const Matrix4 Matrix4::UNIT(1.0f, 0.0f, 0.0f, 0.0f, 
                            0.0f, 1.0f, 0.0f, 0.0f, 
                            0.0f, 0.0f, 1.0f, 0.0f, 
                            0.0f, 0.0f, 0.0f, 1.0f);

// --------------------------------------------------
// construct
// --------------------------------------------------
Matrix4::Matrix4()
{
    Matrix4(0.0f);
}

Matrix4::Matrix4(MATRIX4_TYPE _n)
{
    for (u32 i = 0; i < MATRIX4_ELEM_NUM; ++i ) { this->v[i] = _n; }
}

Matrix4::Matrix4(MATRIX4_TYPE _n00, MATRIX4_TYPE _n01, MATRIX4_TYPE _n02, MATRIX4_TYPE _n03,
                 MATRIX4_TYPE _n10, MATRIX4_TYPE _n11, MATRIX4_TYPE _n12, MATRIX4_TYPE _n13,
                 MATRIX4_TYPE _n20, MATRIX4_TYPE _n21, MATRIX4_TYPE _n22, MATRIX4_TYPE _n23,
                 MATRIX4_TYPE _n30, MATRIX4_TYPE _n31, MATRIX4_TYPE _n32, MATRIX4_TYPE _n33)
: m00(_n00), m01(_n01), m02(_n02), m03(_n03),
  m10(_n10), m11(_n11), m12(_n12), m13(_n13),
  m20(_n20), m21(_n21), m22(_n22), m23(_n23),
  m30(_n30), m31(_n31), m32(_n32), m33(_n33)
{
}

// --------------------------------------------------
// destruct
// --------------------------------------------------
Matrix4::~Matrix4()
{
}

// --------------------------------------------------
// member function
// --------------------------------------------------
void Matrix4::add(Matrix4 *dst, const Matrix4 &src0, const Matrix4 &src1)
{
    dst->v[0]  = src0.v[0]  + src1.v[0];
    dst->v[1]  = src0.v[1]  + src1.v[1];
    dst->v[2]  = src0.v[2]  + src1.v[2];
    dst->v[3]  = src0.v[3]  + src1.v[3];
    dst->v[4]  = src0.v[4]  + src1.v[4];
    dst->v[5]  = src0.v[5]  + src1.v[5];
    dst->v[6]  = src0.v[6]  + src1.v[6];
    dst->v[7]  = src0.v[7]  + src1.v[7];
    dst->v[8]  = src0.v[8]  + src1.v[8];
    dst->v[9]  = src0.v[9]  + src1.v[9];
    dst->v[10] = src0.v[10] + src1.v[10];
    dst->v[11] = src0.v[11] + src1.v[11];
    dst->v[12] = src0.v[12] + src1.v[12];
    dst->v[13] = src0.v[13] + src1.v[13];
    dst->v[14] = src0.v[14] + src1.v[14];
    dst->v[15] = src0.v[15] + src1.v[15];
}

void Matrix4::sub(Matrix4 *dst, const Matrix4 &src0, const Matrix4 &src1)
{
    dst->v[0]  = src0.v[0]  - src1.v[0];
    dst->v[1]  = src0.v[1]  - src1.v[1];
    dst->v[2]  = src0.v[2]  - src1.v[2];
    dst->v[3]  = src0.v[3]  - src1.v[3];
    dst->v[4]  = src0.v[4]  - src1.v[4];
    dst->v[5]  = src0.v[5]  - src1.v[5];
    dst->v[6]  = src0.v[6]  - src1.v[6];
    dst->v[7]  = src0.v[7]  - src1.v[7];
    dst->v[8]  = src0.v[8]  - src1.v[8];
    dst->v[9]  = src0.v[9]  - src1.v[9];
    dst->v[10] = src0.v[10] - src1.v[10];
    dst->v[11] = src0.v[11] - src1.v[11];
    dst->v[12] = src0.v[12] - src1.v[12];
    dst->v[13] = src0.v[13] - src1.v[13];
    dst->v[14] = src0.v[14] - src1.v[14];
    dst->v[15] = src0.v[15] - src1.v[15];
}


void Matrix4::mul(Matrix4 *dst, const Matrix4 &src0, const Matrix4 &src1)
{
    Matrix4 tmp = Matrix4::ZERO;
    tmp.v[0] = mul_row_column(src0, 0, src1, 0);
    tmp.v[1] = mul_row_column(src0, 0, src1, 1);
    tmp.v[2] = mul_row_column(src0, 0, src1, 2);
    tmp.v[3] = mul_row_column(src0, 0, src1, 3);

    tmp.v[4] = mul_row_column(src0, 1, src1, 0);
    tmp.v[5] = mul_row_column(src0, 1, src1, 1);
    tmp.v[6] = mul_row_column(src0, 1, src1, 2);
    tmp.v[7] = mul_row_column(src0, 1, src1, 3);

    tmp.v[8]  = mul_row_column(src0, 2, src1, 0);
    tmp.v[9]  = mul_row_column(src0, 2, src1, 1);
    tmp.v[10] = mul_row_column(src0, 2, src1, 2);
    tmp.v[11] = mul_row_column(src0, 2, src1, 3);

    tmp.v[12] = mul_row_column(src0, 3, src1, 0);
    tmp.v[13] = mul_row_column(src0, 3, src1, 1);
    tmp.v[14] = mul_row_column(src0, 3, src1, 2);
    tmp.v[15] = mul_row_column(src0, 3, src1, 3);
    Matrix4::copy(dst, tmp);
}

void Matrix4::inverse(Matrix4 *dst, const Matrix4 &src)
{
    f32 det = CalDetMat4x4(src.v);
    if( is_float_zero(det) ){
        return ;
    }
    else{
        double inv_det = 1.0/det;
 
        dst->v[0]  = inv_det*(src.v[5]*src.v[10]*src.v[15]+src.v[6]*src.v[11]*src.v[13]+src.v[7]*src.v[9]*src.v[14]
                        -src.v[5]*src.v[11]*src.v[14]-src.v[6]*src.v[9]*src.v[15]-src.v[7]*src.v[10]*src.v[13]);
        dst->v[1]  = inv_det*(src.v[1]*src.v[11]*src.v[14]+src.v[2]*src.v[9]*src.v[15]+src.v[3]*src.v[10]*src.v[13]
                        -src.v[1]*src.v[10]*src.v[15]-src.v[2]*src.v[11]*src.v[13]-src.v[3]*src.v[9]*src.v[14]);
        dst->v[2]  = inv_det*(src.v[1]*src.v[6]*src.v[15]+src.v[2]*src.v[7]*src.v[13]+src.v[3]*src.v[5]*src.v[14]
                        -src.v[1]*src.v[7]*src.v[14]-src.v[2]*src.v[5]*src.v[15]-src.v[3]*src.v[6]*src.v[13]);
        dst->v[3]  = inv_det*(src.v[1]*src.v[7]*src.v[10]+src.v[2]*src.v[5]*src.v[11]+src.v[3]*src.v[6]*src.v[9]
                        -src.v[1]*src.v[6]*src.v[11]-src.v[2]*src.v[7]*src.v[9]-src.v[3]*src.v[5]*src.v[10]);
        dst->v[4]  = inv_det*(src.v[4]*src.v[11]*src.v[14]+src.v[6]*src.v[8]*src.v[15]+src.v[7]*src.v[10]*src.v[12]
                        -src.v[4]*src.v[10]*src.v[15]-src.v[6]*src.v[11]*src.v[12]-src.v[7]*src.v[8]*src.v[14]);
        dst->v[5]  = inv_det*(src.v[0]*src.v[10]*src.v[15]+src.v[2]*src.v[11]*src.v[12]+src.v[3]*src.v[8]*src.v[14]
                        -src.v[0]*src.v[11]*src.v[14]-src.v[2]*src.v[8]*src.v[15]-src.v[3]*src.v[10]*src.v[12]);
        dst->v[6]  = inv_det*(src.v[0]*src.v[7]*src.v[14]+src.v[2]*src.v[4]*src.v[15]+src.v[3]*src.v[6]*src.v[12]
                        -src.v[0]*src.v[6]*src.v[15]-src.v[2]*src.v[7]*src.v[12]-src.v[3]*src.v[4]*src.v[14]);
        dst->v[7]  = inv_det*(src.v[0]*src.v[6]*src.v[11]+src.v[2]*src.v[7]*src.v[8]+src.v[3]*src.v[4]*src.v[10]
                        -src.v[0]*src.v[7]*src.v[10]-src.v[2]*src.v[4]*src.v[11]-src.v[3]*src.v[6]*src.v[8]);
        dst->v[8]  = inv_det*(src.v[4]*src.v[9]*src.v[15]+src.v[5]*src.v[11]*src.v[12]+src.v[7]*src.v[8]*src.v[13]
                        -src.v[4]*src.v[11]*src.v[13]-src.v[5]*src.v[8]*src.v[15]-src.v[7]*src.v[9]*src.v[12]);
        dst->v[9]  = inv_det*(src.v[0]*src.v[11]*src.v[13]+src.v[1]*src.v[8]*src.v[15]+src.v[3]*src.v[9]*src.v[12]
                        -src.v[0]*src.v[9]*src.v[15]-src.v[1]*src.v[11]*src.v[12]-src.v[3]*src.v[8]*src.v[13]);
        dst->v[10] = inv_det*(src.v[0]*src.v[5]*src.v[15]+src.v[1]*src.v[7]*src.v[12]+src.v[3]*src.v[4]*src.v[13]
                        -src.v[0]*src.v[7]*src.v[13]-src.v[1]*src.v[4]*src.v[15]-src.v[3]*src.v[5]*src.v[12]);
        dst->v[11] = inv_det*(src.v[0]*src.v[7]*src.v[9]+src.v[1]*src.v[4]*src.v[11]+src.v[3]*src.v[5]*src.v[8]
                        -src.v[0]*src.v[5]*src.v[11]-src.v[1]*src.v[7]*src.v[8]-src.v[3]*src.v[4]*src.v[9]);
        dst->v[12] = inv_det*(src.v[4]*src.v[10]*src.v[13]+src.v[5]*src.v[8]*src.v[14]+src.v[6]*src.v[9]*src.v[12]
                        -src.v[4]*src.v[9]*src.v[14]-src.v[5]*src.v[10]*src.v[12]-src.v[6]*src.v[8]*src.v[13]);
        dst->v[13] = inv_det*(src.v[0]*src.v[9]*src.v[14]+src.v[1]*src.v[10]*src.v[12]+src.v[2]*src.v[8]*src.v[13]
                        -src.v[0]*src.v[10]*src.v[13]-src.v[1]*src.v[8]*src.v[14]-src.v[2]*src.v[9]*src.v[12]);
        dst->v[14] = inv_det*(src.v[0]*src.v[6]*src.v[13]+src.v[1]*src.v[4]*src.v[14]+src.v[2]*src.v[5]*src.v[12]
                        -src.v[0]*src.v[5]*src.v[14]-src.v[1]*src.v[6]*src.v[12]-src.v[2]*src.v[4]*src.v[13]);
        dst->v[15] = inv_det*(src.v[0]*src.v[5]*src.v[10]+src.v[1]*src.v[6]*src.v[8]+src.v[2]*src.v[4]*src.v[9]
                        -src.v[0]*src.v[6]*src.v[9]-src.v[1]*src.v[4]*src.v[10]-src.v[2]*src.v[5]*src.v[8]);
    }
}


void Matrix4::copy(Matrix4 *dst, const Matrix4 &src)
{
#if 1
    memcpy(dst, &src, sizeof(MATRIX4_TYPE) * MATRIX4_ELEM_NUM);
#else
    for (u32 i = 0; i < MATRIX4_ELEM_NUM; ++i ) {
        dst->v[i] = src.v[i];
    }
#endif
}


} //namespace math
} //namespace rc
