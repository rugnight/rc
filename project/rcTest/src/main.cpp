/*
 * main.cpp
 * 2012年 2月 8日 水曜日 02時20分30秒 JST
 * テスト用プログラム
 */

#include <stdio.h> 
#include "vector3.h"
#include "vector2.h"
#include "matrix4.h"

#include <time.h>

using rc::math::Vector2;
using rc::math::Vector3;
using rc::math::Matrix4;


static void print_vec2(const char* comment, const Vector2 &v)
{
    printf("[%s] %f, %f \n", comment, v.x, v.y);
}

static void print_vec3(const char* comment, const Vector3 &v)
{
    printf("[%s] %f, %f %f\n", comment, v.x, v.y, v.z);
}

static void print_matrix4(const char* comment, const Matrix4 &m)
{
    printf("%s\n", comment);
    for (u32 i = 0; i < 16; ++i )
    {
        if ( i != 0 && i % 4 == 0 ) printf("\n");
        printf("%3.2f, ", m.v[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) 
{
    f32 v_array[16];
    Matrix4 mat(5.73013f);

    s32 mat_size = sizeof(mat);
    printf("mat size = %d \n", mat_size);
    s32 v16_size = sizeof(v_array);
    printf("v16 size = %d \n", v16_size);
    print_matrix4("matrix", mat);


    Matrix4 mat0 = Matrix4::ZERO;
    Matrix4 mat1 = Matrix4::ZERO;
    for ( u32 i = 0; i < 16; ++i ) {
        mat0.v[i] = 0.0f + (f32)(0.0f + i);
        mat1.v[i] = 10.0f + (f32)(0.0f + i);
    }
    print_matrix4("mat0", mat0);
    print_matrix4("mat1", mat1);

    Matrix4 mat_add = mat0 + mat1;
    print_matrix4("mat_add", mat_add);

    Matrix4 mat_sub = mat0 - mat1;
    print_matrix4("mat_sub", mat_sub);

    Matrix4 mat_mul = mat0 * mat1;
    print_matrix4("mat_mul", mat_mul);

    Matrix4 mat_inv;
    Matrix4::inverse(&mat_inv, mat1);
    mat_mul = mat_mul * mat_inv;
    print_matrix4("mat_inv", mat_mul);

#if 0
    u32 ALLOC_NUM = 10000;
    printf("alloc heap\n");
    clock_t start = clock();
    for ( u32 i = 0; i < ALLOC_NUM; ++i ) {
        f32 v[16];
    }
    clock_t end   = clock();
    f64 time = (f64)(end - start) / CLOCKS_PER_SEC;
    printf("heap time = %f\n", time);

    printf("alloc stack\n");
    start = clock();
    for ( u32 i = 0; i < ALLOC_NUM; ++i ) {
        f32 *p = new f32[16];
        SAFE_DELETE_ARRAY(p);
    }
    end   = clock();
    time = (f64)(end - start) / CLOCKS_PER_SEC;
    printf("heap time = %f\n", time);
#endif


#if 0
    f32 array3[3] = { 0.0f };
    u32 size_array3 = sizeof(array3);

    Vector3 vec3(0.0f);
    u32 size_vec3 = sizeof(vec3);

    printf("size array3 = %d\n", size_array3);
    printf("size vec3   = %d\n", size_vec3);
#endif


#if 0
    Vector3 vec3(0.0f, 0.0f, 0.0f);
    vec3.x = 1.0f;
    vec3.y = 2.0f;
    vec3.z = 3.0f;
    print_vec3("base", vec3);

    Vector3 plus = vec3 + vec3;
    print_vec3("Plus", plus);

    Vector3 minus = vec3 - vec3;
    print_vec3("minus", minus);

    Vector3 cross;
    Vector3::cross(&cross, Vector3(0.0f, 0.0f, 1.0f), Vector3(1.0f, 0.0f, 0.0f));
    print_vec3("cross", cross);
#endif


#if 0
    Vector2 vec2;
    vec2.x = 1.0f;
    vec2.y = 2.0f;


    printf("%f, %f \n", vec2.x, vec2.y);
    printf("%f, %f \n", vec2.v[0], vec2.v[1]);

    Vector2 plus = vec2 + vec2; 
    printf("+ %f, %f \n", plus.v[0], plus.v[1]);

    Vector2 minus = vec2 - vec2; 
    printf("- %f, %f \n", minus.v[0], minus.v[1]);

    Vector2 mul = vec2 * 5.0f; 
    printf("* %f, %f \n", mul.v[0], mul.v[1]);

    vec2 *= 5.0f;
    printf("* %f, %f \n", mul.v[0], mul.v[1]);
#endif

    getchar();
    return 0; 
}
