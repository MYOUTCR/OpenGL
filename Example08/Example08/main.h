#pragma once


#ifndef _HEAD_EXAMPLE_SEVEN_MAIN
#define _HEAD_EXAMPLE_SEVEN_MAIN

#define GLEW_STATIC    
#include <GL/glew.h>    
// GLFW    
#include <GLFW/glfw3.h>


#include "shader.h"

/*shader*/


void drawTriangleVertex();
void drawTriangle(Shader &shader);

void drawTriangle_Texture();
void drawTriangle_DeleteVOA();

void drawTriangle_MultTexture();
void drawTriangle_MultTexture(Shader &shader);


// Function prototypes    
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

#endif // !_HEAD_EXAMPLE_SEVEN_MAIN