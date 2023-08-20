#include "graphics.hpp"

void GFX_DrawRect(int startX, int startY, int endX, int endY, u32 color, float zValue)
{
    C2D_DrawRectangle(startX, startY, zValue, endX - startX, endY - startY, color, color, color, color);
}