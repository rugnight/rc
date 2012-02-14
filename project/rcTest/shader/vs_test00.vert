#version 120

invariant gl_Position;

attribute vec2 in_Position;
attribute vec3 in_Color;
attribute vec2 in_Texture;

varying vec3 ex_Color;
varying vec2 ex_Texture;

//頂点シェーダ
void main(void)
{
	gl_Position = vec4(in_Position.x, in_Position.y, 0.0f, 1.0f);
	ex_Color    = in_Color;
	ex_Texture  = in_Texture;
}
