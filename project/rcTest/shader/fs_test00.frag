#version 120

varying vec3 ex_Color;
varying vec2 ex_Texture;

uniform sampler2D texture;

void main(void)
{
    //gl_FragColor = vec4(ex_Color.xyz, 1.0f);
    gl_FragColor   = texture2D(texture, ex_Texture);
    //gl_FragColor   = 0.2f * vec4(ex_Color.xyz, 1.0f) + 0.8f * texture2D(texture, ex_Texture);
}
