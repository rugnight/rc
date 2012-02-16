/*
 * main.cpp
 * 2012年 2月 8日 水曜日 02時20分30秒 JST
 * テスト用プログラム
 */

#include <stdio.h> 
#include "Vector2.h"

using rc::math::Vector2;

int main(int argc, char* argv[]) 
{
    Vector2 vec2;
    vec2.x = 1.0f;
    vec2.y = 2.0f;

    printf("%f, %f \n", vec2.x, vec2.y);
    printf("%f, %f \n", vec2.v[0], vec2.v[1]);

    Vector2 plus = vec2 + vec2; 
    printf("+ %f, %f \n", plus.v[0], plus.v[1]);

    getchar();
    return 0; 
}
