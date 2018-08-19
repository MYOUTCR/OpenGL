#pragma once

#ifndef _HEAD_EXAMPLE_SIX_MAIN
#define _HEAD_EXAMPLE_SIX_MAIN

#define GLEW_STATIC    
#include <GL/glew.h>    
// GLFW    
#include <GLFW/glfw3.h> 


void DrawTriangle_Initialize();

void drawTriangle_Buffer();
void drawTriangle();
void drawTriangle_DeleteVOA();

void DrawTriangle_IndexBuffer();
void DrawTriangle_Index_drawTriangle();
void DrawTriangle_Index_DeleteVOA();

void Exp_drawTriangleBuffer();
void Exp_drawTriangle();
void Exp_DeleteVOA();

void Exp_CreateShader();
void Exp_Shader_drawTriangle();


// Function prototypes    
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

#endif // !_HEAD_EXAMPLE_SIX_MAIN