#pragma once

#ifndef _HEAD_SHADER
#define _HEAD_SHADER

#include <GL/glew.h> // 包含glew来获取所有的必须OpenGL头文件


class Shader
{
public:
	GLint m_Program;/*程序ID*/;
public:
	Shader();/*读取构造Shader*/
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

	~Shader();

	void Use();/*使用程序;*/

private:

};


#endif 
