#pragma once
#ifndef _HEAD_EXAMPLE_TOW_MAIN
#define _HEAD_EXAMPLE_TOW_MAIN


#define PI 3.1415926535898
#define drawOneLine(x1,y1,x2,y2)	glBegin(GL_LINES);	\
	glVertex2f(x1,y1); glVertex2f(x2,y2);glEnd();

#define X .525731112119133606
#define Z .850650808352039932


void init();
void reshape(int w, int h);
void DrawCircle();
void DrawPoint();
void DrawLine();
void DrawLineEx();
void DrawPolygon();
void MarkPolygon();
void DrawTriangle();

void normalize(float v[3]);
void normcrossprod(float v1[3], float v2[3], float out[3]);


#endif // !_HEAD_EXAMPLE_TOW_MAIN
