
#include "man.h"
#include <math.h>
#include<glut.h>
#include <stdio.h>

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

���ö���λ���ģʽ;
glPolygonMode()
����1�������
GL_FRONT			����;
GL_BACK				����;
GL_FRONT_AND_BACK	�����뱳��;
����2����������
GL_POINT			����λ��ɵ�;
GL_LINE				����λ��Ƴ�����;
GL_FILL				����λ��Ƴ����;

���ö����������;
glFrontFace();
����1��
GL_CCW	����������ͶӰ����ζ���˳��Ϊ��ʱ�뷽��Ϊ����;
GL_CW	����˳��Ϊ˳ʱ�뷽��Ϊ����;

���ö���ε㻭ģʽ;
glPolygonStipple()
����1:
32*32λͼָ��
��Ҫ��������ε㻭����;
glEnable(GL_POLYGON_STIPPLE)

��Ƕ����Ƿ��Ƕ������ʼ��;
glEdgeFlag(GL_TRUE);
����1��
GL_TRUE		�Ƕ���ζ���,ֱ������glEdgeFlag(GL_FALSE)j����;
GL_FALSE	���Ƕ���ζ���,ֱ������glEdgeFlag(GL_TRUE)j����;

��������;
glNormal*()
��Ϊ���������÷���,�����������÷��ߡ�Ҳ�ɶ�����㹲��һ������;

��������;
glEnableClientState(GL_VERTEX_ARRAY);
����;
GL_VERTEX_ARRAY
GL_COLOR_ARRAY
GL_SECONDARY_COLOR_ARRAY
GL_INDEX_ARRAY
GL_NORMAL_ARRAY
GL_FOG_COORDINATE_ARRAY
GL_TEXTURE_COORD_ARRAY
GL_EDGE_FLAG_ARRAY

glVertexPointer();
����1��������������;
����2��������������;
����3�����������ƫ��ֵ;
����4�����������׵�ַ;

�ر�����;
glDisableClientState(GL_VERTEX_ARRAY);



*/



int main()
{
	//glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	//��ʼ����ʾģʽ;˫���洰��,RGBģʽ;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitWindowSize(250, 250);					//��ʼ�����ڳߴ�;
	glutInitWindowSize(400, 250);
	glutInitWindowPosition(100, 100);				//��ʼ������λ��;
	glutCreateWindow("Hello");						//��������;
	init();

	//glutDisplayFunc(DrawCircle);
	//glutDisplayFunc(DrawPoint);
	//glutDisplayFunc(DrawLine);
	//glutDisplayFunc(DrawLineEx);
	//glutDisplayFunc(MarkPolygon);
	glutDisplayFunc(DrawTriangle);

	
	
	


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
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);	//Left,Right,bottom,top,naer,far;
	//gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
	//gluOrtho2D(-(GLdouble)w / 100, (GLdouble)w/ 100, -(GLdouble)h / 100, (GLdouble)h/ 100);
	//gluOrtho2D(-(GLdouble)w, (GLdouble)w,- (GLdouble)h, (GLdouble)h);

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

void DrawPoint()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();							//��ջ;
	glColor3f(1.0, 1.0, 1.0);				//������ɫ;

	/*
	���õ�Ĵ�С,Ҫ��Begin֮ǰ;
	*/
	glPointSize((GLfloat)20.0);

	glBegin(GL_POINTS);
	glVertex3f(0.0f, 0.0f,0.0f);
	glEnd();

	glPopMatrix();							//��ջ;
	glutSwapBuffers();						//˫���建��ָ�뽻��;
}

void DrawLine()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glPushMatrix();							//��ջ;
	glColor3f(1.0, 1.0, 1.0);				//������ɫ;

	/*
		�����߿�,Ҫ��glBegin()֮ǰ����;
	*/

	//glLineWidth(50.0f);

	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	//glVertex3f(500.0f, 500.0f, 0.0f);
	glVertex3f(5.0f, 5.0f, 0.0f);
	glEnd();
	glFlush();

	//glPopMatrix();							//��ջ;
	//glutSwapBuffers();						//˫���建��ָ�뽻��;
}

