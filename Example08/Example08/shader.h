#pragma once

#ifndef _HEAD_SHADER
#define _HEAD_SHADER

#include <GL/glew.h> // ����glew����ȡ���еı���OpenGLͷ�ļ�


class Shader
{
public:
	GLint m_Program;/*����ID*/;
public:
	Shader();/*��ȡ����Shader*/
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

	~Shader();

	void Use();/*ʹ�ó���;*/

private:

};


#endif 
