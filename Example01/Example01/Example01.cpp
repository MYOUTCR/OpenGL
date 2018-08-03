// Example01.cpp : 定义控制台应用程序的入口点。
//
#define GLUT_DISABLE_ATEXIT_HACK

#include "stdafx.h"
#include <glut.h>
//#include<freeglut.h>

#ifdef _MSC_VER//隐藏控制台;
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#endif

void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 1.0);
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(25, 25, 0.0);
	glVertex3f(75, 25, 0.0);
	glVertex3f(75, 75, 0.0);
	glVertex3f(25, 75, 0.0);
	glEnd();

}
int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello");
	glutDisplayFunc(display);
	glutMainLoop();


	glFlush();


	return 0;
}