void DrawLineEx()
{
	int i = 0;
	glColor3f(1.0, 1.0, 1.0);

	/*����ֱ�ߵ㻭ģʽ;*/
	glEnable(GL_LINE_STIPPLE);

	/*��һ��;*/
	/*����㻭ģʽ;*/
	glLineStipple(1, 0x0101);
	drawOneLine(50.0f, 125.0f, 150.0f, 125.0f);
	glLineStipple(1, 0x00ff);
	drawOneLine( 150.0f, 125.0f, 250.0f, 125.0f);
	glLineStipple(1, 0x14c7);
	drawOneLine(150.0f, 125.0f, 250.0f, 125.0f);

	/*�ڶ���;*/
	glLineWidth(5.0f);/*�����߿�;*/
	glLineStipple(1, 0x0101);
	drawOneLine(50.0f, 100.0f, 150.0f, 100.0f);
	glLineStipple(1, 0x00ff);
	drawOneLine(150.0f, 100.0f, 250.0f, 100.0f);
	glLineStipple(1, 0x14c7);
	drawOneLine(150.0f, 100.0f, 250.0f, 100.0f);

	/*������;*/
	glLineStipple(1, 0x14c7);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i < 7; i++)
	{
		glVertex2f(GLfloat(50.0 + i * 50), 75.0);
	}
	glEnd();

	/*������;*/
	for (i = 0; i < 6; i++)
	{
		drawOneLine(GLfloat(50.0 + i * 50), 50.0f, GLfloat(50.0 + (i + 1) * 50), 50.0f);
	}

	/*������;*/
	glLineStipple(5, 0x14c7);
	drawOneLine(50.0f, 25.0f, 350.0f, 25.0f);

	glDisable(GL_LINE_STIPPLE);
	glFlush();

	return;
}

void DrawPolygon()
{







}

void MarkPolygon()
{
	glColor3f(1.0, 1.0, 1.0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_POLYGON);
		glEdgeFlag(GL_TRUE);/*��Ƕ����Ƿ��Ƕ������ʼ��;*/
		glVertex3f(0.0f, 0.0f, 0.0f);
		glEdgeFlag(GL_FALSE);
		glVertex3f(20.0f, 50.0f, 0.0f);
		glEdgeFlag(GL_TRUE);
		glVertex3f(150.0f, 150.0f, 0.0f);
	glEnd();
	glFlush();

}

void VertexArray()
{



}


void DrawTriangle()
{
	static GLfloat vdata[12][3] = {
		{-X,0.0,Z},{ X,0.0,Z },{ -X,0.0,-Z },{ X,0.0,-Z },
		{0.0,Z,X},{ 0.0,Z,-X },{ 0.0,-Z,X },{ 0.0,-Z,-X },
		{Z,X,0.0},{ -Z,X,0.0 },{ Z,-X,0.0 },{ -Z,-X,0.0 }
	};

	static GLuint tindices[20][3] = {
		{1,4,0},{4,9,0},{4,5,9},{8,5,4},{1,8,4},
		{1,10,8},{10,3,8},{8,3,5},{3,2,5},{3,7,2},
		{3,10,7},{10,6,7},{6,11,7},{6,0,11},{6,1,0},
		{10,1,6},{10,0,9},{2,11,9},{5,2,9},{11,2,7}
	};

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);				//������ɫ;
	
	//glEnable(GL_LIGHTING);

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 20; i++)
	{
		GLfloat d1[3], d2[3], norm[3];

		for (int j = 0; j < 3; j++)
		{
			d1[j] = vdata[tindices[i][0]][j] - vdata[tindices[i][1]][j];
			d2[j] = vdata[tindices[i][1]][j] - vdata[tindices[i][2]][j];
		}

		normcrossprod(d1, d2, norm);
		glNormal3fv(norm);
		glColor3f(0.5, 0.5, 0.5);

		glVertex3fv(&vdata[tindices[i][0]][0]);
		glVertex3fv(&vdata[tindices[i][1]][0]);
		glVertex3fv(&vdata[tindices[i][2]][0]);

	}
	glEnd();

	glDisable(GL_LIGHTING);
	glFlush();

}


void normalize(float v[3])
{
	GLfloat d = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	if (d == 0.0)
	{
		printf("Zreo lenth vector");
		return;
	}

	v[0] /= d;
	v[1] /= d;
	v[2] /= d;

}

void normcrossprod(float v1[3],float v2[3],float out[3])
{
	out[0] = v1[1] * v2[2] - v1[2] * v2[1];
	out[1] = v1[2] * v2[0] - v1[0] * v2[2];
	out[2] = v1[0] * v2[1] - v1[1] * v2[0];

	normalize(out);
}

