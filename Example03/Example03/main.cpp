
#include "main.h"
#include<glut.h>


#ifdef _MSC_VER//���ؿ���̨;
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#endif

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


*/





int main()
{

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello");
	init();

	glutDisplayFunc(DrawCube);
	glutReshapeFunc(reshape);

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

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	/*�ѵ�ǰ�ľ���ָ��Ϊ����ͶӰ�任;*/
	glMatrixMode(GL_PROJECTION);					//ָ���ĸ�����Ϊ��ǰ����,ͶӰ����;
	glLoadIdentity();								//����ǰ�û�����ԭ���ƶ�����Ļ����;
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
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