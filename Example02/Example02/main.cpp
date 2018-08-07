
#include "man.h"
#include <math.h>
#include<glut.h>
#include <stdio.h>

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

设置多边形绘制模式;
glPolygonMode()
参数1：填充面
GL_FRONT			正面;
GL_BACK				背面;
GL_FRONT_AND_BACK	正面与背面;
参数2：绘制类型
GL_POINT			多边形画成点;
GL_LINE				多边形绘制成轮廓;
GL_FILL				多边形绘制成填充;

设置多边形正反面;
glFrontFace();
参数1：
GL_CCW	窗口坐标上投影多边形顶点顺序为逆时针方向为正面;
GL_CW	顶点顺序为顺时针方向为正面;

设置多边形点画模式;
glPolygonStipple()
参数1:
32*32位图指针
需要启动多边形点画功能;
glEnable(GL_POLYGON_STIPPLE)

标记顶点是否是多边形起始点;
glEdgeFlag(GL_TRUE);
参数1：
GL_TRUE		是多边形顶点,直至调用glEdgeFlag(GL_FALSE)j结束;
GL_FALSE	不是多边形顶点,直至调用glEdgeFlag(GL_TRUE)j结束;

法线向量;
glNormal*()
可为单条边设置法线,单个顶点设置法线、也可多个顶点共享一个法线;

启动数组;
glEnableClientState(GL_VERTEX_ARRAY);
参数;
GL_VERTEX_ARRAY
GL_COLOR_ARRAY
GL_SECONDARY_COLOR_ARRAY
GL_INDEX_ARRAY
GL_NORMAL_ARRAY
GL_FOG_COORDINATE_ARRAY
GL_TEXTURE_COORD_ARRAY
GL_EDGE_FLAG_ARRAY

glVertexPointer();
参数1：顶点坐标数量;
参数2：顶点数据类型;
参数3：连续顶点的偏移值;
参数4：顶点数组首地址;

关闭数组;
glDisableClientState(GL_VERTEX_ARRAY);



*/



int main()
{
	//glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	//初始化显示模式;双缓存窗口,RGB模式;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitWindowSize(250, 250);					//初始化窗口尺寸;
	glutInitWindowSize(400, 250);
	glutInitWindowPosition(100, 100);				//初始化窗口位置;
	glutCreateWindow("Hello");						//创建窗口;
	init();

	//glutDisplayFunc(DrawCircle);
	//glutDisplayFunc(DrawPoint);
	//glutDisplayFunc(DrawLine);
	//glutDisplayFunc(DrawLineEx);
	//glutDisplayFunc(MarkPolygon);
	glutDisplayFunc(DrawTriangle);

	
	
	


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
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);	//Left,Right,bottom,top,naer,far;
	//gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
	//gluOrtho2D(-(GLdouble)w / 100, (GLdouble)w/ 100, -(GLdouble)h / 100, (GLdouble)h/ 100);
	//gluOrtho2D(-(GLdouble)w, (GLdouble)w,- (GLdouble)h, (GLdouble)h);

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

void DrawPoint()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();							//入栈;
	glColor3f(1.0, 1.0, 1.0);				//设置颜色;

	/*
	设置点的大小,要在Begin之前;
	*/
	glPointSize((GLfloat)20.0);

	glBegin(GL_POINTS);
	glVertex3f(0.0f, 0.0f,0.0f);
	glEnd();

	glPopMatrix();							//出栈;
	glutSwapBuffers();						//双缓冲缓存指针交换;
}

void DrawLine()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glPushMatrix();							//入栈;
	glColor3f(1.0, 1.0, 1.0);				//设置颜色;

	/*
		设置线宽,要在glBegin()之前设置;
	*/

	//glLineWidth(50.0f);

	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	//glVertex3f(500.0f, 500.0f, 0.0f);
	glVertex3f(5.0f, 5.0f, 0.0f);
	glEnd();
	glFlush();

	//glPopMatrix();							//出栈;
	//glutSwapBuffers();						//双缓冲缓存指针交换;
}

void DrawLineEx()
{
	int i = 0;
	glColor3f(1.0, 1.0, 1.0);

	/*启动直线点画模式;*/
	glEnable(GL_LINE_STIPPLE);

	/*第一行;*/
	/*定义点画模式;*/
	glLineStipple(1, 0x0101);
	drawOneLine(50.0f, 125.0f, 150.0f, 125.0f);
	glLineStipple(1, 0x00ff);
	drawOneLine( 150.0f, 125.0f, 250.0f, 125.0f);
	glLineStipple(1, 0x14c7);
	drawOneLine(150.0f, 125.0f, 250.0f, 125.0f);

	/*第二行;*/
	glLineWidth(5.0f);/*设置线宽;*/
	glLineStipple(1, 0x0101);
	drawOneLine(50.0f, 100.0f, 150.0f, 100.0f);
	glLineStipple(1, 0x00ff);
	drawOneLine(150.0f, 100.0f, 250.0f, 100.0f);
	glLineStipple(1, 0x14c7);
	drawOneLine(150.0f, 100.0f, 250.0f, 100.0f);

	/*第三行;*/
	glLineStipple(1, 0x14c7);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i < 7; i++)
	{
		glVertex2f(GLfloat(50.0 + i * 50), 75.0);
	}
	glEnd();

	/*第四行;*/
	for (i = 0; i < 6; i++)
	{
		drawOneLine(GLfloat(50.0 + i * 50), 50.0f, GLfloat(50.0 + (i + 1) * 50), 50.0f);
	}

	/*第五行;*/
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
		glEdgeFlag(GL_TRUE);/*标记顶点是否是多边形起始点;*/
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
	glColor3f(1.0, 1.0, 1.0);				//设置颜色;
	
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

