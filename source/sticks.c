#include <citro2d.h>
#include <3ds.h>
#include "extra.h"
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

void drawCStick() {
    u32 white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
    int posdx = 0;
    int posdy = 0;

    hidScanInput();
    u32 kHeld = hidKeysHeld();
    if (kHeld & KEY_CSTICK_UP)
        posdy = 120;
    if (kHeld & KEY_CSTICK_DOWN)
        posdy = -120;
    if (kHeld & KEY_CSTICK_LEFT)
        posdx = -120;
    if (kHeld & KEY_CSTICK_RIGHT)
        posdx = 120;
    

    if(kHeld & KEY_B)
        mainMenuSet();


    m_useColor(0xFF, 0xFF, 0xFF);
    m_circle(165, 85, 70);
    m_useColor(0x35, 0x3E, 0x4A);
    m_circle(167, 87, 66);

    //400*240
    C2D_DrawLine(180 + posdx / 5, 120 + posdy / -5, white, 220 + posdx / 5, 120 + posdy / -5, white, 2, 0);
    C2D_DrawLine(200 + posdx / 5, 100 + posdy / -5, white, 200 + posdx / 5, 140 + posdy / -5, white, 2, 0);
}