
#include "main.h"
#include<glut.h>

#ifdef _MSC_VER//Òþ²Ø¿ØÖÆÌ¨;
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#endif

int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello");
	init();

	glutDisplayFunc(DrawTriangle);
	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}


void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glShadeModel(GL_SMOOTH);
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		gluOrtho2D(0.0, 30.0, 0.0, 30.0*(GLfloat)h / (GLfloat)w);
	else
		gluOrtho2D(0.0, 30.0*(GLfloat)w / (GLfloat)h, 0.0, 30.0);

	glMatrixMode(GL_MODELVIEW);

}

void DrawTriangle()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(5.0, 5.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(25.0, 5.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(5.0, 25.0);
	glEnd();
	glFlush();

}
