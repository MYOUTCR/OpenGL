
#include "man.h"
#include <math.h>
#include<glut.h>

#ifdef _MSC_VER//隐藏控制台;
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#endif


/*
将RGBA模式窗口清除为黑色;
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glClearDepth(1.0f);					//清除深度缓冲区
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);GL_ACCUM_BUFFER_BIT	//累积缓冲区;GL_STENCIL_BUFFER_BIT//模板缓冲区;

glColor3f(1.0, 1.0, 1.0);
参数1：红色0-1.0;
参数2：绿色0-1.0;
参数3：蓝色0-1.0;

glFlush(void);
强制绘制;

glFinish(void);
强制绘制,会阻塞进程;

标志着一个顶点数据的开始;
glBegin(GL_LINE);

GL_POINTS 单个的点;
GL_LINES			一对顶点被解释为一条直线;
GL_LINE_STRIP		一系列的点的连接直线;
GL_LINE_LOOP		和GL_LINE_STRIP一样，但首尾相连;
GL_TRIANGLES		3个顶点被解释为一个三角形;
GL_TRIANGLE_STRIP	3角形的连串;
GL_TRIANGLES_FAN	连接成扇形的三角系列;
GL_QUADS			4个顶点被解释为一个四边形;
GL_QUAD_STRIP		四边形的连接串;
GL_POLYGON			简单的凸多边形;

在其之间可调用函数;
glVertex*();					设置顶点;
glColor*();						设置RGBA颜色;
glIndex*();						设置颜色索引;
glSecondaryColor*();			设置纹理应用后的辅助颜色;
glNormal*();					设置法线向量坐标;
glMaterial*();					设置材料属性;
glFogCoord*();					设置雾坐标;
glTexCoord*();					设置纹理坐标;
glMultiTexCood*();				为多重纹理设置纹理坐标;
glVertexAttrib*();				设置通用的坐标属性;
glEdgeFlag*();					控制边界绘制;
glArraryElement();				提取顶点数组数据;
glEvalCoord*(),glEvalPoint*();	生成坐标;
glCallList(),glCallLists();		执行显示列表;

标志着顶点数据结束;
glEnd();


*/




int main()
{
	//glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	//初始化显示模式;双缓存窗口,RGB模式;
	glutInitWindowSize(250, 250);					//初始化窗口尺寸;
	glutInitWindowPosition(100, 100);				//初始化窗口位置;
	glutCreateWindow("Hello");						//创建窗口;
	init();
	glutDisplayFunc(DrawCircle);						//窗口显示回调;
	glutReshapeFunc(reshape);						//当窗口发生改变时回调事件;
	//glutMouseFunc(Mouse);							//鼠标消息事件回调;
	glutMainLoop();

	return 0;
}


void init()
{
	//清除颜色,设置颜色为黑色;
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//设置作色模式;
	glShadeModel(GL_FLAT);//GL_FLAT:恒定作色(使用某一点作色),GL_SMOOTH:光滑作色(使用各个点作色);
}

void reshape(int w, int h)
{
	/*
	重新调整视图像素矩形;
	*/

	//glViewport(0, 0, (GLint)w, (GLint)h);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);		//截取窗口的宽度;
	glMatrixMode(GL_PROJECTION);					//指定哪个矩阵为当前矩阵,投影矩阵;
	glLoadIdentity();								//将当前用户坐标原点移动到屏幕中心;
	//glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);	//Left,Right,bottom,top,naer,far;
	//gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
	gluOrtho2D(-(GLdouble)w, (GLdouble)w,- (GLdouble)h, (GLdouble)h);

	glMatrixMode(GL_MODELVIEW);						//模型视景矩阵堆;
	glLoadIdentity();

}

void DrawCircle()
{
	GLint circle_point = 100;
	GLdouble dAngle = 0;

	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();							//入栈;
	glColor3f(1.0, 1.0, 1.0);				//设置颜色;

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < circle_point; i++)
	{
		dAngle = 2 * PI*i / circle_point;
		glVertex2f(cos(dAngle)*100 , sin(dAngle)*100 );
	}
	glEnd();

	glPopMatrix();							//出栈;
	glutSwapBuffers();						//双缓冲缓存指针交换;

}