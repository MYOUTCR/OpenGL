// Example01.cpp : �������̨Ӧ�ó������ڵ㡣
//
#define GLUT_DISABLE_ATEXIT_HACK

#include "stdafx.h"
#include<glut.h>

#ifdef _MSC_VER//���ؿ���̨;
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#endif

static GLfloat spin = 0.0;

void init()
{
	//�����ɫ,������ɫΪ��ɫ;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	
	//������ɫģʽ;
	glShadeModel(GL_FLAT);//GL_FLAT:�㶨��ɫ(ʹ��ĳһ����ɫ),GL_SMOOTH:�⻬��ɫ(ʹ�ø�������ɫ);
}


void display()
{
	/*
	�������;
	GL_COLOR_BUFFER_BIT �����ɫ����;
	*/

	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();							//��ջ;
	glRotated(spin, 0.0, 0.0, 1.0);			//��������ת;
	glColor3f(1.0, 1.0, 1.0);				//������ɫ;
	glRectf(-25.0f, -25.0f, 25.0f, 25.0f);	//���ƾ���;
	glPopMatrix();							//��ջ;
	glutSwapBuffers();						//˫���建��ָ�뽻��;

}


void spinDisplay()
{
	spin = spin+ 1.0;
	if (spin > 360.0)
	{
		spin = spin - 360.0;
	}

	glutPostRedisplay();//��ǵ�ǰ�����ػ�;

}


void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);		//��ȡ���ڵĿ��;
	glMatrixMode(GL_PROJECTION);					//ָ���ĸ�����Ϊ��ǰ����,ͶӰ����;
	glLoadIdentity();								//����ǰ�û�����ԭ���ƶ�����Ļ����;
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);	//Left,Right,bottom,top,naer,far;
	glMatrixMode(GL_MODELVIEW);						//ģ���Ӿ������;
	glLoadIdentity();								//����ǰ�û�����ԭ���ƶ�����Ļ����;
}


 void Mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:				//Mouse Left;
		if (GLUT_DOWN == state)
		{
			glutIdleFunc(spinDisplay);	//���лص�;
		}
		break;
	case GLUT_MIDDLE_BUTTON:			//Mouse Middle;
		if (GLUT_DOWN == state)
		{
			glutIdleFunc(NULL);
		}
		break;
	default:
		break;
	}
}


int main(int argc, char ** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	//��ʼ����ʾģʽ;˫���洰��,RGBģʽ;
	glutInitWindowSize(250, 250);					//��ʼ�����ڳߴ�;
	glutInitWindowPosition(100, 100);				//��ʼ������λ��;
	glutCreateWindow("Hello");						//��������;
	init();
	glutDisplayFunc(display);						//������ʾ�ص�;
	glutReshapeFunc(reshape);						//�����ڷ����ı�ʱ�ص��¼�;
	glutMouseFunc(Mouse);							//�����Ϣ�¼��ص�;
	glutMainLoop();
	//glFlush();
	return 0;
}

