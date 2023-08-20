#include "graphics.hpp"

void GFX_DrawRect(int startX, int startY, int endX, int endY, u32 color)
{
    C2D_DrawRectangle(startX, startY, 0, endX - startX, endY - startY, color, color, color, color);
}