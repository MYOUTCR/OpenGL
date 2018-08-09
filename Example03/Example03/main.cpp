
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include<glut.h>

//#ifdef _MSC_VER//隐藏控制台;
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
//#endif

/*
设置照相机的位置;
gluLookAt()
参数1-3;
摄像机放置的位置;
参数4-6;
镜头瞄准的位置;
参数7-9;
设置哪个方向是朝上的;

gluPerspective()
参数1;
视野幅度h;
参数2;aspect
裁剪面的宽高比,这个影响到视野的截面有多大;
参数3;
近裁剪面到摄像机的距离;
参数4;
远裁剪面到摄像机的距离;

设置矩阵;
glMatrixMode();
参数1;
GL_PROJECTION		模型视图矩阵; 
GL_MODELVIEW		投影矩阵;
GL_TEXTURE			纹理矩阵;

把当前矩阵初始化为单位矩阵;
glLoadIdentity();

将当前矩阵设置为参数1所指定的值
glLoadMatrix();
参数1;
需要设置的矩阵值;

把参数1指定的值作为一个矩阵与当前矩阵相乘, 并把结果存储在当前矩阵中;
glMultMatrix();
参数1;
需要与当前矩阵相乘的矩阵;

glLoadMatrix与glMultMatrix矩阵存储方式;
	m1 , m5 , m9  , m13
	m2 , m6 , m10 , m14
	m3 , m7 , m11 , m15
	m4 , m8 , m12 , m16

	
移动,把当前矩阵与表示移动物体的矩阵相乘;
glTranslatef();

移动,把当前矩阵与表示移动物体的矩阵相乘,以逆时针方向绕原点到点(参数2-参数5)的直线进行旋转,旋转角度为参数1;
glRotatef()

缩放,把当前矩阵与表示沿各个轴对物体进行拉伸、收缩或反射的矩阵相乘;
glScaled()

裁剪平面;
glClipPlane()
参数1;
GL_CLIP_PLANEi(i=0,1,2...)
参数2;
平面方程的Ax+By+Cz+D=0;
(A,B,C,D)
需要glEnable(GL_CLIP_PLANEi)启动裁剪;




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
	重新调整视图像素矩形;
	*/

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);		//视口变换;
	/*把当前的矩阵指定为用于投影变换;*/
	glMatrixMode(GL_PROJECTION);					//指定哪个矩阵为当前矩阵,投影矩阵;
	glLoadIdentity();								//将当前用户坐标原点移动到屏幕中心;
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);	//投影变换;
	gluPerspective(60.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);						//模型视景矩阵堆;

}

void DrawCube()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();/*把当前矩阵设置为单位矩阵;*/
	//gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);/*设置照相机的位置 视图变换;*/
	glTranslatef(0.0, 0.0, -5.0);
	glScaled(1.0,2.0,1.0);/*指定物体在坐标上如何缩放 模型变换;*/
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
	glClipPlane(GL_CLIP_PLANE0, eqn);/*裁剪面1*/
	glEnable(GL_CLIP_PLANE0);

	glClipPlane(GL_CLIP_PLANE1, eqn1);/*裁剪面2*/
	glEnable(GL_CLIP_PLANE1);

	glRotatef(90.0, 1.0, 0.0, 0.0);
	glutWireSphere(1.0, 20.0, 16);
	glPopMatrix();
	glFlush();

}

void SolarReshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);		//视口变换;
													/*把当前的矩阵指定为用于投影变换;*/
	glMatrixMode(GL_PROJECTION);					//指定哪个矩阵为当前矩阵,投影矩阵;
	glLoadIdentity();								//将当前用户坐标原点移动到屏幕中心;
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

	glutPostRedisplay();//标记当前窗口重绘;

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
													/*把当前的矩阵指定为用于投影变换;*/
	glMatrixMode(GL_PROJECTION);					//指定哪个矩阵为当前矩阵,投影矩阵;
	glLoadIdentity();								//将当前用户坐标原点移动到屏幕中心;
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
	/*把当前的矩阵指定为用于投影变换;*/
	glMatrixMode(GL_PROJECTION);					//指定哪个矩阵为当前矩阵,投影矩阵;
	glLoadIdentity();								//将当前用户坐标原点移动到屏幕中心;
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

