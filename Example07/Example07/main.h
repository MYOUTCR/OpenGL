#pragma once


#ifndef _HEAD_EXAMPLE_SEVEN_MAIN
#define _HEAD_EXAMPLE_SEVEN_MAIN

#define GLEW_STATIC    
#include <GL/glew.h>    
// GLFW    
#include <GLFW/glfw3.h> 
#include "shader.h"

/*shader*/

void DrawTriangle_Initialize();

void drawTriangle_Buffer();
void drawTriangle();
void drawTriangle_DeleteVOA();

void DrawTriangle_Shader_Uniform();
void drawTriangle_Uniform();

void DrawTriangle_Vertex_Color_Shader();
void drawTriangle_Vertex_Color();

void drawTriangle_Shader(Shader &shader);

void setFloat(Shader shader, float offset);
// Function prototypes    
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

#endif // !_HEAD_EXAMPLE_SEVEN_MAIN