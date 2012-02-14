/*
 * main.cpp
 * 2012年 2月 8日 水曜日 02時20分30秒 JST
 * テスト用プログラム
 */

#include <stdio.h> 
#include "Vector2.h"

int main(int argc, char* argv[]) 
{
    rc::math::Vector2 vec2;
    vec2.x = 1.0f;
    vec2.y = 2.0f;

    printf("%f, %f \n", vec2.x, vec2.y);
    getchar();
    return 0; 
}
