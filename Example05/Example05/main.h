#pragma once

#ifndef _HEAD_EXAMPLE_FIVE_MAIN
#define _HEAD_EXAMPLE_FIVE_MAIN


void ligthSphere_Init(void);
void ligthSphere_reshape(int w, int h);
void ligthSphere_display(void);
void ligthSphere_Show(void);

void moveligth_Show();
void moveligth_Mouse(int button, int state, int x, int y);
void moveligth_reshape(int w, int h);
void moveligth_display();
void moveligth_Init();

void ColorMat_Init();
void ColorMat_display(void);
void ColorMat_reshape(int w, int h);
void  ColorMat_Mouse(int button, int state, int x, int y);
void  ColorMat_Show();

#endif // !_HEAD_EXAMPLE_FOUR_MAIN