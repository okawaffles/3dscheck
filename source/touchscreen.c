#include <citro2d.h>
#include <3ds.h>
#include "okalibs.h"

void touchPosLines(float tX, float tY)
{
    adv_background(0x00, 0x00, 0x00);
    u32 white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
    C2D_DrawLine(0, tY, white, 400, tY, white, 3, 0); // y axis line
    C2D_DrawLine(tX, 0, white, tX, 240, white, 3, 0); // x axis line
}