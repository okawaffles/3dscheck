#include "check_touchscreen.hpp"
#include <iostream>
#include <sstream>

void DrawTouchscreenCheckTop(u8 language, AppTextManager *ATM)
{
    UpdateTouch();
    u16 x = GetTouchX();
    u16 y = GetTouchY();

    std::stringstream s;
    s << textGetString(StrId_Touch_PosX, language) << x << std::endl << textGetString(StrId_Touch_PosY, language) << y;
    ATM->RefreshCR();
    ATM->ParseCR(s.str().c_str());
    ATM->DrawCR(2, 23);
}

void DrawTouchscreenCheckBottom()
{
    // no need to update since the top screen function
    // already does it for us
    u16 x = GetTouchX();
    u16 y = GetTouchY();

    // hide if not being touched.
    if (x == 0 && y == 0) return;

    // background set to black
    GFX_DrawRect(0, 0, 320, 240, Colors_Black);

    // the two lines for x and y axis
    GFX_DrawRect(0, y, 320, y+1, Colors_White); // x0-x320
    GFX_DrawRect(x, 0, x+1, 240, Colors_White); // y0-y240
}