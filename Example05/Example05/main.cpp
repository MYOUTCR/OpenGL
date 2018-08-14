
#include "main.h"
#include<glut.h>

#ifdef _MSC_VER//���ؿ���̨;
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#endif

/*
������Դ;
glLight*()
����1:
����ָ���Ĺ�Դ;
GL_LIGHT0~GL_LIGHT7
����2:
GL_AMBIENT					��Ļ���ǿ��;
GL_DIFFUSE					���ɢ��ǿ��GL_LIGHT0 Ĭ��Ϊ��ɫ ����Ĭ��Ϊ��ɫ;
GL_SPECULAR					��ľ���ǿ��GL_LIGHT0 Ĭ��Ϊ��ɫ ����Ĭ��Ϊ��ɫ;
GL_POSITION					��ʾ��Դ��λ�õ�����(x,y,z,w);
GL_SPOT_DIRECTION			��ʾ�۹�Ʒ��������;
GL_SPOT_EXPONENT			�۹�ָ��;
GL_SPOT_CUTOFF				�۹�Ƶ��н�;
GL_CONSTANT_ATTENUATION		����˥������;
GL_LINEAR_ATTENUATION		����˥������;
GL_QUADRATIC_ATTENUATION	����˥������;


*/

static int spin = 0;

int main()
{
	/*��������;*/
	//ligthSphere_Show();
	//moveligth_Show();
	
	ColorMat_Show();

	return 0;
}

void ligthSphere_Init(void)
{
	GLfloat mat_specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat mat_shinness[] = { 50.0 };
	GLfloat light_position[] = { 1.0,1.0,1.0,0.0 };
	GLfloat white_light[] = { 1.0,1.0,1.0,1.0 };
	GLfloat lmodel_ambient[] = { 0.1,0.1,0.1,1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shinness);
	
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	return;
}

void ligthSphere_reshape(int w, int h)
{
	glViewport(0, 0, (GLfloat)w, (GLfloat)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
		glOrtho(-1.5, 1.5, -1.5*(GLfloat)h / (GLfloat)w, 1.5*(GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-1.5*(GLfloat)h / (GLfloat)w, 1.5*(GLfloat)h / (GLfloat)w, -1.5, 1.5,  -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
}

void ligthSphere_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSolidSphere(1.0, 20, 16);
	glFlush();
}

void ligthSphere_Show(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello");

	ligthSphere_Init();
	glutDisplayFunc(ligthSphere_display);
	glutReshapeFunc(ligthSphere_reshape);

	glutMainLoop();

	return;
}


void moveligth_Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

}


void moveligth_display()
{
	GLfloat position[] = { 0.0,0.0,1.5,1.0 };
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -5.0);

	glPushMatrix();
	glRotated((GLdouble)spin, 1.0, 0.0, 0.0);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glTranslated(0.0, 0.0, 1.5);
	glDisable(GL_DEPTH_TEST);
	glColor3f(0.0, 0.0, 1.0);
	glutWireCube(0.1);
	glEnable(GL_DEPTH_TEST);
	glPopMatrix();

	glutSolidTorus(0.275, 0.85, 8, 15);
	glPopMatrix();

	glFlush();

}


void moveligth_reshape(int w, int h)
{
	glViewport(0, 0, (GLfloat)w, (GLfloat)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void moveligth_Mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (GLUT_DOWN == state)
		{
			spin = (spin + 30) % 360;
			glutPostRedisplay();
		}
		break;



	default:
		break;
	}


}

void moveligth_Show()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello");

	moveligth_Init();
	glutDisplayFunc(moveligth_display);
	glutReshapeFunc(moveligth_reshape);
	glutMouseFunc(moveligth_Mouse);

	glutMainLoop();

}

GLfloat diffuseMaterial[4] = { 0.5,0.5,0.5,1.0 };


void ColorMat_Init()
{
	GLfloat mat_specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat light_position[] = { 1.0,1.0,1.0,0.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 25.0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
}

void ColorMat_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSolidSphere(1.0, 20, 16);
	glFlush();
}

void ColorMat_reshape(int w, int h)
{
	glViewport(0, 0, (GLfloat)w, (GLfloat)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
		glOrtho(-1.5, 1.5, -1.5*(GLfloat)h / (GLfloat)w, 1.5*(GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-1.5*(GLfloat)h / (GLfloat)w, 1.5*(GLfloat)h / (GLfloat)w, -1.5, 1.5, -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
}

void  ColorMat_Mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (GLUT_DOWN == state)
		{
			diffuseMaterial[0] += 0.1;
			if (diffuseMaterial[0] > 1.0)
				diffuseMaterial[0] = 0.0;
			glColor4fv(diffuseMaterial);
			glutPostRedisplay();
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (GLUT_DOWN == state)
		{
			diffuseMaterial[1] += 0.1;
			if (diffuseMaterial[1] > 1.0)
				diffuseMaterial[1] = 0.0;
			glColor4fv(diffuseMaterial);
			glutPostRedisplay();
		}
		break;
	case GLUT_MIDDLE_BUTTON:
		if (GLUT_DOWN == state)
		{
			diffuseMaterial[2] += 0.1;
			if (diffuseMaterial[2] > 1.0)
				diffuseMaterial[2] = 0.0;
			glColor4fv(diffuseMaterial);
			glutPostRedisplay();
		}
		break;
	default:
		break;
	}


}

void  ColorMat_Show()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello");

	ColorMat_Init();
	glutDisplayFunc(ColorMat_display);
	glutReshapeFunc(ColorMat_reshape);
	glutMouseFunc(ColorMat_Mouse);

	glutMainLoop();
}