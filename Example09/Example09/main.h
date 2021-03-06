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

void drawTriangle_DeleteVOA();

void drawTriangle_Mat();

void drawTriangle_MultTexture();
void drawTriangle_MultTexture(Shader &shader);
void processInput(GLFWwindow *window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
// Function prototypes    
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

#endif // !_HEAD_EXAMPLE_SEVEN_MAIN