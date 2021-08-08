#include <citro2d.h>
#include <3ds.h>
#include "mochalibs.h"
#include "main.h"

void drawLStick(int posX, int posY) {
    u32 white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);

    hidScanInput();
    u32 kDown = hidKeysDown();
    circlePosition pos;
    hidCircleRead(&pos);
    if(kDown & KEY_B)
        mainMenuSet();


    m_useColor(0xFF, 0xFF, 0xFF);
    m_circle(165, 85, 70);
    m_useColor(0x35, 0x3E, 0x4A);
    m_circle(167, 87, 66);

    //400*240
    C2D_DrawLine(180 + pos.dx / 5, 120 + pos.dy / -5, white, 220 + pos.dx / 5, 120 + pos.dy / -5, white, 2, 0);
    C2D_DrawLine(200 + pos.dx / 5, 100 + pos.dy / -5, white, 200 + pos.dx / 5, 140 + pos.dy / -5, white, 2, 0);
}