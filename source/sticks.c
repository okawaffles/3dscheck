#include <citro2d.h>
#include <3ds.h>
#include "mochalibs.h"

void drawLStick(int posX, int posY) {
    u32 white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);

    int px = posX * 3;
    int py = posY * 3;

    m_useColor(0xFF, 0x00, 0x00);
    C2D_DrawLine(px, py, white, px, py, white, 2, 0);
}