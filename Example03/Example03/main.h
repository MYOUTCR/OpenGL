#pragma once


#ifndef _HEAD_EXAMPLE_THREE_MAIN
#define _HEAD_EXAMPLE_THREE_MAIN


void init();
void reshape(int w, int h);
void DrawCube();
void ClipPlane();

void SolarWin();
void spinDisplay();
void SolarReshape(int w, int h);
void DisplaySolar();
void SolarKeyboard(unsigned char key, int x, int y);

void ShoulderWin();
void ShoulderDisplay();
void ShoulderReshape(int w, int h);
void ShoulderKeyboard(unsigned char key, int x, int y);

void UnprojectWin();
void UnprojectDisplay();
void UnprojectReshape(int w, int h);
void UnprojectMouse(int button, int state, int x, int y);


#endif // !_HEAD_EXAMPLE_THREE_MAIN