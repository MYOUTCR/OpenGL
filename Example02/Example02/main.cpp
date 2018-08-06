
#include "man.h"
#include <math.h>
#include<glut.h>

#ifdef _MSC_VER//���ؿ���̨;
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#endif


/*
��RGBAģʽ�������Ϊ��ɫ;
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glClearDepth(1.0f);					//�����Ȼ�����
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);GL_ACCUM_BUFFER_BIT	//�ۻ�������;GL_STENCIL_BUFFER_BIT//ģ�建����;

glColor3f(1.0, 1.0, 1.0);
����1����ɫ0-1.0;
����2����ɫ0-1.0;
����3����ɫ0-1.0;

glFlush(void);
ǿ�ƻ���;

glFinish(void);
ǿ�ƻ���,����������;

��־��һ���������ݵĿ�ʼ;
glBegin(GL_LINE);

GL_POINTS �����ĵ�;
GL_LINES			һ�Զ��㱻����Ϊһ��ֱ��;
GL_LINE_STRIP		һϵ�еĵ������ֱ��;
GL_LINE_LOOP		��GL_LINE_STRIPһ��������β����;
GL_TRIANGLES		3�����㱻����Ϊһ��������;
GL_TRIANGLE_STRIP	3���ε�����;
GL_TRIANGLES_FAN	���ӳ����ε�����ϵ��;
GL_QUADS			4�����㱻����Ϊһ���ı���;
GL_QUAD_STRIP		�ı��ε����Ӵ�;
GL_POLYGON			�򵥵�͹�����;

����֮��ɵ��ú���;
glVertex*();					���ö���;
glColor*();						����RGBA��ɫ;
glIndex*();						������ɫ����;
glSecondaryColor*();			��������Ӧ�ú�ĸ�����ɫ;
glNormal*();					���÷�����������;
glMaterial*();					���ò�������;
glFogCoord*();					����������;
glTexCoord*();					������������;
glMultiTexCood*();				Ϊ��������������������;
glVertexAttrib*();				����ͨ�õ���������;
glEdgeFlag*();					���Ʊ߽����;
glArraryElement();				��ȡ������������;
glEvalCoord*(),glEvalPoint*();	��������;
glCallList(),glCallLists();		ִ����ʾ�б�;

��־�Ŷ������ݽ���;
glEnd();


*/




int main()
{
	//glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	//��ʼ����ʾģʽ;˫���洰��,RGBģʽ;
	glutInitWindowSize(250, 250);					//��ʼ�����ڳߴ�;
	glutInitWindowPosition(100, 100);				//��ʼ������λ��;
	glutCreateWindow("Hello");						//��������;
	init();
	glutDisplayFunc(DrawCircle);						//������ʾ�ص�;
	glutReshapeFunc(reshape);						//�����ڷ����ı�ʱ�ص��¼�;
	//glutMouseFunc(Mouse);							//�����Ϣ�¼��ص�;
	glutMainLoop();

	return 0;
}


void init()
{
	//�����ɫ,������ɫΪ��ɫ;
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//������ɫģʽ;
	glShadeModel(GL_FLAT);//GL_FLAT:�㶨��ɫ(ʹ��ĳһ����ɫ),GL_SMOOTH:�⻬��ɫ(ʹ�ø�������ɫ);
}

void reshape(int w, int h)
{
	/*
	���µ�����ͼ���ؾ���;
	*/

	//glViewport(0, 0, (GLint)w, (GLint)h);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);		//��ȡ���ڵĿ��;
	glMatrixMode(GL_PROJECTION);					//ָ���ĸ�����Ϊ��ǰ����,ͶӰ����;
	glLoadIdentity();								//����ǰ�û�����ԭ���ƶ�����Ļ����;
	//glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);	//Left,Right,bottom,top,naer,far;
	//gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
	gluOrtho2D(-(GLdouble)w, (GLdouble)w,- (GLdouble)h, (GLdouble)h);

	glMatrixMode(GL_MODELVIEW);						//ģ���Ӿ������;
	glLoadIdentity();

}

void DrawCircle()
{
	GLint circle_point = 100;
	GLdouble dAngle = 0;

	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();							//��ջ;
	glColor3f(1.0, 1.0, 1.0);				//������ɫ;

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < circle_point; i++)
	{
		dAngle = 2 * PI*i / circle_point;
		glVertex2f(cos(dAngle)*100 , sin(dAngle)*100 );
	}
	glEnd();

	glPopMatrix();							//��ջ;
	glutSwapBuffers();						//˫���建��ָ�뽻��;

}