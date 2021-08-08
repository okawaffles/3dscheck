#include "mochalibs.h"
#include <citro2d.h>
int uc1 = 0xFF;
int uc2 = 0xFF;
int uc3 = 0xFF;

void m_useColor(int c1, int c2, int c3)
{
   uc1 = c1;
   uc2 = c2;
   uc3 = c3; 
}

int touchWithin(float chX, float chY, float tX, float tY, float bX, float bY)
{
    if (chX >= tX && chX <= bX && chY >= tY && chY <= bY)
    {
        return 1;
    } else return 0;
}

void adv_background(int c1, int c2, int c3)
{
    u32 bgC = C2D_Color32(c1, c2, c3, 0xFF);
    C2D_DrawRectangle(0, 0, 0, 400, 240, bgC, bgC, bgC, bgC);
}

void m_background()
{
    u32 bgC = C2D_Color32(uc1, uc2, uc3, 0xFF);
    C2D_DrawRectangle(0, 0, 0, 400, 240, bgC, bgC, bgC, bgC);
}

void m_rect(int x1, int y1, int x2, int y2)
{
    u32 clr = C2D_Color32(uc1, uc2, uc3, 0xFF);
    C2D_DrawRectangle(x1, y1, 0, x2 - x1, y2 - y1, clr, clr, clr, clr);
}

void m_circle(int x, int y, int size)
{
    u32 clr = C2D_Color32(uc1, uc2, uc3, 0xFF);
    C2D_DrawEllipse(x, y, 0, size, size, clr, clr, clr, clr);
}