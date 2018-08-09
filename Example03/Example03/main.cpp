
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include<glut.h>

//#ifdef _MSC_VER//���ؿ���̨;
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
//#endif

/*
�����������λ��;
gluLookAt()
����1-3;
��������õ�λ��;
����4-6;
��ͷ��׼��λ��;
����7-9;
�����ĸ������ǳ��ϵ�;

gluPerspective()
����1;
��Ұ����h;
����2;aspect
�ü���Ŀ�߱�,���Ӱ�쵽��Ұ�Ľ����ж��;
����3;
���ü��浽������ľ���;
����4;
Զ�ü��浽������ľ���;

���þ���;
glMatrixMode();
����1;
GL_PROJECTION		ģ����ͼ����; 
GL_MODELVIEW		ͶӰ����;
GL_TEXTURE			�������;

�ѵ�ǰ�����ʼ��Ϊ��λ����;
glLoadIdentity();

����ǰ��������Ϊ����1��ָ����ֵ
glLoadMatrix();
����1;
��Ҫ���õľ���ֵ;

�Ѳ���1ָ����ֵ��Ϊһ�������뵱ǰ�������, ���ѽ���洢�ڵ�ǰ������;
glMultMatrix();
����1;
��Ҫ�뵱ǰ������˵ľ���;

glLoadMatrix��glMultMatrix����洢��ʽ;
	m1 , m5 , m9  , m13
	m2 , m6 , m10 , m14
	m3 , m7 , m11 , m15
	m4 , m8 , m12 , m16

	
�ƶ�,�ѵ�ǰ�������ʾ�ƶ�����ľ������;
glTranslatef();

�ƶ�,�ѵ�ǰ�������ʾ�ƶ�����ľ������,����ʱ�뷽����ԭ�㵽��(����2-����5)��ֱ�߽�����ת,��ת�Ƕ�Ϊ����1;
glRotatef()

����,�ѵ�ǰ�������ʾ�ظ����������������졢��������ľ������;
glScaled()

�ü�ƽ��;
glClipPlane()
����1;
GL_CLIP_PLANEi(i=0,1,2...)
����2;
ƽ�淽�̵�Ax+By+Cz+D=0;
(A,B,C,D)
��ҪglEnable(GL_CLIP_PLANEi)�����ü�;




*/

static int year = 0, day = 0;

int main()
{

	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitWindowSize(500, 500);
	//glutInitWindowPosition(100, 100);
	//glutCreateWindow("Hello");
	///init();

	//glutDisplayFunc(DrawCube);
	//glutDisplayFunc(ClipPlane);
	//glutReshapeFunc(reshape);

	//SolarWin();
	//ShoulderWin();

	UnprojectWin();

	glutMainLoop();
	return 0;
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{
	/*
	���µ�����ͼ���ؾ���;
	*/

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);		//�ӿڱ任;
	/*�ѵ�ǰ�ľ���ָ��Ϊ����ͶӰ�任;*/
	glMatrixMode(GL_PROJECTION);					//ָ���ĸ�����Ϊ��ǰ����,ͶӰ����;
	glLoadIdentity();								//����ǰ�û�����ԭ���ƶ�����Ļ����;
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);	//ͶӰ�任;
	gluPerspective(60.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);						//ģ���Ӿ������;

}

void DrawCube()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();/*�ѵ�ǰ��������Ϊ��λ����;*/
	//gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);/*�����������λ�� ��ͼ�任;*/
	glTranslatef(0.0, 0.0, -5.0);
	glScaled(1.0,2.0,1.0);/*ָ��������������������� ģ�ͱ任;*/
	//glRotatef(45.0, 0.0, 1.0, 0.0);
	//glTranslatef(1.0, 0.0, 0.0);
	glutWireCube(2.0);
	glFlush();
}

void ClipPlane()
{
	GLdouble eqn[4] = { 0.0,1.0,0.0,0.0 };
	GLdouble eqn1[4] = { 1.0,0.0,0.0,0.0 };

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glPushMatrix();
	glTranslatef(0.0, 0.0, -5.0);
	glClipPlane(GL_CLIP_PLANE0, eqn);/*�ü���1*/
	glEnable(GL_CLIP_PLANE0);

	glClipPlane(GL_CLIP_PLANE1, eqn1);/*�ü���2*/
	glEnable(GL_CLIP_PLANE1);

	glRotatef(90.0, 1.0, 0.0, 0.0);
	glutWireSphere(1.0, 20.0, 16);
	glPopMatrix();
	glFlush();

}

void SolarReshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);		//�ӿڱ任;
													/*�ѵ�ǰ�ľ���ָ��Ϊ����ͶӰ�任;*/
	glMatrixMode(GL_PROJECTION);					//ָ���ĸ�����Ϊ��ǰ����,ͶӰ����;
	glLoadIdentity();								//����ǰ�û�����ԭ���ƶ�����Ļ����;
	gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void SolarKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'd':
		day = (day + 10) % 360;
		glutPostRedisplay();
		break;
	case 'D':
		day = (day - 10) % 360;
		glutPostRedisplay();
		break;
	case 'y':
		year = (year + 5) % 360;
		glutPostRedisplay();
		break;
	case 'Y':
		year = (year - 5) % 360;
		break;
	default:
		break;
	}

}

void DisplaySolar()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glPushMatrix();
	glutWireSphere(1.0, 20,16);/*draw sun*/
	glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
	glTranslatef(2.0, 0.0, 0.0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glutWireSphere(0.2, 10, 8);/*draw smaller planer*/
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
	glTranslatef(3.0, 0.0, 0.0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glutWireSphere(0.2, 10, 8);/*draw smaller planer*/

	glPopMatrix();

	glutSwapBuffers();
}

void SolarWin()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello");
	init();

	glutDisplayFunc(DisplaySolar);
	glutReshapeFunc(SolarReshape);
	glutKeyboardFunc(SolarKeyboard);
	//glutIdleFunc(spinDisplay);

}

void spinDisplay()
{
	day += 1;

	if (day > 360)
	{
		day = day - 360;

		year = year + 1;

		if (year > 360)
		{
			year = year - 360;
		}

	}

	glutPostRedisplay();//��ǵ�ǰ�����ػ�;

}

static int shoulder = 0, elbow = 0;

void ShoulderWin()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello");
	init();

	glutDisplayFunc(ShoulderDisplay);
	glutReshapeFunc(ShoulderReshape);
	glutKeyboardFunc(ShoulderKeyboard);

}

void ShoulderDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPushMatrix();
	glTranslatef(-1.0, 0.0, 0.0);
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);

	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();

}

void ShoulderReshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
													/*�ѵ�ǰ�ľ���ָ��Ϊ����ͶӰ�任;*/
	glMatrixMode(GL_PROJECTION);					//ָ���ĸ�����Ϊ��ǰ����,ͶӰ����;
	glLoadIdentity();								//����ǰ�û�����ԭ���ƶ�����Ļ����;
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void ShoulderKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 's':
		shoulder = (shoulder + 5) % 360;
		glutPostRedisplay();
		break;
	case 'S':
		shoulder = (shoulder - 5) % 360;
		glutPostRedisplay();
		break;
	case 'e':
		elbow = (elbow + 5) % 360;
		glutPostRedisplay();
		break;
	case 'E':
		elbow = (elbow - 5) % 360;
		break;
	default:
		break;
	}

}

void UnprojectWin()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello");
	init();

	glutDisplayFunc(UnprojectDisplay);
	glutReshapeFunc(UnprojectReshape);
	glutMouseFunc(UnprojectMouse);

}

void UnprojectDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void UnprojectReshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	/*�ѵ�ǰ�ľ���ָ��Ϊ����ͶӰ�任;*/
	glMatrixMode(GL_PROJECTION);					//ָ���ĸ�����Ϊ��ǰ����,ͶӰ����;
	glLoadIdentity();								//����ǰ�û�����ԭ���ƶ�����Ļ����;
	gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void UnprojectMouse(int button, int state, int x,int y)
{
	GLint viewport[4];
	GLdouble mvmatrix[16], projmatrix[16];
	GLint realy;
	GLdouble wx, wy, wz;
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (GLUT_DOWN == state)
		{
			glGetIntegerv(GL_VIEWPORT, viewport);
			glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
			glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);
			realy = viewport[3] - (GLint)y - 1;
			printf("Coordinates at cursor are (%4d,%4d)\n", x, realy);

			gluUnProject((GLfloat)x, (GLfloat)realy, 0.0, mvmatrix, projmatrix, viewport, &wx, &wy, &wz);
			printf("World coordinates at z=0 are (%f,%f,%f)\n", wx, wy, wz);

			gluUnProject((GLfloat)x, (GLfloat)realy, 1.0, mvmatrix, projmatrix, viewport, &wx, &wy, &wz);
			printf("World coordinates at z=1.0 are (%f,%f,%f)\n", wx, wy, wz);
			break;
		}
	case GLUT_RIGHT_BUTTON:
		if (GLUT_DOWN == state)
		{
			exit(0);
			break;
		}
	default:
		break;
	}
}

