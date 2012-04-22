//============================================================================
// Name        : rc/graphics/shader/pixel_shader.cpp
// Author      :
// Version     :
//============================================================================

#include <stdio.h>
#include <stdlib.h>
//#include <gl3.h>
#include "pixel_shader.h"

#include "util_file.h"

namespace rc {

/* ---------------------------------------- */
//  class PixelShaderBase
/* ---------------------------------------- */
PixelShaderBase::PixelShaderBase()
: m_shader(0)
{
}

PixelShaderBase::~PixelShaderBase()
{
}

/* ---------------------------------------- */
//	class GLPixelShader : public IVertexShader
/* ---------------------------------------- */
GLPixelShader::GLPixelShader()
{
}

GLPixelShader::~GLPixelShader()
{
	destroy();
}

bool GLPixelShader::create(const char* filename)
{
	destroy();

	GLchar *pixelsource;
	int IsCompiled_PS;
	/* シェーダのコードをバッファに読み込みます */
	pixelsource = createBufferFromFile(filename);
	/* 空の頂点シェーダを作成 */
	m_shader = glCreateShader(GL_FRAGMENT_SHADER);
	/* OpenGLに頂点シェーダのソースを送る */
	/* 最後の引数に0を入れることで、GLが自動的にサイズを判断してくれます */
	glShaderSource(m_shader, 1, (const GLchar**)&pixelsource, 0);
	/* 頂点シェーダをコンパイル */
	glCompileShader(m_shader);
	/* 頂点シェーダが正しくコンパイルされているかをチェック */
	glGetShaderiv(m_shader, GL_COMPILE_STATUS, &IsCompiled_PS);
	if(IsCompiled_PS == false)
	{
		int maxLength;
		/* エラー情報を出力するために、必要な文字列バッファのサイズを取得 */
		glGetShaderiv(m_shader, GL_INFO_LOG_LENGTH, &maxLength);
		/* NULL文字を含んだサイズを返してくれるので取得したサイズをそのまま確保 */
		char *vertexInfoLog;
		vertexInfoLog = (char *)malloc(maxLength);
		/* エラー情報をバッファに書き込み出力して終了 */
		glGetShaderInfoLog(m_shader, maxLength, &maxLength, vertexInfoLog);
		printf("PIXEL SHADER COMPILE ERROR: %s\n", vertexInfoLog);
		free(vertexInfoLog);
		free(pixelsource);
		return false;
	}
	free(pixelsource);
	return true;
}

bool GLPixelShader::destroy()
{
    glDeleteShader(m_shader);
	return true;
}

}; // namespace rc
