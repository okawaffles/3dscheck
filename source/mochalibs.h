#ifndef MOCHALIBS_H_INCLUDED
#define MOCHALIBS_H_INCLUDED

int touchWithin(float chX, float chY, float tX, float tY, float bX, float bY); // checks for touchscreen input within an area
void m_useColor(int c1, int c2, int c3); // sets auto-use color, mainly for easy shapes
void adv_background(int c1, int c2, int c3); // sets background to one color | m_background(0xFF, 0xFF, 0xFF);
void m_background(); // sets background to set color
void m_rect(int x1, int y1, int x2, int y2); // makes a rectangle without the extra params
void m_circle(int x, int y, int size); // makes a circle without the extra params

#endif