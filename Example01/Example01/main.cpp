// Example01.cpp : 定义控制台应用程序的入口点。
//
#define GLUT_DISABLE_ATEXIT_HACK

#include "stdafx.h"
#include<glut.h>

#ifdef _MSC_VER//隐藏控制台;
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#endif

static GLfloat spin = 0.0;

void init()
{
	//清除颜色,设置颜色为黑色;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	
	//设置作色模式;
	glShadeModel(GL_FLAT);//GL_FLAT:恒定作色(使用某一点作色),GL_SMOOTH:光滑作色(使用各个点作色);
}


void display()
{
	/*
	清除缓冲;
	GL_COLOR_BUFFER_BIT 清除颜色缓冲;
	*/

	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();							//入栈;
	glRotated(spin, 0.0, 0.0, 1.0);			//将矩阵旋转;
	glColor3f(1.0, 1.0, 1.0);				//设置颜色;
	glRectf(-25.0f, -25.0f, 25.0f, 25.0f);	//绘制矩形;
	glPopMatrix();							//出栈;
	glutSwapBuffers();						//双缓冲缓存指针交换;

}


void spinDisplay()
{
	spin = spin+ 1.0;
	if (spin > 360.0)
	{
		spin = spin - 360.0;
	}

	glutPostRedisplay();//标记当前窗口重绘;

}


void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);		//截取窗口的宽度;
	glMatrixMode(GL_PROJECTION);					//指定哪个矩阵为当前矩阵,投影矩阵;
	glLoadIdentity();								//将当前用户坐标原点移动到屏幕中心;
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);	//Left,Right,bottom,top,naer,far;
	glMatrixMode(GL_MODELVIEW);						//模型视景矩阵堆;
	glLoadIdentity();								//将当前用户坐标原点移动到屏幕中心;
}


 void Mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:				//Mouse Left;
		if (GLUT_DOWN == state)
		{
			glutIdleFunc(spinDisplay);	//空闲回调;
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
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	//初始化显示模式;双缓存窗口,RGB模式;
	glutInitWindowSize(250, 250);					//初始化窗口尺寸;
	glutInitWindowPosition(100, 100);				//初始化窗口位置;
	glutCreateWindow("Hello");						//创建窗口;
	init();
	glutDisplayFunc(display);						//窗口显示回调;
	glutReshapeFunc(reshape);						//当窗口发生改变时回调事件;
	glutMouseFunc(Mouse);							//鼠标消息事件回调;
	glutMainLoop();
	//glFlush();
	return 0;
}

