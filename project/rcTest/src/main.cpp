/*
 * main.cpp
 * 2012年 2月 8日 水曜日 02時20分30秒 JST
 * テスト用プログラム
 */

#include <stdio.h> 
#include "Vector3.h"
#include "Vector2.h"

using rc::math::Vector2;
using rc::math::Vector3;


static void print_vec2(const char* comment, const Vector2 &v)
{
    printf("[%s] %f, %f \n", comment, v.x, v.y);
}

static void print_vec3(const char* comment, const Vector3 &v)
{
    printf("[%s] %f, %f %f\n", comment, v.x, v.y, v.z);
}

int main(int argc, char* argv[]) 
{
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
