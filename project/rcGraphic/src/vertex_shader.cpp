//============================================================================
// Name        : rc/graphics/shader/vertex_shader.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "vertex_shader.h"
#include "util_file.h"

namespace rc {

/* ---------------------------------------- */
//  class VertexShaderBase
/* ---------------------------------------- */
VertexShaderBase::VertexShaderBase()
: m_shader(0)
{
}

VertexShaderBase::~VertexShaderBase()
{
}

/* ---------------------------------------- */
//	class GLVertexShader : Im_shader
/* ---------------------------------------- */
GLVertexShader::GLVertexShader()
{
}

GLVertexShader::~GLVertexShader()
{
	destroy();
}

bool GLVertexShader::create(const char* filename)
{
	destroy();

	GLchar *vertexsource;
	int IsCompiled_VS;
	/* シェーダのコードをバッファに読み込みます */
	vertexsource = createBufferFromFile(filename);
	/* 空の頂点シェーダを作成 */
	m_shader = glCreateShader(GL_VERTEX_SHADER);
	/* OpenGLに頂点シェーダのソースを送る */
	/* 最後の引数に0を入れることで、GLが自動的にサイズを判断してくれます */
	glShaderSource(m_shader, 1, (const GLchar**)&vertexsource, 0);
	/* 頂点シェーダをコンパイル */
	glCompileShader(m_shader);
	/* 頂点シェーダが正しくコンパイルされているかをチェック */
	glGetShaderiv(m_shader, GL_COMPILE_STATUS, &IsCompiled_VS);
	if(IsCompiled_VS == false)
	{
		int maxLength;
		/* エラー情報を出力するために、必要な文字列バッファのサイズを取得 */
		glGetShaderiv(m_shader, GL_INFO_LOG_LENGTH, &maxLength);
		/* NULL文字を含んだサイズを返してくれるので取得したサイズをそのまま確保 */
		char *vertexInfoLog;
		vertexInfoLog = (char *)malloc(maxLength);
		/* エラー情報をバッファに書き込み出力して終了 */
		glGetShaderInfoLog(m_shader, maxLength, &maxLength, vertexInfoLog);
		printf("VERTEX SHADER COMPILE ERROR: %s\n", vertexInfoLog);
		free(vertexInfoLog);
		free(vertexsource);
		return false;
	}
	free(vertexsource);
	return true;
}

bool GLVertexShader::destroy()
{
    glDeleteShader(m_shader);
	return true;
}

} // namespace rc
