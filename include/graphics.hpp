#pragma once

#include "common.hpp"

// converts C2D_DrawRectangle()'s XYWH to x1y1x2y2 and draws a rectangle
// only supports solid color.
void GFX_DrawRect(int startX, int startY, int endX, int endY, u32 color);