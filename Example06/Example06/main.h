#pragma once

#ifndef _HEAD_EXAMPLE_SIX_MAIN
#define _HEAD_EXAMPLE_SIX_MAIN

#define GLEW_STATIC    
#include <GL/glew.h>    
// GLFW    
#include <GLFW/glfw3.h> 

void drawTriangle_Buffer();
void drawTriangle();




void drawPoint();
void drawcure();
void cube();

// Function prototypes    
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

#endif // !_HEAD_EXAMPLE_SIX_MAIN