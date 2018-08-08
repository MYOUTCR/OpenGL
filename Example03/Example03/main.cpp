
#include "main.h"
#include<glut.h>


#ifdef _MSC_VER//隐藏控制台;
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#endif

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
	重新调整视图像素矩形;
	*/

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	/*把当前的矩阵指定为用于投影变换;*/
	glMatrixMode(GL_PROJECTION);					//指定哪个矩阵为当前矩阵,投影矩阵;
	glLoadIdentity();								//将当前用户坐标原点移动到屏幕中心;
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
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