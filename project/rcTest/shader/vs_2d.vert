#version 120

// -----------------------------------------------------------
//  ウィンドウ座標系で２D座標を指定して描画する
// -----------------------------------------------------------

attribute vec2 in_Position;
attribute vec3 in_Color;
attribute vec2 in_Texture;

uniform vec2 in_WindowWH; 

varying vec3 ex_Color;
varying vec2 ex_Texture;

//頂点シェーダ
void main(void)
{
    float w = 2.0f / in_WindowWH.x;
    float h = 2.0f / in_WindowWH.y;
    gl_Position.x = in_Position.x / in_WindowWH.x - 1.0f;
    gl_Position.y = - (in_Position.y / in_WindowWH.y - 1.0f);
    gl_Position.z = 0.0f;
    gl_Position.w = 1.0f;

	ex_Color    = in_Color;
	ex_Texture  = in_Texture;
}
